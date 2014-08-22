#include<iostream>
#include<fstream>
#include<cmath>
#include<stdio.h>
#include<time.h>
//#include"C:\\Documents and Settings\\Sumit\\My Documents\\C++ prog\\ai\\Cricket\\common.cpp"
#include"C:\\Documents and Settings\\Sumit\\My Documents\\C++ prog\\ai\\Cricket\\test_player.cpp"
using namespace std;


class cricket
{
    ofstream fout;
    player t[2][11],loc[11];           //11 players of both teams,local var to copy fielding team data
    int fr[11],fth[11],bwlr,wkpr,bt1,bt2,r,th,bt;                  //var to copy positon of fielders
    team1 t_1;                      //object of team 1
    team1 t_2;                       //object of team 2
    int toss,scr1,scr2,wkt1,wkt2; //
    public:  
        void init();
        void chkfield(int);
        void Istteambat();
        void IIndteambat();
        void controller();
        int fielded(int,int);
        void setfield(int,int);
        void copystat(int);
        void sort();
        void makefile(int,int);
};

void cricket::init()        // Initial field positions
{
    fout.open("e:\\stat.txt");
    srand(time(0));
    toss=rand()%2;
    t_1.toss=toss;
    t_2.toss=(toss+1)%2;
    scr1=scr2=0;
    wkt1=wkt2=0;
    //setting the first player(t[0][0] & t[1][0]) of each team as wicketkeeper
    //and there coordinates as (22,0 degree)
    wkpr=0;
    t[1][wkpr].r=t[0][wkpr].r=22;               
    t[1][wkpr].theta=t[0][wkpr].theta=0;
    //setting the batting & bowling strength
    for(int i=0;i<11;i++)
    {
        t[1][i].bstren=50;t[1][i].fstren=45;t[1][i].skill=11-i;
        t[0][i].bstren=50;t[0][i].fstren=45;t[0][i].skill=11-i;
        //setfield(0);
        //setfield(1);
    }
}
void cricket::makefile(int tf,int rr)
{
    for(int i=0;i<11;i++)
    {
        fout<<t[tf][i].r<<' '<<t[tf][i].theta<<' '<<t[tf][i].fstren<<' ';
    }
    fout<<r<<' '<<th<<' ';
    if(rr!=-1)
      fout<<t[tf][rr].r<<' '<<t[tf][rr].theta<<endl;
    else
      fout<<t[tf][0].r<<' '<<t[tf][0].theta<<endl;
}
void cricket::sort()
{   
    for(int i = 0; i <= 10; i++)
    {
        
        for (int j=0; j <= 9-i; j++)
        {
            if (fth[j+1] < fth[j])      
            { 
                fr[j+1]=fr[j+1]+fr[j]-(fr[j]=fr[j+1]);
                fth[j+1]=fth[j+1]+fth[j]-(fth[j]=fth[j+1]);
            }
        }
    }
}


void cricket::copystat(int i)
{
    if(toss)
    {
        st.scr1=scr2;
        st.scr2=scr1;
        st.wkt1=wkt2;
        st.wkt2=wkt1;
    }
    else
    {
        st.scr1=scr1;
        st.scr2=scr2;
        st.wkt1=wkt1;
        st.wkt2=wkt2;
    }
    st.ovr=i;
}
    
void cricket::setfield(int tf,int bwlr)
{
    t[tf][2].r=24; t[tf][2].theta=90;            //Check this initial field 
    t[tf][3].r=49; t[tf][3].theta=105;
    t[tf][4].r=49; t[tf][4].theta=205;
    t[tf][5].r=74; t[tf][5].theta=315;
    t[tf][6].r=74; t[tf][6].theta=35;
    t[tf][7].r=74; t[tf][7].theta=335;
    t[tf][8].r=90; t[tf][8].theta=180;
    t[tf][9].r=95; t[tf][9].theta=200;
    t[tf][10].r=99; t[tf][10].theta=100;
    
    t[tf][1].r=t[tf][bwlr].r; t[tf][1].theta=t[tf][bwlr].theta;
    t[tf][bwlr].r=22; t[tf][bwlr].theta=180;
}
   
