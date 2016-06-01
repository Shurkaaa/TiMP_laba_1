#include <fstream>
#include <iostream>


using namespace std;


bool checkfile(string fname, string data);
void compare_files(string fname1, string fname2);


int main(int argc, const char * argv[]) {
    compare_files("file1.txt", "file2.txt");
    compare_files("file2.txt", "file1.txt");
    
    return 0;
}


bool checkfile(string fname, string data) {
    ifstream cmp(fname);
    
    while (!cmp.eof()) {
        string s;
        getline(cmp, s);
        if (s == data)
            return true;
    }
    
    cmp.close();
    return false;
}


void compare_files(string fname1, string fname2) {
    ifstream ist(fname1);
    int i = 0;
    
    while (!ist.eof()) {
        string s;
        getline(ist, s);
        i++;
        if (!checkfile(fname2, s))
            cout << fname1 << " " << i << " \"" << s << "\"" << endl;
    }
    
    ist.close();
    return;
}