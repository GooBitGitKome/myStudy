class B_TestObjectApplication{
    public static void main(String[] args){
        B_Point p1 = new B_Point(10, 10);
        B_Point p2 = new B_Point(10, 20); 
        B_MovingPoint m1 = new B_MovingPoint(0, 0); 
        B_MovingPoint m2 = new B_MovingPoint(0, 0); 
        m1.setVelocity(2, 3); 
        m2.setVelocity(-4, 2);
        for ( int i = 0; i < 10; i++ ) { 
            m1.move();
            m2.move(); 
        }
        p1.print(); 
        p2.print(); 
        m1.print(); 
        m2.print();
        System.out.println(p1.getDistance(p2));
        System.out.println(m1.getDistance(m2)); 
    }
 }
 