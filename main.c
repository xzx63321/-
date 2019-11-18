#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<math.h>
#include"windows.h"

double getG(int* a,int n);
void getdif(double* a,double * b,int n);
void end(double* b,int* compare,int n);
void rank(int* score,int* c,int* d,int n);


void main()
{
int i,n,m,j;
double a[20],b[20]; //a保存数字，b保存差值,c保存b数组的值,d为排好序的下标
int score[20],d[20],c[20];
int compare[2]={0,0};

for(i=0;i<20;i++)
{
a[i]=0;
score[i]=0;
b[i]=0;
c[i]=0;
d[i]=0;
}
printf("请输入共进行几轮：");
scanf("%d",&m);
printf("请输入玩家人数：");
scanf("%d",&n);
for(j=0;j<m;j++)
{
printf("开始第%d轮游戏\n",j+1);
for(i=0;i<n;i++)
{
printf("请输入第%d个玩家的数字:\n",i+1);
scanf("%lf",&a[i]);

}


for(i=0;i<n;i++)//计算分数
{
getdif(a,b,n);
end(b,compare,n);


if(b[i]==b[compare[0]])
score[i]=score[i]+n;
else if(b[i]==b[compare[1]])//注意用else if
score[i]=score[i]-2;
printf("%d号玩家分数为:%d\n",i+1,score[i]);
}

system("pause");
system("cls");
}
printf("-----------成绩总排名-----------\n");
rank(score,c,d,n);
for(i=0;i<n;i++)
{
printf("第%d名:%d号玩家%d\n",i+1,d[i],score[i]);
}


}



double getG(int* a,int n) //求G值
{
int i;
double sum=0,ave,G;
for(i=0;i<n;i++)
{
sum=sum+a[i];
}
ave=sum/n;
G=ave*0.618;
return G;
}


void getdif(double* a,double * b,int n) //将差值存在数组b中,defference，val:差值；
{
int i;
double difference,val;
double c = getG(a,n);
for(i=0;i<n;i++)
{
difference=a[i]-c;
val=fabs(difference);
b[i]=val;
}

}



void end(double* b,int* compare,int n) //通过比较差值的大小，选出最小和最大的。保存最小值和最大值的下标
{
int i;
double max,min;
max=b[0];
min=b[0];
for(i=0;i<n;i++)
{
if(min>b[i])
{
min=b[i];
compare[0]=i;//小
}
if(max<b[i])
{
max=b[i];
compare[1]=i;//大
}
}

}







void rank(int* score,int* c,int* d,int n)
{
int i,q,temp=0;
for(i=0;i<n;i++)
{
c[i]=score[i];
}
for(i=1;i<n;i++)
for(q=0;q<n-i;q++)	//冒泡排序
if(score[q]<score[q+1])
{
temp=score[q];
score[q]=score[q+1];
score[q+1]=temp;
}


for(i=0;i<n;i++)
{ //数组排序并输出原位置
for(q=0;q<n;q++)
{
if(score[i]==c[q])
{
d[i]=q+1;
c[q]=-100;
break;
}

}
}

}
