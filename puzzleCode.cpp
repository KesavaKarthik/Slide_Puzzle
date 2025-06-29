#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <chrono>
using namespace std;

int Manhatten_distance(vector<vector<int>> input ){
    int distance = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if( input[i][j] != 0 )distance += abs( (input[i][j] - 1)/ 4 - i ) + abs( (input[i][j] - 1) % 4 - j);
        }
    }
    return distance;

}

class Puzzle{

private :
    vector<vector<int>> board;
    int depth;



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

    bool operator<(const Puzzle& other) const {
        return board < other.board;
    }


    void generatePath( priority_queue<tuple<int, int, Puzzle>, vector<tuple<int, int, Puzzle>>, greater<tuple<int, int, Puzzle>>> &boards, set<vector<vector<int>>> &vis , int g ){
        int x , y , temp , h;
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
                h = Manhatten_distance(new_board);
                boards.push({g + h + 1 , g + 1 , Puzzle(new_board)} );
                vis.insert(new_board);
            }
            


        }
        if(x < 3){
            new_board = board;
            temp = new_board[x + 1][y];
            new_board[x + 1][y] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                h = Manhatten_distance(new_board);
                boards.push({g + h + 1, g + 1 , Puzzle(new_board)} );
                vis.insert(new_board);
            }
            


        }
        if(y > 0){
            new_board = board;
            temp = new_board[x][y - 1];
            new_board[x][y - 1] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                h = Manhatten_distance(new_board);
                boards.push({g + h + 1 , g + 1 , Puzzle(new_board)} );
                vis.insert(new_board);
            }

        }
        if(y < 3){
            new_board = board;
            temp = new_board[x][y + 1];
            new_board[x][y + 1] = 0;
            new_board[x][y] = temp;
            if( vis.find(new_board) == vis.end() ){
                h = Manhatten_distance(new_board);
                boards.push({g + h + 1 , g + 1 , Puzzle(new_board)} );
                vis.insert(new_board);
            }
            


        }

    }

   
    
};
int merge_sort(vector<int> &num){
    int size = num.size();
    if(size == 1){
        return 0;
    }
    int mid = size/ 2;
    vector<int> left (num.begin() , num.begin() + mid);
    vector<int> right ( num.begin() + mid, num.end());

    int lc = merge_sort(left);
    int rc = merge_sort(right);
    int i = 0 , j = 0;
    vector<int> temp( num.size());
    int t = 0;
    int count = 0;
    while(i < left.size() || j < right.size() ){
        if( i >= left.size()){
            temp[t] = right[j];
            j++;
        }
        else if( j >= right.size()){
            temp[t] = left[i];
            i++;
        }
        else if( left[i] < right[j]){
            temp[t] = left[i];
            i++;
        }
        else{
            count += left.size() - i;
            temp[t] = right[j];
            j++;
        }
        t++;
    }
    num = temp ;
    return count + lc + rc;
}


bool solvability_check(vector<vector<int>> input){
    vector<int> num(15);
    int row_number;
    int t = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if( input[i][j] != 0 ){
                num[t] = input[i][j];
                t++;
            }
            else row_number = 4 - i;
        }
    }
    int inversions = merge_sort(num);
    cout << inversions << " "<< row_number << endl;
    if( (inversions + row_number) % 2 == 0) return false;
    else return true;
}


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
    bool check = solvability_check(input);
    if( check == false){
        cout << "Incorrect input " << endl;
        return 0;
    }
    vector<vector<int>> ans;
    ans = {{1 , 2, 3, 4},
           {5 , 6, 7, 8},
           {9 , 10 , 11, 12},
           {13 , 14 , 15 , 0}};
    
    int distance = Manhatten_distance(input);
    priority_queue<tuple<int, int, Puzzle>, vector<tuple<int, int, Puzzle>>, greater<tuple<int, int, Puzzle>>> boards;
    boards.push({ distance , 0  ,Puzzle(input)});

    auto start = chrono :: high_resolution_clock :: now();
    Puzzle board;
    int g , f;
    while(!boards.empty()){
        f = get<0>(boards.top());
        g = get<1>(boards.top());
        board = get<2>(boards.top());
        //board.print();
        //cout << " "<< endl;
        boards.pop();
        if (g % 10 == 0) {
            cout << "Currently at depth: " << g << ", Manhattan: " << f - g << endl;
        }
        if( board.display() == ans){
            cout << "found " << endl;
            cout << "Count = " << g << endl;

            auto end = chrono :: high_resolution_clock :: now();
            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout <<"Time taken to solve = " << duration.count() << " ms"<<endl;
            break;
        }

        board.generatePath( boards , vis , g );
        

    }
    return 0;
}