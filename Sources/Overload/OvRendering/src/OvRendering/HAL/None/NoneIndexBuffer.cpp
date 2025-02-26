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
void OvRendering::HAL::NoneIndexBuffer::Bind() const
{
}

template<>
void OvRendering::HAL::NoneIndexBuffer::Unbind() const
{
}

template<>
void OvRendering::HAL::NoneIndexBuffer::Upload(std::span<const uint32_t> p_data, Settings::EAccessSpecifier p_usage) const
{
}

template<>
uint32_t OvRendering::HAL::NoneIndexBuffer::GetID() const
{
	return 0;
}
