package package_b;
import package_a.*;
public class B{
    public B(){
 A a = new A();
 a.print(); }
    public static void main(String[] args){
        new B();
 } }