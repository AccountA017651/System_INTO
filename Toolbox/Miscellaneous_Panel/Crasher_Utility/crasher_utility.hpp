#pragma once

#include <cstdlib>
#include <print>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"

namespace CHR {
    namespace DFND_BHVR {
        void Explicit_Abort() {
            std::string user_input = "N";

            std::print("Are you sure you want to continue? [Y = Yes, N = No]: ");
            std::getline(std::cin, user_input);
            std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

            const std::unordered_set<std::string> approval_variations = { "y", "ya", "yeah", "ye", "yes", "yup"} ;

            if (approval_variations.find(user_input) != approval_variations.end()) {
                std::abort();
            } else {
                std::print("User said no. Command discontinued");
            }
        }
    }


    namespace UNDN_BHVR {
        void Divide_Zero() {
            std::string user_input = "N";

            std::print("Are you sure you want to continue? [Y = Yes, N = No]: ");
            std::getline(std::cin, user_input);
            std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

            const std::unordered_set<std::string> approval_variations = { "y", "ya", "yeah", "ye", "yes", "yup"} ;

            if (approval_variations.find(user_input) != approval_variations.end()) {
                int a = 0;
                int b = 0;
                int result = a / b;
            } else {
                std::print("User said no. Command discontinued");
            }
        }

        void Null_Pointer_Dereference(int pointer_value) {
            std::string user_input = "N";

            std::print("Are you sure you want to continue? [Y = Yes, N = No]: ");
            std::getline(std::cin, user_input);
            std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

            const std::unordered_set<std::string> approval_variations = { "y", "ya", "yeah", "ye", "yes", "yup" };

            if (approval_variations.find(user_input) != approval_variations.end()) {
                int* pointer = nullptr;
                *pointer = pointer_value;
            } else {
                std::print("User said no. Command discontinued");
            }
        }

        void Stack_Overflow() {
            Stack_Overflow();
        }

        void Volatile_Assembly_Illegal_Instruction() {
            #if defined(__x86_64__) || defined(__i386__)
                __asm__ volatile ("ud2");
            #elif defined(__aarch64__) || defined(__arm__)
                __asm__ volatile ("udf #0");
            #elif defined(__riscv)
                __asm__ volatile ("ebreak");
            #else
                std::abort();
            #endif
        }
    }
}