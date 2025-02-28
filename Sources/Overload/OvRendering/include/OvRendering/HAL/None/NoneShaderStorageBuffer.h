/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TShaderStorageBuffer.h>

namespace OvRendering::HAL
{
	struct NoneShaderStorageBufferContext {};
	using NoneShaderStorageBuffer = TShaderStorageBuffer<Settings::EGraphicsBackend::NONE, NoneShaderStorageBufferContext>;
}
