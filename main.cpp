
//https://www.nowcoder.com/ta/acm-solutions/review?tpId=20&tqId=11221&query=&asc=true&order=&page=1    跳远题目:

#include <cstdio>
#include <cmath>
const double eps=1e-9;
double h1,h2,d1,d2,a,b;
bool check(double x0){
    double y;
    if(x0<d1){
        double y0=h1-a*x0*x0;
        y=y0-b*(d1-x0)*(d1-x0);
    }
    else if(x0-eps>d2) return false;
    else y=h1-a*d1*d1;
    return y+eps>=h2;
}
int main(){
    while(scanf("%lf %lf %lf %lf %lf %lf",&h1,&h2,&d1,&d2,&a,&b)==6){// 一直读取6个.直到

        //

        double A=a+b;
        double B=-2.*b*d2;
        double C=b*d2*d2-h1;
        double det=B*B-4*A*C;
        bool ans=false;
        if(det+eps>=0){
            det=sqrt(fabs(det));
            double x1=(-B-det)/(2*A);
            double x2=(-B+det)/(2*A);
            if(x1+eps>=0.) ans=ans||check(x1);
            if(x2+eps>=0.) ans=ans||check(x2);
        }
        puts(ans?"Yes":"No");
    }
    return 0;
}