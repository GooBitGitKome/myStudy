public class Queue implements OpenList{
    int head = 0;
    int tail = 0;
    @Override
    public int pop() {
        // TODO Auto-generated method stub
        return A[head++];
    }

    @Override
    public void push(int x) {
        // TODO Auto-generated method stub
        A[tail++] = x;
    }
    @Override
    public boolean isEmpty() {
        // TODO Auto-generated method stub
        if(tail == head)return true;
        return false;
    }
}
