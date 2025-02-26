/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <GL/glew.h>

#include "OvRendering/HAL/Common/TVertexBuffer.h"
#include "OvRendering/HAL/OpenGL/GLTypes.h"

namespace OvRendering::HAL
{
	struct GLVertexBufferContext
	{
		uint32_t bufferID = 0;
	};

	using GLVertexBuffer = TVertexBuffer<Settings::EGraphicsBackend::OPENGL, GLVertexBufferContext>;

	template<>
	template<class T>
	void GLVertexBuffer::Upload(std::span<const T> p_data, Settings::EAccessSpecifier p_usage)
	{
		Bind();
		glBufferData(GL_ARRAY_BUFFER, p_data.size_bytes(), p_data.data(), EnumToValue<GLenum>(p_usage));
		Unbind();
	}
}
