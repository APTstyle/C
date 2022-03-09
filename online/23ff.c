#include<stdio.h>
#include<math.h>
double a=0;

double felf(double x){
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
    double x1,x2,n1=1,n2=2,a1=0,a2=0,i=1,t=0,t1=0;
    x1=(q-p)/n1;
    x2=(q-p)/n2;
    if(felf(q)<0) a1-=felf(q);
    else a1+=felf(q);
    if(felf(p)<0) a1-=felf(p);
    else a1+=felf(p);
    //printf("%.12lf\n",felf(1));
    while(q>(p+i*x1)){
        t1=2*felf(p+i*x1);
        if(t1<0){
            a1-=t1;
        }
        else a1+=t1;
        i++;
    }
    i=1;
    a1=(a1*x1)/2;

    while(1){
    if(felf(q)<0) a2-=felf(q);
    else a2+=felf(q);
    if(felf(p)<0) a2-=felf(p);
    else a2+=felf(p);
    while(q>(p+i*x2)){
        t1=2*felf(p+i*x2);
        if(t1<0){
            a2-=t1;
        }
        else a2+=t1;
        i++;
    }
    i=1;
    a2=(a2*x2)/2;

    //printf("%.12lf\n",a2);
    if(a2-a1>0) t =a2-a1;
    else t=a1-a2;
    if(t<pow(10,-err)){
        break;
    }
    else{
        x2/=2;
        a1=a2;a2=0;
    }

    }
    return a2;
}
double f2(double p,double q,double err){
    double x1,x2,n1=1,n2=2,a1=0,a2=0,i=1,t=0,t1;
    x1=(q-p)/n1;
    x2=(q-p)/n2;
    if(f22(q)<0) a1-=f22(q);
    else a1+=f22(q);
    if(f22(p)<0) a1-=f22(p);
    else a1+=f22(p);
    //printf("%.12lf\n",felf(1));
    while(q>(p+i*x1)){
        t1=2*f22(p+i*x1);
        if(t1<0){
            a1-=t1;
        }
        else a1+=t1;
        i++;
    }
    i=1;
    a1=(a1*x1)/2;

    while(1){
    if(f22(q)<0) a2-=f22(q);
    else a2+=f22(q);
    if(f22(p)<0) a2-=f22(p);
    else a2+=f22(p);
    while(q>(p+i*x2)){
        t1=2*f22(p+i*x2);
        if(t1<0){
            a2-=t1;
        }
        else a2+=t1;
        i++;
    }
    i=1;
    a2=(a2*x2)/2;

    //printf("%.12lf\n",a2);
    if(a1-a2>0) t=a1-a2;
    else t=a2-a1;

    if(t<pow(10,-err)){
        break;
    }
    else{
        x2/=2;
        a1=a2;
        a2=0;
    }
    }
    return a2;
}

int main(void){ //f1(x) =((a-x^2))^(1/2) f2(x) = (ax^3 + 7x)/(a+x)^(1/2)
    while(1){
    //printf("%lf",pow(10,-8));
    double p=0,q=0,err=0,way,fin=0,ans=0,k=0;
    scanf("%lf",&way);
    if(way==0){
        break;
    }
    scanf("%lf",&a);
    scanf("%lf",&p);
    scanf("%lf",&q);
    if(p>q){
        k=p;
        p=q;
        q=k;
    }
    scanf("%lf",&err);

    //printf("%lf",felf(1));
    if(way==1){
        ans=f1(p,q,err);
        if(ans<0)ans*=-1;
        printf("%.12lf\n",ans);
    }
    else if(way==2){
        ans=f2(p,q,err);
        if(ans<0)ans*=-1;
        printf("%.12lf\n",ans);
    }
}
}
