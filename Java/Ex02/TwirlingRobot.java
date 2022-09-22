class TwirlingRobot
{
    private int x = 0;
    private int y = 0;
    private int dir = 0;
    private int id = 0;

    void setId(int i)
    {
        id = i;
    }
    void initialize(int a, int b, int c)
    {
        x = a;
        y = b;
        dir = c;
    }
    void turnLeft()
    {
        dir -= 1;
        if(dir < 0)dir = 3;
    }
    void turnRight()
    {
        dir = (dir + 1) % 4;
    }
    void move()
    {
        switch(dir)
        {
            case 0:
                y--;
                break;
            case 1:
                x++;
                break;
            case 2:
                y++;
                break;
            case 3:
                x--;
                break;
        }
    }
    void printLocation()
    {
        System.out.println(String.format("Robot %d is at (%d, %d)",id,x,y));
    }
}