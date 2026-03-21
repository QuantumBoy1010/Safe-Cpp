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
	///		C++ class template: `SafeFunction`.
	/// </summary>
	/// <typeparam name="GenericType"></typeparam>
	template<typename GenericType> class SafeFunction;

	/// <summary>
	///		C++ class template: `SafeFunction`.
	/// </summary>
	/// <typeparam name="GenericTypeOfReturn"></typeparam>
	/// <typeparam name="...GenericTypesOfArguments"></typeparam>
	template<typename GenericTypeOfReturn,typename ...GenericTypesOfArguments> class SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)> final : public SafeContextBase
	{
	private:
		std::function<GenericTypeOfReturn(GenericTypesOfArguments...)> composedData;


		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>bool</returns>
		bool checkInvocability() const noexcept
		{
			return (this->composedData).operator bool();
		};

	public:
		/// <summary>
		///		Constructor of `SafeFunction`.
		/// </summary>
		inline explicit SafeFunction() : SafeContextBase()
		{
			this->composedData = std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>();
		};

		/// <summary>
		///		Constructor of `SafeFunction`.
		/// </summary>
		/// <typeparam name="GenericTypeOfFunction"></typeparam>
		/// <param name="functionallyInvocable"></param>
		template<class GenericTypeOfFunction> inline SafeFunction(const GenericTypeOfFunction& functionallyInvocable) : SafeContextBase()
		{
			this->composedData = functionallyInvocable;
		};

		/// <summary>
		///		Constructor of `SafeFunction`.
		/// </summary>
		/// <param name="function"></param>
		inline SafeFunction(const std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>& function) : SafeContextBase()
		{
			this->composedData = function;
		};

		/// <summary>
		///		Copy constructor of `SafeFunction`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeFunction(const SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
		{
			this->composedData = other.composedData;
		};

		/// <summary>
		///		Move constructor of `SafeFunction`.
		/// </summary>
		/// <typeparam name="GenericTypeOfFunction"></typeparam>
		/// <param name="functionallyInvocable"></param>
		template<class GenericTypeOfFunction> inline SafeFunction(GenericTypeOfFunction&& functionallyInvocable) : SafeContextBase()
		{
			this->composedData = static_cast<GenericTypeOfFunction&&>(functionallyInvocable);
		};

		/// <summary>
		///		Move constructor of `SafeFunction`.
		/// </summary>
		/// <param name="function"></param>
		inline SafeFunction(std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&& function) : SafeContextBase()
		{
			this->composedData = static_cast<std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&&>(function);
		};

		/// <summary>
		///		Move constructor of `SafeFunction`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeFunction(SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>&& other) noexcept(false) : SafeContextBase(static_cast<SafeContextBase&&>(other))
		{
			this->composedData = static_cast<std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&&>(other.composedData);
		};

		/// <summary>
		///		Destructor of `SafeFunction`.
		/// </summary>
		inline virtual ~SafeFunction() noexcept(false) override = default;

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeFunction&lt;GenericTypeOfReturn,GenericTypesOfArguments...&gt;&amp;</returns>
		inline SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& operator=(const SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& other)
		{
			SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
			this->composedData = other.composedData;

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		noexcept(false)
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeFunction&lt;GenericTypeOfReturn,GenericTypesOfArguments...&gt;&amp;</returns>
		inline SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& operator=(SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>&& other) noexcept(false)
		{
			SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
			this->composedData = static_cast<std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&&>(other.composedData);

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator()
		/// </summary>
		/// <param name="arguments"></param>
		/// <returns>GenericTypeOfReturn</returns>
		inline GenericTypeOfReturn operator()(GenericTypesOfArguments... arguments) const
		{
			if (this->checkInvocability() == true)
			{
				return (this->composedData)(arguments...);
			}
			else
			{
				throw SafeContextException("The current instance of `SafeFunction` is not invocable!");
			}
		};

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>bool</returns>
		bool isInvocable() const noexcept
		{
			return (this->composedData).operator bool();
		};
	};
};