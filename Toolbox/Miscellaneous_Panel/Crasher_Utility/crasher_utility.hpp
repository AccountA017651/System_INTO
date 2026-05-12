#pragma once

#include <cstdlib>
#include <print>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

namespace CHR {
    namespace DFND_BHVR {
        void Explicit_Abort() {
            std::string user_input = "N";

            std::print("Are you sure you want to continue? [Y = Yes, N = No]: ");
            std::getline(std::cin, user_input);
            std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

            const std::unordered_set<std::string> affirmative_variations = {
                "y",
                "ya",
                "yeah",
                "ye",
                "yes",
                "yup",
            };

            if (affirmative_variations.find(user_input) != affirmative_variations.end()) {
                std::abort();
            }
        }
    }


    namespace UNDN_BHVR {
        void Divide_Zero() {
            int a = 0;
            int b = 0;
            int result = a / b;
        }

        void Null_Pointer_Dereference(int pointer_value) {
            int* pointer = nullptr;
            *pointer = pointer_value;
        }
    }
}