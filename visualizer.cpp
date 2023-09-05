/*******************************************************************************************
*Sorting algorithm visualizer
*  
*
********************************************************************************************/

#include <iostream>
#include "raylib.h"
using namespace std;
#define MOUSE_SCALE_MARK_SIZE   12

// quicksort function with pivot point at end of array
void quicksort_lomuto(int* array, int size_array, int low, int high)
{ 
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
        quicksort_lomuto(array,size_array, low, low + size_lower-1);
        cout<<"doing uppeer half \n";
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
    const int screenWidth = 1800;
    const int screenHeight = 950;
    const int margin_vert = int(0.05 * screenHeight);
    const int margin_hori_want = int(0.02* screenWidth);
    int num_recs = 10;
    int width = int((screenWidth - 2 * margin_hori_want)/num_recs);
    int height;
    int margin_hori = int((screenWidth - num_recs * width) / 2);
    int x_pos = margin_hori;
    Rectangle recs[num_recs];
   
    //int size_array = sizeof(test_array) / sizeof(int);
    int size_array = 100;
    int test_array[size_array];

    for(int i = 0; i<size_array; i++)
        {
            test_array[i] = rand()% 100;
            cout << "test_array[" << i <<"]:" << test_array[i]<< "\n" ;
        
        }
    quicksort_lomuto(test_array, size_array, 0, size_array -1 );
    for(int i = 0; i<size_array; i++)
    {
        cout << "sorted_array[" << i <<"]:" << test_array[i]<< "\n" ;
    
    }
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