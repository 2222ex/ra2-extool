#include "quick.h"
#include "client_module.h"
#include "logger.h"
#include "string_util.h"
#include "yrpp.h"

Quick::Quick()
{
}

BOOL Quick::EnumChildProc(HWND hwndChild, LPARAM lParam)
{
    auto &quick = QuickSingleton::instance();
    quick.child_windows.push_back(hwndChild);

    // char title[256];
    // char className[256];
    // GetWindowTextA(hwndChild, title, sizeof(title));
    // GetClassNameA(hwndChild, className, sizeof(className));

    return TRUE;
}
bool Quick::save(std::string &err_msg)
{
    auto &client = ClientModuleSingleton::instance();

    SetProcessDPIAware();

    HWND hMainWindow = FindWindowA(NULL, "Yuris Revenge ");
    if (hMainWindow == NULL)
    {
        err_msg = "main window not found";
        return false;
    }

    client.EnterMenu(reinterpret_cast<uintptr_t>(InputManagerClass::Instance.get()), 0x1b, 0);

    if (ScenarioClass::SaveGame("2.SAV", L"desc", true) == false)
    {
        err_msg = "SaveGame false";
        return false;
    }

    return true;
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    while (true)
    {
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count() > 5)
        {
            err_msg = "time out";
            return false;
        }

        child_windows.clear();
        if (EnumChildWindows(hMainWindow, EnumChildProc, 0))
        {
        }

        HWND hMenu = NULL;

        for (auto hwnd : child_windows)
        {
            char className[256] = {0};
            GetClassNameA(hwnd, className, sizeof(className));

            if (strcmp("#32770", className) == 0)
            {
                Logger::Log()->trace("found #32770");
                hMenu = hwnd;
                break;
            }
        }

        if (hMenu == NULL)
        {
            continue;
        }

        child_windows.clear();
        if (EnumChildWindows(hMenu, EnumChildProc, 0))
        {
        }

        for (auto hwnd : child_windows)
        {
            wchar_t szWindowText[256] = {0};
            int count = GetWindowTextW(hwnd, szWindowText, 256);

            Logger::Log()->trace("GetWindowTextW: {},count: {},error: {},hwnd: {:#x}", Utf16ToUtf8(szWindowText), count, GetLastError(), reinterpret_cast<uint32_t>(hwnd));

            if (wcscmp(L"GUI:SaveGame ", szWindowText) == 0)
            {
                Logger::Log()->trace("Found GUI:SaveGame ");
                SendMessageA(hwnd, BM_CLICK, 0, 0);
                break;
            }
        }
    }

    return true;
}

bool Quick::load()
{
    return false;
}
