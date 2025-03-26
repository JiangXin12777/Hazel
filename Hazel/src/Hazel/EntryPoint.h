#pragma once

#include "Log.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();

	HZ_CORE_WARNING("Hello, Welcome to the Game Engine!!!");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // HZ_PLATFORM_WINDOWS
