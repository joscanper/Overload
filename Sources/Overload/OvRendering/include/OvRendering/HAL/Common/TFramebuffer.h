/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/Settings/DriverSettings.h>
#include <OvRendering/Settings/ERenderingCapability.h>
#include <OvRendering/Settings/EPrimitiveMode.h>
#include <OvRendering/Settings/ERasterizationMode.h>
#include <OvRendering/Settings/EComparaisonAlgorithm.h>
#include <OvRendering/Settings/EOperation.h>
#include <OvRendering/Settings/ECullFace.h>
#include <OvRendering/Settings/ECullingOptions.h>
#include <OvRendering/Settings/EPixelDataFormat.h>
#include <OvRendering/Settings/EPixelDataType.h>
#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Data/PipelineState.h>
#include <OvRendering/Resources/Texture.h>
#include <OvRendering/HAL/Common/TTextureHandle.h>

namespace OvRendering::HAL
{
	template<Settings::EGraphicsBackend Backend, class FramebufferContext, class TextureHandleContext>
	class TFramebuffer final
	{
	public:
		/**
		* Create the framebuffer
		* @param p_width
		* @param p_height
		* @param p_depthOnly
		*/
		TFramebuffer(uint16_t p_width = 0, uint16_t p_height = 0, bool p_depthOnly = false);

		/**
		* Destructor
		*/
		~TFramebuffer();

		/**
		* Bind the framebuffer
		*/
		void Bind() const;

		/**
		* Unbind the framebuffer
		*/
		void Unbind() const;

		/**
		* Defines a new size for the framebuffer
		* @param p_width
		* @param p_height
		* @param p_forceUpdate Force the resizing operation even if the width and height didn't change
		*/
		void Resize(uint16_t p_width, uint16_t p_height, bool p_forceUpdate = false);

		/**
		* Returns the ID of the OpenGL framebuffer
		*/
		uint32_t GetID() const;

		/**
		* Returns the ID of the OpenGL render texture
		*/
		uint32_t GetTextureID() const;

		/**
		* Returns the ID of the OpenGL render texture
		*/
		TTextureHandle<Backend, TextureHandleContext> GetTexture() const;

		/**
		* Returns the ID of the OpenGL render buffer
		*/
		uint32_t GetRenderBufferID() const;

		/**
		* Returns the width of the framebuffer
		*/
		uint16_t GetWidth() const;

		/**
		* Returns the width of the framebuffer
		*/
		uint16_t GetHeight() const;

		/**
		* Generate mip maps for the framebuffer's associated render texture
		*/
		void GenerateMipMaps() const;

		/**
		* Blit the framebuffer to the back buffer
		* @param p_backBufferWidth
		* @param p_backBufferHeight
		*/
		void BlitToBackBuffer(uint16_t p_backBufferWidth, uint16_t p_backBufferHeight) const;

	private:
		FramebufferContext m_context;
	};
}
