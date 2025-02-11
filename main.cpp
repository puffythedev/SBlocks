#include <Application.hpp>
#include <game.hpp>

int main(){
    WindowSize size = {
        .width = 800,
        .height = 600
    };
    
    Application app(size, "Thingy");

    Camera3D cam;

    cam.position = Vector3{0.0f, 5.0f, 10.0f};
    cam.target = Vector3{0.0f, 5.0f, 0.0f};
    cam.up = Vector3{0.0f, 1.0f, 0.0f};
    cam.fovy = 60.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    SBlocks sblocks(cam);

    app.Run(sblocks);
}