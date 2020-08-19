#pragma once

#ifdef POLYGON2D_PLATFORM_WINDOWS

extern Polygon2D::Application* Polygon2D::CreateApplication();

int main(int argc, const char** argv)
{
	auto app = Polygon2D::CreateApplication();
	app->Run();
	delete app;
}

#endif // POLYGON2D_PLATFORM_WINDOWS
