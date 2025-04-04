#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

namespace Hazel {

	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		/** 将图层依附到 APP 中 */
		virtual void OnAttach() {}

		/** 将图层从 App 中分离 */
		virtual void OnDetach() {}

		/** 用于处理渲染的loop */
		virtual void OnUpdate() {}

		virtual void OnImGuiRender() {}

		/** 用于处理事件 */
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}