#include <iostream>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>

#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"

int main() {
    auto screen = ftxui::ScreenInteractive::TerminalOutput();

    auto button = ftxui::Button("Quit", screen.ExitLoopClosure());

    screen.Loop(button);
}