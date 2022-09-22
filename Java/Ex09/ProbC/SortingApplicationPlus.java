class SortingApplicationPlus{ private static int N = 50000;
    public SortingApplicationPlus(){ Judge judge = new Judge(N); int[] data = new int[N];
    SortingMachine machine = new AdvancedSortingMachine(new SelectionSort()); judge.setData(data);
    machine.sort(data);
    judge.validate(data);
    machine.setStrategy(new BubbleSort()); judge.setData(data); machine.sort(data); judge.validate(data);
    machine.setStrategy(new MergeSort()); judge.setData(data); machine.sort(data); judge.validate(data);
    }
    public static void main(String[] args){ new SortingApplicationPlus();
    } }