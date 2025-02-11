#pragma once
#include "engine.hpp"


class SBlocks : public Game {
    public:
        SBlocks(Camera3D cam) : cam(cam) {}
        void MainLoop();
    private:
        Camera3D cam;
        float yaw = 0.0f;
        float pitch = 0.0f;
        int frames = 0;
        bool mouseCaptured = true;
};