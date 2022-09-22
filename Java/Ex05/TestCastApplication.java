public class TestCastApplication
{
    public static void main(String args[])
    {
        C_MovingPoint o1 = new C_MovingPoint(0,0);
        C_Point o2 = new C_MovingPoint(3,4);
        C_MovingPoint o3 = (C_MovingPoint)o2;
        o1.print();
        o2.print();
        o3.print();
        System.out.println(o1.getDistance(o2));
        System.out.println(o2.getDistance(o3));
    }
}