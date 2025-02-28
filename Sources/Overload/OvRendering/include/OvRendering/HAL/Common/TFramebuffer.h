/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <variant>

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
#include <OvRendering/Settings/EFramebufferAttachment.h>
#include <OvRendering/Data/PipelineState.h>
#include <OvRendering/Resources/Texture.h>
#include <OvRendering/HAL/Common/TTexture.h>
#include <OvRendering/HAL/Common/TRenderbuffer.h>
#include <OvTools/Utils/OptRef.h>

namespace OvRendering::HAL
{
	template<Settings::EGraphicsBackend Backend, class TextureContext, class TextureHandleContext, class RenderBufferContext>
	using TFramebufferAttachment = std::variant<
		std::shared_ptr<TTexture<Backend, TextureContext, TextureHandleContext>>,
		std::shared_ptr<TRenderbuffer<Backend, RenderBufferContext>>
	>;

	/**
	* Represents a framebuffer, used to store render data
	*/
	template<Settings::EGraphicsBackend Backend, class FramebufferContext, class TextureContext, class TextureHandleContext, class RenderBufferContext>
	class TFramebuffer final
	{
	public:
		using Attachment = TFramebufferAttachment<Backend, TextureContext, TextureHandleContext, RenderBufferContext>;

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
		* Returns true if the framebuffer is valid
		*/
		bool IsValid() const;

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
		* Attach the given texture or render buffer to the framebuffer, at the given attachment point
		* @param p_toAttach
		* @param p_attachment
		* @param p_index optional, useful when specifying multiple color attachments
		*/
		template<class T>
		void Attach(std::shared_ptr<T> p_toAttach, Settings::EFramebufferAttachment p_attachment, uint32_t p_index = 0);

		/**
		* Return the texture or render buffer associated with the given attachment point
		* @param p_attachment
		* @param p_index optional, useful when specifying multiple color attachments
		*/
		template<class T>
		OvTools::Utils::OptRef<T> GetAttachment(OvRendering::Settings::EFramebufferAttachment p_attachment, uint32_t p_index = 0) const;

		/**
		* Returns the width of the framebuffer
		*/
		uint16_t GetWidth() const;

		/**
		* Returns the width of the framebuffer
		*/
		uint16_t GetHeight() const;

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
