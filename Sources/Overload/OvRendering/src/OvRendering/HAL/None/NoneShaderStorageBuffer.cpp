/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneShaderStorageBuffer.h>

template<>
OvRendering::HAL::NoneShaderStorageBuffer::TShaderStorageBuffer()
{
}

template<>
OvRendering::HAL::NoneShaderStorageBuffer::~TShaderStorageBuffer()
{
}

template<>
void OvRendering::HAL::NoneShaderStorageBuffer::Bind(std::optional<uint32_t> p_bindingPoint)
{
}

template<>
void OvRendering::HAL::NoneShaderStorageBuffer::Unbind()
{
}
