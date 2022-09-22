using System;
class Program
{
    //Global variables
    public static int maxHeapLength = 2000001;
    public static int[] A_max = new int[maxHeapLength];// 1 origine
    public static int[] B_min = new int[maxHeapLength];// 1 origine
    public static int heapSize = 0;
    public static int N=0;
    static void Main()
    {
        for(int i = 1 ; i < maxHeapLength;i++)A_max[i] = int.MinValue;//initialize
        for(int i = 1 ; i < maxHeapLength;i++)B_min[i] = int.MaxValue;//initialize
        N = int.Parse(Console.ReadLine());
        string[] num = Console.ReadLine().Split();
        for( int i = 0 ; i < N ; i++)
        {
            Insert(int.Parse(num[i]));
        }
        int max;
        int[] ans = new int[N+1];
        for(int i = N; (max = ExtractMax()) != -1 ; i--)
        {
            Console.Write($"{max} ");
            //ans[i] = max;
        }
        // for(int i = 1 ; i <= N ; i++){
        //     Console.Write($"{ans[i]}");
        // }
        // Console.WriteLine();
    }
    static int Parent(int i){return i /2;}
    static int Left(int i){return 2*i;}
    static int Right(int i){return 2*i + 1;}
    static void Display()
    {
        for(int i =  1; i <= heapSize ; i++)
        {
        }
        Console.WriteLine();
        for(int i =  1; i <= heapSize ; i++)Console.Write($"{B_min[i]} "); 
        Console.WriteLine();
    }
    static void MaxHeapfy(int i)
    {
        int l = Left(i);//i is parent of this
        int r = Right(i);//i is parent of this
        int largest = 0;//reserve the most high value
        if(l <= heapSize && A_max[l] > A_max[i])
        {
            largest = l;
        }else largest = i;
        if(r<= heapSize && A_max[r] > A_max[largest])
        {
            largest = r;
        }
        if(largest != i)//in the case that children is higher than parent i
        {
            int tmp = A_max[i];
            A_max[i] = A_max[largest];
            A_max[largest] = tmp;
            MaxHeapfy(largest);//call recursively
        }
    }
    static void MaxHeapIncreaseKey(int index , int key)
    {
        int tmp;
        while(index > 1 && A_max[Parent(index)] < A_max[index])
        {
            tmp = A_max[index];
            A_max[index] = A_max[Parent(index)];
            A_max[Parent(index)] = tmp;
            index = Parent(index);
        }
    }
    static void BuildMaxHeap()
    {
        for(int i = heapSize / 2 ; i >=1 ;i--)
        {
            MaxHeapfy(i);
        }
    }
    static void Insert(int key)
    {
        if(heapSize < maxHeapLength)
        {
            heapSize++;
            A_max[heapSize] = key;//preparation
            B_min[heapSize] = key;
            MaxHeapIncreaseKey(heapSize,key);
            //BuildMinHeap();
        }
    }
    static int ExtractMax()
    {
        if(heapSize >= 1)
        {
            int max = A_max[1];
            A_max[1] = A_max[heapSize];//一番末尾のノードをトップに仮挿入後、アジャストする
            heapSize--;
            MaxHeapfy(1);
            return max;
        }
        return -1;//error
    }
}