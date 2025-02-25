/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvDebug/Logger.h>
#include <OvRendering/HAL/OpenGL/GLShaderProgram.h>
#include <OvRendering/HAL/OpenGL/GLTexture.h>

template<>
OvRendering::HAL::GLShaderProgram::TShaderProgram() : id(glCreateProgram())
{
}

template<>
OvRendering::HAL::GLShaderProgram::~TShaderProgram()
{
	glDeleteProgram(id);
}

template<>
void OvRendering::HAL::GLShaderProgram::Bind() const
{
	glUseProgram(id);
}

template<>
void OvRendering::HAL::GLShaderProgram::Unbind() const
{
	glUseProgram(0);
}

template<>
void OvRendering::HAL::GLShaderProgram::Attach(const GLShaderStage& p_shader)
{
	glAttachShader(id, p_shader.GetID());
	m_attachedShaders.push_back(std::ref(p_shader));
}

template<>
void OvRendering::HAL::GLShaderProgram::Detach(const GLShaderStage& p_shader)
{
	glDetachShader(id, p_shader.GetID());
	m_attachedShaders.erase(std::remove_if(
		m_attachedShaders.begin(),
		m_attachedShaders.end(),
		[&p_shader](const std::reference_wrapper<const GLShaderStage> shader) {
			return shader.get().GetID() == p_shader.GetID();
		}
	));
}

template<>
void OvRendering::HAL::GLShaderProgram::DetachAll()
{
	for (auto& shader : m_attachedShaders)
	{
		glDetachShader(id, shader.get().GetID());
	}

	m_attachedShaders.clear();
}

template<>
OvRendering::Settings::ShaderLinkingResult OvRendering::HAL::GLShaderProgram::Link()
{
	glLinkProgram(id);

	GLint linkStatus;
	glGetProgramiv(id, GL_LINK_STATUS, &linkStatus);

	if (linkStatus == GL_FALSE)
	{
		GLint maxLength;
		glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		std::string errorLog(maxLength, ' ');
		glGetProgramInfoLog(id, maxLength, &maxLength, errorLog.data());

		return {
			.success = false,
			.message = errorLog
		};
	}

	glValidateProgram(id); // TODO: Check if we can get data out of this

	QueryUniforms();

	return {
		.success = true
	};
}

template<>
void OvRendering::HAL::GLShaderProgram::SetUniformInt(const std::string& p_name, int p_value)
{
	glUniform1i(GetUniformLocation(p_name), p_value);
}

template<>
void OvRendering::HAL::GLShaderProgram::SetUniformFloat(const std::string& p_name, float p_value)
{
	glUniform1f(GetUniformLocation(p_name), p_value);
}

template<>
void OvRendering::HAL::GLShaderProgram::SetUniformVec2(const std::string& p_name, const OvMaths::FVector2& p_vec2)
{
	glUniform2f(GetUniformLocation(p_name), p_vec2.x, p_vec2.y);
}

template<>
void OvRendering::HAL::GLShaderProgram::SetUniformVec3(const std::string& p_name, const OvMaths::FVector3& p_vec3)
{
	glUniform3f(GetUniformLocation(p_name), p_vec3.x, p_vec3.y, p_vec3.z);
}

template<>
void OvRendering::HAL::GLShaderProgram::SetUniformVec4(const std::string& p_name, const OvMaths::FVector4& p_vec4)
{
	glUniform4f(GetUniformLocation(p_name), p_vec4.x, p_vec4.y, p_vec4.z, p_vec4.w);
}

template<>
void OvRendering::HAL::GLShaderProgram::SetUniformMat4(const std::string& p_name, const OvMaths::FMatrix4& p_mat4)
{
	glUniformMatrix4fv(GetUniformLocation(p_name), 1, GL_TRUE, &p_mat4.data[0]);
}

template<>
int OvRendering::HAL::GLShaderProgram::GetUniformInt(const std::string& p_name)
{
	int value;
	glGetUniformiv(id, GetUniformLocation(p_name), &value);
	return value;
}

template<>
float OvRendering::HAL::GLShaderProgram::GetUniformFloat(const std::string& p_name)
{
	float value;
	glGetUniformfv(id, GetUniformLocation(p_name), &value);
	return value;
}

