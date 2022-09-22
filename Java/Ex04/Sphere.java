public class Sphere{
    double r;

    public Sphere(double radius)
    {
        this.r = radius;
    }
    double getHeightOfContactPoint(Sphere secondSphere)
    {
        double tmp;
        if (r < secondSphere.r)
        {
            tmp = r;
            r = secondSphere.r;
            secondSphere.r = tmp;
        }
        tmp = (r*(r - secondSphere.r)) / (r + secondSphere.r);
        return r - tmp;
    }
}