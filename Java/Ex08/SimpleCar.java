
public class SimpleCar{
    protected int beginWork;
    protected int finWork;
    protected int totalDistance;
    protected int hoursPassengersOn;
    protected double fuelEconno;
    SimpleCar(int beginWork,int finWork, int totalDistance, int hoursPassengersOn, double fuelEconno)
    {
        this.beginWork = beginWork;
        this.finWork = finWork;
        this.totalDistance = totalDistance;
        this.hoursPassengersOn = hoursPassengersOn;
        this.fuelEconno = fuelEconno;
    }
    double getFuelConsumptionOldRegulations(){
        int workTime = finWork - beginWork;
        double cnsmpFuel =totalDistance / fuelEconno;
        return cnsmpFuel;
    }
    double getFuelConsumptionNewRegulations(){
        return getFuelConsumptionOldRegulations();
    }
}
