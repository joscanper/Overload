/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>

#include <OvRendering/HAL/ShaderProgram.h>

namespace OvRendering::Resources
{
	namespace Loaders { class ShaderLoader; }

	/**
	* TODO
	*/
	class Shader : public HAL::ShaderProgram
	{
		friend class Loaders::ShaderLoader;

	private:
		/**
		* TODO
		*/
		Shader(const std::string p_path);

		// TODO: virtual base class destructor?
		~Shader() = default;

	public:
		const std::string path;
	};
}