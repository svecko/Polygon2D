#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Polygon2D {

	class POLYGON2D_API Log
	{
	public:
		Log();
		~Log();

		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define POLYGON2D_CORE_TRACE(...)    ::Polygon2D::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define POLYGON2D_CORE_INFO(...)     ::Polygon2D::Log::GetCoreLogger()->info(__VA_ARGS__)
#define POLYGON2D_CORE_WARN(...)     ::Polygon2D::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define POLYGON2D_CORE_ERROR(...)    ::Polygon2D::Log::GetCoreLogger()->error(__VA_ARGS__)
#define POLYGON2D_CORE_FATAL(...)    ::Polygon2D::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define POLYGON2D_TRACE(...)         ::Polygon2D::Log::GetClientLogger()->trace(__VA_ARGS__)
#define POLYGON2D_INFO(...)          ::Polygon2D::Log::GetClientLogger()->info(__VA_ARGS__)
#define POLYGON2D_WARN(...)          ::Polygon2D::Log::GetClientLogger()->warn(__VA_ARGS__)
#define POLYGON2D_ERROR(...)         ::Polygon2D::Log::GetClientLogger()->error(__VA_ARGS__)
#define POLYGON2D_FATAL(...)         ::Polygon2D::Log::GetClientLogger()->fatal(__VA_ARGS__)