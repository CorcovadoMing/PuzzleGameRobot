#include <iostream>
#include <vector>
#include <ctime>
#include "puzzle.h"
using namespace std;

double fitness();

void print(){
    for(int i = 0; i < global::col; i++){
        for(int j = 0; j < global::row; j++)
            cout << global::board[i][j] << " ";
        cout << endl;
    }
    cout << "adjacent: " << checkAdjacent() << endl;
    cout << "combo: " << checkCombo() << endl;
    cout << "fitness: " << fitness() << endl << endl;
}

double fitness(){
    return checkAdjacent() + 2.5 *checkCombo();
}

vector<int> II(int loop, int r, int c){
    const int range = 6;
    int cur_r = r, cur_c = c; // starting point
    vector<int> path;
    
    while(loop--){
        double score[4] = {-1, -1, -1, -1};
        // R -> D -> L -> U
        // R
        if(cur_r + 1 < range){
            swap(global::board[cur_c][cur_r], global::board[cur_c][cur_r+1]);
            score[0] = fitness();
            swap(global::board[cur_c][cur_r], global::board[cur_c][cur_r+1]);
        }
        // D
        if(cur_c + 1 < range){
            swap(global::board[cur_c][cur_r], global::board[cur_c+1][cur_r]);
            score[1] = fitness();
            swap(global::board[cur_c][cur_r], global::board[cur_c+1][cur_r]);
        }
        // L
        if(cur_r - 1 > -1){
            swap(global::board[cur_c][cur_r], global::board[cur_c][cur_r-1]);
            score[2] = fitness();
            swap(global::board[cur_c][cur_r], global::board[cur_c][cur_r-1]);
        }
        // U
        if(cur_c -1 > -1){
            swap(global::board[cur_c][cur_r], global::board[cur_c-1][cur_r]);
            score[3] = fitness();
            swap(global::board[cur_c][cur_r], global::board[cur_c-1][cur_r]);
        }
        
        double best_move = fitness();
        int move = -1;
        for(int i = 0; i < 4; i++){
            if(score[i] != -1 && score[i] > best_move){
                best_move = score[i];
                move = i;
            }
        }
        
        if(move == -1 && loop > 30){
            while(1){
                int index = rand()%4;
                if(score[index] != -1){
                    move = index;
                    break;
                }
            }
        }
        
        if(move != -1)
        switch(move){
            case 0: {
                swap(global::board[cur_c][cur_r], global::board[cur_c][cur_r+1]); 
                cur_r++;
                path.push_back(0);
                break;
            }
            case 1: {
                swap(global::board[cur_c][cur_r], global::board[cur_c+1][cur_r]); 
                cur_c++;
                path.push_back(1);
                break;
            }
            case 2: { 
                swap(global::board[cur_c][cur_r], global::board[cur_c][cur_r-1]); 
                cur_r--;
                path.push_back(2);
                break;
            }
            case 3: {
                swap(global::board[cur_c][cur_r], global::board[cur_c-1][cur_r]); 
                cur_c--;
                path.push_back(3);
                break;
            }
        }
    }
    return path;
}

void analysis(){
    srand(time(0));
    int times = 50;
    while(times--){
        int before = 0, after = 0;
        int run = 1000;
        while(run--){
            initRandomize();
            before += checkCombo();
            II(500, 1, 1);
            after += checkCombo();
        }
        cout << "improve: " << (after+0.1)/1000 - (before+0.1)/1000 << "\tresult: " << (after+0.1)/1000 << endl;
    }
}

int main (int argc, char const *argv[]){
    initRandomize();
    vector<int> path = II(500, 1, 1);
    vector<int> clean = cleanPath(path);
    
    for(int i: clean){
        cout << i << " ";
    }
    return 0;
}