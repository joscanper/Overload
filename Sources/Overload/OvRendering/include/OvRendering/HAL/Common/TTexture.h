/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/TextureDesc.h>
#include <OvRendering/HAL/Common/TTextureHandle.h>

namespace OvRendering::HAL
{
	/**
	* TODO
	*/
	template<Settings::EGraphicsBackend Backend, class TextureContext, class TextureHandleContext>
	class TTexture final : public TTextureHandle<Backend, TextureHandleContext>
	{
	public:
		/**
		* Create a texture
		*/
		TTexture();

		/**
		* Deletes the internal texture
		*/
		~TTexture();

		/**
		* Upload the given data to the texture
		* @param p_desc
		* @param p_data
		*/
		void Upload(const Settings::TextureDesc& p_desc, void* p_data);

		/**
		* Returns the texture description
		*/
		const Settings::TextureDesc& GetDesc() const;

	private:
		TextureContext m_textureContext;
	};
}
