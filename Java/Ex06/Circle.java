public class Circle extends Shape{
    protected Point p1;
    protected int r;
    public Circle(Point p1, int r)
    { 
        this.p1 = p1;
        this.r = r;
    }
    public void print(){ 
        super.print();
        System.out.print("(" + p1.getX() + ", " + p1.getY() + ")"); 
        System.out.print(" radius = "+ r); 
        System.out.println(); 
    }
    public void move(int dx, int dy){
        p1.move(dx, dy);
    } 
}
