public class DeluxeCar extends AdvancedCar{
    DeluxeCar(int beginWork,int finWork, int totalDistance, int hoursPassengersOn, double fuelEconno, double fuelEconnoOnAircon)
    {
        super(beginWork, finWork, totalDistance, hoursPassengersOn,fuelEconno,fuelEconnoOnAircon);
    }
    
    
    double getFuelConsumptionNewRegulations(){
        int workTime = finWork -beginWork;
        double cnsmpFuel = ((totalDistance * (1 - (hoursPassengersOn / workTime)))) / fuelEconno;
        double cnsmpFuel2 = ((totalDistance * ((hoursPassengersOn / workTime)))) / fuelEconno;
        return cnsmpFuel + cnsmpFuel2;
    }
}
