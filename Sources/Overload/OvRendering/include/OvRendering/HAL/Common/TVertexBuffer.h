/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <span>

#include <OvRendering/Settings/EAccessSpecifier.h>
#include <OvRendering/Settings/EGraphicsBackend.h>

namespace OvRendering::HAL
{
	/**
	* Represents a vertex buffer, used to store vertex data on the GPU
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TVertexBuffer final
	{
	public:
		/**
		* Constructor
		*/
		TVertexBuffer();

		/**
		* Destructor
		*/
		~TVertexBuffer();

		/**
		* Upload vertex data to the GPU
		* @param p_data pointer to the first element of the data
		* @param p_size in bytes
		* @parma p_usage
		*/
		void Upload(const void* p_data, size_t p_size, Settings::EAccessSpecifier p_usage = Settings::EAccessSpecifier::STATIC_DRAW);

		/**
		* Bind the buffer
		*/
		void Bind() const;

		/**
		* Bind the buffer
		*/
		void Unbind() const;

		/**
		* Returns the ID of the VBO
		*/
		uint32_t GetID() const;

	private:
		Context m_context;
	};
}
