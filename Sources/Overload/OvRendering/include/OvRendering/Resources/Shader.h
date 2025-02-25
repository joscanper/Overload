/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>
#include <memory>

#include <OvRendering/HAL/ShaderProgram.h>

namespace OvRendering::Resources
{
	namespace Loaders { class ShaderLoader; }

	/**
	* TODO
	*/
	class Shader
	{
		friend class Loaders::ShaderLoader;

	public:
		HAL::ShaderProgram& GetProgram();

	private:
		/**
		* TODO
		*/
		Shader(const std::string p_path, std::unique_ptr<HAL::ShaderProgram>&& p_program);

		/**
		* TODO
		*/
		~Shader() = default;

		/**
		* TODO
		*/
		void SetProgram(std::unique_ptr<HAL::ShaderProgram>&& p_program);

	public:
		const std::string path;

	private:
		std::unique_ptr<HAL::ShaderProgram> m_program;
	};
}