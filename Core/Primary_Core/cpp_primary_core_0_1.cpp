#include "Minimal_Obtained_Utility/minimal_std_obtained_utility.hpp"

#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"

int main() {
    std::string os = Obtain_OS();

    std::cout << "OS: " << os;
}