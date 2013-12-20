#include <vector>
using namespace std;

namespace global{
    int size = 36;
    int row = 6;
    int col = 6;
    int board[6][6] = {0};
}

vector<int> cleanPath(vector<int>& path){
    vector<int> clean_path;
    for(int i = 0; i+2< path.size(); i+=2){
        int first = path[i];
        int second = path[i+1];
        
        switch(first){
            case 0:{
                if(second != 2){
                    clean_path.push_back(first);
                    clean_path.push_back(second);
                }
                break;
            }
            case 1:{
                if(second != 3){
                    clean_path.push_back(first);
                    clean_path.push_back(second);
                }
                break;
            }
            case 2:{
                if(second != 0){
                    clean_path.push_back(first);
                    clean_path.push_back(second);
                }
                break;
            }
            case 3:{
                if(second != 1){
                    clean_path.push_back(first);
                    clean_path.push_back(second);
                }
                break;
            }
        }
    }
    return clean_path;
}

void initRandomize(){
    for(int i = 0; i < global::col; i++)
        for(int j = 0; j < global::row; j++)
            global::board[i][j] = rand()%6; // six colors
}

int checkAdjacent(){
    int r_cur = -1; int c_cur = -1;
    int score = 0;

    for(int i = 0; i < global::col; i++){
        for(int j = 0; j < global::row; j++){
            if(j == 0){
                r_cur = global::board[i][j]; //row
                c_cur = global::board[j][i]; //col
            }
            else{
                //row
                if(global::board[i][j] == r_cur) score++;
                else r_cur = global::board[i][j];
                
                //col
                if(global::board[j][i] == c_cur) score++;
                else c_cur = global::board[j][i];
            }
        }
    }
    return score;
}

int checkCombo(){
    int r_cur = -1; int c_cur = -1;
    int r_count = 0; int c_count = 0;
    int combo = 0;
    
    for(int i = 0; i < global::col; i++){
        for(int j = 0; j < global::row; j++){
            if(j == 0){
                //row
                r_cur = global::board[i][j];
                r_count = 0;
                
                //col
                c_cur = global::board[j][i];
                c_count = 0;
            }
            else{
                //row
                if(global::board[i][j] == r_cur){
                    r_count++;
                    if(r_count == 2) combo++;
                }
                else{
                    r_cur = global::board[i][j];
                    r_count = 0;
                }
                
                //col
                if(global::board[j][i] == c_cur){
                    c_count++;
                    if(c_count == 2) combo++;
                }
                else{
                    c_cur = global::board[j][i];
                    c_count = 0;
                }
                
            }
        }
    }
    return combo;
}