import java.util.Scanner;
public class FuelConsumptionApplication{ 
    public static final int N = 100; 
    private SimpleCar[] taxis;
    private int numberOfTaxi;
    public FuelConsumptionApplication(){ 
        taxis = new SimpleCar[N];
        Scanner sc = new Scanner(System.in); 
        while( sc.hasNext() ){
            int begin = sc.nextInt(); 
            int end = sc.nextInt();
            int traveled = sc.nextInt(); 
            int passenger = sc.nextInt(); 
            String maker = sc.next();
            if ( maker.equals("Honda") ){ 
                taxis[numberOfTaxi++] = new DeluxeCar(begin,
                    end, traveled, passenger, 14.0, 10.5);
            } else if ( maker.equals("Toyota") ){ 
                taxis[numberOfTaxi++] = new AdvancedCar(begin,
                end, traveled, passenger, 15.5, 9.5);/* your code */;
            } else if ( maker.equals("Nissan") ){ 
                taxis[numberOfTaxi++] = new SimpleCar(begin,
                end, traveled, passenger, 13);/* your code */;
            } else if ( maker.equals("Subaru") ){ 
                taxis[numberOfTaxi++] =  new DeluxeCar(begin,
                end, traveled, passenger, 10.5, 6);/* your code */;
            } 
        }
    }
    public void calculateFuelConsumption(){ 
        double oldRegulation = 0;
        double newRegulation = 0;
        for ( int i = 0; i < numberOfTaxi; i++ ){
            oldRegulation += taxis[i].getFuelConsumptionOldRegulations();
            newRegulation += taxis[i].getFuelConsumptionNewRegulations(); 
        }
        System.out.println("Old regulation: " + oldRegulation ); 
        System.out.println("New regulation: " + newRegulation ); 
        System.out.println("Saved: " + (oldRegulation - newRegulation) );
    }
    public static void main(String[] args){
        FuelConsumptionApplication app = new FuelConsumptionApplication(); app.calculateFuelConsumption();
    } 
}