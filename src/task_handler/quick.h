#ifndef QUICK_H
#define QUICK_H

#include "singleton.h"
#include "stdafx.h"

#include <Windows.h>

class Quick
{
public:
    Quick();
    ~Quick() = default;

    static BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParam);

    bool save(std::string &err_msg);
    bool load();

    std::vector<HWND> child_windows;
};

class QuickSingleton : public Singleton<Quick>
{
};

#endif