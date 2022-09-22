public class MergeSort extends Strategy{
    public void sort(int[] data)
    {
        partition(data,0,data.length -1);
    }
    void merge(int[] data, int l , int m, int r)
    {
        int leftNum = m - l + 1;
        int rightNum = r - m;
        int[] L = new int[leftNum];
        int[] R = new int[rightNum];
        for (int i = 0; i < leftNum; i++)
            L[i] = data[l + i];
        for (int j = 0; j < rightNum; j++)
            R[j] = data[m + 1 + j];

        //Index initializing
        int i = 0, j = 0;
        int k = l;
        while(i < leftNum && j < rightNum)
        {
            if(L[i] <= R[j])
            {
                data[k++]  = L[i++];
            }else{
                data[k++]  = R[j++];
            }
        }
        //remain data copy to original array
        while(i < leftNum)
        {
            data[k++]  = L[i++];
        }
        while(j < rightNum)
        {
            data[k++]  = R[j++];
        }
    }
    void partition(int[] data,int l, int r)
    {
        if(l < r)
        {
            int m = l + (r-l) / 2;
            partition(data, l , m);
            partition(data, m+1, r);
            merge(data, l, m, r);
        }
    }
}