void cricket::chkfield(int tf)       //Ring limit on players  // If field given wrong , deduct scores,t=0 wen t 1 fielding
{
    int counter[5];
    for(int i=0;i<5;i++)
      counter[i]=0;
    int flag=0;
    
    for(int i=1;i<11;i++)
    {
        if(i==bwlr)
            continue;
        if(loc[i].r<100&&loc[i].r>=10&&loc[i].theta>=0&&loc[i].theta<360)
        {
            if(loc[i].r<25)
              counter[0]++;
            else if(loc[i].r<50)
                   counter[1]++;
            else if(loc[i].r<75)
                    counter[2]++;
            else 
              counter[3]++;
            
        }
        else
          counter[4]++;
    }
    if(counter[0]>1||counter[1]>2||counter[2]>3||counter[3]>3||counter[4]>0)
      flag=1;
    if(flag==0)                                     //Copy field locations provided by fielding team
    {
        for(int i=1;i<11;i++)
        {
            if(i==bwlr)
              continue;
            t[tf][i].r=loc[i].r;
            t[tf][i].theta=loc[i].theta;
            
        }
    }
    else                                            //Set field on own and deduct sores
    {
        if(tf==0)
          scr1-=5;                                      //Deducting score 
        else
          scr2-=5;
        cout<<"\n(Field wrong)  Deducting Scores by 5 ";
        setfield(tf,bwlr);
    }    
}

int cricket::fielded(int tb,int tf)
{
    float rr=-1;
    if(r<0)
    {
        cout<<"\n(r<0)  Deducting scores by 5";
        if(tb==0)
          scr1-=5;                                      //score of t1 decreases
        else
          scr2-=5;                                      //score of t2 decreases
        return -1;
        r=0;
    }
    int min=4,m=4,f=-1;
    for(int i=0;i<11;i++)
    {
        double rad;
        rad=sqrt(t[tf][i].r*t[tf][i].fstren/5);
        if(t[tf][i].r<25)
            rad=rad/2.0;
        float b=-2.0*t[tf][i].r*cos(t[tf][i].theta-th);           //check
        float c=t[tf][i].r*t[tf][i].r-rad*rad;  
        float D=b*b-4*c;
        if(D<0)
            continue;
        D=sqrt(D);
        float r1=(b+D)/-2.0;
        float r2=(b-D)/-2.0;
        //cout<<r1<<' ';
        if(r1<0)
          continue;
        if(r>r1)
        {
            if(r1<25)
                m=0;
            else if(r1<50)
                m=1;
            else if(r1<75)
                m=2;
            else if(r1<100)
                m=3;
            if(m<min)
            {
                min=m;
                f=i;
                rr=r1;
            }                
        }
    }
    if(f==-1)
    {
        if(r<25)
            min=0;
        else if(r<50)
            min=1;
        else if(r<75)
            min=2;
        else if(r<100)
            min=3;
    }
    
    //cout<<min<<'\t';
    //cout<<min<<' ';
    for(int i=0;i<11;i++)
    {
        if(f==i)
        {
            t[tf][f].fstren-=9;
            if(t[tf][f].fstren<0)
                t[tf][f].fstren=0;
        }
        else if(t[tf][i].fstren<50)
            t[tf][i].fstren+=1;
    }
    t[tb][bt1].bstren-=r/5;                               //Check this, decreasing value of strength(NOT DECREASE BY R BUT R1)
    t[tb][bt2].bstren+=10;
    if(t[tb][bt2].bstren>50)
        t[tb][bt2].bstren=50;
      
    if(t[tb][bt1].bstren<0)
    {
        cout<<bt1+1<<" is out\t";
        if(tb)
            wkt2++;
        else
            wkt1++;      
        bt1=bt;
        bt++;
    }
    else
    {
        if(tb==0)
          scr1+=min;                                      //score of t1 increased
        else
          scr2+=min;                                      //score of t2 increased
        if(m==1||m==3)
        {
            bt1=bt1+bt2-(bt2=bt1);
        }
    }
    if(rr>=0)
        r=rr;
    return f;
    
}

