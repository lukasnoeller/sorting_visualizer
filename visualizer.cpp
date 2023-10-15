
#include <iostream>
#include "raylib.h"
using namespace std;
#define MOUSE_SCALE_MARK_SIZE   12
/*******************************************************************************************
*Sorting algorithm visualizer
*  
*
********************************************************************************************/


// quicksort function with pivot point at end of array
void quicksort_lomuto(int* array, int size_array, int low, int high)
{ 
    Music music = LoadMusicStream("resources/ff7_enemy_death.mp3");

    PlayMusicStream(music);
    const int screenWidth = 1900;
    const int screenHeight = 950;
    const int margin_vert = int(0.05 * screenHeight);
    const int margin_hori_want = int(0.015* screenWidth);
    
    int width = int((screenWidth - 2 * margin_hori_want)/size_array);
    int height;
    int margin_hori = int((screenWidth - size_array * width) / 2);
    int x_pos = margin_hori;
    Rectangle recs[size_array];
    for(int i = 0; i<size_array; i++)
    {
        height = array[i] % (screenHeight - margin_vert); 
        x_pos = x_pos + width;
        Rectangle rec = { x_pos, screenHeight - height - margin_vert, width, height };
        recs[i] = rec;
    }

        BeginDrawing();
            ClearBackground(RAYWHITE);
               for(int i = 0; i<sizeof(recs) / sizeof(Rectangle); i++)
            {
                DrawRectangleLinesEx(recs[i], 1, RED);
                
            }
        EndDrawing();
   

    cout<<"low:"<< low<< "\n";
    cout<<"high:"<< high<< "\n";
    int array_lower[size_array];
    int array_upper[size_array];
    int pivot_index = high; 
    int size_lower = 0;
    int size_upper = 1;
    int num_repeats = 0;
    if(high - low < 2)
    {
       return;
    }
    else
    {
        array_upper[0] = array[pivot_index];
        for(int i = low; i<high ;i++)
        {
            if(array[i]<array[pivot_index])
            {
                array_lower[size_lower] = array[i];
                size_lower++;
            
            }
            else
            {
                if(array[i]==array[pivot_index])
                {num_repeats++;}
                array_upper[size_upper] = array[i];
                size_upper++;
               
            }    
        }
   
        for(int i = low; i < low + size_lower;i++)
        {
            array[i] = array_lower[i-low];
        }
        for(int i = low + size_lower; i<= high;i++)
        {
            array[i] = array_upper[i - low - size_lower];
        }
        cout<< "array =[";
        for(int i = 0 ;i< size_array;i++)
        {
            cout<<array[i];
            if(i!=size_array-1)
            {cout<<",";}
        }
         cout<<"]\n";
         cout<< "array_lower =[";
        for(int i = 0 ;i< size_lower;i++)
        {
            cout<<array_lower[i];
            if(i!=size_lower-1)
            {cout<<",";}
        }
         cout<<"]\n";
         cout<< "array_upper =[";
        for(int i = 0 ;i< size_upper;i++)
        {
            cout<<array_upper[i];
            if(i!=size_upper-1)
            {cout<<",";}
        }
         cout<<"]\n";

             if((num_repeats == size_upper -1) && (size_lower == 0))
        {
            return;
        }
        cout<<"doing lower half \n";
        UnloadMusicStream(music);   // Unload music stream buffers from RAM
        quicksort_lomuto(array,size_array, low, low + size_lower-1);
        cout<<"doing upper half \n";
        quicksort_lomuto(array, size_array, low + size_lower,high);
        return;
    }
}
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int num_recs = 1000;
    int test_array[num_recs];
    Rectangle recs[num_recs];

    const int screenWidth = 1900;
    const int screenHeight = 950;
    const int margin_vert = int(0.05 * screenHeight);
    const int margin_hori_want = int(0.015* screenWidth);
    
    int width = int((screenWidth - 2 * margin_hori_want)/num_recs);
    int height;
    int margin_hori = int((screenWidth - num_recs * width) / 2);
    int x_pos = margin_hori;
    
   
    InitWindow(screenWidth, screenHeight, "Sorting algorithm visualizer");
    InitAudioDevice();              // Initialize audio device

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    for(int i = 0; i<num_recs; i++)
        {
            test_array[i] = rand()% 900;
            cout << "test_array[" << i <<"]:" << test_array[i]<< "\n" ;
        
        }
    quicksort_lomuto(test_array, num_recs, 0, num_recs -1 );
    for(int i = 0; i<num_recs; i++)
    {
        cout << "sorted_array[" << i <<"]:" << test_array[i]<< "\n" ;
    
    }
    // for(int i = 0; i<sizeof(recs) / sizeof(Rectangle); i++)
    // {
    //     height = test_array[i] % (screenHeight - margin_vert); 
    //     x_pos = x_pos + width;
    //     Rectangle rec = { x_pos, screenHeight - height - margin_vert, width, height };
    //     recs[i] = rec;
    //     cout << "rec[" << i <<"].x:" << rec.x<< "\n" ;
    //     cout << "rec[" << i <<"].y:" << rec.y<< "\n" ;
    //     cout << "rec[" << i <<"].width:" << rec.width<< "\n" ;
    //     cout << "rec[" << i <<"].height:" << rec.height<< "\n" ;
    // }
   
    
    CloseAudioDevice();         // Close audio device (music streaming is automatically stopped)


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
       //     ClearBackground(RAYWHITE);

            DrawText("Visualize the array elements", 10, 10, 20, GRAY);
            for(int i = 0; i<sizeof(recs) / sizeof(Rectangle); i++)
            {
                //DrawRectangleLinesEx(recs[i], 1, RED);
                
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