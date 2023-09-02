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
    const int screenWidth = 1800;
    const int screenHeight = 950;
    const int margin_vert = int(0.05 * screenHeight);
    const int margin_hori_want = int(0.02* screenWidth);
    int num_recs = 300;
    int width = int((screenWidth - 2 * margin_hori_want)/num_recs);
    int height;
    int margin_hori = int((screenWidth - num_recs * width) / 2);
    int x_pos = margin_hori;
    Rectangle recs[num_recs];
    cout << "width:" << width<< "\n" ;
  
    for(int i = 0; i<sizeof(recs) / sizeof(Rectangle); i++)
    {
        height = rand() % (screenHeight - margin_vert); 
        x_pos = x_pos + width;
        Rectangle rec = { x_pos, screenHeight - height - margin_vert, width, height };
        recs[i] = rec;
        cout << "rec[" << i <<"].x:" << rec.x<< "\n" ;
        cout << "rec[" << i <<"].y:" << rec.y<< "\n" ;
        cout << "rec[" << i <<"].width:" << rec.width<< "\n" ;
        cout << "rec[" << i <<"].height:" << rec.height<< "\n" ;
    }
    InitWindow(screenWidth, screenHeight, "Sorting algorithm visualizer");

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
            for(int i = 0; i<sizeof(recs) / sizeof(Rectangle); i++)
            {
                DrawRectangleLinesEx(recs[i], 1, RED);
                
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}