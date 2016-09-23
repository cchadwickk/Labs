#include "iostream"
using namespace std;

struct node
{
    int x;
    int y;
}s[8];

void DFS(int s);
node n[20];
int index;
int v[20];
int graph[20][20];
int check(int arr[5][4],int xf,int yf);
void rules(node m);

int main()
{
    int arr[5][4];
    int x0=0,y0=0,xf=0,yf=0,i=0,j=0;
    cout<<"Enter the initial volume in the two jugs\n";
    cin>>x0>>y0;
    cout<<"Enter the final volume required in the two jugs\n";
    cin>>xf>>yf;
    for(i=0;i<20;i++)
    {
        v[i]=0;
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
            arr[i][j]=0;
    }
    index=0;
    arr[x0][y0]=1;
    n[index].x=x0;
    n[index].y=y0;
    index++;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
            graph[i][j]=0;
    }
    check(arr,xf,yf);
    /*for(i=0;i<index;i++)
    {
        for(j=0;j<index;j++)
            cout<<graph[i][j]<<" ";
        cout<<"\n";
    }*/
    DFS(0);
    return 0;
}

int check(int arr[5][4], int xf, int yf)
{
  int i=0,j=0,flag=0;
  node m;
  int parent;
  for(i=0;i<5;i++)
  {
      for(j=0;j<4;j++)
      {
          if(arr[i][j]!=0)
          {
              //cout<<"P: "<<"("<<i<<","<<j<<")"<<endl;
              m.x=i;
              m.y=j;
              for(int l=0;l<index;l++)
              {
                  if(n[l].x==i&&n[l].y==j)
                  {parent=l;
                  break;}
              }
              //cout<<parent<<"\n";
              rules(m);
              for(int k=0;k<8;k++)
              {
                  if(arr[s[k].x][s[k].y]==0)
                  {

                      arr[s[k].x][s[k].y]=1;
                      n[index].x=s[k].x;
                      n[index].y=s[k].y;
                      graph[parent][index]=1;
                      index++;
                      //cout<<index<<"\n";
                      //cout<<"("<<s[k].x<<","<<s[k].y<<")"<<endl;
                      if((s[k].x==xf)&& s[k].y==yf)
                      {
                          flag=1;
                          break;
                      }
                  }
              }
          }
          if(flag==1)
            break;

      }
      if(flag==1)
            break;
  }
  int temp=0;
  for(i=0;i<5;i++)
  {
      for(j=0;j<4;j++)
      {
          if(arr[i][j]!=0)
            temp++;
      }
  }
  if(flag!=1 && temp!=14)
    check(arr,xf,yf);
}

void rules(node m)
{
    if(m.x<4)
    {
        s[0].x=4;
        s[0].y=m.y;
    }
    else
    {
        s[0].x=m.x;
        s[0].y=m.y;
    }
    if(m.y<3)
    {
        s[1].x=m.x;
        s[1].y=3;
    }
    else
    {
        s[1].x=m.x;
        s[1].y=m.y;
    }
    if(m.x>0)
    {
        s[2].x=0;
        s[2].y=m.y;
    }
     else
    {
        s[2].x=m.x;
        s[2].y=m.y;
    }
    if(m.y>0)
    {
        s[3].x=m.x;
        s[3].y=0;
    }
     else
    {
        s[3].x=m.x;
        s[3].y=m.y;
    }
    if((m.x+m.y)>0 && m.y>0 && (m.x+m.y)>=4)
    {
        s[4].x=4;
        s[4].y=m.y-(4-m.x);
    }
     else
    {
        s[4].x=m.x;
        s[4].y=m.y;
    }
    if(m.x>0 && (m.x+m.y)>0 && (m.x+m.y)>=3)
    {
        s[5].x=m.x-(3-m.y);
        s[5].y=3;
    }
     else
    {
        s[5].x=m.x;
        s[5].y=m.y;
    }
    if(m.y>=0 && (m.x+m.y)>0 && (m.x+m.y)<=4)
    {
        s[6].x=m.x+m.y;
        s[6].y=0;
    }
     else
    {
        s[6].x=m.x;
        s[6].y=m.y;
    }
    if(m.x>=0 && (m.x+m.y)>0 && (m.x+m.y)<=3)
    {
        s[7].x=0;
        s[7].y=m.x+m.y;
    }
     else
    {
        s[7].x=m.x;
        s[7].y=m.y;
    }
}

void DFS(int s)
{
    int i;
    if(v[s]==0)
    {
         cout<<"("<<n[s].x<<","<<n[s].y<<")"<<endl;
         v[s]=-1;
         for(i=0;i<index;i++)
         {
             if(graph[s][i]>0)
             DFS(i);
         }
    }
    else
        return;
}
