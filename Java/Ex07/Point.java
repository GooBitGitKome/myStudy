public class Point implements Relatable{
    protected int x, y;
    public Point(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    public boolean isSmallerThan(Relatable other)
    {
        Point otherPoint = (Point)other;
        if(this.x < otherPoint.x)
        {
            return true;
        }else if(this.x == otherPoint.x)
        {
            if(this.y < otherPoint.y)return true;
        }
        return false;
    }
    public int getY()
    {
        return this.y;
    }
    public int getX()
    {
        return this.x;
    }
    public void print()
    {
        System.out.println("("+ this.x +", "+ this.y +")");
    }
}
