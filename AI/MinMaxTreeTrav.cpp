#include<iostream>
using namespace std;
class tictacgrid{
    // 0:empty 1:X 4:O
public:
    int grid[3][3];
    tictacgrid()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                grid[i][j]=0;
    }
    void printgrid()
    {
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                switch(grid[i][j])
                {
                    case 1:cout<<"X ";
                    break;
                    case 4:cout<<"O ";
                    break;
                    case 0:cout<<"_ ";
                }
            }
            cout<<"\n";
        }
    }
    void inputgrid()
    {
        cout<<"Enter 0 for empty 1 for cross 4 for circles";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<i*3+j+1<<" : ";
                cin>>grid[i][j];
            }
        }
    }
};

void retpossmoves(tictacgrid a, int moves[]){
    int movcnt=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(!a.grid[i][j])
                moves[movcnt++]=i*3+j;
    moves[movcnt]=-1;
}

int checkcorner(tictacgrid a, int player){
    int retval=0;
    if(a.grid[0][0]==player)
        retval++;
    if(a.grid[0][2]==player)
        retval++;
    if(a.grid[2][0]==player)
        retval++;
    if(a.grid[2][2]==player)
        retval++;
    return retval;
}

int checkother(tictacgrid a, int player){
    int retval=0;
    if(a.grid[0][1]==player)
        retval++;
    if(a.grid[1][0]==player)
        retval++;
    if(a.grid[1][2]==player)
        retval++;
    if(a.grid[2][1]==player)
        retval++;
    return retval;
}

int sumrow(tictacgrid a, int row){
    //ROW WITH BASE 0
    int sum=0;
    for(int i=0;i<3;i++)
        sum+=a.grid[row][i];
    return sum;
}

int sumcol(tictacgrid a, int col){
    //COLUMN WITH BASE 0
    int sum=0;
    for(int i=0;i<3;i++)
        sum+=a.grid[i][col];
    return sum;
}

int checkinseries(tictacgrid a, int player, int check){
    int sumr, sumc, sumd1=0, sumd2=0, posswins=0;
    for(int i=0;i<3;i++)
    {
        sumr=sumrow(a, i);
        sumc=sumcol(a, i);
        if(sumr==(player*check))
            posswins++;
        if(sumc==(player*check))
            posswins++;
    }
    sumd1+=a.grid[0][0]+a.grid[1][1]+a.grid[2][2];
    sumd2+=a.grid[0][2]+a.grid[1][1]+a.grid[2][0];
    if(sumd1==player*check)
        posswins++;
    if(sumd2==player*check)
        posswins++;
    return posswins;
}

int rating(tictacgrid a, int player){
    int rate=0;
    if(checkinseries(a,player,3))
        rate=500;
    else{
        rate+=checkinseries(a, player, 2)*100;
        if(a.grid[1][1]==player)
            rate+=10;
        rate+=checkcorner(a, player)*2;
        rate+=checkother(a, player);
    }
    return rate;
}

int main()
{
    tictacgrid a;
    a.inputgrid();
    a.printgrid();
    cout<<"\nRating for 1, rating for 4 :\n"<<rating(a, 1)<<" , "<<rating(a, 4);
    return 0;
}
