/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/Core/CompositeRenderer.h"
#include "OvRendering/Features/ARenderFeature.h"
#include "OvRendering/Data/FrameInfo.h"
#include "OvRendering/Entities/Light.h"
#include "OvRendering/Buffers/ShaderStorageBuffer.h"
#include "OvRendering/Data/Frustum.h"

namespace OvRendering::Features
{
	class LightingRenderFeature : public ARenderFeature
	{
	public:
		// TODO: Consider not using references here, but copying the light instead (should be fairly cheap and doesn't require to keep an instance outside of the scope)
		using LightSet = std::vector<std::reference_wrapper<const OvRendering::Entities::Light>>;

		struct LightingDescriptor
		{
			LightSet lights;
		};

		/**
		* Constructor
		* @param p_renderer
		* @param p_bufferBindingPoint
		*/
		LightingRenderFeature(OvRendering::Core::CompositeRenderer& p_renderer, uint32_t p_bufferBindingPoint = 0);

		/**
		* Invoked when the frame begins, bind the light buffer
		* @param p_frameDescriptor
		*/
		virtual void OnBeginFrame(const Data::FrameDescriptor& p_frameDescriptor) override;

		/**
		* Invoked when the frame ends, unbind the light buffer
		*/
		virtual void OnEndFrame() override;

	private:
		uint32_t m_bufferBindingPoint;
		std::unique_ptr<OvRendering::Buffers::ShaderStorageBuffer> m_lightBuffer;
	};
}
