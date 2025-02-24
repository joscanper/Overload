/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>

#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/ShaderCompilationResult.h>
#include <OvRendering/Settings/EShaderType.h>

namespace OvRendering::HAL
{
	/**
	* TODO
	*/
	template<Settings::EGraphicsBackend Backend>
	class TShaderStage
	{
	public:
		/**
		* TODO
		*/
		TShaderStage(Settings::EShaderType p_type);

		/**
		* TODO
		*/
		~TShaderStage();

		/**
		* TODO
		*/
		void Upload(const std::string& p_source) const;

		/**
		* TODO
		*/
		Settings::ShaderCompilationResult Compile() const;

		/**
		* TODO
		*/
		uint32_t GetID() const;

	protected:
		uint32_t m_id;
		Settings::EShaderType m_type;
	};
}