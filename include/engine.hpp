#pragma once
#include <vector>
#include <map>
#include <string>

typedef void (*LoopFunc)();

class Game {
    public:
        int getSceneID(std::string sceneName);
        int getCurrentScene();
        void addScene(std::string sceneName, LoopFunc thing);

    private:
        int currentScene = 0;
        int totalScenes = 0;
        std::map<std::string, int> screenIDs;
        std::map<std::string, LoopFunc> screens;
};