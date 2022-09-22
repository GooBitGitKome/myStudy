#include <stdio.h>
#include <math.h>

int main()
{
    int i,j,lnm,innm,flg = 0,tmp;
    int cntPrime= 0;// count the number of prime in integers inputed
    
    //Get the number of how many integers we need to take
    scanf("%d", &lnm); 
    //Loop "lnm" times
    for( i = 0 ; i < lnm ; i++)
    {
        //Start to search prime number in each input
        //input integer
        scanf("%d", &innm);
        //Start Prime number search
        for(j = 2 ; j < innm ; j++)
        {
            if((innm % j) == 0)
            {
                flg= 1; //Marking as no prime with -1;
                break;
            }
            //if there are some factors, these cannot be grater than sqrt(n)
            if(j >= sqrt(innm))break;
        }
        if(flg == 0){cntPrime++;}
        if(innm == 1 )cntPrime--;
        flg=0;
    }
    printf("%d\n",cntPrime);
    
    return 0;
}