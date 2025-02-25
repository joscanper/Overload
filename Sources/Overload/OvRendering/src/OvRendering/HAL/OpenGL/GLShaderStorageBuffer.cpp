/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLTypes.h>
#include <OvRendering/HAL/OpenGL/GLShaderStorageBuffer.h>

template<>
OvRendering::HAL::GLShaderStorageBuffer::TShaderStorageBuffer(Settings::EAccessSpecifier p_accessSpecifier)
{
	glGenBuffers(1, &m_context.bufferID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_context.bufferID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, 0, nullptr, ToGLenum(p_accessSpecifier));
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

template<>
OvRendering::HAL::GLShaderStorageBuffer::~TShaderStorageBuffer()
{
	glDeleteBuffers(1, &m_context.bufferID);
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::SendBlocks(void* p_data, size_t p_size)
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, m_context.bufferID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, p_size, p_data, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Bind(uint32_t p_bindingPoint)
{
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, p_bindingPoint, m_context.bufferID);
}

template<>
void OvRendering::HAL::GLShaderStorageBuffer::Unbind()
{
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}
