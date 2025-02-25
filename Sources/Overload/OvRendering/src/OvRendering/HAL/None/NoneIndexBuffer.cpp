/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneIndexBuffer.h>

template<>
OvRendering::HAL::NoneIndexBuffer::TIndexBuffer(unsigned int* p_data, size_t p_elements)
{
}

template<>
OvRendering::HAL::NoneIndexBuffer::TIndexBuffer(std::vector<uint32_t>& p_data) : TIndexBuffer(p_data.data(), p_data.size())
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
uint32_t OvRendering::HAL::NoneIndexBuffer::GetID()
{
	return 0;
}
