/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>

namespace OvRendering::Settings
{
	/**
	* TODO
	*/
	struct ShaderCompilationResult
	{
		const bool success;
        const std::string message;
	};
}