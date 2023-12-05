/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include "OvRendering/Core/CompositeRenderer.h"

namespace OvRendering::Core
{
	template <typename T, typename... Args>
	T& CompositeRenderer::AddFeature(Args&&... args)
	{
		OVASSERT(!m_isDrawing, "You cannot add a render feature while drawing.");
		OVASSERT(!HasFeature<T>(), "Feature already added");
		static_assert(std::is_base_of<Features::ARenderFeature, T>::value, "T must inherit from ARenderFeature");
		T* feature = new T(*this, std::forward<Args>(args)...);
		m_features.emplace(typeid(T), feature);
		return dynamic_cast<T&>(*feature);
	}

	template<typename T>
	inline bool CompositeRenderer::RemoveFeature()
	{
		OVASSERT(!m_isDrawing, "You cannot add remove a render feature while drawing.");
		static_assert(std::is_base_of<Features::ARenderFeature, T>::value, "T should derive from ARenderFeature");

		if (auto it = m_features.find(typeid(T)); it != m_features.end())
		{
			m_features.erase(it);
			return true;
		}

		return false;
	}

	template<typename T>
	inline T& CompositeRenderer::GetFeature()
	{
		static_assert(std::is_base_of<Features::ARenderFeature, T>::value, "T should derive from ARenderFeature");
		auto it = m_features.find(typeid(T));
		OVASSERT(it != m_features.end(), "Couldn't find a render feature matching the given type T.");
		return *dynamic_cast<T*>(it->second.get());
	}

	template<typename T>
	inline bool CompositeRenderer::HasFeature() const
	{
		static_assert(std::is_base_of<Features::ARenderFeature, T>::value, "T should derive from ARenderFeature");
		auto it = m_features.find(typeid(T));
		return it != m_features.end();
	}

	template<typename T, typename ...Args>
	inline T& CompositeRenderer::AddPass(const std::string& p_name, uint32_t p_order, Args&& ...p_args)
	{
		OVASSERT(!m_isDrawing, "You cannot add a render pass while drawing.");
		static_assert(std::is_base_of<ARenderPass, T>::value, "T must inherit from ARenderPass");
		// TODO: Add validation, make sure every pass has a unique name
		T* pass = new T(*this, std::forward<Args>(args)...);
		m_passes.emplace(p_order, std::make_pair(p_name, std::unique_ptr<ARenderPass>(pass)));
		return dynamic_cast<T&>(*pass);
	}

	template<typename T>
	inline T& CompositeRenderer::GetPass(const std::string& p_name)
	{
		static_assert(std::is_base_of<ARenderPass, T>::value, "T should derive from ARenderPass");
		for (const auto& [_, pass] : m_passes)
		{
			if (pass.first == p_name)
			{
				return dynamic_cast<T&>(*pass.second.get());
			}
		}

		OVASSERT(true, "Couldn't find a render pass matching the given type T.");
	}
}
