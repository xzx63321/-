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
double a[20],b[20]; //a�������֣�b�����ֵ,c����b�����ֵ,dΪ�ź�����±�
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
printf("�����빲���м��֣�");
scanf("%d",&m);
printf("���������������");
scanf("%d",&n);
for(j=0;j<m;j++)
{
printf("��ʼ��%d����Ϸ\n",j+1);
for(i=0;i<n;i++)
{
printf("�������%d����ҵ�����:\n",i+1);
scanf("%lf",&a[i]);

}


for(i=0;i<n;i++)//�������
{
getdif(a,b,n);
end(b,compare,n);


if(b[i]==b[compare[0]])
score[i]=score[i]+n;
else if(b[i]==b[compare[1]])//ע����else if
score[i]=score[i]-2;
printf("%d����ҷ���Ϊ:%d\n",i+1,score[i]);
}

system("pause");
system("cls");
}
printf("-----------�ɼ�������-----------\n");
rank(score,c,d,n);
for(i=0;i<n;i++)
{
printf("��%d��:%d�����%d\n",i+1,d[i],score[i]);
}


}



double getG(int* a,int n) //��Gֵ
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


void getdif(double* a,double * b,int n) //����ֵ��������b��,defference��val:��ֵ��
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



void end(double* b,int* compare,int n) //ͨ���Ƚϲ�ֵ�Ĵ�С��ѡ����С�����ġ�������Сֵ�����ֵ���±�
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
compare[0]=i;//С
}
if(max<b[i])
{
max=b[i];
compare[1]=i;//��
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
for(q=0;q<n-i;q++)	//ð������
if(score[q]<score[q+1])
{
temp=score[q];
score[q]=score[q+1];
score[q+1]=temp;
}


for(i=0;i<n;i++)
{ //�����������ԭλ��
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
