/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/HAL/Common/TIndexBuffer.h"

namespace OvRendering::HAL
{
	struct GLIndexBufferContext
	{
		uint32_t bufferID = 0;
	};

	using GLIndexBuffer = TIndexBuffer<Settings::EGraphicsBackend::OPENGL, GLIndexBufferContext>;
}
