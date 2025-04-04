#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

#include "Hazel/Log.h"

namespace Hazel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		// m_WindowHandle（一个 GLFW 窗口对象）成为当前线程的 OpenGL 上下文。
		glfwMakeContextCurrent(m_WindowHandle);
		// 加载 OpenGL 函数
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");

		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO("  Vendor: {0}", (char*)glGetString(GL_VENDOR));
		HZ_CORE_INFO("  Renderer: {0}", (char*)glGetString(GL_RENDERER));
		HZ_CORE_INFO("  Version: {0}", (char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}