/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>

#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/EShaderType.h>
#include <OvRendering/Settings/ShaderCompilationResult.h>

namespace OvRendering::HAL
{
	/**
	* Part of a shader program that is responsible of a specific stage (Vertex, Fragment, Geometry, etc.)
	*/
	template<Settings::EGraphicsBackend Backend, class Context>
	class TShaderStage final
	{
	public:
		/**
		* Create a shader stage of the given type
		* @param p_type
		*/
		TShaderStage(Settings::EShaderType p_type);

		/**
		* Destructor of the shader stage
		*/
		~TShaderStage();

		/**
		* Upload shader source from the CPU to the GPU
		* @param p_source
		*/
		void Upload(const std::string& p_source) const;

		/**
		* Compile the uploaded shader source
		* @return The compilation result
		*/
		Settings::ShaderCompilationResult Compile() const;

		/**
		* @return The ID of the shader stage
		*/
		uint32_t GetID() const;

	private:
		Context m_context;
	};
}
