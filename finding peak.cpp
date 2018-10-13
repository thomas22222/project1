#include<iostream>
#include<string>
#include<fstream>

using namespace std;



int main(int agrc,char *agrv[])
{

    cout<<agrc<<endl;
    string id,id2;
    id=agrv[1];
    id2=agrv[1];
    cout<<id<<endl;
    id+="/matrix.data";
    //string idn="../";     //桌面
    //id=idn+id;
    ifstream infile(id,ios::in);
    if(!infile){cout<<id<<endl;
    return 1;}
    int x;
    int y;
    infile>>x;
    infile>>y;
    cout<<x<<' '<<y<<endl;

    int map[3][y];
    bool tf[x][y];
    
    for(int i=0 ;i<=x;i++)
    {
        for(int j=0;j<y;j++)
        {   
            if(i!=x)tf[i][j]=1;
            if(i!=x)infile>>map[i%3][j];
            if(i!=0&&i!=1)  if(map[(i-1)%3][j]<map[(i-2)%3]     [j])      tf[i-1][j]=false;
            if(j!=0)        if(map[(i-1)%3][j]<map[(i-1)%3]     [j-1])    tf[i-1][j]=false;
            if(i!=x&&i!=0)        if(map[(i-1)%3][j]<map[(i  )%3]     [j])      tf[i-1][j]=false;
            if(j!=y-1)      if(map[(i-1)%3][j]<map[(i-1)%3]     [j+1])    tf[i-1][j]=false;
        }   
    }
    id2+="/final.peak";
    ofstream outfile(id2,ios::out);
    if(!outfile)cout<<"errrrrr";
    int sum=0;
    for(int i=0 ;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {   
            if(tf[i][j]==true)
            sum+=1;
        }   
    }
    outfile<<sum<<endl;
    for(int i=0 ;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {   
            if(tf[i][j]==true)

            outfile<<i+1<<' '<<j+1<<endl;
        }   
    }

    return 0;
}

