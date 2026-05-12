#include <iostream>
#include <fstream>
#include <print>
#include <map>
#include <functional>

#include "Central_Versioning_Utility/central_versioning_utility.hpp"
#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"
#include "Terminal_Color_Utility/terminal_color_utility.hpp"
#include "Miscellaneous_Panel/Crasher_Utility/crasher_utility.hpp"

int main(int argc, char* argv[]) {
    std::string os_name = OSOU::Obtain_OS();
    bool command_used = false;

    if (argc < 2) {
        TCU::Terminal_Error("No command provided, please provide a command.\n");
        return 1;
    }

    // Flag handler
    std::unordered_map<std::string, std::function<void()>> flag_map = {
        {"--version", [&](){ std::print("Tool_N version: {}.{}.{}.{}\n", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE); }},
        {"-v",        [&](){ std::print("Tool_N version: {}.{}.{}.{}\n", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE); }},
        {"--os_name", [&](){ std::print("OS name: {}\n", os_name); }},
        {"-osn",      [&](){ std::print("OS name: {}\n", os_name); }},
        {"--help",    [&](){ std::print("Available commands: None\n"); }},
        {"-h",        [&](){ std::print("Available commands: None\n"); }}
    };

    // Command handler
    std::unordered_map<std::string, std::function<void()>> command_map = {
        {"Misc-Predictable-Terminate-0",    [&](){ CHR::DFND_BHVR::Explicit_Abort(); } },
        {"Misc-Unpredictable-Terminate-0",    [&](){ CHR::UNDN_BHVR::Divide_Zero(); } },
        {"Misc-Null-Pointer-Dereference-1",    [&](){ CHR::UNDN_BHVR::Null_Pointer_Dereference(42); } }
    };


    for (int index = 1; index < argc; index++) {
        std::string arg = argv[index];

        auto flag_it = flag_map.find(arg);
        if (flag_it != flag_map.end()) {
            flag_it->second();
            continue;
        }

        auto cmd_it = command_map.find(arg);
        if (cmd_it != command_map.end()) {
            cmd_it->second();
            command_used = true;
            continue;
        }


        TCU::Terminal_Error("Unknown argument: " + arg + "\n");
        return 1;
    }

    return command_used ? 0 : 0;
}
