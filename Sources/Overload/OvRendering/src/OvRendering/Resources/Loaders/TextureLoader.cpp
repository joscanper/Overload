/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image/stb_image.h>
#include <array>
#include <memory>

#include "OvRendering/Resources/Loaders/TextureLoader.h"

struct Image
{
	uint8_t* data;
	int width;
	int height;
	int bpp;

	Image(const std::string& p_filepath)
	{
		stbi_set_flip_vertically_on_load(true);
		data = stbi_load(p_filepath.c_str(), &width, &height, &bpp, 4);
	}

	~Image()
	{
		stbi_image_free(data);
	}

	bool IsValid() const
	{
		return data;
	}

	operator bool() const
	{
		return IsValid();
	}
};

void FreeImage(uint8_t* p_data)
{
	stbi_image_free(p_data);
}

OvRendering::Resources::Texture* OvRendering::Resources::Loaders::TextureLoader::Create(const std::string& p_filepath, OvRendering::Settings::ETextureFilteringMode p_firstFilter, OvRendering::Settings::ETextureFilteringMode p_secondFilter, bool p_generateMipmap)
{
	if (Image image{ p_filepath })
	{
		auto texture = std::make_unique<HAL::Texture>();
		texture->Upload({
			.width = static_cast<uint32_t>(image.width),
			.height = static_cast<uint32_t>(image.height),
			.firstFilter = p_firstFilter,
			.secondFilter = p_secondFilter,
			.generateMipmap = p_generateMipmap
		}, image.data);
		return new Texture{ p_filepath, std::move(texture) };
	}

	return nullptr;
}

OvRendering::Resources::Texture* OvRendering::Resources::Loaders::TextureLoader::CreatePixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	std::array<uint8_t, 4> colorData = { r, g, b, a };

	return OvRendering::Resources::Loaders::TextureLoader::CreateFromMemory(
		colorData.data(), 1, 1,
		OvRendering::Settings::ETextureFilteringMode::NEAREST,
		OvRendering::Settings::ETextureFilteringMode::NEAREST,
		false
	);
}

OvRendering::Resources::Texture* OvRendering::Resources::Loaders::TextureLoader::CreateFromMemory(uint8_t* p_data, uint32_t p_width, uint32_t p_height, OvRendering::Settings::ETextureFilteringMode p_firstFilter, OvRendering::Settings::ETextureFilteringMode p_secondFilter, bool p_generateMipmap)
{
	auto texture = std::make_unique<HAL::Texture>();

	texture->Upload({
		.width = p_width,
		.height = p_height,
		.firstFilter = p_firstFilter,
		.secondFilter = p_secondFilter,
		.generateMipmap = p_generateMipmap
	}, p_data);

	return new Texture("", std::move(texture));
}

void OvRendering::Resources::Loaders::TextureLoader::Reload(Texture& p_texture, const std::string& p_filePath, OvRendering::Settings::ETextureFilteringMode p_firstFilter, OvRendering::Settings::ETextureFilteringMode p_secondFilter, bool p_generateMipmap)
{
	if (Image image{p_texture.path})
	{
		auto texture = std::make_unique<HAL::Texture>();
		texture->Upload({
			.width = static_cast<uint32_t>(image.width),
			.height = static_cast<uint32_t>(image.height),
			.firstFilter = p_firstFilter,
			.secondFilter = p_secondFilter,
			.generateMipmap = p_generateMipmap
			}, image.data);
		p_texture.SetTexture(std::move(texture));
	}
}

bool OvRendering::Resources::Loaders::TextureLoader::Destroy(Texture*& p_textureInstance)
{
	if (p_textureInstance)
	{
		delete p_textureInstance;
		p_textureInstance = nullptr;
		return true;
	}

	return false;
}
