/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include <OvRendering/HAL/None//NoneTexture.h>

template<>
OvRendering::HAL::NoneTexture::TTexture()
{
}

template<>
OvRendering::HAL::NoneTexture::~TTexture()
{
}

template<>
void OvRendering::HAL::NoneTexture::Upload(const Settings::TextureDesc& p_desc, void* p_data)
{
}



template<>
const OvRendering::Settings::TextureDesc& OvRendering::HAL::NoneTexture::GetDesc() const
{
	static Settings::TextureDesc _defaultTextureDesc;
	return _defaultTextureDesc;
}
