/// <summary>
///		Legal & Licensing Information
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
#include <functional>
#include <type_traits>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeFunction.h"
#include "SafeNamespace.h"
#include "SafeTrade.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{

#if (defined(CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_EXPORT) || defined(CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_IMPORT)) && defined(WINDOWS_VISUAL_CPP)

	template class CPP_SAFE_LIBRARY_TRADE SafeFunction<void(void)>;

#endif

	/// <summary>
	///		C++ class: `SafeEvent`.
	/// </summary>
	class SafeEvent : public SafeContextBase
	{
	public:
		typedef SafeFunction<void()> SafeEventOccurrence;

	private:
		bool cancellation;
		SafeEventOccurrence occurrence;

	public:
		/// <summary>
		///		Constructor of `SafeEvent`.
		/// </summary>
		explicit SafeEvent();

		/// <summary>
		///		Constructor of `SafeEvent`.
		/// </summary>
		/// <param name="occurrence"></param>
		explicit SafeEvent(const SafeEventOccurrence& occurrence);

		/// <summary>
		///		Copy constructor of `SafeEvent`.
		/// </summary>
		/// <param name="other"></param>
		SafeEvent(const SafeEvent& other);

		/// <summary>
		///		Move constructor of `SafeEvent`.
		/// </summary>
		/// <param name="occurrence"></param>
		explicit SafeEvent(SafeEventOccurrence&& occurrence) noexcept(false);

		/// <summary>
		///		Move constructor of `SafeEvent`.
		/// </summary>
		/// <param name="other"></param>
		SafeEvent(SafeEvent&& other) noexcept(false);

		/// <summary>
		///		Destructor of `SafeEvent`.
		/// </summary>
		virtual ~SafeEvent() noexcept(false) override;

		/// <summary>
		///		dynamic
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEvent&amp;</returns>
		SafeEvent& operator=(const SafeEvent& other);

		/// <summary>
		///		dynamic
		///		noexcept(false)
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEvent&amp;</returns>
		SafeEvent& operator=(SafeEvent&& other) noexcept(false);

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>bool</returns>
		bool getCancellation() const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>void</returns>
		void setCancellation(const bool& cancellation) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>void</returns>
		void setCancellation(bool&& cancellation) noexcept;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>SafeEventOccurrence</returns>
		SafeEventOccurrence getOccurrence() const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="occurrence"></param>
		/// <returns>void</returns>
		void setOccurrence(const SafeEventOccurrence& occurrence);

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="occurrence"></param>
		/// <returns>void</returns>
		void setOccurrence(SafeEventOccurrence&& occurrence) noexcept;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>void</returns>
		void broadcast();

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>void</returns>
		void cancel() noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>void</returns>
		void raise() noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>void</returns>
		void abrogate() noexcept;
	};

	/// <summary>
	///		C++ class template: `SafeEventHandler`.
	/// </summary>
	/// <typeparam name="GenericTypeOfSafeEvent"></typeparam>
	template<typename GenericTypeOfSafeEvent> class SafeEventHandler final : public SafeContextBase
	{
		static_assert((std::is_base_of<SafeEvent,GenericTypeOfSafeEvent>::value == true),"`GenericTypeOfSafeEvent` must be a type that inherits from `SafeEvent`!");

	private:
		SafeFunction<void(const GenericTypeOfSafeEvent&)> composedHandle;

	public:
		/// <summary>
		///		C++ functional type: `SafeEventHandle`.
		/// </summary>
		typedef SafeFunction<void(const SafeEvent&)> SafeEventHandle;


		/// <summary>
		///		Constructor of `SafeEventHandler`.
		/// </summary>
		inline explicit SafeEventHandler() : SafeContextBase()
		{
			this->composedHandle = [](const GenericTypeOfSafeEvent&) -> void
			{

			};
		};

		/// <summary>
		///		Constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="eventHandle"></param>
		inline explicit SafeEventHandler(const std::function<void(const GenericTypeOfSafeEvent&)>& eventHandle) : SafeContextBase()
		{
			this->composedHandle = eventHandle;
		};

		/// <summary>
		///		Copy constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeEventHandler(const SafeEventHandler<GenericTypeOfSafeEvent>& other) noexcept(false) : SafeContextBase(static_cast<const SafeContextBase&>(other))
		{
			this->composedHandle = other.composedHandle;
		};

		/// <summary>
		///		Move constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="eventHandle"></param>
		inline explicit SafeEventHandler(std::function<void(const GenericTypeOfSafeEvent&)>&& eventHandle) : SafeContextBase()
		{
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfSafeEvent&)>&&>(eventHandle);
		};

		/// <summary>
		///		Move constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeEventHandler(SafeEventHandler<GenericTypeOfSafeEvent>&& other) noexcept(false) : SafeContextBase(static_cast<SafeContextBase&&>(other))
		{
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfSafeEvent&)>&&>(other.composedHandle);
		};

		/// <summary>
		///		Destructor of `SafeEventHandler`.
		/// </summary>
		inline virtual ~SafeEventHandler() noexcept(false) override = default;

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="eventHandle"></param>
		/// <returns>SafeEventHandler&lt;GenericTypeOfSafeEvent&gt;&amp;</returns>
		inline SafeEventHandler<GenericTypeOfSafeEvent>& operator=(const std::function<void(const GenericTypeOfSafeEvent&)>& eventHandle)
		{
			this->composedHandle = eventHandle;

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="eventHandle"></param>
		/// <returns>SafeEventHandler&lt;GenericTypeOfSafeEvent&gt;&amp;</returns>
		inline SafeEventHandler<GenericTypeOfSafeEvent>& operator=(std::function<void(const GenericTypeOfSafeEvent&)>&& eventHandle)
		{
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfSafeEvent&)>&&>(eventHandle);

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEventHandler&lt;GenericTypeOfSafeEvent&gt;&amp;</returns>
		inline SafeEventHandler<GenericTypeOfSafeEvent>& operator=(const SafeEventHandler<GenericTypeOfSafeEvent>& other)
		{
			SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
			this->composedHandle = other.composedHandle;

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		noexcept(false)
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEventHandler&lt;GenericTypeOfSafeEvent&gt;&amp;</returns>
		inline SafeEventHandler<GenericTypeOfSafeEvent>& operator=(SafeEventHandler<GenericTypeOfSafeEvent>&& other) noexcept(false)
		{
			SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfSafeEvent&)>&&>(other.composedHandle);

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		/// </summary>
		/// <param name="event"></param>
		/// <returns>void</returns>
		inline void handle(const GenericTypeOfSafeEvent& event)
		{
			(this->composedHandle)(event);
		};

		/// <summary>
		///		dynamic
		///		inline
		/// </summary>
		/// <param name="eventPointer"></param>
		/// <returns>void</returns>
		inline void handle(const GenericTypeOfSafeEvent* const eventPointer)
		{
			(this->composedHandle)(*eventPointer);
		};
	};
};