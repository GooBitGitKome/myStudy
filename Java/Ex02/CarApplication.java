class CarApplication{
    public static void main(String[] args){
        Car car1 = new Car(); 
        Car car2 = new Car(); 
        Car car3 = new Car();
        car1.speedUp(100); 
        car2.speedUp(80); 
        car3.speedUp(40);
        car1.travelledTimeUp(3); 
        car2.travelledTimeUp(7); 
        car3.travelledTimeUp(10);
        car1.printStateTank(); 
        car2.printStateTank(); 
        car3.printStateTank();
    } 
}