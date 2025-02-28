/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvCore/Rendering/RenderFramebuffer.h>

OvCore::Rendering::RenderFramebuffer::RenderFramebuffer(uint32_t p_width, uint32_t p_height, bool p_useMipMaps)
{
	using namespace OvRendering::HAL;
	using namespace OvRendering::Settings;

	m_context.width = static_cast<uint16_t>(std::max(1u, p_width));
	m_context.height = static_cast<uint16_t>(std::max(1u, p_height));

	std::shared_ptr<GLRenderbuffer> renderbuffer = std::make_shared<GLRenderbuffer>();
	std::shared_ptr<GLTexture> renderTexture = std::make_shared<GLTexture>();

	TextureDesc renderTextureDesc{
		.width = m_context.width,
		.height = m_context.height,
		.minFilter = ETextureFilteringMode::LINEAR,
		.magFilter = ETextureFilteringMode::LINEAR,
		.horizontalWrap = ETextureWrapMode::CLAMP_TO_BORDER,
		.verticalWrap = ETextureWrapMode::CLAMP_TO_BORDER,
		.internalFormat = EInternalFormat::RGBA32F,
		.useMipMaps = p_useMipMaps,
		.mutableDesc = MutableTextureDesc{
			.format = EFormat::RGBA,
			.type = EPixelDataType::FLOAT
		}
	};

	renderTexture->Allocate(renderTextureDesc);
	Attach<GLTexture>(renderTexture, EFramebufferAttachment::COLOR);

	renderbuffer->Allocate(m_context.width, m_context.height, EInternalFormat::DEPTH_STENCIL);
	Attach<GLRenderbuffer>(renderbuffer, EFramebufferAttachment::DEPTH);
	Attach<GLRenderbuffer>(renderbuffer, EFramebufferAttachment::STENCIL);

	Validate();
}
