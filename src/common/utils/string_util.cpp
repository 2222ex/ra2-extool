#include "string_util.h"


#include <windows.h>

std::string Utf16ToUtf8(const std::wstring &wStr)
{
    int utf8Len = WideCharToMultiByte(CP_UTF8, 0, wStr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    if (utf8Len <= 1)
        return "";

    std::string utf8Str(utf8Len - 1, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wStr.c_str(), -1, &utf8Str[0], utf8Len, nullptr, nullptr);
    return utf8Str;
}