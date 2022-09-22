using System;
class  Program
{
    public struct dataSet{
        public char key;
        public int num;
        public int inputOrder = 0;
    };
    static unsafe void Main()
    {
        int n = int.Parse(Console.ReadLine());
        dataSet[] A = new dataSet[n];
        string[] tmp;
        for(int i = 0 ; i < n ; i++)
        {
            tmp = Console.ReadLine().Split();
            A[i].key = tmp[0][0];
            A[i].num = int.Parse(tmp[1]);
            A[i].inputOrder = i + 1;
        }
        fixed(dataSet* pointA = &A[0])
        {
            QuickSort(pointA,0,n-1);
        }
        int order = 0;
        int stableFlg = 1;
        foreach(dataSet tmpA in A)
        {
            if(order < tmpA.inputOrder && stableFlg == 1)order = tmpA.inputOrder;
            else stableFlg = -1;
        }
        if(stableFlg == 1)Console.WriteLine("Stable");
        else Console.WriteLine("Not stable");
        foreach(dataSet tmpA in A)
        {

            Console.WriteLine($"{tmpA.key} {tmpA.num}");
        }
    }
    static unsafe void QuickSort(dataSet* A, int p, int r)
    {
        if(p<r)
        {
            int q = MakePartition(A,p,r);
            QuickSort(A,p, q-1);
            QuickSort(A,q+1,r);
        }

    }
    static unsafe int MakePartition(dataSet* A,int p, int r)
    {
        int x = A[r].num;//You should use any other value for the more safe sorting
        int i = p -1;
        dataSet tmp;
        for(int j = p; j < r; j++)
        {
            if(A[j].num <= x)
            {
                i++;
                tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;
            }
        }
        i++;
        tmp = A[r];
        A[r] = A[i];
        A[i] = tmp;
        return i;
    }
}