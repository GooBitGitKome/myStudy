#include <stdio.h>
#include <string.h>

#define M 1047133 //Prime number
#define L 14

char H[M][L]; /* Hash Table */


int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
  return 0;
}

/* convert a string into an integer value */
//５進数に変換
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(long long key){ return key % M; }
int h2(long long key){ return (key % (M - 1)); }

int find(char str[]){
    long long strValue;
    long long key;
    long long value = getKey(str);
    int i=0;
    key = strValue = h1(getKey(str));
    while(1)
    {
        i++;
        if( H[key][0] == '\0'){
            return 0;
        }else if(strcmp(H[key],str) == 0){
            return 1;
        }else{
            key = h1(strValue + (i * h2(value)));
        }
        //return 0;
    }
    return 0;
}

void insert(char str[]){
    long long strValue;
    long long key;
    int i=0;
    long long value = getKey(str);
    key = strValue = h1(getKey(str));    
    while(1)
    {
        i++;
        if(H[key][0] == '\0'){
            strcpy(H[key],str);
            break;
        }else{
            key = h1(strValue + (i * h2(value)));
            continue;
        }
        //break;
    }
}

int main(){
    int i, n, h;
    char str[L], com[9];
    for ( i = 0; i < M; i++ ) H[i][0] = '\0';
    
    scanf("%d", &n);
    
    for ( i = 0; i < n; i++ ){
        scanf("%s %s", com, str);
        
        if ( com[0] == 'i' ){
            insert(str);
        } else {
            if (find(str)){
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}