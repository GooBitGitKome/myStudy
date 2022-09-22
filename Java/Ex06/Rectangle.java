public class Rectangle extends Shape{
    protected Point P[];
    protected int l;
    public Rectangle(Point p1,Point p3)
    {
        P = new Point[4];
        P[0] = p1;
        P[1] = new Point(p1.getX(), p1.getY());
        P[1].move(p3.getX() -p1.getX(),0);
        P[2] = p3;
        P[3] = new Point(p3.getX(),p3.getY());
        P[3].move(-(p3.getX() -p1.getX()),0);
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
