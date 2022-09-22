#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define STR_LENGTH 14// the length for input string
#define M 100019 //Prime number to make hash values
//Structure
//Prototype Declaration
int Hash(int , int );
int Hash1(int );
int Hash2(int );
void Insert(char[STR_LENGTH]);
int Find(char[STR_LENGTH]);
int ChangeDigitTo5th(char[STR_LENGTH]);
int getChar(char c);
//Global Variables
char hashTable[M+1][STR_LENGTH];
int main()
{
    int n;
    char cmd[7];
    char str[STR_LENGTH];
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%s",cmd);
        switch(cmd[0])
        {
            case 'i':
                scanf("%s",str);
                Insert(str);
            break;
            case 'f':
                scanf("%s",str);
                if(Find(str) == 0){
                    printf("no\n");
                }else{
                    printf("yes\n");
                }
            break;
        }
    }
    return 0;
}

void Insert(char str_key[STR_LENGTH])
{
    int tmp_hash,i = 0;
    //make hash values
    int key = ChangeDigitTo5th(str_key);
    while(1)
    {
        //make hash values
        tmp_hash = Hash(key,i);
        if(strcmp(hashTable[tmp_hash],"\0") == 0)
        {
            strcpy(hashTable[tmp_hash],str_key);
            break;
        }else{
            i++;
        }
        if(i>100)break;

    }
}
//search key : return values 0 = none; 1 = found;
int Find(char str_key[STR_LENGTH])
{
    int tmp_hash,i = 0;
    //make hash values
    int key = ChangeDigitTo5th(str_key);
    
    while(1)
    {
        //make hash values
        tmp_hash = Hash(key,i);
        if(strcmp(hashTable[tmp_hash],"\0") == 0)
        {
            //none
            return 0;
        }else if(strcmp(hashTable[tmp_hash],str_key) == 0){
            //found
            return 1;
        }else{
            i++;
        }
    }
return 0;
}
//Make the String to 5th digit number
int ChangeDigitTo5th(char str[STR_LENGTH])
{
    long long sum, d = 1;
    for(int i = 1; i < strlen(str) ; i++)
    {
        sum = d * getChar(str[i]);
        d *= 5; 
    }
    if(sum == 0)return 1;
    return sum;
}
//Make character to number
int getChar(char c)
{
    switch(c)
    {
        case 'A':return 1;
        break;
        case 'C':return 2;
        break;
        case 'G':return 3;
        break;
        case 'T':return 4;
        break;
    }
    return 0;
}
int Hash(int key, int i)
{
    if(i == 0){
        return Hash1(key);
    }
    return ( Hash1(key) + i * Hash2(key) ) % M;
}
int Hash1(int key)
{
    return key % M;
}
int Hash2(int key)
{
    return 1 + (key % (M-1));
}
