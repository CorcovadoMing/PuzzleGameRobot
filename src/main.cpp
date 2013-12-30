#include <iostream>
#include <vector>
#include "trackheuristic.h"
#include "populationheuristic.h"
using namespace std;

int main (int argc, char const *argv[]){
    //initRandomize();
    readMatrix(argc, argv);
    vector<int> path = trackHeuristic(100, 0, 0);
    vector<int> clean = cleanPath(path);
    for(int i: clean){
        cout << i << " ";
    }
    return 0;
}