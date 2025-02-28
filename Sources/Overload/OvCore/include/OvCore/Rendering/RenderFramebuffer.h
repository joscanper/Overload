/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Framebuffer.h>

namespace OvCore::Rendering
{
	/**
	* A standard "ready-to-use" framebuffer, with color, depth and stencil attachments
	*/
	class RenderFramebuffer : public OvRendering::HAL::Framebuffer
	{
	public:
		/**
		* Constructor of the render framebuffer
		* @param p_width
		* @param p_height
		* @param p_useMipMaps
		*/
		RenderFramebuffer(uint32_t p_width = 0, uint32_t p_height = 0, bool p_useMipMaps = false);
	};
}
