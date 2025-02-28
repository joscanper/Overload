/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLIndexBuffer.h>
#include <OvRendering/HAL/OpenGL/GLTypes.h>

template<>
OvRendering::HAL::GLIndexBuffer::TIndexBuffer()
{
	glGenBuffers(1, &m_context.id);
}

template<>
OvRendering::HAL::GLIndexBuffer::~TIndexBuffer()
{
	glDeleteBuffers(1, &m_context.id);
}

template<>
void OvRendering::HAL::GLIndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_context.id);
}

template<>
void OvRendering::HAL::GLIndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

template<>
void OvRendering::HAL::GLIndexBuffer::Upload(const void* p_data, size_t p_size, Settings::EAccessSpecifier p_usage) const
{
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_size, p_data, EnumToValue<GLenum>(p_usage));
	Unbind();
}

template<>
uint32_t OvRendering::HAL::GLIndexBuffer::GetID() const
{
	return m_context.id;
}
