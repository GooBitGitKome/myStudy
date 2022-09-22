public class B_Point
{
    protected int x, y;

    public B_Point(int x,int y)
    {
        this.x = x;
        this.y = y;
    }
    public void print()
    {
        System.out.println("("+ x + ", " + y +")");
    }
    public double getDistance(B_Point p2)
    {
        return Math.sqrt(Math.abs(x - p2.x) * Math.abs(x - p2.x)
             + Math.abs(y - p2.y)* Math.abs(y - p2.y));
    }
}