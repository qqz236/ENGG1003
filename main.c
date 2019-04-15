#include<stdio.h>
//encryption given k = 1

char upperCase (char *x, int y); //make all letters in an array upper case
//char rotate (char *x, int y ) //x is the message, y is the size of the message array,

int main(){
    int k = 0, i = 0; //i is the index of the array to be used later
    k = 1; //k is the rotation amount
    char message[] = {"Where did you hide the body?"};
    
    int size = sizeof(message)/sizeof(char) - 1; // create interger 'size' and is the length of the array
    
    upperCase(message, size); //calling function to make all letters upper case
    printf("%s\n", message); //printing the original message
    
    for (i = 0; i < sizeof(message)/sizeof(char) - 1; i++){ //rotating each character by k and prints each letter
        if (message[i] + k > 90){ //if adding k gives a value greater than Z, then minus 26 to make a value between A and Z
            message[i] = message[i] + k - 26;
            printf("%c", message[i]);
        }
        else if (message[i] + k <= 90 && message[i] >64){//if adding k gives value between A and Z, then just leave it at adding k
            message[i] += k;
            printf("%c", message[i]);
        }
        else
            printf("%c", message[i]); //if it's some other ASCII punctuation, just pring it as is
    }
return 0;
}



char upperCase (char *x, int y) { //make all letters in an array upper case
    int i;
    for (i = 0; i < y; i++){ //make everything upper case
            if (x[i] >=97 && x[i] <= 122)   {
                x[i] -= 32;
            } 
        }
        return 0;
}