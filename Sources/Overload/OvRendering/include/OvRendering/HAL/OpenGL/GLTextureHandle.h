/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/HAL/Common/TTextureHandle.h"

namespace OvRendering::HAL
{
	using GLTextureHandle = TTextureHandle<Settings::EGraphicsBackend::OPENGL>;
}
