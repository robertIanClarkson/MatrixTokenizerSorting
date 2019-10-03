#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

bool operator < ( TokenFreq& ob1, TokenFreq& ob2 ) {
    if ( ob1.freq < ob2.freq ) {
        return true;
    } else {
        return false;
    }
}

bool operator > ( TokenFreq& ob1, TokenFreq& ob2 ) {
    if ( ob1.freq > ob2.freq ) {
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

vector<string> getTokens( string& istr ) {
    vector<string> tokens;
    char current;
    string buffer = "";
    int startIndex = 0;
    int endIndex = 0;
    for (int i = 0; i < istr.length(); i++ ) {
        current = istr.at( i );
        if ( current == ' ' ) {
            endIndex = i;
            buffer = istr.substr( startIndex, (endIndex - startIndex) );
            startIndex = endIndex + 1;
            tokens.push_back( buffer );
        } else if ( i == istr.length() -1 ) {
            endIndex = i +1;
            buffer = istr.substr( startIndex, (endIndex - startIndex) );
            tokens.push_back( buffer );
        }
    }
    return tokens;
}

string toLowerCase( string& token ) {
    transform( token.begin(), token.end(), token.begin(), ::tolower);
    return token;
}

void processToken( string token, vector<TokenFreq> & tfVec ) {
    TokenFreq newToken;
    string currentToken;
    for ( int i = 0; i < tfVec.size(); i++ ) {
        currentToken = tfVec.at( i ).token;
        if( toLowerCase( token ) == toLowerCase( currentToken ) ) {
            tfVec.at( i ).freq += 1;
            return;
        }
    }
    newToken.token = token;
    newToken.freq = 1;
    tfVec.push_back( newToken );
}

/*  istr ==> input string
    tfVec ==> used to store the list of unique and case insensitive tokens
                    and their corresponding frequencies identified within istr
*/
void getTokenFreqVec( string& istr, vector<TokenFreq> & tfVec ) {
    vector<string> tokens = getTokens( istr );
    for ( int i = 0; i < tokens.size(); i++ ) {
        processToken( tokens.at(i), tfVec );
    }
}

void print( vector<TokenFreq> tfVec ) {
    for( int i = 0; i < tfVec.size(); i++ ) {
        cout << tfVec.at( i ) << endl;
    }
}

void selectionSort( vector<TokenFreq> & tokFreqVector ) {
    TokenFreq *min;
    for ( int i = 0; i < tokFreqVector.size(); i++ ) {
        min = &tokFreqVector.at( i );
        for ( int j = i; j < tokFreqVector.size(); j++ ) {
            if ( tokFreqVector.at( j ) < *min ) {
                min = &tokFreqVector.at( j );
            }
        }
        swap( tokFreqVector.at( i ), *min );
    }
}

void insertionSort( vector<TokenFreq> & tokFreqVector ) {
    // vector<TokenFreq> sorted;
    // sorted.push_back( tokFreqVector.at(0) );
    TokenFreq x;
    int index;
    for ( int i = 1; i < tokFreqVector.size(); i++ ) {
        x = tokFreqVector.at(i);
        index = i;
        while ( index > 0 && tokFreqVector.at( index -1 ) > x ) {
            tokFreqVector.at( index ) = tokFreqVector.at( index - 1 );
            index -= 1;
        }
        tokFreqVector.at( index ) = x;
    }
}

int main() {
    vector< vector<int> > matrix;
    int numRows, numCols;
    numRows = 1;
    numCols = 2;
    matrixInit( matrix, numRows, numCols );
    // string sample = "hello hello hi hi hi hey";
    string sample = "And no, I'm not a walking C++ dictionary. I do not keep every technical detail in my head at all times. If I did that, I would be a much poorer programmer. I do keep the main points straight in my head most of the time, and I do know where to find the details when I need them. by Bjarne Stroustrup";
    vector<TokenFreq> tfVec;
    getTokenFreqVec( sample, tfVec );
    print( tfVec );
    // selectionSort( tfVec );
    cout << endl;
    insertionSort( tfVec );
    print( tfVec );
}
