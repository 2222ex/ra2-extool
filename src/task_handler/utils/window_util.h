#ifndef WINDOW_UTIL_H
#define WINDOW_UTIL_H

#include "stdafx.h"
#include <Windows.h>

bool IsWindowTitleContains(HWND hwnd, const std::string &target);

#endif