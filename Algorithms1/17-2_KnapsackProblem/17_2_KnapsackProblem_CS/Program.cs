using System;
class Program
{
    struct Item{
        public int value,weight;
    };
    static int gMaxN = 100;
    static int gMaxW = 10000;
    static int gN;
    static int gW;
    static int DIAGONAL = 1;
    static Item[] items = new Item[gMaxN+1];
    static int[,] C = new int[gMaxN+1,gMaxW+1];//------------------IMPORTANT

    static void Main()
    {
        int maxValue;
        Input();
        maxValue = Compute();
        Console.WriteLine($"{maxValue}");
    }
    static int Compute()
    {
        //initialize------
        for(int i = 0;i<gW;i++)C[0,i] = 0;
        for(int i = 0;i<gN+1; i++)C[i,0] = 0;
        //----------------
        for(int i = 1; i <= gN ; i++)
        {
            for(int w = 1; w <=gW ;w++)
            {
                C[i,w] = C[i-1,w];
                if(items[i].weight >= w)continue;
                if(items[i].value + C[i-1,w-items[i].weight] > C[i-1,w])
                {
                    C[i,w] = items[i].value + C[i-1,w-items[i].weight];
                }
            }
        }
        return C[gN,gW];
    }
    static void Input()
    {
        string[] inf = Console.ReadLine().Split();
        gN = int.Parse(inf[0]);
        gW = int.Parse(inf[1]);//Knapsack Reguration
        for(int i = 1; i <= gN ; i++)
        {
            inf = Console.ReadLine().Split();
            items[i].value = int.Parse(inf[1]);// value
            items[i].weight = int.Parse(inf[0]);// weight
            //Console.WriteLine($"{items[i].value} {items[i].weight}");
        }
    }
//Puesue code------------------------
//     static void Knapsack()
//     {
//         for(int i = 1 ; i <= gN ; i++)
//         {
//             for(int w = 1; w <= gW; w++)
//             {
//                 if(items[i].weight < w)
//                 {
//                     if(items[i].weight + C[i-1,w-items[i].weight] > C[i-1,w])
//                     {
//                         C[i,w] = items[i].value+C[i-1,w-items[i].weight];
//                     }else{
//                         C[i,w] = C[i-1,w];
//                     }
//                 }else{

//                 }
//             }
//         }
//     }
//---------------------------------
}