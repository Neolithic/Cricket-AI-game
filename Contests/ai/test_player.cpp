#include<iostream>
#include"C:\\Users\\Kshitiz\\Documents\\cpp\\kt\\common.cpp"
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
    p[2].r=24;p[2].theta=90;
    p[3].r=49;p[3].theta=105;
    p[4].r=49;p[4].theta=205;
    p[5].r=74;p[5].theta=315;
    p[6].r=74;p[6].theta=35;
    p[7].r=74;p[7].theta=335;
    p[8].r=90;p[8].theta=180;
    p[9].r=95;p[9].theta=200;
    p[10].r=99;p[10].theta=100;
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
    r=bst1/2;
}
    
