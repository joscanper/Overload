/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TUniformBuffer.h>

namespace OvRendering::HAL
{
	struct GLUniformBufferContext
	{
		uint32_t id = 0;
		uint32_t bindingPoint = 0;
	};

	using GLUniformBuffer = TUniformBuffer<Settings::EGraphicsBackend::OPENGL, GLUniformBufferContext>;
}
