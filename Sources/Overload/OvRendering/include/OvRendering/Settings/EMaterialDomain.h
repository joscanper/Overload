/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <cstdint>

namespace OvRendering::Settings
{
	/**
	* Material Domains
	*/
	enum class EMaterialDomain : uint8_t
	{
		SURFACE,
		USER_INTERFACE,
	};
}