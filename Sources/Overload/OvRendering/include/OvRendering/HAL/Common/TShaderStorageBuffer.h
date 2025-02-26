/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <span>
#include <optional>

#include <OvRendering/Settings/EAccessSpecifier.h>
#include <OvRendering/Settings/EGraphicsBackend.h>

namespace OvRendering::Resources { class Shader; }

namespace OvRendering::HAL
{
	/**
	* Shader storage buffer object, used to store data of variable size that can be accessed by shaders
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TShaderStorageBuffer final
	{
	public:
		/**
		* Create a SSBO with the given access specifier hint
		*/
		TShaderStorageBuffer();

		/**
		* Destroy the SSBO
		*/
		~TShaderStorageBuffer();

		/**
		* Bind the SSBO to the optional given binding point
		* @param p_bindingPoint
		*/
		void Bind(std::optional<uint32_t> p_bindingPoint = std::nullopt);

		/**
		* Unbind the SSBO
		*/
		void Unbind();

		/**
		* Sends the given shader storage buffer data to the GPU
		* @param p_data
		* @param p_usage
		*/
		template<class T>
		void Upload(std::span<const T> p_data, Settings::EAccessSpecifier p_usage = Settings::EAccessSpecifier::STATIC_DRAW);

	private:
		Context m_context;
	};
}
