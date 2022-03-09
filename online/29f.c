#include<stdio.h>

#define GATEVALUE(TYPE) int(*GateValue)(void)
typedef struct _Gate{
    GATEVALUE();
}Gate;

typedef struct _Gateand{       /////and
    GATEVALUE();
}Gateand;

int GateandValue(int a, int b){
    if(a==1 && b==1){
        return 1;
    }
    else return 0;
    }

typedef struct _Gateor{        ////or
    GATEVALUE();
}Gateor;

int GateorValue1(int a,int b){
    if(a==1 || b==1){
        return 1;
    }
    else return 0;
}

typedef struct _Gatexor{   ////xor
    GATEVALUE();
}Gatexor;

int GatexorValue(int a ,int b){
    if((a*b)==0 && a!=b){
        return 1;
    }
    else return 0;
}

typedef struct _Gatenot{   ////not
    GATEVALUE(int);
}Gatenot;

int GatenotValue(int a){
    if(a==1){
        return 0;
    }
    else return 1;
    }

typedef struct _Gateemp{   ////empty
    GATEVALUE(int);
}Gateemp;

int GateempValue(int a){return a;}

void CreateGateor(Gateor *obj){
    obj->GateValue = GateorValue1;
}
void CreateGateand(Gateand *obj){
    obj->GateValue = GateandValue;
}
void CreateGatexor(Gatexor *obj){
    obj->GateValue = GatexorValue;
}
void CreateGatenot(Gatenot *obj){
    obj->GateValue = GatenotValue;
}
void CreateGateemp(Gateemp *obj){
    obj->GateValue = GateempValue;
}

int one(char a,int b){
    if(a=='N'){
        return GatenotValue(b);
    }
    if(a=='E'){
        return GateempValue(b);
    }
}
int two(char a,int b,int c){
    if(a=='O'){
        return GateorValue1(b,c);
    }
    if(a=='A'){
        return GateandValue(b,c);
    }
    if(a=='X'){
        return GatexorValue(b,c);
    }
}

int main(int argc, char *argv[]){
    int i1,i2,i3,i4,a,b,c,d,e,f,ans1,ans2,ans3;
    char g[10];
    scanf("%d,%d,%d,%d",&i1,&i2,&i3,&i4);
    scanf(" %c,%c,%c,%c,%c,%c",&g[0],&g[1],&g[2],&g[3],&g[4],&g[5]);


    Gateor or;
    CreateGateor(&or);
    Gateand and;
    CreateGateand(&and);
    Gatexor xor;
    CreateGatexor(&xor);
    Gatenot not;
    CreateGatenot(&not);
    Gateemp emp;
    CreateGateemp(&emp);

    a=one(g[0],i1);

    e=one(g[4],i4);

    b=two(g[1],a,i2);

    ans1=b;
    c=two(g[2],i3,ans1);

    d=two(g[3],c,ans1);

    ans2=d;
    f=two(g[5],d,e);

    ans3=f;

   // printf("%d%d%d%d%d%d\n",a,b,c,d,e,f);

    printf("%d,%d,%d",ans1,ans2,ans3);
return 0;
}
