#include <engine.hpp>

void Game::addScene(std::string sceneName, LoopFunc thing){
    screens[sceneName] = thing;
    screenIDs[sceneName] = totalScenes;
    totalScenes++;
}

int Game::getCurrentScene(){
    return currentScene;
}

int Game::getSceneID(std::string sceneName){
    return screenIDs[sceneName];
}