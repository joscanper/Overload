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
	* Represents an index buffer, used to store index data on the GPU
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TIndexBuffer final
	{
	public:
		/**
		* Create an index buffer
		*/
		TIndexBuffer();

		/**
		* Destructor
		*/
		~TIndexBuffer();

		/**
		* Bind the buffer
		*/
		void Bind() const;

		/**
		* Unbind the buffer
		*/
		void Unbind() const;

		/**
		* Upload data index data to the GPU
		* @param p_data
		* @param p_usage
		*/
		void Upload(std::span<const uint32_t> p_data, Settings::EAccessSpecifier p_usage = Settings::EAccessSpecifier::STATIC_DRAW) const;

		/**
		* Returns the ID of the IBO
		*/
		uint32_t GetID() const;

	private:
		Context m_context;
	};
}
