/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TIndexBuffer.h>

namespace OvRendering::HAL
{
	struct NoneIndexBufferContext {};
	using NoneIndexBuffer = TIndexBuffer<Settings::EGraphicsBackend::NONE, NoneIndexBufferContext>;
}
