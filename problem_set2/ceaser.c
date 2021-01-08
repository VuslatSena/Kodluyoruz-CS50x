#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// input cipher key at command line
int main(int argc, string argv[]){
    
    // per instructions -- terminate program if more than one key
    if(argc != 2){

        printf("error");
        return 1;
    }
        
    // convert command line cipher key input from string to int
    int key = atoi(argv[argc - 1]);
    
    // prompt user for plaintext input
    printf("plaintext:");
    string plainText = get_string();
    
    // declare ciphertext array of characters
    
    char cipherText[strlen(plainText)];
    
    // iterate over plaintext and encrypt each item
    for(int i = 0; i < strlen(plainText); i++){
        
        // convert each plaintext item to (plaintext + key), maintaining capitalization
        if(isalpha(plainText[i])){
            
            if(isupper(plainText[i])){
                
                cipherText[i] = (((plainText[i] - 65 + key) % 26) + 65);
                
            } else {
                if(islower(plainText[i])){
                
                cipherText[i] = (((plainText[i] - 97 + key) % 26) + 97);
                    
                }
            }
            
        // leave all non-alphabetical items as is    
        } else {
            cipherText[i] = plainText[i];
        }
        
    }
    
    // per instructions, print cipherText with no newline
    printf("ciphertext:%s",cipherText);
    // per instructions, print newline
    printf("\n");
        
    return 0;

}
