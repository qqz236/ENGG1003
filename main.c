#include<stdio.h>
//encryption given k = 1

char upperCase (char *x, int y); //make all letters in an array upper case
//char rotate (char *x, int y ) //x is the message, y is the size of the message array,

int main()
{
    //char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int k = 0, i = 0;
    k = 1;
    char message[] = {"Where did you hide the body?"};
    
    int size = sizeof(message)/sizeof(char) - 1;
    
    upperCase(message, size);
    printf("%s\n", message);
    
    for (i = 0; i < sizeof(message)/sizeof(char) - 1; i++){
        if (message[i] + k > 90){
            message[i] = message[i] + k - 26;
            printf("%c", message[i]);
        }
        else if (message[i] + k <= 90 && message[i] >64){
            message[i] = message[i] + k;
            printf("%c", message[i]);
        }
        else
            printf("%c", message[i]);
    }
return 0;
}


char upperCase (char *x, int y) { //make all letters in an array lower case
    int i;
    for (i = 0; i < y; i++){ //make everything upper case
            if (x[i] >=97 && x[i] <= 122)   {
                x[i] -= 32;
            } 
        }
        return 0;
}