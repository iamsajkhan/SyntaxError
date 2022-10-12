#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

char findMismatch( string &input ){
    stack<char> mem;
    unordered_map<char, char> map = {{'(',')'}, {'[',']'}, {'{','}'}, {'<','>'}};

    for( char c : input ){
        if( map.find(c) != map.end() ){
            mem.push(c);
        }
        else if( map[mem.top()]  == c ){
            mem.pop();
        }
        else{
            return c;
        }
    }
    return '\0';
}

int main( int argc, char *argv[] ){

    ifstream input( argv[1] );
    if( !input.is_open() ){
        cout << "Failed to open!"<<endl;
        return 1;
    }
    unordered_map<char, int> scoreMap = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
    string line;
    int lineNum = 0;
    int score = 0;
    while( getline( input, line )){
        char c = findMismatch( line );
        if( c != '\0' ){
            score += scoreMap[c];
            cout << "First mistached char at line : "<< lineNum << " is : "<< c  << " & score is : "<< score << endl;
            lineNum++;
        }
    }
    return 1;
}
