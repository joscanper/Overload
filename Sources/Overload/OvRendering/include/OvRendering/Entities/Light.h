/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvMaths/FVector3.h>
#include <OvMaths/FMatrix4.h>
#include <OvMaths/FTransform.h>

#include "OvRendering/Entities/Entity.h"
#include "OvRendering/Settings/ELightType.h"
#include "OvRendering/Resources/Texture.h"
#include "OvRendering/Buffers/Framebuffer.h"

namespace OvRendering::Entities
{
	/**
	* Data structure that can represent any type of light
	*/
	struct Light : public Entity
	{
		OvMaths::FVector3 color{ 1.f, 1.f, 1.f };
		float intensity = 1.f;
		float constant = 0.0f;
		float linear = 0.0f;
		float quadratic = 1.0f;
		float cutoff = 12.f;
		float outerCutoff = 15.f;
		Settings::ELightType type = Settings::ELightType::POINT;
		// TODO: Add bool to toggle shadow feature

		/**
		* Update the content of the shadow cache
		*/
		void UpdateShadowData(uint16_t p_shadowMapResolution);

		/**
		* Returns the light space matrix
		*/
		const OvMaths::FMatrix4& GetLightSpaceMatrix() const;

		/**
		* Returns the framebuffer used to render the shadow map
		*/
		const OvRendering::Buffers::Framebuffer& GetShadowBuffer() const;

		/**
		* Generate the light matrix, ready to send to the GPU
		*/
		OvMaths::FMatrix4 GenerateMatrix() const;

		/**
		* Calculate the light effect range from the quadratic falloff equation
		*/
		float GetEffectRange() const;

		OvMaths::FMatrix4 lightSpaceMatrix;
		std::unique_ptr<OvRendering::Buffers::Framebuffer> shadowBuffer;
	};
}