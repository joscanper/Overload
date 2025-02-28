/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/Core/ARenderPass.h>
#include <OvCore/Rendering/PostProcess/AEffect.h>
#include <OvCore/Rendering/RenderFramebuffer.h>

namespace OvCore::Rendering
{
	/**
	* Draw post-processing effects
	*/
	class PostProcessRenderPass : public OvRendering::Core::ARenderPass
	{
	public:
		/**
		* Constructor of the post-process render pass
		* @param p_renderer
		*/
		PostProcessRenderPass(OvRendering::Core::CompositeRenderer& p_renderer);

	protected:
		virtual void Draw(OvRendering::Data::PipelineState p_pso) override;

	private:
		OvRendering::Data::Material m_blitMaterial;
		std::vector<std::unique_ptr<PostProcess::AEffect>> m_effects;
		std::array<RenderFramebuffer, 2> m_pingPongBuffers;
	};
}