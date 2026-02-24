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
#include <memory>
#include <string>
#include <vector>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeNamespace.h"


/** Main code.**/

#define safe : public Safe::SafeContextBase

#if defined(WINDOWS) && defined(_MSC_VER)
#pragma unmanaged
#define WINDOWS_VISUAL_CPP
#endif

#if (defined(CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_EXPORT) || defined(CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_IMPORT)) && defined(WINDOWS_VISUAL_CPP)

class CPP_SAFE_LIBRARY_TRADE std::exception;
struct CPP_SAFE_LIBRARY_TRADE std::_Container_base12;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<char>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<char,unsigned long long int,ptrdiff_t,char*,const char>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char,std::char_traits<char>,std::allocator<char>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<void*>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<void*>;
template class CPP_SAFE_LIBRARY_TRADE std::_Vector_val<std::_Simple_types<void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<void*>,std::_Vector_val<std::_Simple_types<void*>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::vector<void*,std::allocator<void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<const void*>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<const void*>;
template class CPP_SAFE_LIBRARY_TRADE std::_Vector_val<std::_Simple_types<const void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<const void*>,std::_Vector_val<std::_Simple_types<const void*>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::vector<const void*,std::allocator<const void*>>;

#endif