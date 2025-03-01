/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <OvRendering/HAL/Common/TBuffer.h>

namespace OvRendering::HAL
{
	/**
	* Represents an index buffer, used to store index data on the GPU
	*/
	template<Settings::EGraphicsBackend Backend, class IndexBufferContext, class BufferContext>
	class TIndexBuffer : public TBuffer<Backend, BufferContext>
	{
	public:
		/**
		* Create an index buffer
		*/
		TIndexBuffer();

	private:
		IndexBufferContext m_context;
	};
}
