package ProbC;

public class StackApplication {
public static void main(String[] args){
    Stack stack = new Stack(5);
    int[] a = {8, 0, 0, 5, 2, 4, 8, 6, 7, 0, 0};
    for ( int i = 0; i < a.length; i++ ){ 
        try
        {
            if ( a[i] == 0 ) {
                int v = stack.pop(); System.out.println("pop " + v);
            } else {
                stack.push(a[i]); 
                System.out.println("push " + a[i]);
            }
        } 
        catch (StackUnderflowException e)
        {
            System.out.println(e.getMessage()); 
        } 
        catch (StackOverflowException e)
        {
            System.out.println(e.getMessage()); 
        }
    } 
}
}
