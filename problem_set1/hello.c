#include <stdio.h>
#include <cs50.h>

int main(void)      //initialize main function
{
    string name = get_string("What is your name?\n");   //gets name of the user
    
    printf("hello, %s\n", name);        //prints the name
}
