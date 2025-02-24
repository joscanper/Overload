/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/HAL/Common/TShaderStorageBuffer.h"

namespace OvRendering::HAL
{
	struct GLShaderStorageBufferContext
	{
		uint32_t bufferID = 0;
	};

	using GLShaderStorageBuffer = TShaderStorageBuffer<Settings::EGraphicsBackend::OPENGL, GLShaderStorageBufferContext>;
}
