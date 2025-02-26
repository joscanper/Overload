/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TVertexBuffer.h>

namespace OvRendering::HAL
{
	struct NoneVertexBufferContext {};
	using NoneVertexBuffer = TVertexBuffer<Settings::EGraphicsBackend::NONE, NoneVertexBufferContext>;

	template<>
	template<class T>
	void NoneVertexBuffer::Upload(std::span<const T> p_data, Settings::EAccessSpecifier p_usage)
	{
	}
}
