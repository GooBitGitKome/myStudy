public class C_Point
{
    public int x, y;

    public C_Point(int x,int y)
    {
        this.x = x;
        this.y = y;
    }
    public void print()
    {
        System.out.println("("+ x + ", " + y +")");
    }
    public double getDistance(C_Point p2)
    {
        return Math.sqrt(Math.abs(x - p2.x) * Math.abs(x - p2.x)
             + Math.abs(y - p2.y)* Math.abs(y - p2.y));
    }
}