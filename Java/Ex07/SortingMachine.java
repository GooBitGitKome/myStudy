public class SortingMachine {
    public void sort(Point[] p)
    {
        Point tmp;
        int n = p.length;
        for (int i = 0; i < n - 1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (!p[j].isSmallerThan(p[j + 1])) {
                    // swap arr[j+1] and arr[j]
                    Point temp = p[j];
                    p[j] = p[j + 1];
                    p[j + 1] = temp;
                }
            }
        }
    } 
    
}
