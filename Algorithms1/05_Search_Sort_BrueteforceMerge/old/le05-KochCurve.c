#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
}POINT;

 int tes = 0;
void makeCurve(int n,POINT,POINT);
int main()
{
    int n;
    POINT L_Point;
    POINT R_Point;
    L_Point.x = 0;
    L_Point.y = 0;
    R_Point.x = 100;
    R_Point.y = 0;

    scanf("%d", &n);
    makeCurve(n,L_Point,R_Point);
    printf("%lf %lf\n",R_Point.x,R_Point.y);
    return 0;
}

void makeCurve( int n , POINT L_Point , POINT R_Point )
{
    //create 3 points on the line without the both ends we already know in [edge]
    POINT new_M_L_Point;
    POINT new_M_Point;
    POINT new_M_R_Point;
    double seta;
    double length = sqrt( fabs((L_Point.x - R_Point.x) * (L_Point.x - R_Point.x)) + fabs((L_Point.y - R_Point.y) * (L_Point.y - R_Point.y))) / 3;
    new_M_L_Point.x = (2 * L_Point.x +  R_Point.x) / 3;
    new_M_L_Point.y = (2 * L_Point.y + R_Point.y) / 3;
    new_M_Point.x = length * cos(M_PI / 3) + new_M_L_Point.x;

    //頂点生成時に直線が水平でない場合、６０度回転に対して、計算に必要な角度を調整する
    if((L_Point.y - R_Point.y) < 0){
        seta = (R_Point.y - L_Point.y) / length;
    }else{
        seta = -1 * ((L_Point.y - R_Point.y) / length);
    }
    new_M_Point.y = length * sin((M_PI / 3) + asin(seta)) + new_M_L_Point.y;
    new_M_R_Point.x = (L_Point.x +  2 * R_Point.x) / 3;
    new_M_R_Point.y = (L_Point.y + 2 * R_Point.y) / 3;
    if(n <=0){
        tes++;
        printf("%d : \n", tes);
        printf("%.8lf %.8lf\n",L_Point.x,L_Point.y);
    }else{
        n--;
        makeCurve(n,L_Point,new_M_L_Point);//left
        makeCurve(n, new_M_L_Point, new_M_Point);//middle
        makeCurve(n, new_M_Point, new_M_R_Point);//right
        makeCurve(n, new_M_R_Point,R_Point);
        
    }
}