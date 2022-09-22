class Car
{
    double speed = 0;
    double fuelConsumption = 12;
    double gasTank = 60;
    double travelledTime = 0;

    void speedUp(int n){speed += n;}
    void applyBrakes(){}
    void travelledTimeUp(int n){travelledTime = n;}
    void printStateTank()
    {
        double wasteOilPerHour = (double)speed / fuelConsumption; // liter/ hour
        double wasteOil = wasteOilPerHour * travelledTime;
        double temp;
        if(wasteOil <= gasTank)
        {
            gasTank -= wasteOil;
        }else{
            gasTank = 0;
        }
        System.out.println(gasTank);
    }
}