/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#define GFX_USE_OPENGL

#if defined(GFX_USE_OPENGL)
#include <OvRendering/HAL/OpenGL/GLVertexArray.h>
#endif // defined(GFX_USE_OPENGL)

namespace OvRendering
{
	namespace HAL
	{
#if defined(GFX_USE_OPENGL)
		using VertexArray = HAL::GLVertexArray;
#endif // defined(GFX_USE_OPENGL)
	}
}
