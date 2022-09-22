public class C_MovingPoint extends C_Point
{
    public int vx,vy;
    public C_MovingPoint(int x, int y)
    {
        super(x,y);
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
}