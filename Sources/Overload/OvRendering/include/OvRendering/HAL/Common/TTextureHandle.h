/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/Settings/EGraphicsBackend.h>

namespace OvRendering::HAL
{
	template<Settings::EGraphicsBackend Backend>
	class TTextureHandle
	{
	public:
		/**
		* Default constructor of the texture handle
		*/
		TTextureHandle() = default;

		/**
		* Constructor of the texture handle
		* @param p_id
		*/
		TTextureHandle(const uint32_t p_id);

		/**
		* Bind the texture to the given slot
		* @param p_slot
		*/
		void Bind(uint32_t p_slot = 0) const;

		/**
		* Unbind the texture
		*/
		void Unbind() const;

		/**
		* Returns the ID associated with the texture
		*/
		uint32_t GetID() const;

	protected:
		uint32_t m_id = 0;
	};
}
