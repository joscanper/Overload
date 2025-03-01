/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvDebug/Assertion.h>
#include <OvRendering/HAL/None/NoneBuffer.h>

template<>
OvRendering::HAL::NoneBuffer::TBuffer(Settings::EBufferType p_type)
{
}

template<>
OvRendering::HAL::NoneBuffer::~TBuffer()
{
}

template<>
void OvRendering::HAL::NoneBuffer::Allocate(size_t p_size, Settings::EAccessSpecifier p_usage)
{
	m_buffer.allocatedBytes = p_size;
}

template<>
void OvRendering::HAL::NoneBuffer::Upload(const void* p_data, std::optional<BufferMemoryRange> p_range)
{
	OVASSERT(IsValid(), "Trying to upload data to an invalid buffer");
}

template<>
void OvRendering::HAL::NoneBuffer::Bind(std::optional<uint32_t> p_index) const
{
	OVASSERT(IsValid(), "Cannot bind an invalid buffer");
}

template<>
void OvRendering::HAL::NoneBuffer::Unbind() const
{
	OVASSERT(IsValid(), "Cannot unbind an invalid buffer");
}

template<>
bool OvRendering::HAL::NoneBuffer::IsValid() const
{
	return
		m_buffer.type != Settings::EBufferType::UNKNOWN &&
		m_buffer.allocatedBytes > 0;
}

template<>
uint32_t OvRendering::HAL::NoneBuffer::GetID() const
{
	return 0;
}
