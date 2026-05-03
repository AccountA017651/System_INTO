#include <iostream>

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>

#include "OS_Obtainer_Utility/os_obtainer_utility_0_1.hpp"

int main() {
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    
    // =======ELEMENTS=======
    // =======BUTTONS=======
    auto button1 = ftxui::Button("Quit", screen.ExitLoopClosure());
    auto button2 = ftxui::Button("Hello", [&] {});

    auto container = ftxui::Container::Vertical({
        button1,
        button2
    });

    screen.Loop(container);
}