class C_TestObjectApplication{
    public static void main(String[] args){
        C_Point p1 = new C_Point(10, 10);
        C_Point p2 = new C_Point(10, 20); 
        C_MovingPoint m1 = new C_MovingPoint(0, 0); 
        C_MovingPoint m2 = new C_MovingPoint(0, 0); 
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
        System.out.println(p1.getDistance(m1)); 
        System.out.println(p2.getDistance(m2));
    }
 }
 