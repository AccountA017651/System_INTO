#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <print>

namespace D_0_0_PU {

    enum class Status_Code {
        Success,
        Failure,
        Error,
        Input_Error,
        Warning
    };

    inline Status_Code Obtain_Data_0_0() {
        std::string roblox_data_number;
        std::string date_taken;
        std::string roblox_data_player_username;
        std::string roblox_data_player_displayname;
        std::string roblox_data_player_userid;
        std::string roblox_data_player_notes;
        std::string roblox_data_account_link;
        std::string additional_information;
        std::string roblox_data_game_name;
        std::string roblox_data_game_link;
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

        std::print("Roblox Account Link: ");
        std::getline(std::cin, roblox_data_account_link);

        std::print("Roblox Game Name: ");
        std::getline(std::cin, roblox_data_game_name);

        std::print("Roblox Game Link: ");
        std::getline(std::cin, roblox_data_game_link);

        std::print("Roblox Player Notes: ");
        std::getline(std::cin, roblox_data_player_notes);

        std::print("Additional Information: ");
        std::getline(std::cin, additional_information);

        filename = "Data_0_0_" + roblox_data_number + ".txt";

        std::ofstream file(filename);
        if (!file.is_open()) {
            std::print("Error: Error creating file '{}'\n", filename); // TODO: Replace with custom ASCII-Based text colors.
            return Status_Code::Error;
        }

        file << "=== Data_0_0 ===\n\n\n";
        file << "Date Taken: " << date_taken << "\n\n";
        file << "Roblox User Username: " << roblox_data_player_username << "\n\n";
        file << "Roblox User Displayname: " << roblox_data_player_displayname << "\n\n";
        file << "Roblox User UserID: " << roblox_data_player_userid << "\n\n";
        file << "Roblox User Link: " << roblox_data_account_link << "\n\n";
        file << "Roblox Game Name (of Data Collection): " << roblox_data_game_name << "\n\n";
        file << "Roblox Game Link (of Data Collection): " << roblox_data_game_link << "\n\n";
        file << "Roblox User Notes: " << roblox_data_player_notes << "\n\n";
        file << "Additional Information: " << additional_information << "\n\n";

        std::print("Created filename: {}\n", filename); // TODO: Replace with custom ASCII-Based text colors.
        std::print("Data type: Data_0_0\n"); // TODO: Replace with custom ASCII-Based text colors.

        return Status_Code::Success;
    }
}