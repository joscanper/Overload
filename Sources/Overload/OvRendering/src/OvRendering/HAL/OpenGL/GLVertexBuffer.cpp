/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/OpenGL/GLVertexBuffer.h>

template<>
OvRendering::HAL::GLVertexBuffer::TVertexBuffer()
{
	glGenBuffers(1, &m_context.bufferID);
}

template<>
OvRendering::HAL::GLVertexBuffer::~TVertexBuffer()
{
	glDeleteBuffers(1, &m_context.bufferID);
}

template<>
void OvRendering::HAL::GLVertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_context.bufferID);
}

template<>
void OvRendering::HAL::GLVertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

template<>
uint32_t OvRendering::HAL::GLVertexBuffer::GetID() const
{
	return m_context.bufferID;
}
