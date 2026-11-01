#include "iostream"
using namespace std;
#define N 4

int board[N][N]={0};

bool isSafe(int row, int col){
    
    //vertical
    for(int i=0 ; i<row ; i++){
        if(board[i][col]==1) return false;
    }

    //uppper left
    for(int i=row-1, j=col-1 ; i>=0 && j>=0 ; i--,j--){
        if(board[i][j]==1) return false;
    }

    //upper right
    for(int i=row-1, j=col+1 ; i>=0 && j<N ; i--,j++){
        if(board[i][j]==1) return false;
    }

    return true;
}

bool QueenProb(int row){
    if(row==N) return true;
    
    for(int col=0;col<N;col++){
        if(isSafe(row,col)){
            board[row][col]=1;
            if(QueenProb(row+1)) return true;
            board[row][col]=0;
        }
    }
    return false;

}

void display(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==1) cout<<"Q ";
            else cout<<". ";
        }
        cout<<endl;
    }
}

int main(){
    if(QueenProb(0)) display();
    else cout<<"No solution";
}