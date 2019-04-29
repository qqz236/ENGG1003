#include<stdio.h>

//Function Prototypes
char roEncrypt(char *alpha, char c, int k); //passes alphabet, current letter the function must work on and the rotation key k
char roDecrypt(char *alpha, char c, int k);
char subEncrypt(char *key, char c);
char subDecrypt(char *x, char *y, char c); //x is alphabet array and c are the letters from input file
char countGreatest(char *count); //finds the letter that occurs most in a file, where count is an array that stores the presence of each letter in a count[26]

int main(){
    //Setting initial conditions
    FILE *fp = fopen("message","r");
    FILE *out = fopen("output", "w");
    int k = 1, x; //k is the rotation amount
    int task = 0; //See determining task in comments a few lines below
    char c = 0;
    char key[26];
    char alphabet[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char count[26] = {0};
    
    //To determine which task will run
    /*
     * If task = 1, then the rotation encryption will run
     * If task = 2, then the rotation decryption will run
     * If task = 3, then the substitution encryption will run
     * If task = 4, then the substitution decryption will run
     * 
     * Task that will be run is dependent on the number on the first line of message input file.
     */
    //First, print out original message
    printf("Original Message:   \n");
    scanf("%d", &task);//scan first line to task
    fseek(fp, 29, SEEK_SET);
    while ((c = fgetc(fp)) != EOF){
            //taking input single character at a time
            printf("%c", c); //print original message char by char
        if (c > 64 && c < 91) {//quick analysis of presence of each letter
             x = c - 'A';
             count[x]++;
          }
        }
    
    //scan second line for key
    scanf("%s", &key);
    
    switch(task){
    case 1: //Rotation Encryption
        printf("\nRotation Encrypted:      ");  
        fseek(fp, 29, SEEK_SET);
        while ((c = fgetc(fp)) != EOF){
            //taking input single character at a time
            //printf("\nreach");
            printf("%c", roEncrypt(alphabet, c, k)); //encrypted char by char
            fputc(roEncrypt(alphabet, c, k), out);
        }
        break;
        
   
    case 2: //Rotation Decryption With or Without Key
        printf("\n\nRotation Decrypted:\n");
        fseek(fp, 29, SEEK_SET); //start reading file from beginning
        while ((c = fgetc(fp)) != EOF){
            if (key[1] == ' '){ //if there is no key    
                    if (c > 64 && c < 91){
                        k = countGreatest(count) - 'E' + 4;
                            if(k<0)
                                k = 26 + k;
                        printf("%c", roDecrypt(alphabet, c, k));
                        fputc(roDecrypt(alphabet, c, k), out);
                    }
                        
                    else{
                        printf("%c", c);
                        fputc(c, out);
                    }
            }       
            else{
                
                
                //taking input single character at a time
                printf("%c", roDecrypt(alphabet, c, k)); //decrypted char by char
                fputc(roDecrypt(alphabet, c, k), out);
            }

        }
        break;
        
    
    case 3: //Substitution Encryption with key
        printf("\nSub Encrypted:\n"); 
        fseek(fp, 29, SEEK_SET); //Start from beginning of file for encryption
        while ((c = getc(fp)) != EOF){
            printf("%c", subEncrypt(key, c));
            fputc(subEncrypt(key, c), out);  
        } 
        break;
        
    
    case 4: //Substitution Decryption with key
        
        fseek(fp, 29, SEEK_SET);
        printf("\nSub Decrypted:\n");
        if (key[1] == ' '){ //if there is no key then print all Es and hope for the best
            while ((c = getc(fp)) != EOF){
                if (c > 64 && c < 91){
                    printf("%c", roDecrypt(alphabet, key, c) + 4);
                    fputc(roDecrypt(alphabet, key, c) + 4, out);
                }
                    
                else{
                    printf("%c", c);
                    fputc(c, out);
                }

            }
        }       
        else{
        while ((c = getc(fp)) != EOF){
            printf("%c", subDecrypt(alphabet, key, c) + 4);
            fputc(subDecrypt(alphabet, key, c) + 4, out);
        }}
        break;
        
        
    default: 
    printf("\nNo task selected");
    }
       
    fclose(out);
    fclose(fp);   
    return 0;
}









//FUNCTION DEFINITIONS
char roEncrypt(char *alpha, char c, int k) {
    if (c > 96 && c < 123){ //make all letters upper case
        c -= 32;
    }
    if (c > 64 && c < 91){ //if it's a capital letter
        if (c + k > 90){ //if the ASCII code of the letter plus the rotation key exceeds allowed value of 90, then minus 26 to go between 65 and 90
            c -= 26;
            return alpha[c - 65];
        }
    }
    else return c; //if it's not a letter, just return as is
}
    
char roDecrypt(char *alpha, char c, int k){
    if (c > 96 && c < 123){ //make all letters upper case
        c -= 32;
    }
    if (c > 64 && c < 91){ //if it's a capital letter
        if (c - k <= 64){ //if the ASCII code of the letter minus the rotation key is less than 65, then plus 26 to go between 65 and 90
            c += 26;
            return alpha[(c - k) - 65];
        }
    }
    else return c; //if it's not a letter, just return as is
}

//Sub Encryption - making each letter according to given key
char subEncrypt(char *key, char c){   //Substitution Cipher Encryption Given Key
    //make each letter according to key
    if (c > 64 && c < 91)
        return key[c-65];
    else if (c > 96 && c < 123)
        return key[c - 32 - 65];
    else 
        return c; 
}

char subDecrypt(char *x, char *y, char c){
    //find index of key that the character belongs to
        int i, index;
        for (i = 0, index = 0; i <= 25; i++){
            int compar = y[c - 65]; 
            if (x[i] == compar){
                index = i;}
        }
        
        if (c > 64 && c < 91){
                return x[index];}
            else
                return c;
}

char countGreatest(char *count){
    int c = 0, greatest;
     
    for (c = 0, greatest  = 0; c < 26; c++){
        if (count[c] > greatest){
        greatest = count[c];
        }
    }
    return greatest + 38;
}
