/*
	MIT License

	Copyright (c) 2019 Robert Bendun

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#ifndef GRUBEO_TYPESWITCH_HH
#define GRUBEO_TYPESWITCH_HH

#include <variant>
#include <any>

namespace typeswitch_details
{
	template<typename T, typename ...Types>
	decltype(auto) get_if(std::variant<Types...> &variant) noexcept
	{
		return std::get_if<T>(&variant);
	}

	template<typename T>
	decltype(auto) get_if(std::any &any) noexcept
	{
		return std::any_cast<T>(&any);
	}

	template<typename T, typename ...Types>
	decltype(auto) get_if(const std::variant<Types...> &variant) noexcept
	{
		return std::get_if<T>(&variant);
	}

	template<typename T>
	decltype(auto) get_if(const std::any &any) noexcept
	{
		return std::any_cast<T>(&any);
	}
}

#define TYPESWITCH_TOKENPASTE(x, y) x ## y
#define TYPESWITCH_TOKENPASTE2(x, y) TYPESWITCH_TOKENPASTE(x, y)

#define typeswitch(container) \
	for (bool __loop = true; __loop; __loop = false) \
		if (decltype(auto) __typeswitch_container = container; true) 

#define typecase(type, name) \
	if (auto __typeswitch_ptr = typeswitch_details::get_if<type>(__typeswitch_container); __typeswitch_ptr) \
		if (decltype(auto) name = *typeswitch_details::get_if<type>(__typeswitch_container); true) \
			// TYPESWITCH_TOKENPASTE2(__typeswitch_colon, __LINE__) // <- uncomment to enable : support in typecase

#endif