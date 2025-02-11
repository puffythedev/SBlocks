#pragma once
#include <string>
#include <raylib.h>
#include <game.hpp>

struct WindowSize {
    int width;
    int height;
};

class Application {
    public:
        ~Application();
        Application(WindowSize size, std::string title, ConfigFlags flags = FLAG_WINDOW_RESIZABLE);
        void Run(SBlocks &game);
        int getCurrentFrame(); 

    private:
        int frames;
        WindowSize windowSize;
        ConfigFlags flags;
        std::string title;
};