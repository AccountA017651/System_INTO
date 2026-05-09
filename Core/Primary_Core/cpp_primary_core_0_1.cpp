#include <iostream>
#include <fstream>
#include <print>
#include <map>
#include <functional>

#include "Data_Pusher_Utility/Data_0_0_Pusher_Utility/data_0_0_pusher_utility.hpp"
#include "Central_Versioning_Utility/central_versioning_utility.hpp"
#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"
#include "Terminal_Color_Utility/terminal_color_utility.hpp"


int main(int argc, char* argv[]) {
    std::string os_name = OSOU::Obtain_OS();

    if (argc < 2) {
        TCU::Terminal_Error("No command provided, please provide a command.\n");
        return 1;
    }

    std::string command = argv[1];

    // Flag handler
    std::unordered_map<std::string, std::function<void()>> flag_map = {
        {"--version", [&](){ std::print("System_INTO Version: {}.{}.{}.{}\n", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE); }},
        {"-v", [&](){ std::print("System_INTO Version: {}.{}.{}.{}\n", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE); }},
        {"--os_name", [&](){ std::print("OS Name: {}\n", os_name); }},
        {"-osn", [&](){ std::print("OS Name: {}\n", os_name); }},
        {"--help", [&](){ std::print("Available commands: RBLX_D_0_0\n"); }},
        {"-h", [&](){ std::print("Available commands: RBLX_D_0_0\n"); }}
    };

    for (int index = 1; index < argc; index++) {
        auto flag_map_iterator = flag_map.find(argv[index]);
        if (flag_map_iterator != flag_map.end()) {
            flag_map_iterator->second();
            
            return 0;
        }
    }

    // Command handler
    std::unordered_map<std::string, std::function<void()>> command_map = {
        {"D_0_0", [&](){ D_0_0_PU::Obtain_Data_0_0(); }}
    };

    auto command_map_iterator = command_map.find(command);
    if (command_map_iterator != command_map.end()) {
        command_map_iterator->second();
    } else {
        TCU::Terminal_Error("Unknown command, please enter a valid command.");
    }

    return 0;
}