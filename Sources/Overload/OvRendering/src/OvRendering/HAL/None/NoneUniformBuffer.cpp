/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneUniformBuffer.h>

template<>
OvRendering::HAL::NoneUniformBuffer::TUniformBuffer(
	size_t p_size,
	uint32_t p_bindingPoint,
	uint32_t p_offset,
	OvRendering::Settings::EAccessSpecifier p_accessSpecifier
)
{
}

template<>
OvRendering::HAL::NoneUniformBuffer::~TUniformBuffer()
{
}

template<>
void OvRendering::HAL::NoneUniformBuffer::Bind(uint32_t p_bindingPoint)
{
}

template<>
void OvRendering::HAL::NoneUniformBuffer::Unbind()
{
}

template<>
uint32_t OvRendering::HAL::NoneUniformBuffer::GetID() const
{
	return 0;
}

template<>
void OvRendering::HAL::NoneUniformBuffer::BindBlockToShader(OvRendering::Resources::Shader& p_shader, uint32_t p_uniformBlockLocation, uint32_t p_bindingPoint)
{
}

template<>
void OvRendering::HAL::NoneUniformBuffer::BindBlockToShader(OvRendering::Resources::Shader& p_shader, const std::string& p_name, uint32_t p_bindingPoint)
{
}

template<>
uint32_t OvRendering::HAL::NoneUniformBuffer::GetBlockLocation(OvRendering::Resources::Shader& p_shader, const std::string& p_name)
{
	return 0;
}
