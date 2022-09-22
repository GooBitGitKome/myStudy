using System;
class Program
{
    static long[,] m = new long[1010,1010];
    static int[,] s = new int[1010,1010];
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] p = new int[ 2*n ];
        for(int i = 0 ; i < n ; i++)
        {
            string[] tmp = Console.ReadLine().Split();
            p[i] = int.Parse(tmp[0]);
            p[i+1] = int.Parse(tmp[1]);
        }
        MatrixChainMulti(p);
        Console.WriteLine($"{m[1,n]}");
    }
    static void MatrixChainMulti(int[] p)
    { 
        int n = p.Length - 1;
        for(int i = 1 ; i < 100 ; i++)m[i,i] = 0;
        for(int l = 2 ; l <= n; l++)//is the chain length
        {
            for(int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;
                m[i,j] = int.MaxValue;
                for(int k = i ; k < j ; k++)
                {
                    long q = m[i,k] + m[k+1,j] + p[i-1]*p[k]*p[j];
                    if(q < m[i,j])
                    {
                        m[i,j] = q;
                        s[i,j] = k;
                    }
                }
            }
        }
    }
}