void cricket::Istteambat()                              //Ist team bats and IInd team bowls
{
    bt1=0;
    bt2=1;
    bt=2;
    for(int i=0;i<50;i++)               //50 overs
    {
        for(int k=0;k<11;k++)       //Copying field to local var
        {
            loc[k]=t[1][k];
        }
        bwlr=t_2.setbwlr(loc);             //set bowler before each over
        if(bwlr<1||bwlr>10)             //if wrong choice is given then 2nd player is set as bowler
            bwlr=1;
        t[1][bwlr].r=22;
        t[1][bwlr].theta=180;
        
        for(int j=0;j<6;j++)            //6 balls of an over
        {
            copystat(i+1);
            for(int k=0;k<11;k++)       //Copying field to local var
            {
                loc[k]=t[1][k];
            }
            t_2.fieldset(loc);
            chkfield(1);
            
            for(int k=0;k<11;k++)          //Copying field locations, sort acc to x
            {
                fr[k]=t[1][k].r;
                fth[k]=t[1][k].theta;
            }
            sort();
            t_1.hit(r,th,fr,fth,t[0][bt1].bstren,t[0][bt2].bstren);                  // Check for r, th in their limits , and also acc to batsman strength
            
            int yyy=fielded(0,1);                                                    // Returns fielder who fielded
            makefile(1,yyy);
            if(bt==12)
            {
                return;
            }
//            cout<<"score is:"<<scr1<<'\t';
cout<<scr1<<'\\'<<wkt1<<' '<<i+1<<'.'<<j<<endl;
        }
//        cout<<"After over"<<i+1<<",Score is"<<scr1<<endl;
        
        //cin>>nn;
        bt1=bt1+bt2-(bt2=bt1);
    }
}

void cricket::IIndteambat()
{
    bt1=0;
    bt2=1;
    bt=2;
    for(int i=0;i<50;i++)               //50 overs
    {
        for(int k=0;k<11;k++)       //Copying field to local var
        {
            loc[k]=t[0][k];
        }
        bwlr=t_1.setbwlr(loc);             //set bowler before each over
        if(bwlr<1||bwlr>10)             
            bwlr=1;
        t[0][bwlr].r=22;
        t[0][bwlr].theta=180;
        for(int j=0;j<6;j++)            //6 balls of an over
        {
            copystat(i+1);
            for(int k=0;k<11;k++)       //Copying field to local var
            {
                loc[k]=t[0][k];
            }
            t_1.fieldset(loc);
            chkfield(0);
            
            for(int k=0;k<11;k++)          //Copying field locations, sort acc to x
            {
                fr[k]=t[0][k].r;
                fth[k]=t[0][k].theta;
            }
            sort();
            t_2.hit(r,th,fr,fth,t[1][bt1].bstren,t[1][bt2].bstren);                  // Check for r, th in their limits , and also acc to batsman strength
            
            int yyy=fielded(1,0);
            makefile(0,yyy);
            if(bt==12)
            {
                return;
            }
            cout<<scr2<<'\\'<<wkt2<<' '<<i+1<<'.'<<j<<endl;
        }
        bt1=bt1+bt2-(bt2=bt1);
    }
}
void cricket::controller()
{                             
    init();
    if(toss==0)
    {
        Istteambat();
        IIndteambat();
    }
    else
    {
        IIndteambat();
        Istteambat();
    }
    cout<<endl<<scr1<<' '<<scr2<<endl;
    if(scr1>scr2)
        cout<<"team 1 wins";
    else if(scr2>scr1)
        cout<<"team 2 wins";
    else
        cout<<"tied";
        fout.close();
}
            
int main()
{
    cricket match;
    match.controller();
    system("pause");
    return 0;
}
