public class AdvancedSortingMachine extends SortingMachine{

    public AdvancedSortingMachine(Strategy s) {
        super(s);
    }
    public void sort(int[] data){ 
        System.out.println(strategy.getClass().getName()); 
        double startTime = System.currentTimeMillis();
        strategy.sort(data);
        double stopTime = System.currentTimeMillis();
        System.out.println("time:"+ (int)(stopTime - startTime) + " msec");
    } 
}
