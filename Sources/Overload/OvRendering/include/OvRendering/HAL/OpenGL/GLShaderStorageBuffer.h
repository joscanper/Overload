/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TShaderStorageBuffer.h>
#include <OvRendering/HAL/OpenGL/GLTypes.h>

namespace OvRendering::HAL
{
	struct GLShaderStorageBufferContext
	{
		uint32_t id = 0;
	};

	using GLShaderStorageBuffer = TShaderStorageBuffer<Settings::EGraphicsBackend::OPENGL, GLShaderStorageBufferContext>;

	template<>
	template<class T>
	void GLShaderStorageBuffer::Upload(std::span<const T> p_data, Settings::EAccessSpecifier p_usage) const
	{
		Bind();
		glBufferData(GL_SHADER_STORAGE_BUFFER, p_data.size_bytes(), p_data.data(), EnumToValue<GLenum>(p_usage));
		Unbind();
	}
}
