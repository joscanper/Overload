/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneVertexBuffer.h>

template<>
OvRendering::HAL::NoneVertexBuffer::TVertexBuffer()
{
}

template<>
OvRendering::HAL::NoneVertexBuffer::~TVertexBuffer()
{
}


template<>
void OvRendering::HAL::NoneVertexBuffer::Upload(const void* p_data, size_t p_size, Settings::EAccessSpecifier p_usage)
{
}

template<>
void OvRendering::HAL::NoneVertexBuffer::Bind() const
{
}

template<>
void OvRendering::HAL::NoneVertexBuffer::Unbind() const
{
}

template<>
uint32_t OvRendering::HAL::NoneVertexBuffer::GetID() const
{
	return 0;
}
