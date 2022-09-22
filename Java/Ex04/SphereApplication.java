import java.util.Scanner;
class SphereApplication{
   public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Sphere s1 = new Sphere(sc.nextDouble());
        Sphere s2 = new Sphere(sc.nextDouble()); 
        System.out.println(s1.getHeightOfContactPoint(s2));
    } 
}