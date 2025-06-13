
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
//#define int long long
using namespace std;

class Puzzle{

private :
    vector<vector<int>> board;

public :
    Puzzle(){}
    Puzzle( vector<vector<int>> Board ){
        board = Board;
    }
    vector<vector<int>> display(){
        return board;
    }
    void print(){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void generatePath( queue <Puzzle> &boards , set<vector<vector<int>>> &vis){
        int x , y , temp;
        vector<vector<int>> new_board;
        for(int i = 0; i < 4; i++){
            for(int j = 0 ; j < 4; j++){
                if(board[i][j] == 0){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if(x > 0){
            new_board = board;
            temp = new_board[x - 1][y];
            new_board[x - 1][y] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                boards.push(Puzzle(new_board));
                vis.insert(new_board);
            }
            


        }
        if(x < 3){
            new_board = board;
            temp = new_board[x + 1][y];
            new_board[x + 1][y] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                boards.push(Puzzle(new_board));
                vis.insert(new_board);
            }
            


        }
        if(y > 0){
            new_board = board;
            temp = new_board[x][y - 1];
            new_board[x][y - 1] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                boards.push(Puzzle(new_board));
                vis.insert(new_board);
            }

        }
        if(y < 3){
            new_board = board;
            temp = new_board[x][y + 1];
            new_board[x][y + 1] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                boards.push(Puzzle(new_board));
                vis.insert(new_board);
            }
            


        }

    }

   
    
};
int main(){
    vector<vector<int>> input( 4, vector<int>(4 , 0));
    set<vector<vector<int>>> vis;
    cout << "Enter board :"<< endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> input[i][j];
        }
    }
    vis.insert(input);
    vector<vector<int>> ans;
    ans = {{1 , 2, 3, 4},
           {5 , 6, 7, 8},
           {9 , 10 , 11, 12},
           {13 , 14 , 15 , 0}};

    queue<Puzzle> boards;
    boards.push(Puzzle(input));
    Puzzle board;
    while(!boards.empty()){
        board = boards.front();
        boards.pop();
        if( board.display() == ans){
            cout << "found " << endl;
            board.print();
            
            break;
        }
        board.generatePath( boards , vis);










    }
    return 0;
}