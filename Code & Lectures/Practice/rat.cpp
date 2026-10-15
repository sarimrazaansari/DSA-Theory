#include <iostream>
using namespace std;

const int N=4;

int maze[N][N]={
    {1, 1, 1, 1},
    {0, 1, 1, 1},
    {0, 0, 0, 1},
    {0, 0, 1, 1}
};

int solution[N][N]={0};

bool isSafe(int row, int col){
    if(col>=0 && col<N && row>=0 && row<N && maze[row][col]==1) return true;
    return false;
}

bool Rat(int row, int col){
    if(row==N-1 && col==N-1){
        solution[row][col]=1;
        return true;
    }

    if(isSafe(row,col)){
        
        solution[row][col]=1;

        
        if(Rat(row+1,col)) return true; //down
        if(Rat(row,col+1)) return true; //right

        solution[row][col]=0; //backtracking
    }

    return false;
}

void displaySolution()
{
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    if (Rat(0,0)) displaySolution();
    else cout<<"No solution";
}