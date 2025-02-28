/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>

#include "OvRendering/Settings/EAccessSpecifier.h"
#include <OvRendering/Settings/EGraphicsBackend.h>

namespace OvRendering::Resources { class Shader; }

namespace OvRendering::HAL
{
	/**
	* Represents a uniform buffer object, used to store uniform data that can be accessed by shaders
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TUniformBuffer final
	{
	public:
		/**
		* Create a UniformBuffer
		* @param p_size Specify the size in bytes of the UBO data
		* @param p_bindingPoint Specify the binding point on which the uniform buffer should be binded
		* @param p_offset The offset of the UBO, sizeof previouses UBO if the binding point is != 0
		* @param p_accessSpecifier
		*/
		TUniformBuffer(
			size_t p_size,
			uint32_t p_bindingPoint = 0,
			uint32_t p_offset = 0,
			Settings::EAccessSpecifier p_accessSpecifier = Settings::EAccessSpecifier::DYNAMIC_DRAW);

		/**
		* Destructor of the UniformBuffer
		*/
		~TUniformBuffer();

		/**
		* Bind the UBO
		* @param p_bindingPoint
		*/
		void Bind(uint32_t p_bindingPoint);

		/**
		* Unbind the UBO
		*/
		void Unbind();

		/**
		* Set the data in the UBO located at p_offset to p_data
		* @param p_data
		* @param p_size
		* @param p_offset
		* @return The new offset
		*/
		size_t Upload(const void* p_data, size_t p_size, size_t p_offset);

		/**
		* Return the ID of the UBO
		*/
		uint32_t GetID() const;

		/**
		* Bind a block identified by the given ID to given shader
		* @param p_shader
		* @param p_uniformBlockLocation
		* @param p_bindingPoint
		*/
		static void BindBlockToShader(OvRendering::Resources::Shader& p_shader, uint32_t p_uniformBlockLocation, uint32_t p_bindingPoint = 0);

		/**
		* Bind a block identified by the given name to the given shader
		* @param p_shader
		* @param p_name
		* @param p_bindingPoint
		*/
		static void BindBlockToShader(OvRendering::Resources::Shader& p_shader, const std::string& p_name, uint32_t p_bindingPoint = 0);

		/**
		* Return the location of the block (ID)
		* @param p_shader
		* @param p_name
		*/
		static uint32_t GetBlockLocation(OvRendering::Resources::Shader& p_shader, const std::string& p_name);

	private:
		Context m_context;
	};
}
