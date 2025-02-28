/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TVertexBuffer.h>

namespace OvRendering::HAL
{
	struct NoneVertexBufferContext {};
	using NoneVertexBuffer = TVertexBuffer<Settings::EGraphicsBackend::NONE, NoneVertexBufferContext>;
}
