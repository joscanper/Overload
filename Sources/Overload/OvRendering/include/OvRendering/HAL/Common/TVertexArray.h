/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/Settings/EDataType.h"
#include <OvRendering/Settings/EGraphicsBackend.h>

#include "OvRendering/HAL/VertexBuffer.h"

namespace OvRendering::HAL
{
	/**
	* Wraps OpenGL VAO
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TVertexArray final
	{
	public:
		/**
		* Create the vertex array
		*/
		TVertexArray();

		/**
		* Destroy the vertex array
		*/
		~TVertexArray();

		/**
		* Register a VBO into the VAO
		* @param p_attribute
		* @param p_vertexBuffer
		* @param p_type
		* @param p_count
		* @param p_stride
		* @param p_offset
		*/
		void BindAttribute(
			uint32_t p_attribute,
			HAL::VertexBuffer& p_vertexBuffer,
			Settings::EDataType p_type,
			uint64_t p_count,
			uint64_t p_stride,
			intptr_t p_offset
		) const;

		/**
		* Bind the buffer
		*/
		void Bind() const;

		/**
		* Unbind the buffer
		*/
		void Unbind() const;

		/**
		* Return the VAO OpenGL ID
		*/
		uint32_t GetID() const;

	private:
		Context m_context;
	};
}
