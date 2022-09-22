public class GasStation
{
    private static int MAX = 10000;
    private int N; // the number of lanes
    private int M; // the number of infomation 
    private int[] amount;
    private int[] head;
    private int[] tale;
    private int[][] queue;// Lane arrays of the number of cars 
    public GasStation(int N , int M)
    {
        this.N = N;
        this.M = M;
        head =  new int[this.N + 1];//each head 
        tale =  new int[this.N + 1];//each tale
        amount =  new int[this.N + 1];//each number of lane 
        queue = new int[this.N + 1][MAX];// only queue[] is 1 origine
        for(int i = 0 ; i <= this.N ; i++){
            head[i] = tale[i] = 0;
            amount[i] = 0;
        }
    }
    int dequeue(int lane)
    {
        int tmp = queue[lane][head[lane]];
        head[lane] = (head[lane] + 1 ) % MAX;
        amount[lane]--;
        return tmp;
    }
    
    void enqueue(int carNumber)
    {
        //carNumber enters most fewest queue[]
        int lane = 1;// 1 origine and from 1 to N+1
        int fewestLane = amount[1];
        for(int i = 2 ; i <= N ; i++)// search fewest lane
        {
            if(fewestLane > amount[i])
            {
                lane = i;//fewestLane;
                fewestLane = amount[i];
                if(amount[i] == 0 )break;
            }
        }
        amount[lane]++;
        queue[lane][tale[lane]] = carNumber;
        tale[lane] = (tale[lane] + 1) % MAX;
        //System.out.println(lane + " "+ tale[lane] + " "+ carNumber +" "+ amount[lane]);

    }
}