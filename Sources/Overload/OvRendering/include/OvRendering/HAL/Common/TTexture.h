/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TTextureHandle.h>
#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/TextureDesc.h>

namespace OvRendering::HAL
{
	/**
	* Represents a texture, used to store image data on the GPU
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
		* Allocates memory for the texture
		* @param p_desc
		*/
		void Allocate(const Settings::TextureDesc& p_desc);

		/**
		* Returns true if the texture has been properly allocated
		*/
		bool IsValid() const;

		/**
		* Returns true if the texture is mutable
		*/
		bool IsMutable() const;

		/**
		* Uploads data to the GPU
		* @param p_data
		* @param p_format
		* @param p_type
		*/
		void Upload(void* p_data, Settings::EFormat p_format, Settings::EPixelDataType p_type);

		/**
		* Resizes the texture
		* @param p_width
		* @param p_height
		*/
		void Resize(uint32_t p_width, uint32_t p_height);

		/**
		* Returns the texture description
		*/
		const Settings::TextureDesc& GetDesc() const;

		/**
		* Generate mip maps for the texture
		*/
		void GenerateMipMaps() const;

	private:
		TextureContext m_textureContext;
	};
}
