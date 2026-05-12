#pragma once

#include <print>

namespace LN_PRINT {
    void Help_Command_Output() {
        std::print("This tool is provided to you by the Resonance Community. Tool_N is licensed MIT, you are free to fork, modify, publish, sell any derivative work based on this Tool, commercial, proprietary, personal use.\n\nCurrent commands:\nMisc-Predictable-Terminate-0 [ Uses std::abort(); to crash the program intentionally, predictable ]\nMisc-Unpredictable-Terminate-0 [ Divides by zero (0) to crash the program intentionally, unpredictable ]\nMisc-Unpredictable-Terminate-1 [ Uses null pointer dereferencing, unpredictable ]");
    }
}