#include<stdio.h>
//encryption given k = 1
int main()
{
    //char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int k = 0, i = 0;
    k = 20;
    char message[] = {"F"};
    
    for (i = 0; i < 5; i++){
        if (i + k > 90){
            message[i] = message[i] + k - 26;
            printf("%c", message[i]);
        }
        


    }
return 0;
}
