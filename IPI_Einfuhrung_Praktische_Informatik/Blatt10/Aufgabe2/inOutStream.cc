#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void copyFile(string filename) {
    string inName = filename;
    string outName = inName.substr(0, inName.size() - 4) + "-a.txt";
    ifstream in(inName.c_str(), ios::in);
    ofstream out(outName.c_str(), ios::out);
    int lineNbr = 1;

    while(in.good()) {
        string line;
        getline(in, line);
        out << lineNbr << ": " << line << endl;
        lineNbr++;
    }
}

main(int argc, char const *argv[])
{
    copyFile(argv[1]);
}
