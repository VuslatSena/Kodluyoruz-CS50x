#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int height;
    do
    {
        height = get_int("Height:\n");          //get height value from user
    }
    while (height < 1 || height > 8);           //ask user until specified range
    
    for (int row = 0; row < height ; row++)         //counter for row for (height x height matrix)
    {
        for (int col = 0; col < height; col++)       //counter for col
        {
            if (col >= height - (row + 1))
            {           
                printf("#");                        //print height times "#"
            }
            else
            {
                printf(" ");                        //print height-column times "space"
            }
            
        }
        printf("\n");                       //newline for each row
    }
}
