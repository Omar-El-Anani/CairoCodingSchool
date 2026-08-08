#include <iostream>
#include <string>


using namespace std;

void XoBoard(char board[3][3]) {
    cout<<"   1   2   3"<<endl;

    for (int i = 0; i < 3; i++) {
        cout<<i + 1 <<" ";

        for (int j = 0; j < 3; j++) {
            cout<<" "<<board[i][j] <<" ";

            if (j < 2) {
                cout<<"|";
            }

        }
        cout<<endl;


        if (i < 2) {
            cout<<"   ---+---+---"<<endl;
        }
    }
    cout<<endl;
}

bool ChekWinner(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            //Check Rows & Columns
        {
            return true;
        }

    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        //Chek Diagonals

    {
        return true;
    }

    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}





int main() {
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int row,col;
    char currentplayer='X';


    while (true) {
        XoBoard(board);

        cout<<"Player "<<currentplayer<<" , enter row (1-3) and column (1-3): ";
        cin>>row>>col;

        row--; col--; //convert to 0-based index

        if (row<0 || row>2||col<0 || col>2 || board[row][col]!=' ') {
            cout<<"Invalid input! , Try again."<<endl;
            continue;
        }
        board[row][col]=currentplayer;

        if (ChekWinner(board,currentplayer)) {
            XoBoard(board);
            cout<<"Player "<<currentplayer<<" Wins!"<<endl;
            break;
        }
        if (isBoardFull(board)) {
            XoBoard(board);
            break;
        }

        //switch players
        if (currentplayer=='X') {
            currentplayer='O';
        }else {
            currentplayer='X';
        }
    }
    return 0;
}