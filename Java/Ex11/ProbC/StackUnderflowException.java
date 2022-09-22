package ProbC;

public class StackUnderflowException extends Exception {
    public String getMessage()
    {
        return "Underflow. There is no element in the stack.";
    }
}
