class TwirlingRobotApplication{
    public static void main(String[] args){
        TwirlingRobot r1 = new TwirlingRobot(); 
        TwirlingRobot r2 = new TwirlingRobot();
        r1.setId(1); 
        r2.setId(2);
        r1.initialize(0, 0, 1); 
        r2.initialize(7, 4, 3);
        for ( int j = 4; j >= 1; j-- ){ 
            for ( int i = 0; i < j; i++ ) {
                r1.move();
                r2.move();
            }
            if ( j % 2 == 0 ){ 
                r1.turnRight(); 
                r2.turnRight();
            } else { 
                r1.turnLeft(); r2.turnLeft();
            } 
        }
        r1.printLocation();
        r2.printLocation(); 
    }
}