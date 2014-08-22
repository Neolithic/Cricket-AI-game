#include<iostream>
using namespace std;
void move1(bool hor[6][5],bool ver[5][6],int &row,int &col,bool &dir)
{
    bool flag=0;
    int a,b;
    bool d;
    row=1;
    col=2;
    dir=1;return;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(!flag)
            {
                if(!ver[i][j])
                {
                    flag=1;
                    a=i;b=j;d=1;
                }
                else if(!ver[i][j+1])
                {
                    flag=1;
                    a=i;b=j+1;d=1;
                }
                else if(!hor[i][j])
                {
                    flag=1;
                    a=i;b=j;d=0;
                }
                else if(!hor[i+1][j])
                {
                    flag=1;
                    a=i+1;b=j;d=0;
                }
            }
            if(ver[i][j]&&ver[i][j+1]&&hor[i][j]&&!hor[i+1][j])
            {
                dir=0;
                row=i+1;
                col=j;
                return;
            }
            else if(ver[i][j]==1&&ver[i][j+1]==1&&hor[i][j]==0&&hor[i+1][j]==1)
            {
                dir=0;
                row=i;
                col=j;
                return;
            }
            else if(ver[i][j]==1&&ver[i][j+1]==0&&hor[i][j]==1&&hor[i+1][j]==1)
            {
                dir=1;
                row=i;
                col=j+1;
                return;
            }
            else if(ver[i][j]==0&&ver[i][j+1]==1&&hor[i][j]==1&&hor[i+1][j]==1)
            {
                dir=1;
                row=i;
                col=j;
                return;
            }
        }
    }
    dir=d;
    row=a;
    col=b;
    return;
}
            
