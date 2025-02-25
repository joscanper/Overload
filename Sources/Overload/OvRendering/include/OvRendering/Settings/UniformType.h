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
	* Enumeration of uniform types
	*/
	enum class UniformType : uint8_t
	{
		UNIFORM_BOOL,
		UNIFORM_INT,
		UNIFORM_FLOAT,
		UNIFORM_FLOAT_VEC2,
		UNIFORM_FLOAT_VEC3,
		UNIFORM_FLOAT_VEC4,
		UNIFORM_FLOAT_MAT4,
		UNIFORM_DOUBLE_MAT4,
		UNIFORM_SAMPLER_2D,
		UNIFORM_SAMPLER_CUBE
	};
}
