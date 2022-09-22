public class Stack implements OpenList {
    int head = 0;

    @Override
    public int pop() {
        // TODO Auto-generated method stub
        return A[--head];
    }

    @Override
    public void push(int x) {
        // TODO Auto-generated method stub
        A[head++] = x;
    }

    @Override
    public boolean isEmpty() {
        // TODO Auto-generated method stub
        if(head == 0)return true;
        return false;
    }
}
