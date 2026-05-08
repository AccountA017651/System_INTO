#include <iostream>
#include <fstream>
#include <print>

#include "Data_Pusher_Utility/RBLX_Data_Pusher_Utility/rblx_data_pusher_utility.hpp"
#include "Central_Versioning_Utility/central_versioning_utility.hpp"
#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"

int main(int argc, char* argv[]) {
    std::string os_name = OSOU::Obtain_OS();


    if (argc < 2) {
        std::print("No command provided, please provide a command.");
        return 1;
    }


    std::string command = argv[1];

    // Flag handler
    for (int index = 1; index < argc; index++) {
        std::string flag = argv[index];

        if (flag == "--version" || flag == "-v") {
            std::print("System_INTO Version: {}.{}.{}.{}", CVU::VERSION_MAJOR, CVU::VERSION_MINOR, CVU::VERSION_FIX, CVU::VERSION_STAGE);
            return 0;
        }

        if (flag == "--os_name" || flag == "-osn") {
            std::print("OS Name: {}", os_name);
            return 0;
        }
    }

    // Command handler
    if (command == "rblx_d") {
        RBLXDPU::Obtain_RBLX_Data();
    } else {
        std::print("Unknown command, please enter a valid command.");
        return  1;
    }

    return 0;
}