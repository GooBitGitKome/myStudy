import java.io.*;
public class ListOfNumbers {
    private static final int SIZE = 10; private int[] vector;
    int i;
    public ListOfNumbers () {
        vector = new int[SIZE];
        for (int i = 0; i < SIZE; i++) vector[i] = i;
    }
    public void writeList() throws ArrayIndexOutOfBoundsException{
        try{
            for (i = 0; i <= SIZE; i++){
            System.out.println("Value at: " + i + " = " + vector[i]); }
        }
        catch(ArrayIndexOutOfBoundsException e)
        {
            System.err.println("Entering catch block.");
            getMessage(i);
        }
        finally
        {
            System.out.println("Entering finally block.");
        }
    }
    public void getMessage(int i)//for using it in catch clauses.
    {
        System.err.println("Caught ArrayIndexOutOfBoundsException: " + i);
    }
    public static void main(String[] args)
    { 
        ListOfNumbers l = new ListOfNumbers(); l.writeList();
    }
}
