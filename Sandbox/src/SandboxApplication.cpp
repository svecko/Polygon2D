#include <Polygon2D.h>

class Sandbox : public Polygon2D::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

};

Polygon2D::Application* Polygon2D::CreateApplication()
{
	return new Sandbox();
}