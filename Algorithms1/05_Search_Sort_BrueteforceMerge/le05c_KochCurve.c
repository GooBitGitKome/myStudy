#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Structure
struct Vector{
    double x;
    double y;
};
//Prototype Declaration
int KochCurve(struct Vector p1,struct Vector p4,int n);
//Global Variables
int main()
{
    //initializing-----------------------------------------
    int n;
    struct Vector p1;
    p1.x = 0;
    p1.y = 0;
    struct Vector p4;
    p4.x = 100;
    p4.y = 0;
    //initializing-----------------------------------------

    scanf("%d",&n);
    printf("%.8lf %.8lf\n", p1.x,p1.y);
    KochCurve(p1,p4,n);
    printf("%.8lf %.8lf\n", p4.x,p4.y);
    return 0;
}

int KochCurve(struct Vector p1,struct Vector p4,int n)
{
    struct Vector p2,p3;
    struct Vector newVertex;
    //end condition
    if(n == 0)return 0;
    //divide the range[l,r] into three of length as the vector of p1 p2 p3 p4
    //first point on between p1 and p4;
    p2.x = (2*p1.x + p4.x) / 3;
    p2.y = (2*p1.y + p4.y) / 3;
    
    p3.x = (p1.x + 2 * p4.x) / 3;
    p3.y = (p1.y + 2 * p4.y) / 3;

    //make the new vertex as long as the length between p2 and p3
    //newVertex and p2 and p3 make basic triangle
    // double length = sqrt(pow(p3.x - p2.x,2) + pow(p3.y - p2.y,2));
    double seta = 60 * M_PI / 180;// make radiun degree
    //seta += (p4.y == 0) ? 0: atan(p4.x / p4.y);
    // //in the point of p2, this is calclated
    // newVertex.x =  p2.x + length * cos(seta);
    // newVertex.y =  p2.y + length * sin(seta);
    newVertex.x = (p3.x - p2.x) * cos(seta) - (p3.y - p2.y) * sin(seta) + p2.x;
    newVertex.y = (p3.x - p2.x) * sin(seta) + (p3.y - p2.y) * cos(seta) + p2.y;

    KochCurve(p1,p2,n-1);
    printf("%.8lf %.8lf\n", p2.x,p2.y);
    KochCurve(p2,newVertex,n-1);
    printf("%.8lf %.8lf\n", newVertex.x,newVertex.y);
    KochCurve(newVertex,p3,n-1);
    printf("%.8lf %.8lf\n", p3.x,p3.y);
    KochCurve(p3,p4,n-1);
    

    return 0;
}