/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLTexture.h>
#include <OvDebug/Assertion.h>

template<>
OvRendering::HAL::GLTexture::TTexture() :
	m_textureContext{
		.desc = {
			.width = 0,
			.height = 0,
			.firstFilter = OvRendering::Settings::ETextureFilteringMode::LINEAR,
			.secondFilter = OvRendering::Settings::ETextureFilteringMode::LINEAR,
			.generateMipmap = false
		}
	}
{
	glGenTextures(1, &m_context.id);
}

template<>
OvRendering::HAL::GLTexture::~TTexture()
{
	glDeleteTextures(1, &m_context.id);
}

template<>
void OvRendering::HAL::GLTexture::Upload(const Settings::TextureDesc& p_desc, void* p_data)
{
	OVASSERT(p_data, "Trying to upload a texture with invalid data");
	OVASSERT(p_desc.width > 0, "Texture width cannot be 0");
	OVASSERT(p_desc.height > 0, "Texture height cannot be 0");

	m_textureContext.desc = p_desc;

	glBindTexture(GL_TEXTURE_2D, m_context.id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, p_desc.width, p_desc.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, p_data);

	if (p_desc.generateMipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(p_desc.firstFilter));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(p_desc.secondFilter));
}

template<>
const OvRendering::Settings::TextureDesc& OvRendering::HAL::GLTexture::GetDesc() const
{
	return m_textureContext.desc;
}
