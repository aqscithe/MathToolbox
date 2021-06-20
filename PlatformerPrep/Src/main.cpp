#include <raylib/raylib.h>
#include <raylib/raymath.h>

#include <primitives.h>


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    using namespace Core::Maths;

    Color planeColor = BLUE;

    vec3 normal = { 0.f, 1.f, 1.f };
    vec3 intersect = { 0.f, 1.f, 3.f };

    Plane plane(normal, intersect);



    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);          // Update camera

        if (IsKeyDown('Z')) camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        DrawLine3D({ 0,0,0 }, { 1,0,0 }, RED);
        DrawLine3D({ 0,0,0 }, { 0,1,0 }, RED);
        DrawLine3D({ 0,0,0 }, { 0,0,1 }, RED);


        // Affichage d’un plan  (vous afficherez un carré centré sur le projeté de O sur le plan, et de vecteur normal plane.normal)
        

        DrawSphere({ 1, 1, 1 }, 0.5f, RED);
        DrawCube(cubePosition, 2.0f, 2.0f, 4.0f, RED);

        DrawGrid(50, 1.0f);

        EndMode3D();

        DrawRectangle(10, 10, 320, 133, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 320, 133, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Alt + Mouse Wheel Pressed to Rotate", 40, 80, 10, DARKGRAY);
        DrawText("- Alt + Ctrl + Mouse Wheel Pressed for Smooth Zoom", 40, 100, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 0, 0)", 40, 120, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}

//quarternion q = quatenionFromAxisAngle(normalize({1,0,1}), PI /4);