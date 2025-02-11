#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raymath.h>
#include <string>
#include <Application.hpp>
#include <vector>
#include <game.hpp>
#include <cmath>
#include <fstream>
#include <sstream>

void SBlocks::MainLoop() {
    float moveSpeed = 0.2f;
    float mouseSensitivity = 0.001f;
    float verticalMoveSpeed = 0.1f;
    Vector2 screenCenter = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };

    Vector3 forward = Vector3Normalize(Vector3Subtract(cam.target, cam.position));
    Vector3 right = Vector3Normalize(Vector3CrossProduct(forward, cam.up));

    if (IsKeyDown(KEY_W)) cam.position = Vector3Add(cam.position, Vector3Scale(forward, moveSpeed));
    if (IsKeyDown(KEY_S)) cam.position = Vector3Add(cam.position, Vector3Scale(forward, -moveSpeed));
    if (IsKeyDown(KEY_A)) cam.position = Vector3Add(cam.position, Vector3Scale(right, -moveSpeed));
    if (IsKeyDown(KEY_D)) cam.position = Vector3Add(cam.position, Vector3Scale(right, moveSpeed));
    if (IsKeyDown(KEY_SPACE)) 
        cam.position.y += verticalMoveSpeed;
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))
        cam.position.y -= verticalMoveSpeed;

    float zoom = GetMouseWheelMove();
    cam.position = Vector3Add(cam.position, Vector3Scale(forward, zoom));
    frames++;

    if (IsKeyPressed(KEY_ESCAPE)) {
        if(frames < 15){
            frames = 0;
        } else {
            mouseCaptured = !mouseCaptured;
            mouseCaptured ? DisableCursor() : EnableCursor();
        }
    }

    BeginDrawing();
        ClearBackground(BLACK);
        DrawFPS(20, 20);
        DrawText(TextFormat("Position: %.2f, %.2f, %.2f", cam.position.x, cam.position.y, cam.position.z), 20, 40, 20, WHITE);

        Vector2 mouseDelta = GetMouseDelta();

        yaw += mouseDelta.x * mouseSensitivity;
        pitch -= mouseDelta.y * mouseSensitivity;
        pitch = Clamp(pitch, -89.0f, 89.0f);
        if (fabsf(mouseDelta.x) > 0.5f) yaw += mouseDelta.x * mouseSensitivity;
        if (fabsf(mouseDelta.y) > 0.5f) pitch -= mouseDelta.y * mouseSensitivity;

        Vector3 direction = {
            cosf(yaw) * cosf(pitch),
            sinf(pitch),
            sinf(yaw) * cosf(pitch)
        };
        direction = Vector3Normalize(direction);
        
        cam.target = Vector3Add(cam.position, direction);


        BeginMode3D(cam);
            DrawCube({0, 5, 0}, 10, 10, 10, RED);
        EndMode3D();

    EndDrawing();

    if (mouseCaptured) {
        SetMousePosition(screenCenter.x, screenCenter.y);
    }
}