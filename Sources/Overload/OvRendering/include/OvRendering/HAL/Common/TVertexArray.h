/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <span>

#include <OvRendering/HAL/VertexBuffer.h>
#include <OvRendering/HAL/IndexBuffer.h>
#include <OvRendering/Settings/EDataType.h>
#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/VertexAttribute.h>

namespace OvRendering::HAL
{
	/**
	* Represents a vertex array, used to layout vertex data on the GPU
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
		* Returns true if the vertex array is valid (non-empty layout)
		*/
		bool IsValid() const;

		/**
		* Sets the vertex attribute layout
		* @param p_attributes
		* @param p_vertexBuffer
		* @param p_indexBuffer
		*/
		void SetLayout(
			std::span<const Settings::VertexAttribute> p_attributes,
			VertexBuffer& p_vertexBuffer,
			IndexBuffer& p_indexBuffer
		);

		/**
		* Resets the vertex attribute layout
		*/
		void ResetLayout();

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
