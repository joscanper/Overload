/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLUniformBuffer.h>
#include <OvRendering/Resources/Shader.h>

template<>
OvRendering::HAL::GLUniformBuffer::TUniformBuffer(
	size_t p_size,
	uint32_t p_bindingPoint,
	uint32_t p_offset,
	OvRendering::Settings::EAccessSpecifier p_accessSpecifier
) : m_context{ .bindingPoint = p_bindingPoint }
{
	glGenBuffers(1, &m_context.bufferID);
	glBindBuffer(GL_UNIFORM_BUFFER, m_context.bufferID);
	glBufferData(GL_UNIFORM_BUFFER, p_size, nullptr, static_cast<GLint>(p_accessSpecifier));
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

template<>
OvRendering::HAL::GLUniformBuffer::~TUniformBuffer()
{
	glDeleteBuffers(1, &m_context.bufferID);
}

template<>
void OvRendering::HAL::GLUniformBuffer::Bind(uint32_t p_bindingPoint)
{
	glBindBufferBase(GL_UNIFORM_BUFFER, p_bindingPoint, m_context.bufferID);
}

template<>
void OvRendering::HAL::GLUniformBuffer::Unbind()
{
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

template<>
GLuint OvRendering::HAL::GLUniformBuffer::GetID() const
{
	return m_context.bufferID;
}

template<>
void OvRendering::HAL::GLUniformBuffer::BindBlockToShader(OvRendering::Resources::Shader& p_shader, uint32_t p_uniformBlockLocation, uint32_t p_bindingPoint)
{
	glUniformBlockBinding(p_shader.GetProgram().id, p_uniformBlockLocation, p_bindingPoint);
}

template<>
void OvRendering::HAL::GLUniformBuffer::BindBlockToShader(OvRendering::Resources::Shader& p_shader, const std::string& p_name, uint32_t p_bindingPoint)
{
	glUniformBlockBinding(p_shader.GetProgram().id, GetBlockLocation(p_shader, p_name), p_bindingPoint);
}

template<>
uint32_t OvRendering::HAL::GLUniformBuffer::GetBlockLocation(OvRendering::Resources::Shader& p_shader, const std::string& p_name)
{
	return glGetUniformBlockIndex(p_shader.GetProgram().id, p_name.c_str());
}
