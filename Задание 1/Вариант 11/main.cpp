#include <string>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void countDividers() {

    int signsCount = 0;
    int linesCount = 1;

    ifstream fs ("file.txt");

    string  line;
    if (fs.is_open())
    {
        while ( getline (fs,line) )
        {
            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == ',' || line[i] == '.' || line[i] == ':' || line[i] == ';' || line[i] == '!' || line[i] == '?'){
                    signsCount++;
                }
            }
            if(signsCount!=0){
                cout<<"Строка "<<linesCount<<" содержит"<<signsCount<<" знак(ов) препинания"<<endl;
            } else {
                cout<< "В строке "<<linesCount<< " не обнаружено знаков препинания"<<endl;
            }
            linesCount++;
            signsCount = 0;
        }
        fs.close();
    }
    else cout << "Unable to open file";
}

int main() {
    countDividers();
    return 0;
}


