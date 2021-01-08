#include <stdio.h>

#include <math.h>

int which_card(long number);                    //function which checks card type and returns 1 to 4

int main(void)
{
    
    
    long card_num = get_long("Enter card number:\n");       //user prompt for card number input
    int total = 0;
    int even = 0;           
    int odd = 0;
    int last_digit;
    int i;
    int card_type = which_card(card_num);
    
    //this checksum loop divides the card number by 10 and looks for the last digit
    
    for (i = 0; card_num > 10; i++)
    {              
        last_digit = (int)(card_num % 10);              //last digit of the division is the mod 10 of card num.
        
        if (i % 2 != 0)                 //loop counter i counts digit number, according to luhn, even numbered digits are underlined
        {                               
            if (last_digit * 2 >= 10)       //and multiplied by 2
            {
                even += (((last_digit * 2) % 10) + 1);      //if multiplication exceeds over 10, get the sum of two digits (ie: 12 -> 1+2)
            } 
            
            else
            {
                even += (last_digit * 2);
            }
            
        }
        else
        {
            odd += last_digit;              //odd numbered digits are added to the sum without multiplication
        }
        
        card_num = card_num / 10;
        /* printf("last digit: %d\n",last_digit);
        printf("final card number: %ld\n",card_num);
        printf("i: %d\n",i); */
        
    }
    
    total = even + odd;         //total sum, however, first digit from left isn't calculated.
    if (i % 2 != 0)
    {
        if (2 * (int)card_num >= 10)
        {
            total += (2 * ((int)card_num % 10) + 1);        //same process if last loop counter is even
        }
        else
        {
            total += 2 * (int)card_num;
        }
        
    }
    else
    {
        total += (int)card_num;
    }
    printf("total: %d\n", total);
    printf("card type: %d\n", card_type);
    if (total % 10 != 0)                                    //the checksum begins, according to luhn's
    {
        printf("INVALID\n");
    } 
    else
    {
        
        switch (card_type)                          //if checksum meets the requirement, this prints card type from which_card function's output
        {
            case 1:
                printf("VISA\n");
                break;
            case 2:
                printf("AMEX\n");
                break;
            case 3:
                printf("MASTERCARD\n");
                break;
            case 4:
                printf("INVALID\n");
                break;
            

        }
        
    }
    
}

int which_card(long number)                                 //card type function
{
    
    int first_two = (int)(number / (long)pow(10, 12));      //every card has at least 13 digits or 1e+12
    
    //printf("first numbers: %d\n", first_two);
    
    if (first_two == 4 || (int)(first_two / 1000 == 4))     //check for VISA (13 or 16 digits, first number 4)
    {
        return 1;
        
    }
    else if ((int)(first_two / 10 == 34) || (int)(first_two / 10 == 37))    //check for AMEX (15 digits, first two digits 34 or 37)
    {
        return 2;
        
    } 
    else if (((int)(first_two / 100) <= 55) && ((int)(first_two / 100) >= 51))  //check for MASTERCARD(16 digits, first two 51 to 55)
    {
        return 3;
        
    }
    else                //INVALID
    {
        return 4;
    }
    
}
