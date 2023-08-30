/*******************************************************************************************
*Sorting algorithm visualizer
*  
*
********************************************************************************************/

#include <iostream>
#include "raylib.h"
using namespace std;
#define MOUSE_SCALE_MARK_SIZE   12

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Sorting algorithm visualizer");

    Rectangle rec = { 100, 100, 200, 80 };

    Vector2 mousePosition = { 0 };

    bool mouseScaleReady = false;
    bool mouseScaleMode = false;
    int array[20];
    for(int i = 0; i<sizeof(array) / sizeof(int); i++)
    {
        array[i] = rand() % 100;
        cout << "array[" << i <<"]:" << array[i] << "\n" ;
    }
    int r = rand() % 100;   
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText("Visualize the array elements", 10, 10, 20, GRAY);

            DrawRectangleRec(rec, Fade(GREEN, 0.5f));

            DrawRectangleLinesEx(rec, 1, RED);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}