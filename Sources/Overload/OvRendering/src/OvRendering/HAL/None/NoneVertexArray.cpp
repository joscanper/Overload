/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None/NoneVertexArray.h>

template<>
OvRendering::HAL::NoneVertexArray::TVertexArray()
{
}

template<>
OvRendering::HAL::NoneVertexArray::~TVertexArray()
{
}

template<>
void OvRendering::HAL::NoneVertexArray::BindAttribute(
	uint32_t p_attribute,
	VertexBuffer& p_vertexBuffer,
	Settings::EDataType p_type,
	uint64_t p_count,
	uint64_t p_stride,
	intptr_t p_offset
) const
{
}

template<>
void OvRendering::HAL::NoneVertexArray::Bind() const
{
}

template<>
void OvRendering::HAL::NoneVertexArray::Unbind() const
{
}

template<>
uint32_t OvRendering::HAL::NoneVertexArray::GetID() const
{
	return 0;
}