template<>
OvMaths::FVector2 OvRendering::HAL::GLShaderProgram::GetUniformVec2(const std::string& p_name)
{
	GLfloat values[2];
	glGetUniformfv(id, GetUniformLocation(p_name), values);
	return reinterpret_cast<OvMaths::FVector2&>(values);
}

template<>
OvMaths::FVector3 OvRendering::HAL::GLShaderProgram::GetUniformVec3(const std::string& p_name)
{
	GLfloat values[3];
	glGetUniformfv(id, GetUniformLocation(p_name), values);
	return reinterpret_cast<OvMaths::FVector3&>(values);
}

template<>
OvMaths::FVector4 OvRendering::HAL::GLShaderProgram::GetUniformVec4(const std::string& p_name)
{
	GLfloat values[4];
	glGetUniformfv(id, GetUniformLocation(p_name), values);
	return reinterpret_cast<OvMaths::FVector4&>(values);
}

template<>
OvMaths::FMatrix4 OvRendering::HAL::GLShaderProgram::GetUniformMat4(const std::string& p_name)
{
	GLfloat values[16];
	glGetUniformfv(id, GetUniformLocation(p_name), values);
	return reinterpret_cast<OvMaths::FMatrix4&>(values);
}

bool IsEngineUBOMember(const std::string& p_uniformName)
{
	return p_uniformName.rfind("ubo_", 0) == 0;
}

template<>
uint32_t OvRendering::HAL::GLShaderProgram::GetUniformLocation(const std::string& name)
{
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
		return m_uniformLocationCache.at(name);

	const int location = glGetUniformLocation(id, name.c_str());

	if (location == -1)
		OVLOG_WARNING("Uniform: '" + name + "' doesn't exist");

	m_uniformLocationCache[name] = location;

	return location;
}

template<>
void OvRendering::HAL::GLShaderProgram::QueryUniforms()
{
	GLint numActiveUniforms = 0;
	uniforms.clear();
	glGetProgramiv(id, GL_ACTIVE_UNIFORMS, &numActiveUniforms);
	std::vector<GLchar> nameData(256);
	for (int unif = 0; unif < numActiveUniforms; ++unif)
	{
		GLint arraySize = 0;
		GLenum type = 0;
		GLsizei actualLength = 0;
		glGetActiveUniform(id, unif, static_cast<GLsizei>(nameData.size()), &actualLength, &arraySize, &type, &nameData[0]);
		std::string name(static_cast<char*>(nameData.data()), actualLength);

		if (!IsEngineUBOMember(name))
		{
			std::any defaultValue;

			switch (static_cast<Settings::UniformType>(type))
			{
			case Settings::UniformType::UNIFORM_BOOL: defaultValue = std::make_any<bool>(GetUniformInt(name));					break;
			case Settings::UniformType::UNIFORM_INT: defaultValue = std::make_any<int>(GetUniformInt(name));						break;
			case Settings::UniformType::UNIFORM_FLOAT: defaultValue = std::make_any<float>(GetUniformFloat(name));					break;
			case Settings::UniformType::UNIFORM_FLOAT_VEC2:	defaultValue = std::make_any<OvMaths::FVector2>(GetUniformVec2(name));		break;
			case Settings::UniformType::UNIFORM_FLOAT_VEC3:	defaultValue = std::make_any<OvMaths::FVector3>(GetUniformVec3(name));		break;
			case Settings::UniformType::UNIFORM_FLOAT_VEC4:	defaultValue = std::make_any<OvMaths::FVector4>(GetUniformVec4(name));		break;
			case Settings::UniformType::UNIFORM_FLOAT_MAT4:	defaultValue = std::make_any<OvMaths::FMatrix4>(GetUniformMat4(name));		break;
			case Settings::UniformType::UNIFORM_SAMPLER_2D:	defaultValue = std::make_any<GLTexture*>(nullptr);	break;
			}

			if (defaultValue.has_value())
			{
				uniforms.push_back({
					static_cast<Settings::UniformType>(type),
					name,
					GetUniformLocation(nameData.data()),
					defaultValue
				});
			}
		}
	}
}

template<>
const OvRendering::Settings::UniformInfo* OvRendering::HAL::GLShaderProgram::GetUniformInfo(const std::string& p_name) const
{
	auto found = std::find_if(uniforms.begin(), uniforms.end(), [&p_name](const Settings::UniformInfo& p_element)
		{
			return p_name == p_element.name;
		});

	if (found != uniforms.end())
		return &*found;
	else
		return nullptr;
}
