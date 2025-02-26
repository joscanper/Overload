/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <gl/glew.h>

#include <OvRendering/HAL/OpenGL/GLVertexArray.h>
#include <OvRendering/HAL/OpenGL/GLTypes.h>

template<>
OvRendering::HAL::GLVertexArray::TVertexArray()
{
	glGenVertexArrays(1, &m_context.bufferID);
	glBindVertexArray(m_context.bufferID);
}

template<>
OvRendering::HAL::GLVertexArray::~TVertexArray()
{
	glDeleteVertexArrays(1, &m_context.bufferID);
}

template<>
void OvRendering::HAL::GLVertexArray::BindAttribute(
	uint32_t p_attribute,
	HAL::VertexBuffer& p_vertexBuffer,
	Settings::EDataType p_type,
	uint64_t p_count,
	uint64_t p_stride,
	intptr_t p_offset
) const
{
	Bind();
	p_vertexBuffer.Bind();
	glEnableVertexAttribArray(p_attribute);
	glVertexAttribPointer(static_cast<GLenum>(p_attribute), static_cast<GLint>(p_count), EnumToValue<GLenum>(p_type), GL_FALSE, static_cast<GLsizei>(p_stride), reinterpret_cast<const GLvoid*>(p_offset));
}

template<>
void OvRendering::HAL::GLVertexArray::Bind() const
{
	glBindVertexArray(m_context.bufferID);
}

template<>
void OvRendering::HAL::GLVertexArray::Unbind() const
{
	glBindVertexArray(0);
}

template<>
uint32_t OvRendering::HAL::GLVertexArray::GetID() const
{
	return m_context.bufferID;
}
