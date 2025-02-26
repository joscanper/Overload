/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLTypes.h>
#include <OvRendering/HAL/OpenGL/GLShaderStorageBuffer.h>

template<>
OvRendering::HAL::GLShaderStorageBuffer::TShaderStorageBuffer()
{
	glGenBuffers(1, &m_context.bufferID);
}

template<>
OvRendering::HAL::GLShaderStorageBuffer::~TShaderStorageBuffer()
{
	glDeleteBuffers(1, &m_context.bufferID);
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Bind(std::optional<uint32_t> p_bindingPoint)
{
	if (p_bindingPoint.has_value())
	{
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, p_bindingPoint.value(), m_context.bufferID);
	}
	else
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_context.bufferID);
	}
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Unbind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}
