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
	glGenBuffers(1, &m_context.id);
}

template<>
OvRendering::HAL::GLShaderStorageBuffer::~TShaderStorageBuffer()
{
	glDeleteBuffers(1, &m_context.id);
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Bind(std::optional<uint32_t> p_bindingPoint) const
{
	if (p_bindingPoint.has_value())
	{
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, p_bindingPoint.value(), m_context.id);
	}
	else
	{
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_context.id);
	}
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Unbind() const
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Upload(void* p_data, size_t p_size, Settings::EAccessSpecifier p_usage) const
{
	Bind();
	glBufferData(GL_SHADER_STORAGE_BUFFER, p_size, p_data, EnumToValue<GLenum>(p_usage));
	Unbind();
}
