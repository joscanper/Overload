/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TShaderStorageBuffer.h>

namespace OvRendering::HAL
{
	struct NoneShaderStorageBufferContext {};
	using NoneShaderStorageBuffer = TShaderStorageBuffer<Settings::EGraphicsBackend::NONE, NoneShaderStorageBufferContext>;

	template<>
	template<class T>
	void NoneShaderStorageBuffer::Upload(std::span<const T> p_data, Settings::EAccessSpecifier p_usage)
	{
	}
}
