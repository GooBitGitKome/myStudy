using System;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        for(int i = 0 ; i < n ; i++)
        {
            string tmp1 = Console.ReadLine();
            string tmp2 = Console.ReadLine();
            tmp1 = " " + tmp1;
            tmp2 = " " + tmp2;
            Console.WriteLine($"{LCS(tmp1,tmp2)}");
        }
    }
    static int LCS(string X, string Y)
    {
        int[,] c = new int[1001,1001];
        for(int i = 0 ; i < X.Length; i++)c[i,0] = 0;
        for(int i = 0 ; i < Y.Length; i++)c[0,i] = 0;
        for(int i = 1 ; i < Y.Length; i++)
        {
            for(int j = 1 ; j < X.Length ; j++)
            {
                if(Y[i] == X[j])c[i,j] = c[i-1,j-1] + 1;
                else if(c[i-1,j] >= c[i,j-1])c[i,j] = c[i-1,j]; 
                else c[i,j] = c[i,j-1];
            }
        }
        return c[Y.Length -1,X.Length-1];
    }
}