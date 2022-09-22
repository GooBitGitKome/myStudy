using System;
class Program
{
    static int NMAX =20;
    static int QMAX = 200;
    static int[] inputs = new int[NMAX];
    static int[] bitFlg = new int[NMAX];
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        string[] tmp = Console.ReadLine().Split();
        for(int i = 0; i < n ; i++)
        {
            inputs[i] = int.Parse(tmp[i]);
        }
        int m = int.Parse(Console.ReadLine());
        string[] tmp2 = Console.ReadLine().Split();
        foreach(string q in tmp2)
        {
            
            if(Solve(n - 1,int.Parse(q)))Console.WriteLine("yes");
            else Console.WriteLine("no");    
        }
    }
    static bool Solve(int n, int m)
    {
        if(m == 0)return true;
        if(n < 0)return false;
        return Solve(n -1 , m - inputs[n]) || Solve(n - 1,m);        
    }
}