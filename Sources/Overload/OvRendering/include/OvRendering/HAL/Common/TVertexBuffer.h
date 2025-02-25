/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <vector>

#include <OvRendering/Settings/EGraphicsBackend.h>

namespace OvRendering::HAL
{
	/**
	* Wraps OpenGL VBO
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
		* Create the VBO using a pointer to the first element and a size (number of elements)
		* @param p_data
		* @parma p_elements
		*/
		template <class T>
		void UploadData(T* p_data, size_t p_elements);

		/**
		* Create the EBO using a vector
		* @param p_data
		*/
		template <class T>
		void UploadData(std::vector<T>& p_data);

		/**
		* Bind the buffer
		*/
		void Bind();

		/**
		* Bind the buffer
		*/
		void Unbind();

		/**
		* Returnd the ID of the VBO
		*/
		uint32_t GetID();

	private:
		Context m_context;
	};
}
