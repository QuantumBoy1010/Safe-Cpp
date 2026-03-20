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
#include <functional>
#include <type_traits>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class: `SafeEvent`.
	/// </summary>
	class SafeEvent : public SafeContextBase
	{
	public:
		typedef std::function<void()> SafeEventOccurrence;

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
		SafeEvent(const SafeEvent& other) noexcept;

		/// <summary>
		///		Move constructor of `SafeEvent`.
		/// </summary>
		/// <param name="occurrence"></param>
		explicit SafeEvent(SafeEventOccurrence&& occurrence) noexcept;

		/// <summary>
		///		Move constructor of `SafeEvent`.
		/// </summary>
		/// <param name="other"></param>
		SafeEvent(SafeEvent&& other) noexcept;

		/// <summary>
		///		Destructor of `SafeEvent`.
		/// </summary>
		virtual ~SafeEvent() override;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEvent&amp;</returns>
		SafeEvent& operator=(const SafeEvent& other) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEvent&amp;</returns>
		SafeEvent& operator=(SafeEvent&& other) noexcept;

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
	template<typename GenericTypeOfEvent> class SafeEventHandler final : public SafeContextBase
	{
		static_assert((std::is_base_of<SafeEvent,GenericTypeOfEvent>::value == true),"`GenericTypeOfEvent` must be a type that inherits from `SafeEvent`!");

	private:
		std::function<void(const GenericTypeOfEvent&)> composedHandle;

	public:
		/// <summary>
		///		C++ functional type: `SafeEventHandle`.
		/// </summary>
		typedef std::function<void(const SafeEvent&)> SafeEventHandle;


		/// <summary>
		///		Constructor of `SafeEventHandler`.
		/// </summary>
		inline explicit SafeEventHandler() noexcept : SafeContextBase()
		{
			this->composedHandle = [](const GenericTypeOfEvent&) -> void
			{

			};
		};

		/// <summary>
		///		Constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="eventHandle"></param>
		inline explicit SafeEventHandler(const std::function<void(const GenericTypeOfEvent&)>& eventHandle) : SafeContextBase()
		{
			this->composedHandle = eventHandle;
		};

		/// <summary>
		///		Copy constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeEventHandler(const SafeEventHandler<GenericTypeOfEvent>& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
		{
			this->composedHandle = other.composedHandle;
		};

		/// <summary>
		///		Move constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="eventHandle"></param>
		inline explicit SafeEventHandler(std::function<void(const GenericTypeOfEvent&)>&& eventHandle) : SafeContextBase()
		{
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfEvent&)>&&>(eventHandle);
		};

		/// <summary>
		///		Move constructor of `SafeEventHandler`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeEventHandler(SafeEventHandler<GenericTypeOfEvent>&& other) noexcept : SafeContextBase(static_cast<SafeContextBase&&>(other))
		{
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfEvent&)>&&>(other.composedHandle);
		};

		/// <summary>
		///		Destructor of `SafeEventHandler`.
		/// </summary>
		inline virtual ~SafeEventHandler() noexcept override = default;

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="eventHandle"></param>
		/// <returns>SafeEventHandler&amp;</returns>
		inline SafeEventHandler& operator=(const std::function<void(const GenericTypeOfEvent&)>& eventHandle)
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
		/// <returns>SafeEventHandler&amp;</returns>
		inline SafeEventHandler& operator=(std::function<void(const GenericTypeOfEvent&)>&& eventHandle)
		{
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfEvent&)>&&>(eventHandle);

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEventHandler&amp;</returns>
		inline SafeEventHandler& operator=(const SafeEventHandler& other)
		{
			SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
			this->composedHandle = other.composedHandle;

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeEventHandler&amp;</returns>
		inline SafeEventHandler& operator=(SafeEventHandler&& other)
		{
			SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
			this->composedHandle = static_cast<std::function<void(const GenericTypeOfEvent&)>&&>(other.composedHandle);

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		/// </summary>
		/// <param name="event"></param>
		/// <returns>void</returns>
		inline void handle(const GenericTypeOfEvent& event)
		{
			(this->composedHandle)(event);
		};

		/// <summary>
		///		dynamic
		///		inline
		/// </summary>
		/// <param name="eventPointer"></param>
		/// <returns>void</returns>
		inline void handle(const GenericTypeOfEvent* const eventPointer)
		{
			(this->composedHandle)(*eventPointer);
		};
	};
};