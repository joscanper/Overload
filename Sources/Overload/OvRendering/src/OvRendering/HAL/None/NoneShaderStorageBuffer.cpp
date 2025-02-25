/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneShaderStorageBuffer.h>

template<>
OvRendering::HAL::NoneShaderStorageBuffer::TShaderStorageBuffer(Settings::EAccessSpecifier p_accessSpecifier)
{
}

template<>
OvRendering::HAL::NoneShaderStorageBuffer::~TShaderStorageBuffer()
{
}

template<>
void OvRendering::HAL::NoneShaderStorageBuffer::SendBlocks(void* p_data, size_t p_size)
{
}

template<>
void OvRendering::HAL::NoneShaderStorageBuffer::Bind(uint32_t p_bindingPoint)
{
}

template<>
void OvRendering::HAL::NoneShaderStorageBuffer::Unbind()
{
}
