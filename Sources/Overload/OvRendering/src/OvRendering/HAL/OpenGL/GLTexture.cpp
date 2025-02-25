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

	glBindTexture(GL_TEXTURE_2D, m_context.id);
	glTexImage2D(GL_TEXTURE_2D, 0, ToGLenum(p_desc.internalFormat), p_desc.width, p_desc.height, 0, ToGLenum(p_desc.format), ToGLenum(p_desc.type), p_data);

	if (p_desc.generateMipmap)
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, ToGLenum(p_desc.horizontalWrapMode));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, ToGLenum(p_desc.verticalWrapMode));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, ToGLenum(p_desc.firstFilter));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, ToGLenum(p_desc.secondFilter));
}

template<>
const OvRendering::Settings::TextureDesc& OvRendering::HAL::GLTexture::GetDesc() const
{
	return m_textureContext.desc;
}
