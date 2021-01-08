#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    float owe_float;
    int coin_count = 0;
    
    //Get user "owe" amount, check if its non negative
    do
    {
        owe_float = get_float("How much owe: \n");
    }
    while (owe_float < 0);
    
    
    //Float to integer, rounded to nearest penny
    int owe = round(owe_float * 100);
    
    /*printf("owe: %d\n",owe);*/
    
    //Loop that counts how many coins, and subtracts desired amount
    while (owe > 0)
    {
        if (owe >= 25)
        {
            owe -= 25;
            //printf("-25\n");
            coin_count++;
            
        }
        else if (owe >= 10)
        {
            owe -= 10;
            //printf("-10\n");
            coin_count++;
        }
        else if (owe >= 5)
        {
            owe -= 5;
            //printf("-5\n");
            coin_count++;
        }
        else if (owe >= 1)
        {
            owe -= 1;
            //printf("-1\n");
            coin_count++;
        }
        else
        {
            owe = 0;
        }
        //printf("new owe: %d\n", owe);
        
    }
    
    //Print counted coins
    printf("%d\n", coin_count);
}
