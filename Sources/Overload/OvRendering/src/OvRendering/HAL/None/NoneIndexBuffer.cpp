/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneIndexBuffer.h>

template<>
OvRendering::HAL::NoneIndexBuffer::TIndexBuffer()
{
}


template<>
OvRendering::HAL::NoneIndexBuffer::~TIndexBuffer()
{
}

template<>
void OvRendering::HAL::NoneIndexBuffer::Bind()
{
}

template<>
void OvRendering::HAL::NoneIndexBuffer::Unbind()
{
}

template<>
void OvRendering::HAL::NoneIndexBuffer::Upload(std::span<const uint32_t> p_data, Settings::EAccessSpecifier p_usage)
{
}

template<>
uint32_t OvRendering::HAL::NoneIndexBuffer::GetID()
{
	return 0;
}
