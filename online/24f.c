#include<stdio.h>
typedef enum scoreType_s {G, S,GPA} scoreType_t;
typedef enum grade_s{A, B, C ,F} grade_t;
typedef union score_s{
    int score;
    grade_t grade;
    float gpa;
} score_t; // �T�ص�����@��
// �L�X�������G

int gogo(score_t s, scoreType_t t,char sign) {
char g[] = {'A','B','C','F'};
int ans=0;
if (t == G) {
    //printf("%c?\n", g[s.grade]);
    if(s.grade==B){
        ans=75;
        if(sign=='+'){
            ans+=3;
        }
        else if(sign=='-'){
            ans-=5;
        }
    }
    else if(s.grade==A){
        ans=87;
        if(sign=='+'){
            ans+=8;
        }
        else if(sign=='-'){
            ans-=5;
        }
    }
    else if(s.grade==C){
        ans=65;
        if(sign=='+'){
            ans+=3;
        }
        else if(sign=='-'){
            ans-=5;
        }
    }
    else ans=50;
   // printf("%d g",ans);
}
else if(t==GPA){
    int test = s.gpa*10;
    if(test==43){
        ans=95;
    }
    else if(test==40){
        ans=87;
    }
    else if(test==37){
        ans=82;
    }
    else if(test==33){
        ans=78;
    }
    else if(test==30){
        ans=75;
    }
    else if(test==27){
        ans=70;
    }
    else if(test==23){
        ans=68;
    }
    else if(test==20){
        ans=65;
    }
    else if(test==17){
        ans=60;
    }
    else ans =50;
   // printf("%d gpa\n",ans);

}
else if(t==S){
    if(s.score==90){
        ans=95;
    }
    else if(s.score==85){
        ans=87;
    }
    else if(s.score==80){
        ans=82;
    }
    else if(s.score==77){
        ans=78;
    }
    else if(s.score==73){
        ans=75;
    }
    else if(s.score==70){
        ans=70;
    }
    else if(s.score==67){
        ans=68;
    }
    else if(s.score==63){
        ans=65;
    }
    else if(s.score==60){
        ans=60;
    }
    else ans =50;
   // printf("%d s\n",ans);

}
    return ans;
}


int main(void) {
    int cn=0,n=0,id[1000],ans=0,ids[1000],t=0;
    float gpa; //�~����Jgpa
    int rs; //�~����Js
    scoreType_t type[5];
    char str[1000]; // �~����Jg
    char ty[100];
    scanf("%d",&cn);
    for(int i=0; i<cn;i++){
        scanf("%s",ty);
        if(ty[0]=='G' && ty[1]=='P'){
            //printf("gap!?!??!?!");
            type[i]=GPA;
        }
        else if(ty[0]=='G'){
            //printf("g!?!");
            type[i]=G;
        }
        else type[i]=S;
    }
    scanf("%d",&n);
    score_t student[n];

    for(int i = 0 ; i<n;i++){
        scanf("%d",&id[i]);
        ans=0;
        for(int j=0;j<cn;j++){
            if(type[j]==GPA){
               //printf("test1");
                scanf("%f",&gpa);
                student[i].gpa=gpa;
            }
            else if(type[j]==S){
                //printf("test2");
                scanf("%s",str);
                //printf("%s",str);
                rs=(str[0]-'0')*10+(str[1]-'0');
               // printf("%d",rs);
                student[i].score=rs;
            }
            else if(type[j]==G){
                //printf("test3");
                scanf("%s",str);
                if(str[0]=='A'){
                    student[i].grade=A;
                }
                else if(str[0]=='B'){
                    student[i].grade=B;
                }
                else if(str[0]=='C'){
                    student[i].grade=C;
                }
                else if(str[0]=='F'){
                    student[i].grade=F;
                }
            }
            ans+=gogo(student[i],type[j],str[1]);
        }
        t=ans/cn;
        if(ans%cn!=0) t+=1;
        //printf("%d",t);
        ids[i]=t;
    }
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j <n;j++){
            if(ids[i]>ids[j]){
                t=ids[i];
                ids[i]=ids[j];
                ids[j]=t;
                t=id[i];
                id[i]=id[j];
                id[j]=t;
            }
        }
    }
    for(int i = 0 ;i<3;i++){
        printf("%d\n",id[i]);
        printf("%d\n",ids[i]);
    }




   /* student[0].score=90;
    type[0]=S;
    student[1].gpa=4.3;
    type[1]=GPA;

    if(str[0]=='A'){
    student[2].grade=A;
    }
    else if(str[0]=='B'){
    student[2].grade=B;
    }
    else if(str[0]=='C'){
    student[2].grade=C;
    }
    else student[2].grade=F;
    type[2]=G;

    for(int i=0; i<3; i++) gogo(student[i], type[i],str[1]);*/

}
