/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#define GFX_USE_OPENGL

#if defined(GFX_USE_OPENGL)
#include <OvRendering/HAL/OpenGL/GLBackend.h>
#endif // defined(GFX_USE_OPENGL)

namespace OvRendering
{
	namespace HAL
	{
#if defined(GFX_USE_OPENGL)
		using Backend = HAL::GLBackend;
#endif // defined(GFX_USE_OPENGL)
	}
}
