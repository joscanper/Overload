/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneShaderProgram.h>
#include <OvRendering/HAL/None/NoneTexture.h>

template<>
OvRendering::HAL::NoneShaderProgram::TShaderProgram() 
{
}

template<>
OvRendering::HAL::NoneShaderProgram::~TShaderProgram()
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::Bind() const
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::Unbind() const
{
}

template<>
uint32_t OvRendering::HAL::NoneShaderProgram::GetID() const
{
	return 0;
}

template<>
void OvRendering::HAL::NoneShaderProgram::Attach(const NoneShaderStage& p_shader)
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::Detach(const NoneShaderStage& p_shader)
{
	
}

template<>
void OvRendering::HAL::NoneShaderProgram::DetachAll()
{
}

template<>
OvRendering::Settings::ShaderLinkingResult OvRendering::HAL::NoneShaderProgram::Link()
{
	return {
		.success = true
	};
}

template<>
void OvRendering::HAL::NoneShaderProgram::SetUniformInt(const std::string& p_name, int p_value)
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::SetUniformFloat(const std::string& p_name, float p_value)
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::SetUniformVec2(const std::string& p_name, const OvMaths::FVector2& p_vec2)
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::SetUniformVec3(const std::string& p_name, const OvMaths::FVector3& p_vec3)
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::SetUniformVec4(const std::string& p_name, const OvMaths::FVector4& p_vec4)
{
}

template<>
void OvRendering::HAL::NoneShaderProgram::SetUniformMat4(const std::string& p_name, const OvMaths::FMatrix4& p_mat4)
{
}

template<>
int OvRendering::HAL::NoneShaderProgram::GetUniformInt(const std::string& p_name)
{
	return {};
}

template<>
float OvRendering::HAL::NoneShaderProgram::GetUniformFloat(const std::string& p_name)
{
	return {};
}

template<>
OvMaths::FVector2 OvRendering::HAL::NoneShaderProgram::GetUniformVec2(const std::string& p_name)
{
	return {};
}

template<>
OvMaths::FVector3 OvRendering::HAL::NoneShaderProgram::GetUniformVec3(const std::string& p_name)
{
	return {};
}

template<>
OvMaths::FVector4 OvRendering::HAL::NoneShaderProgram::GetUniformVec4(const std::string& p_name)
{
	return {};
}

template<>
OvMaths::FMatrix4 OvRendering::HAL::NoneShaderProgram::GetUniformMat4(const std::string& p_name)
{
	return {};
}

template<>
void OvRendering::HAL::NoneShaderProgram::QueryUniforms()
{
}

template<>
const OvRendering::Settings::UniformInfo* OvRendering::HAL::NoneShaderProgram::GetUniformInfo(const std::string& p_name) const
{
	return nullptr;
}

template<>
std::span<const OvRendering::Settings::UniformInfo> OvRendering::HAL::NoneShaderProgram::GetUniforms() const
{
	return {};
}