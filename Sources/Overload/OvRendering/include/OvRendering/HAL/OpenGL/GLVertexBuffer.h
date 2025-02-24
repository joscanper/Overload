/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <GL/glew.h>

#include "OvRendering/HAL/Common/TVertexBuffer.h"

namespace OvRendering::HAL
{
	struct GLVertexBufferContext
	{
		uint32_t bufferID = 0;
	};

	using GLVertexBuffer = TVertexBuffer<Settings::EGraphicsBackend::OPENGL, GLVertexBufferContext>;

	template<>
	template<class T>
	void GLVertexBuffer::UploadData(T* p_data, size_t p_elements)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_context.bufferID);
		glBufferData(GL_ARRAY_BUFFER, p_elements * sizeof(T), p_data, GL_STATIC_DRAW);
	}

	template<>
	template<class T>
	void GLVertexBuffer::UploadData(std::vector<T>& p_data)
	{
		UploadData(p_data.data(), p_data.size());
	}
}
