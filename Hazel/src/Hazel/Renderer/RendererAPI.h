#pragma once

#include <glm/glm.hpp>

#include "Hazel/Renderer/VertexArray.h"

namespace Hazel {

	/**
	* 对不同平台的渲染指令进行封装
	*/
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, OpenGL = 1
		};
	public:
		static Scope<RendererAPI> Create();

		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		/**
		* @param vertexArray 需要绘制得 VAO 数据
		*/
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount = 0) = 0;

		inline static API GetAPI() { return s_API; }
	private:
		static API s_API;
	};

}