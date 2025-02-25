/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <vector>

#include "OvRendering/Settings/EGraphicsBackend.h"

namespace OvRendering::HAL
{
	/**
	* TODO
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TIndexBuffer final
	{
	public:
		/**
		* Create the Index Buffer using a pointer to the first element and a size (number of elements)
		* @param p_data
		* @parma p_elements
		*/
		TIndexBuffer(unsigned int* p_data, size_t p_elements);

		/**
		* Create the IBO using a vector
		* @param p_data
		*/
		TIndexBuffer(std::vector<uint32_t>& p_data);

		/**
		* Destructor
		*/
		~TIndexBuffer();

		/**
		* Bind the buffer
		*/
		void Bind();

		/**
		* Unbind the buffer
		*/
		void Unbind();

		/**
		* Returns the ID of the IBO
		*/
		uint32_t GetID();

	private:
		Context m_context;
	};
}