using System;
class Program
{
    static long[] fib = new long[44];
    static void Main()
    {
        Console.WriteLine($"{Fibonach(int.Parse(Console.ReadLine()))}");        
    }
    static long Fibonach(int n)
    {
        
        if(n == 0 || n == 1)
        {
            fib[n] = 1;
            return fib[n];
        }
        return fib[n] != 0 ? fib[n] : fib[n] = Fibonach(n-1) + Fibonach(n-2);
    }
}
