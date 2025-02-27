/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <string>
#include <any>

#include <OvRendering/Settings/EUniformType.h>

namespace OvRendering::Settings
{
	/**
	* Structure that holds information about a uniform
	*/
	struct UniformInfo
	{
		EUniformType type;
		std::string name;
		uint32_t location;
		std::any defaultValue;
	};
}