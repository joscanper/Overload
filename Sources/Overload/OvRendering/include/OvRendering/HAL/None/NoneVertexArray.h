/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TVertexArray.h>

namespace OvRendering::HAL
{
	struct NoneVertexArrayContext {};
	using NoneVertexArray = TVertexArray<Settings::EGraphicsBackend::NONE, NoneVertexArrayContext>;
}
