public class B_MovingPoint
{
    protected int x, y;
    protected int vx,vy;
    public B_MovingPoint(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public void setVelocity(int vx, int vy)
    {
        this.vx = vx;
        this.vy = vy;
    }

    public void move()
    {
        x = x + vx;
        y = y + vy;
    }
    public void print()
    {
        System.out.println("("+ x + ", " + y +")");
    }
    public double getDistance(B_MovingPoint p2)
    {
        return Math.sqrt(Math.abs(x - p2.x) * Math.abs(x - p2.x)
             + Math.abs(y - p2.y)* Math.abs(y - p2.y));
    }
}