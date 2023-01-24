#ifndef IO_CPP
#define IO_CPP

#include <iostream>
#include <time.h>
#include "solve24.cpp"

using namespace std;

int randomizer() {
    long rand = clock();
    return (rand%13)+1;
}

int userinput(int k) {
    int i = 15;
    string input;

    while ((i > 13)|| (i < 1)) {
        cout << "Masukkan kartu ke-" << k << " : ";
        cin >> input;
        i = card2int(input);
        if ((i > 13)|| (i < 1)) {
            cout << "Masukan tidak sesuai!\n";
        }
    }
    
    return i;
}

void fileoutput(string result) {

}

/*int main() {
    userinput(3);
}*/

#endif