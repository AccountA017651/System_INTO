#include <iostream>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"

int main() {
    std::string os = Obtain_OS();
    std::cout << os;
}