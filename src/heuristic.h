#include <iostream>
#include <vector>
#include <ctime>
#include "puzzle.h"
using namespace std;

double fitness();

void print(){
    for(int i = 0; i < global::row; i++){
        for(int j = 0; j < global::col; j++)
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
    const int r_range = 5, c_range = 6;
    int cur_r = r, cur_c = c; // starting point
    vector<int> path;
    
    while(loop--){
        double score[4] = {-1, -1, -1, -1};
        // R -> D -> L -> U
        // R
        if(cur_c + 1 < c_range){
            swap(global::board[cur_r][cur_c], global::board[cur_r][cur_c+1]);
            score[0] = fitness();
            swap(global::board[cur_r][cur_c], global::board[cur_r][cur_c+1]);
        }
        // D
        if(cur_r + 1 < r_range){
            swap(global::board[cur_r][cur_c], global::board[cur_r+1][cur_c]);
            score[1] = fitness();
            swap(global::board[cur_r][cur_c], global::board[cur_r+1][cur_c]);
        }
        // L
        if(cur_c - 1 > -1){
            swap(global::board[cur_r][cur_c], global::board[cur_r][cur_c-1]);
            score[2] = fitness();
            swap(global::board[cur_r][cur_c], global::board[cur_r][cur_c-1]);
        }
        // U
        if(cur_r -1 > -1){
            swap(global::board[cur_r][cur_c], global::board[cur_r-1][cur_c]);
            score[3] = fitness();
            swap(global::board[cur_r][cur_c], global::board[cur_r-1][cur_c]);
        }
        
        double best_move = fitness();
        int move = -1;
        for(int i = 0; i < 4; i++){
            if(score[i] != -1 && score[i] > best_move){
                best_move = score[i];
                move = i;
            }
        }
        
        if(move == -1 && loop > 10){
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
                swap(global::board[cur_r][cur_c], global::board[cur_r][cur_c+1]);
                cur_c++;
                path.push_back(0);
                break;
            }
            case 1: {
                swap(global::board[cur_r][cur_c], global::board[cur_r+1][cur_c]); 
                cur_r++;
                path.push_back(1);
                break;
            }
            case 2: { 
                swap(global::board[cur_r][cur_c], global::board[cur_r][cur_c-1]); 
                cur_c--;
                path.push_back(2);
                break;
            }
            case 3: {
                swap(global::board[cur_r][cur_c], global::board[cur_r-1][cur_c]); 
                cur_r--;
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
            II(500, 0, 0);
            after += checkCombo();
        }
        cout << "improve: " << (after+0.1)/1000 - (before+0.1)/1000 << "\tresult: " << (after+0.1)/1000 << endl;
    }
}