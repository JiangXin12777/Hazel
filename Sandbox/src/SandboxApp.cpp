#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include "ExampleLayer.h"
#include "Sandbox2D.h"


/**
* 
*/
class Sandbox : public Hazel::Application
{
public:
	Sandbox(Hazel::ApplicationCommandLineArgs args)
		: Application("Sandbox", args)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

Hazel::Application* Hazel::CreateApplication(Hazel::ApplicationCommandLineArgs args)
{
	return new Sandbox(args);
}
