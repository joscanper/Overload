/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <span>

#include <OvRendering/HAL/Common/TBuffer.h>

namespace OvRendering::HAL
{
	/**
	* Represents a vertex buffer, used to store vertex data on the GPU
	*/
	template<Settings::EGraphicsBackend Backend, class VertexBufferContext, class BufferContext>
	class TVertexBuffer final : public TBuffer<Backend, BufferContext>
	{
	public:
		/**
		* Constructor
		*/
		TVertexBuffer();

	private:
		VertexBufferContext m_context;
	};
}
