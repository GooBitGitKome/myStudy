public class Rectangle extends Point
{
    Point p1,p3;
    public Rectangle(Point p1, Point p3)
    {  
        super(0, 0);
        this.p1 = p1;
        this.p3 = p3;
    }
    public int getArea()
    {
        int pp1 = (p1.getX() - p3.getX());
        int pp3 = (p1.getY() - p3.getY());
        return pp1 * pp3;
    }
    public boolean isSmallerThan(Relatable other)
    {
        Rectangle otherPoint = (Rectangle)other;
        if(this.getArea() < otherPoint.getArea())
        {
            return true;
        }
        return false;
    }
}