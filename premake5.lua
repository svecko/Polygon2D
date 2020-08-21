workspace "Polygon2D"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Polygon2D"
	location "Polygon2D"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"POLYGON2D_PLATFORM_WINDOWS",
			"POLYGON2D_BUILD_DLL"
		}

		postbuildcommands
		{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "POLYGON2D_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POLYGON2D_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POLYGON2D_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Polygon2D/vendor/spdlog/include",
		"Polygon2D/src"
	}

	links 
	{
		"Polygon2D"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"POLYGON2D_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "POLYGON2D_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "POLYGON2D_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "POLYGON2D_DIST"
		optimize "On"