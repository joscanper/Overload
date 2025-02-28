/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TUniformBuffer.h>

namespace OvRendering::HAL
{
	struct NoneUniformBufferContext {};
	using NoneUniformBuffer = TUniformBuffer<Settings::EGraphicsBackend::NONE, NoneUniformBufferContext>;
}
