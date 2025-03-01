/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#pragma once

#include <optional>

#include <OvRendering/Settings/EGraphicsBackend.h>
#include <OvRendering/Settings/EAccessSpecifier.h>
#include <OvRendering/Settings/EBufferType.h>

namespace OvRendering::HAL
{
	/**
	* Represents a range of memory in a buffer
	*/
	struct BufferMemoryRange
	{
		uint64_t offset;
		uint64_t size;
	};

	/**
	* Represents a buffer, used to store data on the GPU
	*/
	template<Settings::EGraphicsBackend Backend, class BufferContext>
	class TBuffer
	{
	public:
		/**
		* Constructor
		* @param p_type
		*/
		TBuffer(Settings::EBufferType p_type);

		/**
		* Destructor
		*/
		~TBuffer();

		/**
		* Allocate memory for the buffer
		* @param p_size
		* @param p_usage
		*/
		void Allocate(uint64_t p_size, Settings::EAccessSpecifier p_usage = Settings::EAccessSpecifier::STATIC_DRAW);

		/**
		* Upload data to the buffer
		* @param p_data
		* @param p_range
		*/
		void Upload(const void* p_data, std::optional<BufferMemoryRange> p_range = std::nullopt);

		/**
		* Returns true if the buffer is valid (properly allocated)
		*/
		bool IsValid() const;

		/**
		* Returns true if the buffer is empty
		*/
		bool IsEmpty() const;

		/**
		* Returns the size of the allocated buffer in bytes
		*/
		uint64_t GetSize() const;

		/**
		* Bind the buffer
		* @param p_index (Optional) Index to bind the buffer to
		*/
		void Bind(std::optional<uint32_t> p_index = std::nullopt) const;

		/**
		* Unbind the buffer
		*/
		void Unbind() const;

		/**
		* Returns the ID of the buffer
		*/
		uint32_t GetID() const;

	protected:
		BufferContext m_buffer;
	};
}
