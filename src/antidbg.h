#pragma once

#include <Windows.h>

namespace Antidbg {
    bool IsDebuggerPresentCheck() {
        return IsDebuggerPresent();
    }

    bool CloseHandleCheck() {
        HANDLE hProcess = GetCurrentProcess();
        HANDLE hDuplicate = nullptr;
        DuplicateHandle(hProcess, hProcess, hProcess, &hDuplicate, 0, FALSE, DUPLICATE_SAME_ACCESS);
        if (hDuplicate == nullptr) {
            return true;
        }
        CloseHandle(hDuplicate);
        return false;
    }
}
