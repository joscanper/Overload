/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvDebug/Logger.h>
#include <OvRendering/HAL/OpenGL/GLShaderStage.h>

GLenum GetGLShaderType(OvRendering::Settings::EShaderType p_type)
{
	switch (p_type)
	{
	case OvRendering::Settings::EShaderType::VERTEX:
		return GL_VERTEX_SHADER;
	case OvRendering::Settings::EShaderType::FRAGMENT:
		return GL_FRAGMENT_SHADER;
	default:
		return 0;
	}
}

std::string GetShaderTypeString(OvRendering::Settings::EShaderType p_type)
{
	switch (p_type)
	{
	case OvRendering::Settings::EShaderType::VERTEX:
		return "VERTEX SHADER";
	case OvRendering::Settings::EShaderType::FRAGMENT:
		return "FRAGMENT SHADER";
	default:
		return "UNKNOWN SHADER";
	}
}

template<>
OvRendering::HAL::GLShaderStage::TShaderStage(Settings::EShaderType p_type) : m_type(p_type)
{
	m_id = glCreateShader(GetGLShaderType(p_type));
}

template<>
OvRendering::HAL::GLShaderStage::~TShaderStage()
{
	glDeleteShader(m_id);
}

template<>
void OvRendering::HAL::GLShaderStage::Upload(const std::string& p_source) const
{
	const char* source = p_source.c_str();
	glShaderSource(m_id, 1, &source, nullptr);
}

template<>
OvRendering::Settings::ShaderCompilationResult OvRendering::HAL::GLShaderStage::Compile() const
{
	glCompileShader(m_id);

	GLint compileStatus;
	glGetShaderiv(m_id, GL_COMPILE_STATUS, &compileStatus);

	if (compileStatus == GL_FALSE)
	{
		GLint maxLength;
		glGetShaderiv(m_id, GL_INFO_LOG_LENGTH, &maxLength);

		std::string errorLog(maxLength, ' ');
		glGetShaderInfoLog(m_id, maxLength, &maxLength, errorLog.data());

		std::string shaderTypeString = GetShaderTypeString(m_type);
		std::string errorHeader = "[" + shaderTypeString + "] \"";
		return {
			.success = false,
			.message = errorLog
		};
	}

	return {
		.success = true
	};
}

template<>
uint32_t OvRendering::HAL::GLShaderStage::GetID() const
{
	return m_id;
}
