class Point{
    protected int x;
    protected int y;
    
    public Point(int x, int y){
        this.x = x;
        this.y = y; 
    }
    public boolean equals​(Object obj)
    {
        if(obj == null)return false;
        if(super.equals(obj))return true;
        Point p = (Point)obj;
        if( x == p.x && y == p.y)
        {
            return true;
        }
        return false;
    }
    protected int getX(){return x;}
    protected int getY(){return y;}
    protected void move(int a, int b){x += a; y +=b;}

 }