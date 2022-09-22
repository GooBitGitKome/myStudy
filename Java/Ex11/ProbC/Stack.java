package ProbC;
public class Stack{
    int head = 0;
    static int MAX;
    int[] A;
    public Stack(int i)
    {
        A = new int[i];//initializing the array A
        MAX = i;
    }
    public int pop() throws StackUnderflowException{
        if(head -1 < 0)throw new StackUnderflowException();
        return A[--head];
    }

    public void push(int x) throws StackOverflowException{
        if(head+1 > MAX)throw new StackOverflowException(x);
        A[head++] = x;
    }

    public boolean isEmpty() {
        if(head == 0)return true;
        return false;
    }
}
