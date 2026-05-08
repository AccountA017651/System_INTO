#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <print>

namespace RBLXDPU {

    enum class Status_Code {
        Success,
        Failure,
        Error,
        Input_Error,
        Warning
    };

    Status_Code Obtain_RBLX_Data() {
        std::string roblox_data_number;
        std::string date_taken;
        std::string roblox_data_player_username;
        std::string roblox_data_player_displayname;
        std::string roblox_data_player_userid;
        std::string roblox_data_player_notes;
        std::string roblox_data_account_state;
        std::string roblox_data_account_link;
        std::string filename;

        std::print("<NUMBER>: ");
        std::getline(std::cin, roblox_data_number);
        
        std::print("Date Taken: ");
        std::getline(std::cin, date_taken);

        std::print("Roblox Player Username: ");
        std::getline(std::cin, roblox_data_player_username);
        if (roblox_data_player_username.empty()) { return Status_Code::Input_Error; }

        std::print("Roblox Player Displayname: ");
        std::getline(std::cin, roblox_data_player_displayname);

        std::print("Roblox Player UserID: ");
        std::getline(std::cin, roblox_data_player_userid);

        std::print("Roblox Account State: ");
        std::getline(std::cin, roblox_data_account_state);

        std::print("Roblox Account Link: ");
        std::getline(std::cin, roblox_data_account_link);

        std::print("Roblox Player Notes: ");
        std::getline(std::cin, roblox_data_player_notes);

        filename = "RBLX_D_" + roblox_data_number + ".txt";

        std::ofstream file(filename);
        if (!file.is_open()) {
            std::print("Error: Error creating file '{}'\n", filename); // TODO: Replace with custom ASCII-Based text colors.
            return Status_Code::Error;
        }

        file << "=== RBLX_D ===\n\n";
        file << "Date Taken: " << date_taken << "\n";
        file << "Roblox User Username: " << roblox_data_player_username << "\n";
        file << "Roblox User Displayname: " << roblox_data_player_displayname << "\n";
        file << "Roblox User UserID: " << roblox_data_player_userid << "\n";
        file << "Roblox User State: " << roblox_data_account_state << "\n";
        file << "Roblox User Link: " << roblox_data_account_link << "\n";
        file << "Roblox User Notes: " << roblox_data_player_notes << "\n";

        std::print("Created filename: {}", filename); // TODO: Replace with custom ASCII-Based text colors.
        std::print("Data type: RBLX_D"); // TODO: Replace with custom ASCII-Based text colors.

        return Status_Code::Success;
    }
}