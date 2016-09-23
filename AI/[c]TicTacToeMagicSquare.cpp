#include <iostream>
using namespace std;
// 2:Empty, 3:X, 5:O
int board[10],first_turn,turn=1,pos;
void comp_move();
int mgsq[10]={0,8,3,4,
            1,5,9,
            6,7,2};

void display_board(){
    for(int i=0;i<3;i++){
        for(int j=(i*3+1);j<(i*3+4);j++){
          if(board[j]==2)
            cout<<" "<<"|";
          else if(board[j]==3)
            cout<<"X"<<"|";
          else
            cout<<"O"<<"|";
        }
        cout<<endl<<"------"<<endl;
    }
}

int win(char choice){
    if(choice=='x'||choice=='X'){
        if(board[1]*board[2]*board[3]==27)
            return 1;
        else if(board[4]*board[5]*board[6]==27)
            return 1;
        else if(board[7]*board[8]*board[9]==27)
            return 1;
        else if(board[1]*board[4]*board[7]==27)
            return 1;
        else if(board[5]*board[2]*board[8]==27)
            return 1;
        else if(board[9]*board[6]*board[3]==27)
            return 1;
        else if(board[1]*board[5]*board[9]==27)
            return 1;
        else if(board[7]*board[5]*board[3]==27)
            return 1;
        else
            return 0;
    }
    else{
        if(board[1]*board[2]*board[3]==125)
            return 1;
        else if(board[4]*board[5]*board[6]==125)
            return 1;
        else if(board[7]*board[8]*board[9]==125)
            return 1;
        else if(board[1]*board[4]*board[7]==125)
            return 1;
        else if(board[5]*board[2]*board[8]==125)
            return 1;
        else if(board[9]*board[6]*board[3]==125)
            return 1;
        else if(board[1]*board[5]*board[9]==125)
            return 1;
        else if(board[7]*board[5]*board[3]==125)
            return 1;
        else
            return 0;
    }
}

int possible_win(char choice){
    int i,pos;
    if(choice=='x'||choice=='X'){
        for(i=1;i<=9;i++)
    {
        if(board[i]==3)
        {
            for(int j=i+1;j<=9;j++)
            {
                if(board[j]==3)
                {
                    int res=15-(mgsq[i]+mgsq[j]);
                    for(int k=1;k<=9;k++)
                    {if(mgsq[k]==res)
                        pos=k;}
                    if(res>0 && res<=9 && board[pos]==2)
                        return pos;
                }
            }
        }
    }
    if(i==10)
        return 0;
    }
    else{
        for(i=1;i<=9;i++)
    {
        if(board[i]==5)
        {
            for(int j=i+1;j<=9;j++)
            {
                if(board[j]==5)
                {
                     int res=15-(mgsq[i]+mgsq[j]);
                    for(int k=1;k<=9;k++)
                    {if(mgsq[k]==res)
                        pos=k;}
                    if(res>0 && res<=9 && board[pos]==2)
                        return pos;
                }
            }
        }
    }
    if(i==10)
        return 0;
    }
}

void go(int position){
    if(turn%2==0)
        board[position]=5;
    else
        board[position]=3;
}


void user_input(){
    int pos;
    cout<<"Enter position";
    cin>>pos;
    go(pos);
    turn++;
    display_board();
    comp_move();
}



void comp_move(){
    if(turn%2!=0){
        switch(turn){
        case 1:
            cout<<"AI's Turn"<<endl;
            go(1);
            display_board();
            turn++;
            user_input();
            break;
        case 3:
            cout<<"AI's Turn"<<endl;
            if(board[5]==2)
                go(5);
            else
                go(9);
            display_board();
            turn++;
            user_input();
            break;
        case 5:
            cout<<"AI's Turn"<<endl;
            if(possible_win('x')){
                pos=possible_win('x');
                go(pos);
                display_board();
                cout<<"AI WINS";
            }
            else if(possible_win('o')){
                pos=possible_win('o');
                go(pos);
                display_board();
                turn++;
                if(win('x'))
                    cout<<"AI WINS!!";
                else
                    user_input();
            }
            else{
                if(board[2]==2){
                    go(3);
                    display_board();
                    cout<<"USER CANNOT WIN";
                }
                else{
                    go(7);
                    display_board();
                    cout<<"USER CANNOT WIN";
                }
            }
            break;
        case 7:
            cout<<"Computer's Turn"<<endl;
            if(possible_win('x')){
                pos=possible_win('x');
                go(pos);
                display_board();
                cout<<"AI WINS";
            }
            else if(possible_win('o')){
                pos=possible_win('o');
                go(pos);
                display_board();
                turn++;
                if(win('x'))
                    cout<<"AI WINS!!";
                else
                    user_input();
            }            break;
        case 9:
            cout<<"AI's Turn"<<endl;
            for(int i=1;i<9;i++){
                if(board[i]==2){
                    go(i);
                    break;
                }
            }
            display_board();
            if(win('x'))
                cout<<"AI WINS";
            else if(win('o'))
                cout<<"YOU WIN";
            else
                cout<<"MATCH DRAW";
            break;
        }
    }
    else{
    switch(turn){
    case 2:
        cout<<"AI TURN"<<endl;
        if(board[5]==2){
            go(5);
            turn++;
            display_board();
            user_input();
        }
        else{
            go(1);
            turn++;
            display_board();
            user_input();
        }
        break;
    case 4:
        cout<<"AI TURN"<<endl;
        if(possible_win('x')){
            pos=possible_win('x');
            go(pos);
            turn++;
            display_board();
            user_input();
        }
        else{
            if(board[3]==2)
                go(7);
            else if(board[7]==2)
                go(3);
            else
                go(1);
            turn++;
            display_board();
            user_input();
        }
        break;
    case 6:
        cout<<"AI TURN"<<endl;
        if(possible_win('o')){
            pos=possible_win('o');
            go(pos);
            display_board();
            cout<<"AI WINS";
        }
        else if(win('x')){
            cout<<"YOU WIN";
            display_board();
        }
        else if(possible_win('x')){
            pos=possible_win('x');
            go(pos);
            turn++;
            display_board();
            user_input();
        }
        break;
    case 8:
        cout<<"AI's TURN"<<endl;
        if(possible_win('o')){
            pos=possible_win('o');
            go(pos);
            display_board();
            cout<<"AI WINS";
        }
        else if(win('x')){
            cout<<"YOU WIN";
            display_board();
        }
        else if(possible_win('x')){
            pos=possible_win('x');
            go(pos);
            turn++;
            display_board();
            user_input();
        }
        break;
    case 10:
        if(win('x')){
            cout<<"YOU WIN";
        }
        else if(win('o')){
            cout<<"AI WINS";
        }
        else{
            cout<<"MATCH DRAW";
        }
    }
    }
}

int main()
{
    int i;
    for(int i=1;i<=9;i++)
        board[i]=2;
    display_board();
    cout<<"AI 1, User 2";
    cin>>first_turn;
    if(first_turn==1)
        comp_move();
    else
        user_input();
    return 0;
}
