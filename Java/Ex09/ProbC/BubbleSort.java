public class BubbleSort extends Strategy{
    public void sort(int[] data)
    {
        int length = data.length;
        for(int i = 0 ; i < length - 1 ; i++)
        {
            for( int j = 0 ; j <  length - 1 - i ;j++)
            {
                if(data[j] >= data[j+1])
                {
                    int tmp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = tmp;
                }
            }
        }
    }
}
