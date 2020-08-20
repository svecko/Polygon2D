#pragma once

#ifdef POLYGON2D_PLATFORM_WINDOWS

extern Polygon2D::Application* Polygon2D::CreateApplication();

int main(int argc, const char** argv)
{
	Polygon2D::Log::Init();
	POLYGON2D_CORE_WARN("Initialized Log!");
	int a = 5;
	POLYGON2D_INFO("Hello! Var={0}", a);

	auto app = Polygon2D::CreateApplication();
	app->Run();
	delete app;
}

#endif // POLYGON2D_PLATFORM_WINDOWS
