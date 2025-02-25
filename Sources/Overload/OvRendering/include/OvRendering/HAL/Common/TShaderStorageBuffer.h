/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <vector>

#include <OvRendering/Settings/EAccessSpecifier.h>
#include <OvRendering/Settings/EGraphicsBackend.h>

namespace OvRendering::Resources { class Shader; }

namespace OvRendering::HAL
{
	/**
	* TODO
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TShaderStorageBuffer final
	{
	public:
		/**
		* Create a SSBO with the given access specifier hint
		*/
		TShaderStorageBuffer(Settings::EAccessSpecifier p_accessSpecifier);

		/**
		* Destroy the SSBO
		*/
		~TShaderStorageBuffer();

		/**
		* Bind the SSBO to the given binding point
		* @param p_bindingPoint
		*/
		void Bind(uint32_t p_bindingPoint);

		/**
		* Unbind the SSBO from the currently binding point
		*/
		void Unbind();

		/**
		* Send the block data
		*/
		void SendBlocks(void* p_data, size_t p_size);

	private:
		Context m_context;
	};
}
