/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TVertexArray.h>

namespace OvRendering::HAL
{
	struct GLVertexArrayContext
	{
		uint32_t id = 0;
	};

	using GLVertexArray = TVertexArray<Settings::EGraphicsBackend::OPENGL, GLVertexArrayContext>;
}
