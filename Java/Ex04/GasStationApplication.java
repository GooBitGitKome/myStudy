import java.util.Scanner;

public class GasStationApplication
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // the number of lanes
        int M = sc.nextInt(); // the number of infomation 
        GasStation gs = new GasStation(N,M);

        for(int i = 0 ; i < M ; i++)
        {
            int cmd = sc.nextInt(); // the number of lanes
            int nm = sc.nextInt(); // the number of infomation: 0 means to refuell 1 means to add a car to the fewest number lane
            switch(cmd)
            {
                case 0:
                System.out.println(gs.dequeue(nm));
                break;
                
                case 1:// enter the car into queue
                gs.enqueue(nm);
                break;
            }
        }

    }
}