import java.util.Random;
public class CounterApplication{
    public static void main(String[] args) {
        Random rand = new Random();
        Animal[] a = new Animal[rand.nextInt(5) + 5]; 
        for ( int i = 0; i < a.length; i++ ) {
            a[i] = (rand.nextInt(2) == 0) ? new Dog() : new Cat(); 
        }
        for (int i = 0; i < a.length; i++) a[i].noise();
        System.out.println(Dog.getCount() + " woofs and " + Cat.getCount() + " meow");
    } 
}