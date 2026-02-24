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


/** Main code.**/

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
#define UNIX
#else
#define OTHER_OS
#endif

#ifdef WINDOWS
#ifdef CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_EXPORT
#define CPP_SAFE_LIBRARY_TRADE __declspec(dllexport)
#else
#ifdef CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_IMPORT
#define CPP_SAFE_LIBRARY_TRADE __declspec(dllimport)
#else
#ifdef CPP_SAFE_STATICALLY_LINKED_LIBRARY_EXPORT
#define CPP_SAFE_LIBRARY_TRADE
#else
#ifdef CPP_SAFE_STATICALLY_LINKED_LIBRARY_IMPORT
#define CPP_SAFE_LIBRARY_TRADE
#endif
#endif
#endif
#endif
#else
#define CPP_SAFE_LIBRARY_TRADE
#endif


/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	class CPP_SAFE_LIBRARY_TRADE SafeContextBase;
	class CPP_SAFE_LIBRARY_TRADE SafeContextException;
};