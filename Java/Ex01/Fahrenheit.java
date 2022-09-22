import java.util.Scanner; // API to use the Scanner object class Fahrenheit{
class Fahrenheit
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in); // A reference to a Scanner object 
        int F = sc.nextInt(); // read an integer from the std. input 
        // you code
        double C = ((double)5/9) * ( F - 32);
        System.out.println(String.format("%.4f",C));
    } 
}