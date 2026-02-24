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
#include <exception>
#include <string>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeNamespace.h"
#include "SafeTrade.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class: `SafeContextException`.
	/// </summary>
	class SafeContextException final : public std::exception
	{
	private:
		std::string message;

	public:
		/// <summary>
		///		Constructor of `SafeContextException`.
		/// </summary>
		explicit SafeContextException();

		/// <summary>
		///		Constructor of `SafeContextException`.
		/// </summary>
		/// <param name="message"></param>
		explicit SafeContextException(const std::string& message);

		/// <summary>
		///		Copy constructor of `SafeContextException`.
		/// </summary>
		/// <param name="other"></param>
		SafeContextException(const SafeContextException& other);

		/// <summary>
		///		Move constructor of `SafeContextException`.
		/// </summary>
		/// <param name="message"></param>
		explicit SafeContextException(std::string&& message) noexcept;

		/// <summary>
		///		Move constructor of `SafeContextException`.
		/// </summary>
		/// <param name="other"></param>
		SafeContextException(SafeContextException&& other) noexcept;

		/// <summary>
		///		Destructor of `SafeContextException`.
		/// </summary>
		~SafeContextException() noexcept override;

		/// <summary>
		///		dynamic
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeContextException&amp;</returns>
		SafeContextException& operator=(const SafeContextException& other);

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeContextException&amp;</returns>
		SafeContextException& operator=(SafeContextException&& other) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator==
		/// </summary>
		/// <param name="other"></param>
		/// <returns>bool</returns>
		bool operator==(const SafeContextException& other) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		override
		/// </summary>
		/// <returns>char*</returns>
		const char* what() const noexcept override;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>string</returns>
		std::string getMessage() const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="message"></param>
		/// <returns>void</returns>
		void setMessage(const std::string& message);

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="message"></param>
		/// <returns>void</returns>
		void setMessage(std::string&& message) noexcept;
	};
};
