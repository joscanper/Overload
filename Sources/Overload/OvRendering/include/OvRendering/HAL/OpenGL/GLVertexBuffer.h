/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <GL/glew.h>

#include <OvRendering/HAL/Common/TVertexBuffer.h>
#include <OvRendering/HAL/OpenGL/GLTypes.h>

namespace OvRendering::HAL
{
	struct GLVertexBufferContext
	{
		uint32_t id = 0;
	};

	using GLVertexBuffer = TVertexBuffer<Settings::EGraphicsBackend::OPENGL, GLVertexBufferContext>;
}
