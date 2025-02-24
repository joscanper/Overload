/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/HAL/Common/TUniformBuffer.h"

#include <GL/glew.h>

namespace OvRendering::HAL
{
	struct GLUniformBufferContext
	{
		uint32_t bufferID = 0;
		uint32_t bindingPoint = 0;
	};

	using GLUniformBuffer = TUniformBuffer<Settings::EGraphicsBackend::OPENGL, GLUniformBufferContext>;

	template<>
	template<typename T>
	void GLUniformBuffer::SetSubData(const T& p_data, size_t p_offsetInOut)
	{
		// TODO: Maybe we could find a way to set sub data without having to use bind/unbind, would be more efficient
		glBindBuffer(GL_UNIFORM_BUFFER, m_context.bufferID);
		glBufferSubData(GL_UNIFORM_BUFFER, p_offsetInOut, sizeof(T), std::addressof(p_data));
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	template<>
	template<typename T>
	void GLUniformBuffer::SetSubData(const T& p_data, std::reference_wrapper<size_t> p_offsetInOut)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_context.bufferID);
		size_t dataSize = sizeof(T);
		glBufferSubData(GL_UNIFORM_BUFFER, p_offsetInOut.get(), dataSize, std::addressof(p_data));
		p_offsetInOut.get() += dataSize;
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
}
