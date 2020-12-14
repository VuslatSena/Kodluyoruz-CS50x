#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height;
    int counter = 0;
    do
    {
        height = get_int("Height:\n");          //get height value from user
    }
    while (height < 1 || height > 8);           //ask user until specified range

    for (int row = 0; row < height ; row++)         //counter for row
    {
        for (int col = 0; col < height; col++)       //counter for column for left side of the stair
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
        printf("  ");                   //for each row add double space
        while (counter < row + 1)       //loop checks how many times the "#" will be printed
        {
            printf("#");
            counter++;
        }
        counter = 0;                        //for each row, counter needs to be set 0
        printf("\n");                       //newline for each row
    }
}
