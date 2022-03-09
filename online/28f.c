#include<stdio.h>
#define ShapeText(TYPE) char name[10];
#define pi 3.14
typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} circle;
typedef struct square_s {
    ShapeText(square_s);
    double len;
} square;
typedef struct triangle_s {
    ShapeText(triangle_s);
    double x1,x2,x3;
} triangle;
typedef struct rectangle_s {
    ShapeText(rectangle_s);
    double len,wid;
} rectangle;
double per(char type){
    double ans=0;
    rectangle r;
    triangle t;
    square s;
    circle c;
    if(type =='C'){
        scanf(" %lf",&c.radius);
        ans = 2*c.radius*pi;
        printf("%.2f\n",ans);
    }
    if(type == 'R'){
        scanf(" %lf",&r.len);
        scanf(" %lf",&r.wid);
        ans= r.len*2+2*r.wid;
        printf("%.2f\n",ans);
    }
    if(type == 'T'){
        scanf(" %lf",&t.x1);
        scanf(" %lf",&t.x2);
        scanf(" %lf",&t.x3);
        ans = t.x1+t.x2+t.x3;
        printf("%.2f\n",ans);

    }
    if(type == 'S'){
        //printf("bang!");
        scanf(" %lf",&s.len);
        //printf("%f!",s.len);
        ans = s.len*4;
        printf("%.2f\n",ans);
    }
    //printf("done");
    return ans;
}
int main(void){
    double (*perimeterer)(char)=per;
    int m;
    double a;
    char t;
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        scanf(" %c",&t);
        a+=(*perimeterer)(t);
    }
    printf("%.2f",a);
}