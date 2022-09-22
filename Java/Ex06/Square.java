public class Square extends Shape{
    protected Point P[];
    protected int l;
    public Square(Point p1,int l)
    {
        P = new Point[4];
        P[0] = p1;
        P[1] = new Point(p1.getX(),p1.getY());
        P[1].move(l,0);
        P[2] = new Point(p1.getX(),p1.getY());
        P[2].move(l, l);
        P[3] = new Point(p1.getX(),p1.getY());
        P[3].move(0, l);
    }
    public void print(){ 
        super.print();
        for ( int i = 0; i < 4; i++ ) {
        if ( i > 0 ) System.out.print("-");
        System.out.print("(" + P[i].getX() + ", " + P[i].getY() + ")"); }
        System.out.println(); 
    }
    public void move(int dx, int dy){
        for ( int i = 0; i < 4; i++ ) P[i].move(dx, dy);
    } 
}
