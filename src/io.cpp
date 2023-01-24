#ifndef IO_CPP
#define IO_CPP

#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
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

void fileoutput(int count, string result, string file_name) {
    string fileName = file_name+".txt";
    ofstream fw;
    fw.open("test/"+fileName);
    if (fw.is_open()) {
        fw << "Terdapat " << count << " kombinasi yang menghasilkan 24.\n";
        fw << result;
        fw.close();
        cout << "File berhasil di simpan! \n\n";
    } else {
        cout << "Terdapat kesalahan membuka file.\n\n";
    }
}

/*int main() {
    userinput(3);
}*/

#endif