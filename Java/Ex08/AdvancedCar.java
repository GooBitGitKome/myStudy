public class AdvancedCar extends SimpleCar{
    protected double fuelEconnoOnAircon;
    AdvancedCar(int beginWork,int finWork, int totalDistance, int hoursPassengersOn, 
                                                    double fuelEconno, double fuelEconnoOnAircon)
    {
        super(beginWork, finWork, totalDistance, hoursPassengersOn,fuelEconno);
        this.fuelEconnoOnAircon = fuelEconnoOnAircon;
    }
    double getFuelConsumptionOldRegulations(){
        double cnsmpFuel = totalDistance / fuelEconnoOnAircon;
        return cnsmpFuel;
    }
    double getFuelConsumptionNewRegulations(){
        return getFuelConsumptionOldRegulations();
    }
}
