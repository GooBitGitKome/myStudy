public class XYComparator implements PointComparator{
    @Override
    public int compare(Point p1, Point p2) {
        // TODO Auto-generated method stub
        if(p1.getX() < p2.getX())return -1;
        if(p1.getX() == p2.getX())
        {
            if(p1.getY() < p2.getY())return -1;
            else if(p1.getY() == p2.getY())return 0;
            else return 1;
        }
        return 1;
    }
    
}
