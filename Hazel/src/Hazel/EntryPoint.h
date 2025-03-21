#pragma once
#include <stdio.h>
#include "Log.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	 Hazel::Log::Init();

	 HZ_CORE_WARNING("Initialize log!");

	 HZ_INFO("Hello! Var={0}", argc);

	printf("Hazel Engine Start!\n");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif // HZ_PLATFORM_WINDOWS
