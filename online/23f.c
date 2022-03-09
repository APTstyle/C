#include<stdio.h>
#include<math.h>
double a=0;

double f11(double x){
   // printf("%.12lf\n", a);
    double t;
    t=sqrt(a-x*x);
    return t;
}
double f22(double x){
    double t;
    t=(a*x*x*x+7*x)/sqrt(a+x);
    return t;
}


double f1(double p,double q,double err){
    double x1,x2,n1=1,n2=2,a1=0,a2=0,i=1;
    while(1){
    i=1;
    x1=(q-p)/n1;
    x2=(q-p)/n2;


    a1+=f11(q);
    a1+=f11(p);
    //printf("%.12lf\n",f11(1));
    while(q>(p+i*x1)){
        a1+=2*f11(p+i*x1);
        i++;
    }
    i=0;
    a1=(a1*x1)/2;

    a2+=f11(q);
    a2+=f11(p);
    while(q>(p+i*x2)){
        a2+=2*f11(p+i*x2);
        i++;
    }
    i=0;
    a2=(a2*x2)/2;

    //printf("%.12lf\n",a2);
    if(a2-a1<pow(10,-err)){
        break;
    }
    else{

        n1*=2;
        n2*=2;
        a1=0;a2=0;
    }

    }
    return a2;
}
double f2(double p,double q,double err){
    double x1,x2,n1=1,n2=2,a1=0,a2=0,i=1;
    while(1){
    i=1;
    x1=(q-p)/n1;
    x2=(q-p)/n2;


    a1+=f22(q);
    a1+=f22(p);
    //printf("%.12lf\n",f11(1));
    while(q>(p+i*x1)){
        a1+=2*f22(p+i*x1);
        i++;
    }
    i=0;
    a1=(a1*x1)/2;

    a2+=f22(q);
    a2+=f22(p);
    while(q>(p+i*x2)){
        a2+=2*f22(p+i*x2);
        i++;
    }
    i=0;
    a2=(a2*x2)/2;

    //printf("%.12lf\n",a2-a1);
    if((a1-a2)<pow(10,-err)){
        break;
    }
    else{

        n1*=2;
        n2*=2;
        a1=0;a2=0;
    }

    }
    return a2;
}

int main(void){ //f1(x) =((a-x^2))^(1/2) f2(x) = (ax^3 + 7x)/(a+x)^(1/2)
    while(1){
    //printf("%lf",pow(10,-8));
    double p=0,q=0,err=0,way,fin=0,ans=0;
    scanf("%lf",&way);
    if(way==0){
        break;
    }
    scanf("%lf",&a);
    scanf("%lf",&p);
    scanf("%lf",&q);
    scanf("%lf",&err);

    //printf("%lf",f11(1));
    if(way==1){
        ans=f1(p,q,err);
        printf("%.12lf\n",ans);
    }
    else if(way==2){
        ans=f2(p,q,err);
        printf("%.12lf\n",ans);
    }
}
}
