public class SelectionSort extends Strategy{
    public void sort(int[] data)
    {
        int length = data.length;
        for(int i = 0 ; i < length-1 ; i++)
        {
            int minIndex = i;
            for(int j = i+1 ; j < length; j++)
            {
                if(data[minIndex] > data[j])minIndex = j;
            }
            int tmp = data[minIndex];
            data[minIndex] = data[i];
            data[i] = tmp;
        }
    }
}
