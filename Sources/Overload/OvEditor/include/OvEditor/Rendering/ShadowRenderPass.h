/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/Entities/Camera.h>
#include <OvRendering/Features/DebugShapeRenderFeature.h>

#include <OvCore/ECS/Actor.h>
#include <OvCore/SceneSystem/SceneManager.h>
#include <OvCore/ECS/Components/CModelRenderer.h>
#include <OvCore/Resources/Material.h>
#include <OvCore/ECS/Components/CAmbientBoxLight.h>
#include <OvCore/ECS/Components/CAmbientSphereLight.h>
#include <OvCore/Rendering/SceneRenderer.h>

#include "OvEditor/Core/Context.h"
#include "OvEditor/Core/GizmoBehaviour.h"

namespace OvEditor::Rendering
{
	/**
	* Draw the scene for actor picking
	*/
	class ShadowRenderPass : public OvRendering::Core::ARenderPass
	{
	public:
		/**
		* Constructor
		* @param p_renderer
		*/
		ShadowRenderPass(OvRendering::Core::CompositeRenderer& p_renderer);

	private:
		virtual void Draw(OvRendering::Data::PipelineState p_pso) override;
		void DrawOpaques(OvRendering::Data::PipelineState p_pso, OvCore::SceneSystem::Scene& p_scene);

	private:
		OvCore::Resources::Material m_opaqueMaterial;
	};
}