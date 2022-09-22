package ProbC;

public class StackOverflowException extends Exception {
    int errVal;
    public StackOverflowException(int errVal){
        this.errVal = errVal;
    }
    public String getMessage()
    {
        return "Overflow. "+errVal+" can not be pushed.";
    }
}
