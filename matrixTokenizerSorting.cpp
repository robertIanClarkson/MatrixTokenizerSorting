#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TokenFreq {
    string token;
    int freq;
};

bool operator <= ( TokenFreq& ob1, TokenFreq& ob2 ) {
    if ( ob1.freq <= ob2.freq ) {
        return true;
    } else {
        return false;
    }
}

TokenFreq operator + ( TokenFreq& ob1, TokenFreq& ob2 ) {
    TokenFreq result;
    if( ob1.token.compare( ob2.token ) != 0 ) {
        result.token = ob1.token + " or " + ob2.token;
    } else {
        result.token = ob1.token;
    }
    result.freq = ob1.freq + ob2.freq;
    return result;
}

ostream& operator << ( ostream& output, TokenFreq& ob1 ) {
    output << "(token, freq)=(" << ob1.token << ", " << ob1.freq << ")";
    return output;
}

void matrixInit( vector< vector<int> >& matrix, int numRows, int numCols) {
    matrix.resize(numRows);
    for( int i = 0; i < numRows; i++ ) {
        matrix[i] = vector<int>(numCols);
    }
}

void getTokenFreqVec( string& istr, vector<TokenFreq> & tfVec) {

}

int main() {
    vector< vector<int> > matrix;
    int numRows, numCols;
    matrixInit( matrix, numRows, numCols );

    TokenFreq test1;
    TokenFreq test2;
    TokenFreq test3;
    test1.token = "hello";
    test1.freq = 12;
    test2.token = "world";
    test2.freq = 8;

    test1 = test1 + test2;

    cout << test1.token << endl;
    cout << test1.freq << endl;
    cout << test1 << endl;
    cout << test2 << endl;

}
