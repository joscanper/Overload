/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLIndexBuffer.h>

template<>
OvRendering::HAL::GLIndexBuffer::TIndexBuffer(unsigned int* p_data, size_t p_elements)
{
	glGenBuffers(1, &m_context.bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_context.bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_elements * sizeof(unsigned int), p_data, GL_STATIC_DRAW);
}

template<>
OvRendering::HAL::GLIndexBuffer::TIndexBuffer(std::vector<uint32_t>& p_data) : TIndexBuffer(p_data.data(), p_data.size())
{
}

template<>
OvRendering::HAL::GLIndexBuffer::~TIndexBuffer()
{
	glDeleteBuffers(1, &m_context.bufferID);
}

template<>
void OvRendering::HAL::GLIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_context.bufferID);
}

template<>
void OvRendering::HAL::GLIndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

template<>
uint32_t OvRendering::HAL::GLIndexBuffer::GetID()
{
	return m_context.bufferID;
}
