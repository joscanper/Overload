/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLTexture.h>
#include <OvRendering/HAL/OpenGL/GLTypes.h>
#include <OvDebug/Assertion.h>

template<>
OvRendering::HAL::GLTexture::TTexture()
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
	m_textureContext.desc = p_desc;

	Bind();
	glTexImage2D(GL_TEXTURE_2D, 0, EnumToValue<GLenum>(p_desc.internalFormat), p_desc.width, p_desc.height, 0, EnumToValue<GLenum>(p_desc.format), EnumToValue<GLenum>(p_desc.type), p_data);

	if (p_desc.generateMipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, EnumToValue<GLenum>(p_desc.horizontalWrapMode));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, EnumToValue<GLenum>(p_desc.verticalWrapMode));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, EnumToValue<GLenum>(p_desc.firstFilter));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, EnumToValue<GLenum>(p_desc.secondFilter));
	Unbind();
}

template<>
const OvRendering::Settings::TextureDesc& OvRendering::HAL::GLTexture::GetDesc() const
{
	return m_textureContext.desc;
}
