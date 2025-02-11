#include <Application.hpp>
#include <game.hpp>
#include <raylib.h>

Application::Application(WindowSize size, std::string title, ConfigFlags flags) : windowSize(size), title(title), flags(flags) {
    InitWindow(size.width, size.height, title.c_str());
    InitAudioDevice();
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    SetExitKey(KEY_NULL);
}

void Application::Run(SBlocks &game){
    DisableCursor();
    while(!WindowShouldClose()){
        game.MainLoop();
        frames++;
    }

    delete this;
}

Application::~Application(){
    CloseAudioDevice();
    CloseWindow();
}

int Application::getCurrentFrame(){
    return frames;
}