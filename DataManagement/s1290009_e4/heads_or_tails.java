import java.util.*;
public class heads_or_tails{
    private static int TIMES;
    heads_or_tails()
    {
        TIMES = 3;
    }
    public static void main(String[] args){
        
        new heads_or_tails().tossCoin(TIMES);
    }

    public void tossCoin(int times){
        int cntHead,cntTails;
        String name;
        cntHead = cntTails = 0;
        System.out.println("Who are you?");
        System.out.print("> ");
        name = new Scanner(System.in).nextLine();
        System.out.println("Hello, "+name +"!");
        System.out.println("Tossing a coin...");
        for(int i = 0 ; i < times; i++)
        {
            //0 is head, 1 is tail
            if((new Random().nextInt() % 2) == 0)
            {
                cntHead++;
                System.out.println(String.format("Round %d: Heads",i));
            }else{
                cntTails++;
                System.out.println(String.format("Round %d: Tails",i));
            }
        }
        System.out.println(String.format("Heads: %d, Tails: %d", cntHead, cntTails));
        if(cntHead > cntTails)
        {
            System.out.println(String.format("%s won!",name));
        }else{
            System.out.println(String.format("%s lost!",name));
        }
    }
}