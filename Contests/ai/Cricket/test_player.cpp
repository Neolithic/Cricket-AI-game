#include<iostream>
#include"C:\\Documents and Settings\\Sumit\\My Documents\\C++ prog\\ai\\Cricket\\common.cpp"
#include<stdio.h>
#include<time.h>
using namespace std;

class team1
{
    public:
        int toss;               //if toss=0 your batting is first, otherwise if toss=1
        void fieldset(player p[11]);          
        
        int setbwlr(player p[11]){  return 1;}
        //
        void hit(int &r,int &th,int fr[11],int fth[11],int bst1,int bst2);
};
void team1::fieldset(player p[11])
{
    //p[1].r=22;p[1].theta=180;
    int rr,tt;
    rr=rand()%15;tt=rand()%360;
    p[2].r=rr+10;p[2].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[3].r=rr+25;p[3].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[4].r=rr+25;p[4].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[5].r=rr+50;p[5].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[6].r=rr+50;p[6].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[7].r=rr+50;p[7].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[8].r=rr+75;p[8].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[9].r=rr+75;p[9].theta=tt;
    
    rr=rand()%25;tt=rand()%360;
    p[10].r=rr+75;p[10].theta=tt;
}
void team1::hit(int &r,int &th,int fr[11],int fth[11],int bst1, int bst2)
{
    int max=0,m,t;
    for(int i=0;i<8;i++)
    {
        m=fr[i]+fth[i+1];
        if(m>max)
        {
            th=fr[i]+fth[i+1];
            max=m;
            t=i;
        }    
    } 
    r=rand()%101;     
    //r=bst1/2;
}
    
