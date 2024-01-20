#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include "antidbg.h"
class ProcessList {
public:
    static bool CheckRunningProcesses() {
        std::vector<std::wstring> processList = {
            L"http toolkit.exe",
            L"httpdebuggerui.exe",
            L"wireshark.exe",
            L"fiddler.exe",
            L"charles.exe",
            L"regedit.exe",
            L"debugger.exe",
            L"taskmgr.exe",
            L"vboxservice.exe",
            L"df5serv.exe",
            L"processhacker.exe",
            L"vboxtray.exe",
            L"vmtoolsd.exe",
            L"vmwaretray.exe",
            L"ida64.exe",
            L"ollydbg.exe",
            L"pestudio.exe",
            L"vmwareuser",
            L"vgauthservice.exe",
            L"vmacthlp.exe",
            L"x96dbg.exe",
            L"vmsrvc.exe",
            L"x32dbg.exe",
            L"vmusrvc.exe",
            L"prl_cc.exe",
            L"prl_tools.exe",
            L"qemu-ga.exe",
            L"joeboxcontrol.exe",
            L"ksdumperclient.exe",
            L"ksdumper.exe",
            L"joeboxserver.exe",
            L"xenservice.exe",
        };

        for (const auto& process : processList) {
            if (IsProcessRunning(process.c_str())) {
                return true;
            }
        }

        return false;
    }

private:
    static bool IsProcessRunning(const wchar_t* processName) {
        HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);

        if (hSnapshot == INVALID_HANDLE_VALUE) {
            return false;
        }

        if (!Process32First(hSnapshot, &pe32)) {
            CloseHandle(hSnapshot);
            return false;
        }

        do {
            if (_wcsicmp(pe32.szExeFile, processName) == 0) {
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Process32Next(hSnapshot, &pe32));

        CloseHandle(hSnapshot);
        return false;
    }
};
