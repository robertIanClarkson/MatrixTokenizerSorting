#include <iostream>
#include <vector>
#include <string>
using namespace std;

void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols) {
    matrix.resize(numRows);
    for( int i = 0; i < numRows; i++ ) {
        matrix[i] = vector<int>(numCols);
    }
}

int main() {
    vector< vector<int> > matrix;
    int numRows, numCols;
    matrixInit( matrix, numRows, numCols );
}
