/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <span>

#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/EAccessSpecifier.h>

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
		* Upload vertex data from to the GPU
		* @param p_data
		* @parma p_usage
		*/
		template <class T>
		void Upload(std::span<const T> p_data, Settings::EAccessSpecifier p_usage = Settings::EAccessSpecifier::STATIC_DRAW) const;

		/**
		* Bind the buffer
		*/
		void Bind() const;

		/**
		* Bind the buffer
		*/
		void Unbind() const;

		/**
		* Returnd the ID of the VBO
		*/
		uint32_t GetID() const;

	private:
		Context m_context;
	};
}
