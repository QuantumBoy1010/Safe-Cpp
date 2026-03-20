/// <summary>
///		Legal and Licensing Information
/// </summary>
/// <remarks>
///		Required Notice: Copyright@2026 Duc Nguyen (workofduc@gmail.com) [cite: 6, 7]
///		This software is licensed under the PolyForm Noncommercial License 1.0.0. [cite: 1]
/// 
///		PERMITTED USE:
///		Any noncommercial purpose is a permitted purpose. [cite: 9]
///		Personal use for research, hobby projects, or personal study is permitted. [cite: 9]
/// 
///		DISTRIBUTION:
///		Redistribution is permitted only under the terms of the PolyForm Noncommercial License. [cite: 3, 4, 5]
/// 
///		COMMERCIAL USE:
///		Commercial use is NOT permitted under these terms. 
///		To obtain a commercial license, please contact me via email: workofduc@gmail.com [cite: 23]
/// </remarks>

#pragma once

/** Inclusion(s) of C++ standard library header file(s).**/
#include <string>
#include <type_traits>
#include <typeinfo>
#include <vector>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeContextException.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class template: `SafeMemoryChunk`.
	/// </summary>
	/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
	template<typename GenericTypeOfSafeContextDerivative> class SafeContextBase::SafeMemoryChunk final : public SafeContextBase
	{
	private:
		GenericTypeOfSafeContextDerivative* composedBufferPointer;
		std::size_t cardinality;
		std::vector<const void*> constantPointerMasks;
		std::vector<void*> variablePointerMasks;

	public:
		static_assert((std::is_base_of<SafeContextBase,GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type inherited from `SafeContextBase`!");
		static_assert((std::is_default_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a default constructor!");
		static_assert((std::is_copy_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a copy constructor!");
		static_assert((std::is_move_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a move constructor!");
		static_assert((std::is_copy_assignable<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a copy assignment operator!");
		static_assert((std::is_move_assignable<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a move assignment operator!");
		static_assert((std::is_pointer<GenericTypeOfSafeContextDerivative>::value == false),"`GenericTypeOfSafeContextDerivative` can't be a pointer type!");


		/// <summary>
		///		Constructor of `SafeMemoryChunk`.
		/// </summary>
		inline constexpr explicit SafeMemoryChunk() : SafeContextBase()
		{
			this->cardinality = 10;
			this->constantPointerMasks = std::vector<const void*>();
			this->variablePointerMasks = std::vector<void*>();
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();
			GenericTypeOfSafeContextDerivative* chunkPointer = static_cast<GenericTypeOfSafeContextDerivative*>(::operator new(sizeof(GenericTypeOfSafeContextDerivative) * this->cardinality));
			std::size_t i = 0;

			for (i = 0;i < this->cardinality;i++)
			{
				(this->constantPointerMasks).push_back(static_cast<const void*>(chunkPointer + i));
				(this->variablePointerMasks).push_back(static_cast<void*>(chunkPointer + i));
				chunkBufferElementPointers.push_back(static_cast<SafeContextBase*>(chunkPointer + i));
			}

			this->composedBufferPointer = chunkPointer;
			SafeContextBase::helpInitializeChunk(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks,[](SafeContextBase* const instancePointer) -> void
			{
				::new(instancePointer) GenericTypeOfSafeContextDerivative();
			});
		};

		/// <summary>
		///		Constructor of `SafeMemoryChunk`.
		/// </summary>
		/// <param name="cardinality"></param>
		inline explicit SafeMemoryChunk(const std::size_t& cardinality) : SafeContextBase()
		{
			this->cardinality = cardinality;
			this->constantPointerMasks = std::vector<const void*>();
			this->variablePointerMasks = std::vector<void*>();
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();
			GenericTypeOfSafeContextDerivative* chunkPointer = static_cast<GenericTypeOfSafeContextDerivative*>(::operator new(sizeof(GenericTypeOfSafeContextDerivative) * this->cardinality));
			std::size_t i = 0;

			for (i = 0;i < cardinality;i++)
			{
				(this->constantPointerMasks).push_back(static_cast<const void*>(chunkPointer + i));
				(this->variablePointerMasks).push_back(static_cast<void*>(chunkPointer + i));
				chunkBufferElementPointers.push_back(static_cast<SafeContextBase*>(chunkPointer + i));
			}

			this->composedBufferPointer = chunkPointer;
			SafeContextBase::helpInitializeChunk(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks,[](SafeContextBase* const instancePointer) -> void
			{
				::new(instancePointer) GenericTypeOfSafeContextDerivative();
			});
		};

	private:
		/// <summary>
		///		Copy constructor of `SafeMemoryChunk`.
		/// </summary>
		inline SafeMemoryChunk(const SafeMemoryChunk&) = delete;

		/// <summary>
		///		Move constructor of `SafeMemoryChunk`.
		/// </summary>
		inline SafeMemoryChunk(SafeMemoryChunk&&) = delete;

	public:
		/// <summary>
		///		Destructor of `SafeMemoryChunk`.
		/// </summary>
		inline virtual ~SafeMemoryChunk() noexcept(true) override
		{
			if (this->composedBufferPointer != nullptr)
			{
				std::size_t i = 0;
				std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();

				for (i = 0;i < this->cardinality;i++)
				{
					chunkBufferElementPointers.push_back(&((this->composedBufferPointer)[i]));
				}

				SafeContextBase::destroyDerivedChunkOnMemoryHeap(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks);
				::delete(static_cast<void*>(this->composedBufferPointer));
				this->composedBufferPointer = nullptr;
			}
		};

	private:
		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <returns>GenericTypeOfSafeContextDerivative&amp;</returns>
		inline GenericTypeOfSafeContextDerivative& operator=(const GenericTypeOfSafeContextDerivative&) = delete;

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <returns>GenericTypeOfSafeContextDerivative&amp;</returns>
		inline GenericTypeOfSafeContextDerivative& operator=(GenericTypeOfSafeContextDerivative&&) = delete;

	public:
		/// <summary>
		///		dynamic
		///		inline
		///		operator[]
		/// </summary>
		/// <param name="index"></param>
		/// <returns>GenericTypeOfSafeContextDerivative&amp;</returns>
		/// <exception cref="SafeContextException"/>
		inline const GenericTypeOfSafeContextDerivative& operator[](const std::size_t& index) const
		{
			if (index >= this->cardinality)
			{
				throw SafeContextException("Argument `index` is out of bound: `" + std::to_string(index) + "` while the cardinality is `" + std::to_string(this->cardinality) + "`!");
			}
			else
			{
				return *(static_cast<const GenericTypeOfSafeContextDerivative*>((this->constantPointerMasks)[index]));
			}
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator[]
		/// </summary>
		/// <param name="index"></param>
		/// <returns>GenericTypeOfSafeContextDerivative&amp;</returns>
		/// <exception cref="SafeContextException"/>
		inline GenericTypeOfSafeContextDerivative& operator[](const std::size_t& index)
		{
			if (index >= this->cardinality)
			{
				throw SafeContextException("Argument `index` is out of bound: `" + std::to_string(index) + "` while the cardinality is `" + std::to_string(this->cardinality) + "`!");
			}
			else
			{
				return *(static_cast<GenericTypeOfSafeContextDerivative*>((this->variablePointerMasks)[index]));
			}
		};

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>size_t</returns>
		std::size_t getCardinality() const noexcept
		{
			return this->cardinality;
		};

		/// <summary>
		///		dynamic
		///		inline
		/// </summary>
		/// <returns>void</returns>
		inline void dispose()
		{
			const GenericTypeOfSafeContextDerivative* constantProxyInstancePointer = static_cast<const GenericTypeOfSafeContextDerivative*>(SafeContextBase::referToDefaultConstantInstance(typeid(GenericTypeOfSafeContextDerivative)));
			GenericTypeOfSafeContextDerivative* variableProxyInstancePointer = ::new GenericTypeOfSafeContextDerivative();

			if (constantProxyInstancePointer == nullptr)
			{
				constantProxyInstancePointer = SafeContextBase::supplementDefaultInstanceOfDerivedType<GenericTypeOfSafeContextDerivative>();
			}

			std::size_t i = 0;
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();

			for (i = 0;i < this->cardinality;i++)
			{
				chunkBufferElementPointers.push_back(&((this->composedBufferPointer)[i]));
			}

			SafeContextBase::helpDisposeChunk(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks,constantProxyInstancePointer,variableProxyInstancePointer);
			::delete static_cast<void*>(this->composedBufferPointer);
			this->composedBufferPointer = nullptr;
		};
	};

	/// <summary>
	///		C++ type name alias: `SafeMemoryChunk`.
	/// </summary>
	/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
	template<typename GenericTypeOfSafeContextDerivative> using SafeMemoryChunk = SafeContextBase::SafeMemoryChunk<GenericTypeOfSafeContextDerivative>;
};