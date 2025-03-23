#include "window_util.h"

#include "logger.h"

bool IsWindowTitleContains(HWND hwnd, const std::string &target)
{
    const int bufferSize = 256;
    char buffer[bufferSize];

    if (GetWindowTextA(hwnd, buffer, bufferSize) > 0)
    {
        std::string title(buffer);
        Logger::Log()->info("title: {}", title);
        return title.find(target) != std::string::npos;
    }
    return false;
}