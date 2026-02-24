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

/** Inclusion(s) of C++ & Microsoft Windows standard library header file(s).**/
#include <string>
#include <type_traits>
#include <typeinfo>
#include <vector>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextException.h"
#include "SafeNamespace.h"
#include "SafeTrade.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class: `SafeContextBase`.
	/// </summary>
	class SafeContextBase
	{
	private:
		/// <summary>
		///		C++ class: `SafeMemoryManager`.
		/// </summary>
		class SafeMemoryManager;

		/// <summary>
		///		C++ functional pointer type: `SafeConstructionInvoker`.
		/// </summary>
		typedef void (*SafeConstructionInvoker)(SafeContextBase* const);

	public:
		/// <summary>
		///		C++ class: `SafeMemoryChunk`.
		/// </summary>
		/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
		template<typename GenericTypeOfSafeContextDerivative> class SafeMemoryChunk;

	protected:
		/// <summary>
		///		Constructor of `SafeContextBase`.
		/// </summary>
		explicit SafeContextBase();

	private:
		/// <summary>
		///		Constructor of `SafeContextBase`.
		/// </summary>
		/// <param name="classifcation"></param>
		explicit SafeContextBase(const bool& classifcation);

	protected:
		/// <summary>
		///		Copy constructor of `SafeContextBase`.
		/// </summary>
		/// <param name="other"></param>
		explicit SafeContextBase(const SafeContextBase& other) noexcept(true);

		/// <summary>
		///		Move constructor of `SafeContextBase`.
		/// </summary>
		/// <param name="classifcation"></param>
		explicit SafeContextBase(SafeContextBase&& other) noexcept(true);

		/// <summary>
		///		Destructor of `SafeContextBase`.
		/// </summary>
		/// <exception cref="SafeContextException"/>
		virtual ~SafeContextBase() noexcept(false);

		/// <summary>
		///		static
		///		operator new()
		/// </summary>
		/// <param name="memorySize"></param>
		/// <returns>void*</returns>
		static void* operator new(std::size_t memorySize);

		/// <summary>
		///		static
		///		noexcept
		///		operator delete()
		/// </summary>
		/// <param name="memoryPointer"></param>
		/// <returns>void</returns>
		static void operator delete(void* const memoryPointer) noexcept;

	private:
		/// <summary>
		///		static
		///		operator new[]()
		/// </summary>
		/// <param name="memoryArraySize"></param>
		/// <returns>void*</returns>
		static void* operator new[](std::size_t memoryArraySize);

		/// <summary>
		///		static
		///		noexcept
		///		operator delete[]()
		/// </summary>
		/// <param name="memoryArrayPointer"></param>
		/// <returns>void</returns>
		static void operator delete[](void* const memoryArrayPointer) noexcept;

		/// <summary>
		///		dynamic
		///		virtual
		///		noexcept
		///		final
		///		operator&amp;
		/// </summary>
		/// <returns>SafeContextBase*</returns>
		virtual SafeContextBase* operator&() noexcept final;

	protected:
		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeContextBase&amp;</returns>
		SafeContextBase& operator=(const SafeContextBase& other) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeContextBase&amp;</returns>
		SafeContextBase& operator=(SafeContextBase&& other) noexcept;

	public:
		/// <summary>
		///		dynamic
		///		noexcept
		///		operator==
		/// </summary>
		/// <param name="other"></param>
		/// <returns>bool</returns>
		bool operator==(const SafeContextBase& other) const noexcept;

		/// <summary>
		///		static
		/// </summary>
		/// <returns>SafeContextBase&amp;</returns>
		static SafeContextBase& constructInstanceOnMemoryHeap();

		/// <summary>
		///		static
		/// </summary>
		/// <param name="arraySize"></param>
		/// <returns>SafeContextBase*</returns>
		static SafeContextBase* allocateArrayOnMemoryHeap(const std::size_t& arraySize);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkCardinality"></param>
		/// <returns>SafeContextBase*</returns>
		static SafeContextBase* allocateChunkOnMemoryHeap(const std::size_t& chunkCardinality);

	private:
		/// <summary>
		///		static
		///		noexcept
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <returns>void</returns>
		static void destructInstanceOnMemoryHeap(SafeContextBase* const instancePointer) noexcept;

		/// <summary>
		///		static
		///		noexcept
		/// </summary>
		/// <param name="arrayPointer"></param>
		/// <returns>void</returns>
		static void deallocateArrayOnMemoryHeap(SafeContextBase* const arrayPointer) noexcept;

		/// <summary>
		///		static
		///		noexcept
		/// </summary>
		/// <param name="chunkPointer"></param>
		/// <returns>void</returns>
		static void deallocateChunkOnMemoryHeap(SafeContextBase* const chunkPointer) noexcept;

		/// <summary>
		///		static
		/// </summary>
		/// <param name="typeInformation"></param>
		/// <returns>SafeContextBase*</returns>
		static const SafeContextBase* referToDefaultConstantInstance(const std::type_info& typeInformation);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="defaultedInstancePointer"></param>
		/// <returns>void</returns>
		static void supplementDefaultPolymorphicInstance(const SafeContextBase* defaultedInstancePointer);

		/// <summary>
		///		static
		///		inline
		/// </summary>
		/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
		/// <returns>GenericTypeOfSafeContextDerivative*</returns>
		template<typename GenericTypeOfSafeContextDerivative> static inline GenericTypeOfSafeContextDerivative* supplementDefaultInstanceOfDerivedType()
		{
			GenericTypeOfSafeContextDerivative* defaultInstancePointer = ::new GenericTypeOfSafeContextDerivative();
			SafeContextBase::supplementDefaultPolymorphicInstance(defaultInstancePointer);

			return defaultInstancePointer;
		};

		/// <summary>
		///		static
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <param name="constructionInvoker"></param>
		/// <returns>void</returns>
		static void reconstructSafely(SafeContextBase* const instancePointer,const SafeConstructionInvoker& constructionInvoker);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkBufferElementPointers"></param>
		/// <param name="cardinality"></param>
		/// <param name="constantMasks"></param>
		/// <param name="variableMasks"></param>
		/// <param name="constructionInvoker"></param>
		/// <returns>void</returns>
		static void helpInitializeChunk(std::vector<SafeContextBase*>& chunkBufferElementPointers,const std::size_t& cardinality,const std::vector<const void*>& constantMasks,const std::vector<void*>& variableMasks,const SafeConstructionInvoker& constructionInvoker);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkBufferElementPointers"></param>
		/// <param name="cardinality"></param>
		/// <param name="constantMasks"></param>
		/// <param name="variableMasks"></param>
		/// <param name="constantProxyInstancePointer"></param>
		/// <param name="variableProxyInstancePointer"></param>
		/// <returns>void</returns>
		static void helpDisposeChunk(const std::vector<SafeContextBase*>& chunkBufferElementPointers,const std::size_t& cardinality,std::vector<const void*>& constantMasks,std::vector<void*>& variableMasks,const void* const constantProxyInstancePointer,void* const variableProxyInstancePointer);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkBufferElementPointers"></param>
		/// <param name="cardinality"></param>
		/// <param name="constantMasks"></param>
		/// <param name="variableMasks"></param>
		/// <returns>void</returns>
		static void destroyDerivedChunkOnMemoryHeap(const std::vector<SafeContextBase*>& chunkBufferElementPointers,const std::size_t& cardinality,std::vector<const void*>& constantMasks,std::vector<void*>& variableMasks);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="typeInformation"></param>
		/// <returns>SafeContextBase*</returns>
		static SafeContextBase* upcycle(const std::type_info& typeInformation);

		/// <summary>
		///		static
		///		noexcept
		/// </summary>
		/// <param name="pointer"></param>
		/// <returns>void</returns>
		static void finalize(SafeContextBase*& pointer) noexcept;

	public:
		/// <summary>
		///		static
		/// </summary>
		/// <param name="instanceReference"></param>
		/// <returns>void</returns>
		static void recycle(SafeContextBase& instanceReference);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <returns>void</returns>
		static void recycle(SafeContextBase* const instancePointer);

		/// <summary>
		///		static
		///		inline
		/// </summary>
		/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
		/// <returns>GenericTypeOfSafeContext&amp;</returns>
		template<typename GenericTypeOfSafeContextDerivative> static inline GenericTypeOfSafeContextDerivative& repurpose()
		{
			static_assert((std::is_base_of<SafeContextBase,GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type inherited from `SafeContextBase`!");
			static_assert((std::is_default_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a default constructor!");
			static_assert((std::is_pointer<GenericTypeOfSafeContextDerivative>::value == false),"`GenericTypeOfSafeContextDerivative` can't be a pointer type!");

			GenericTypeOfSafeContextDerivative* recycledPointer = static_cast<GenericTypeOfSafeContextDerivative*>(SafeContextBase::upcycle(typeid(GenericTypeOfSafeContextDerivative)));

			if (recycledPointer != nullptr)
			{
				SafeContextBase::reconstructSafely(recycledPointer,[](SafeContextBase* const instancePointer) -> void
				{
					::new(instancePointer) GenericTypeOfSafeContextDerivative();
				});

				return *recycledPointer;
			}
			else
			{
				return *(new GenericTypeOfSafeContextDerivative());
			}
		};

		/// <summary>
		///		static
		///		inline
		/// </summary>
		/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
		/// <param name="chunkCardinality"></param>
		/// <returns>SafeMemoryChunk&lt;GenericTypeOfSafeContextDerivative&gt;&amp;</returns>
		template<typename GenericTypeOfSafeContextDerivative> static inline SafeMemoryChunk<GenericTypeOfSafeContextDerivative>& createDerivedChunkOnMemoryHeap(const std::size_t& chunkCardinality)
		{
			static_assert((std::is_base_of<SafeContextBase,GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type inherited from `SafeContextBase`!");
			static_assert((std::is_default_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a default constructor!");
			static_assert((std::is_copy_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a copy constructor!");
			static_assert((std::is_move_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a move constructor!");
			static_assert((std::is_copy_assignable<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a copy assignment operator!");
			static_assert((std::is_move_assignable<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a move assignment operator!");
			static_assert((std::is_pointer<GenericTypeOfSafeContextDerivative>::value == false),"`GenericTypeOfSafeContextDerivative` can't be a pointer type!");

			return *(new SafeMemoryChunk<GenericTypeOfSafeContextDerivative>(chunkCardinality));
		};

		/// <summary>
		///		dynamic
		///		virtual
		///		noexcept
		///		final
		/// </summary>
		/// <returns>std::size_t</returns>
		virtual std::size_t getMemorySize() const noexcept final;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>type_info&amp;</returns>
		const std::type_info& getTypeInfo() const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>size_t</returns>
		std::size_t getHashCode() const noexcept;
	};

	/// <summary>
	///		C++ class: `SafeMemoryChunk`.
	/// </summary>
	/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
	template<typename GenericTypeOfSafeContextDerivative> class SafeContextBase::SafeMemoryChunk final : public SafeContextBase
	{
	private:
		GenericTypeOfSafeContextDerivative* composedBufferPointer;
		std::size_t cardinality;
		std::vector<const void*> constantMasks;
		std::vector<void*> variableMasks;

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
			this->constantMasks = std::vector<const void*>();
			this->variableMasks = std::vector<void*>();
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();
			GenericTypeOfSafeContextDerivative* chunkPointer = static_cast<GenericTypeOfSafeContextDerivative*>(::operator new(sizeof(GenericTypeOfSafeContextDerivative) * this->cardinality));
			std::size_t i = 0;

			for (i = 0;i < this->cardinality;i++)
			{
				(this->constantMasks).push_back(static_cast<const void*>(chunkPointer + i));
				(this->variableMasks).push_back(static_cast<void*>(chunkPointer + i));
				chunkBufferElementPointers.push_back(static_cast<SafeContextBase*>(chunkPointer + i));
			}

			this->composedBufferPointer = chunkPointer;
			SafeContextBase::helpInitializeChunk(chunkBufferElementPointers,this->cardinality,this->constantMasks,this->variableMasks,[](SafeContextBase* const instancePointer) -> void
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
			this->constantMasks = std::vector<const void*>();
			this->variableMasks = std::vector<void*>();
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();
			GenericTypeOfSafeContextDerivative* chunkPointer = static_cast<GenericTypeOfSafeContextDerivative*>(::operator new(sizeof(GenericTypeOfSafeContextDerivative) * this->cardinality));
			std::size_t i = 0;

			for (i = 0;i < cardinality;i++)
			{
				(this->constantMasks).push_back(static_cast<const void*>(chunkPointer + i));
				(this->variableMasks).push_back(static_cast<void*>(chunkPointer + i));
				chunkBufferElementPointers.push_back(static_cast<SafeContextBase*>(chunkPointer + i));
			}

			this->composedBufferPointer = chunkPointer;
			SafeContextBase::helpInitializeChunk(chunkBufferElementPointers,this->cardinality,this->constantMasks,this->variableMasks,[](SafeContextBase* const instancePointer) -> void
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
		inline ~SafeMemoryChunk() noexcept(true) override
		{
			if (this->composedBufferPointer != nullptr)
			{
				std::size_t i = 0;
				std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();

				for (i = 0;i < this->cardinality;i++)
				{
					chunkBufferElementPointers.push_back(&((this->composedBufferPointer)[i]));
				}

				SafeContextBase::destroyDerivedChunkOnMemoryHeap(chunkBufferElementPointers,this->cardinality,this->constantMasks,this->variableMasks);
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
				return *(static_cast<const GenericTypeOfSafeContextDerivative*>((this->constantMasks)[index]));
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
				return *(static_cast<GenericTypeOfSafeContextDerivative*>((this->variableMasks)[index]));
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

			SafeContextBase::helpDisposeChunk(chunkBufferElementPointers,this->cardinality,this->constantMasks,this->variableMasks,constantProxyInstancePointer,variableProxyInstancePointer);
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