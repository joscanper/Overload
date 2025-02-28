/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TVertexArray.h>

namespace OvRendering::HAL
{
	struct NoneVertexArrayContext
	{
		uint32_t attributeCount = 0;
	};

	using NoneVertexArray = TVertexArray<Settings::EGraphicsBackend::NONE, NoneVertexArrayContext>;
}
