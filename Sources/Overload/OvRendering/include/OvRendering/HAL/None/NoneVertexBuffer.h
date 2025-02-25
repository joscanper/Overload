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
	void NoneVertexBuffer::UploadData(T* p_data, size_t p_elements)
	{
	}

	template<>
	template<class T>
	void NoneVertexBuffer::UploadData(std::vector<T>& p_data)
	{
	}
}
