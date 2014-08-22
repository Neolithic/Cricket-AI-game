#include<fstream>
#include"testplayer.cpp"
using namespace std;
bool hor[6][5],ver[5][6];           
int score[2];
void set()
{
    for(int i=0;i<6;i++)
        for(int j=0;j<5;j++)
            ver[j][i]=hor[j][i]=0;
    score[0]=score[1]=0;
}
bool check(int row,int col,bool dir)                  //assingns a valid line(already not presents) and returns 0
{
    if(row<0||col<0)
        return 1;
    if(dir&&(row>4||col>5))
        return 1;
    if(!dir&&(row>5||col>4))
        return 1;
    if(dir&&!ver[row][col])
    {
        ver[row][col]=1;
        return 0;
    }
    else if(!dir&&!hor[row][col])
    {
        hor[row][col]=1;
        return 0;
    }
    cout<<"wrong entry";
    return 1;
}
bool made(bool dir,int row,int col,int p)            //return when box(es) is(are) made and adds score of player p(1 or 2)
{
    bool flag=0;
    if(dir==0)                                      //dir=0 for horizontal lines and 1 for vertical lines
    {
        if(row!=5&&hor[row+1][col]==1&&ver[row][col]==1&&ver[row][col+1]==1)
        {
            score[p-1]++;
            flag=1;
        }
        if(row!=0&&hor[row-1][col]==1&&ver[row-1][col]==1&&ver[row-1][col+1]==1)
        {
            score[p-1]++;
            flag=1;
        }
    }
    else
    {
        if(col!=5&&(ver[row][col+1]==1&&hor[row][col]==1&&hor[row+1][col]==1))
        {
            score[p-1]++;
            flag=1;
        }
        if(col!=0&&ver[row][col-1]==1&&hor[row][col-1]==1&&hor[row+1][col-1]==1)
        {    
            score[p-1]++;
            flag=1;
        }
    }
    if(flag)
    { 
//        cout<<score[0]<<score[1]<<" ";  
        return 1;
    }
    return 0;
}
void run(int t)
{
    int row=0,col=0;
    bool dir=0,tmp;
    set();
    ifstream fin;
    fin.open("a.txt");
    if(!t)
    {
        while(1)
        {
            do
            {
                do
                {
                    
  //                  move1(hor,ver,row,col,dir);                 //decomment this function call when u r ready with 
                    if(score[0]+score[1]==25)                    //ur move function
                        return;
                }while(check(row,col,dir));
            }while(made(dir,row,col,1));
            
            
            
            do
            {
                do
                {
                    move2(hor,ver,row,col,dir);
                  if(score[0]+score[1]==25)
                        return;
                }while(check(row,col,dir));
                
            }while(made(dir,row,col,2));
                           
        }
    }
    else
    {
        while(1)
        {
            do
            {
                do
                {
                    
                    move2(hor,ver,row,col,dir);        
                    if(score[0]+score[1]==25)
                        return;
                }while(check(row,col,dir));
            }while(made(dir,row,col,2));
            
            
            
            do
            {
                do
                {
                    
//                   move1(hor,ver,row,col,dir);                //decomment this function call when u r ready with 
                    if(score[0]+score[1]==25)                    //ur move function
                    {
                        fin.close();
                        return;
                    }
                }while(check(row,col,dir));
                
            }while(made(dir,row,col,1));
                           
        }
    }
    cout<<score[0];
    return;
}
       
int main()
{
    run(0);
    printf("final score is:%d %d ",score[0],score[1]);
    printf("winner is: p%d\n",score[0]>score[1]?1:2);
    run(1);
    printf("final score is:%d %d ",score[0],score[1]);
    printf("winner is: p%d\n",score[0]>score[1]?1:2);
    
    system("pause");
    return 0;
}
