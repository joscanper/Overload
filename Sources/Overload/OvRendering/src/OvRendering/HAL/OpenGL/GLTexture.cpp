/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <GL/glew.h>

#include <OvRendering/HAL/OpenGL/GLTexture.h>

template<>
OvRendering::HAL::GLTexture::TTexture()
{
	glGenTextures(1, &m_id);
}

template<>
OvRendering::HAL::GLTexture::~TTexture()
{
	glDeleteTextures(1, &m_id);
}

template<>
void OvRendering::HAL::GLTexture::Upload(const Settings::TextureDesc& p_desc, void* p_data)
{
	glBindTexture(GL_TEXTURE_2D, m_id);
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
