#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class node {
public:
    node(int tf=0,int height=0){
        peak=tf;
        v=height;
    }
    int peak ;
    int v;
};

int main(int agrc,char *agrv[])
{

    cout<<agrc<<endl;
    string id;
    id=agrv[1];
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

    node map[2][y];
    infile>>map[0][0];
    map[0][0].peak+=2;
    map[0][y-1].peak+=1;
    for(int j=1;j<y;j++)
    {
        infile>>map[0][j].v;
        if(map[0][j-1].v<map[0][j].v)map[0][j].peak++;
        else (map[0][j-1].v>map[0][j].v)map[0][j-1].peak++;
        else {map[0][j].peak++;map[0][j-1].peak++;}
        peak+=1;
    }  
    
    for(int i=1 ;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            infile>>map[i%3][j].v;
        }   
    }

    return 0;
}

