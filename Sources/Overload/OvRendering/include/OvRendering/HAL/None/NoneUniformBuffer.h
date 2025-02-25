/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TUniformBuffer.h>

namespace OvRendering::HAL
{
	struct NoneUniformBufferContext {};
	using NoneUniformBuffer = TUniformBuffer<Settings::EGraphicsBackend::NONE, NoneUniformBufferContext>;

	template<>
	template<typename T>
	void NoneUniformBuffer::SetSubData(const T& p_data, size_t p_offsetInOut)
	{
	}

	template<>
	template<typename T>
	void NoneUniformBuffer::SetSubData(const T& p_data, std::reference_wrapper<size_t> p_offsetInOut)
	{
	}
}
