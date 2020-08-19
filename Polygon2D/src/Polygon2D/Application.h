#pragma once

#include "Core.h"

namespace Polygon2D {

	class POLYGON2D_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}


