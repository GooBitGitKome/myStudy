class Stack
{
    private int[] array = new int[100];//1 origine 
    private int head = -1;//
    void push(int in)
    {
        if(head< array.length)
        {
            head++;
            array[head] = in;
        }
    }
    int pop()
    {
        int tmp = 0;
        if(head >= 0)
        {
            tmp = array[head];
            head--;
        }
        return tmp;
    }
    int getHead()
    {
        return head;
    }
}