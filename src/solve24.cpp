#ifndef SOLVE24_CPP
#define SOLVE24_CPP

#include <iostream>
#include <random>
using namespace std;

// Fungsi untuk mengubah input dari char menjadi integer
int card2int(string x) {
    int result;
    string key1 = "A";
    string key2 = "2";
    string key3 = "3";
    string key4 = "4";
    string key5 = "5";
    string key6 = "6";
    string key7 = "7";
    string key8 = "8";
    string key9 = "9";
    string key10 = "10";
    string key11 = "J";
    string key12 = "Q";
    string key13 = "K";
    if (x == key1) {
        result = 1;
    } else if (x == key2) {
        result = 2;
    } else if (x == key3) {
        result = 3;
    } else if (x == key4) {
        result = 4;
    } else if (x == key5) {
        result = 5;
    } else if (x == key6) {
        result = 6;
    } else if (x == key7) {
        result = 7;
    } else if (x == key8) {
        result = 8;
    } else if (x == key9) {
        result = 9;
    } else if (x == key10) {
        result = 10;
    } else if (x == key11) {
        result = 11;
    } else if (x == key12) {
        result = 12;
    } else if (x == key13) {
        result = 13;
    }
    return result;
}

// Fungsi untuk mengubah integer menjadi char pada card sebelum dikeluarkan
string int2card(int x) {
    string result;
    if (x == 1) {
        result = 'A';
    } else if (x == 2) {
        result = '2';
    } else if (x == 3) {
        result = '3';
    } else if (x == 4) {
        result = '4';
    } else if (x == 5) {
        result = '5';
    } else if (x == 6) {
        result = '6';
    } else if (x == 7) {
        result = '7';
    } else if (x == 8) {
        result = '8';
    } else if (x == 9) {
        result = '9';
    } else if (x == 10) {
        result = "10";
    } else if (x == 11) {
        result = 'J';
    } else if (x == 12) {
        result = 'Q';
    } else if (x == 13) {
        result = 'K';
    }
    return result;
}

// Fungsi untuk menambahkan hasil yang sesuai menuju array result a x b y c z d with type of brackets
string resultstr(int* array, char x, char y, char z, int bracket_type) {
    string result;
    // bracket_type 0 (no bracket)
    if (bracket_type == 0) {
        result = int2card(array[0]) + " " + x + " " + int2card(array[1]) + " " + y + " " + int2card(array[2]) + " " + z + " " + int2card(array[3]) + "\n";
        cout << result;
    } 
    
    // bracket_type 1 ((a _ b) _ (c _ d))
    else if (bracket_type == 1) {
        result = "(" + int2card(array[0]) + " " + x + " " + int2card(array[1]) + ") " + y + " (" + int2card(array[2]) + " " + z + " " + int2card(array[3]) + ")\n";
        cout << result;
    }

    // bracket_type 2 (((a _ b) _ c) _ d)
    else if (bracket_type == 2) {
        result = "(((" + int2card(array[0]) + " " + x + " " + int2card(array[1]) + ") " + y + " " + int2card(array[2]) + ") " + z + " " + int2card(array[3]) + ")\n";
        cout << result;
    }

    // bracket_type 3 ((a _ (b _ c)) _ d)
    else if (bracket_type == 3) {
        result = "((" + int2card(array[0]) + " " + x + " (" + int2card(array[1]) + " " + y + " " + int2card(array[2]) + ")) " + z + " " + int2card(array[3]) + ")\n";
        cout << result;
    }

    // bracket_type 4 (a _ ((b _ c) _ d))
    else if (bracket_type == 4) {
        result = "(" + int2card(array[0]) + " " + x + " ((" + int2card(array[1]) + " " + y + " " + int2card(array[2]) + ") " + z + " " + int2card(array[3]) + "))\n";
        cout << result;
    }

    // bracket_type 5 (a _ (b _ (c _ d)))
    else if (bracket_type == 5) {
        result = "(" + int2card(array[0]) + " " + x + " (" + int2card(array[1]) + " " + y + " (" + int2card(array[2]) + " " + z + " " + int2card(array[3]) + ")))\n";
        cout << result;
    }
    return result;
}

// Fungsi untuk mengecek kombinasi operasi yang dapat menghasilkan 24
int solver24e(int d[4], string *result) {
    int count = 0;

    // a _ b _ c _ d
    if (d[0]+d[1]+d[2]+d[3] == 24) {count++; *result += resultstr(d,'+','+','+',0);}
    if (d[0]*d[1]*d[2]*d[3] == 24) {count++; *result += resultstr(d,'*','*','*',0);}
    
    // (a _ b) _ (c _ d)
    if ((d[0]-d[1])+(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'-','+','+',1);}
    if ((d[0]*d[1])+(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'*','+','+',1);}
    if ((d[0]/d[1])+(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'/','+','+',1);}
    if ((d[0]+d[1])-(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'+','-','+',1);}
    if ((d[0]-d[1])-(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'-','-','+',1);}
    if ((d[0]*d[1])-(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'*','-','+',1);}
    if ((d[0]/d[1])-(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'/','-','+',1);}
    if ((d[0]+d[1])*(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'+','*','+',1);}
    if ((d[0]-d[1])*(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'-','*','+',1);}
    if ((d[0]*d[1])*(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'*','*','+',1);}
    if ((d[0]/d[1])*(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'/','*','+',1);}
    if ((d[0]+d[1])/(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'+','/','+',1);}
    if ((d[0]-d[1])/(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'-','/','+',1);}
    if ((d[0]*d[1])/(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'*','/','+',1);}
    if ((d[0]/d[1])/(d[2]+d[3]) == 24) {count++; *result += resultstr(d,'/','/','+',1);}

    if ((d[0]+d[1])+(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'+','+','-',1);}
    if ((d[0]-d[1])+(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'-','+','-',1);}
    if ((d[0]*d[1])+(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'*','+','-',1);}
    if ((d[0]/d[1])+(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'/','+','-',1);}
    if ((d[0]-d[1])-(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'-','-','-',1);}
    if ((d[0]*d[1])-(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'*','-','-',1);}
    if ((d[0]/d[1])-(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'/','-','-',1);}
    if ((d[0]+d[1])*(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'+','*','-',1);}
    if ((d[0]-d[1])*(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'-','*','-',1);}
    if ((d[0]*d[1])*(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'*','*','-',1);}
    if ((d[0]/d[1])*(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'/','*','-',1);}
    if ((d[0]+d[1])/(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'+','/','-',1);}
    if ((d[0]-d[1])/(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'-','/','-',1);}
    if ((d[0]*d[1])/(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'*','/','-',1);}
    if ((d[0]/d[1])/(d[2]-d[3]) == 24) {count++; *result += resultstr(d,'/','/','-',1);}

    if ((d[0]+d[1])+(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'+','+','*',1);}
    if ((d[0]-d[1])+(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'-','+','*',1);}
    if ((d[0]*d[1])+(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'*','+','*',1);}
    if ((d[0]/d[1])+(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'/','+','*',1);}
    if ((d[0]+d[1])-(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'+','-','*',1);}
    if ((d[0]-d[1])-(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'-','-','*',1);}
    if ((d[0]*d[1])-(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'*','-','*',1);}
    if ((d[0]/d[1])-(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'/','-','*',1);}
    if ((d[0]+d[1])*(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'+','*','*',1);}
    if ((d[0]-d[1])*(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'-','*','*',1);}
    if ((d[0]/d[1])*(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'/','*','*',1);}
    if ((d[0]+d[1])/(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'+','/','*',1);}
    if ((d[0]-d[1])/(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'-','/','*',1);}
    if ((d[0]*d[1])/(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'*','/','*',1);}
    if ((d[0]/d[1])/(d[2]*d[3]) == 24) {count++; *result += resultstr(d,'/','/','*',1);}

    if ((d[0]+d[1])+(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'+','+','/',1);}
    if ((d[0]-d[1])+(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'-','+','/',1);}
    if ((d[0]*d[1])+(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'*','+','/',1);}
    if ((d[0]/d[1])+(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'/','+','/',1);}
    if ((d[0]+d[1])-(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'+','-','/',1);}
    if ((d[0]-d[1])-(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'-','-','/',1);}
    if ((d[0]*d[1])-(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'*','-','/',1);}
    if ((d[0]/d[1])-(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'/','-','/',1);}
    if ((d[0]+d[1])*(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'+','*','/',1);}
    if ((d[0]-d[1])*(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'-','*','/',1);}
    if ((d[0]*d[1])*(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'*','*','/',1);}
    if ((d[0]/d[1])*(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'/','*','/',1);}
    if ((d[0]+d[1])/(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'+','/','/',1);}
    if ((d[0]-d[1])/(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'-','/','/',1);}
    if ((d[0]*d[1])/(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'*','/','/',1);}
    if ((d[0]/d[1])/(d[2]/d[3]) == 24) {count++; *result += resultstr(d,'/','/','/',1);}

    // ((a _ b) _ c) _ d
    if (((d[0]-d[1])+d[2])+d[3] == 24) {count++; *result += resultstr(d,'-','+','+',2);}
    if (((d[0]*d[1])+d[2])+d[3] == 24) {count++; *result += resultstr(d,'*','+','+',2);}
    if (((d[0]/d[1])+d[2])+d[3] == 24) {count++; *result += resultstr(d,'/','+','+',2);}
    if (((d[0]+d[1])-d[2])+d[3] == 24) {count++; *result += resultstr(d,'+','-','+',2);}
    if (((d[0]-d[1])-d[2])+d[3] == 24) {count++; *result += resultstr(d,'-','-','+',2);}
    if (((d[0]*d[1])-d[2])+d[3] == 24) {count++; *result += resultstr(d,'*','-','+',2);}
    if (((d[0]/d[1])-d[2])+d[3] == 24) {count++; *result += resultstr(d,'/','-','+',2);}
    if (((d[0]+d[1])*d[2])+d[3] == 24) {count++; *result += resultstr(d,'+','*','+',2);}
    if (((d[0]-d[1])*d[2])+d[3] == 24) {count++; *result += resultstr(d,'-','*','+',2);}
    if (((d[0]*d[1])*d[2])+d[3] == 24) {count++; *result += resultstr(d,'*','*','+',2);}
    if (((d[0]/d[1])*d[2])+d[3] == 24) {count++; *result += resultstr(d,'/','*','+',2);}
    if (((d[0]+d[1])/d[2])+d[3] == 24) {count++; *result += resultstr(d,'+','/','+',2);}
    if (((d[0]-d[1])/d[2])+d[3] == 24) {count++; *result += resultstr(d,'-','/','+',2);}
    if (((d[0]*d[1])/d[2])+d[3] == 24) {count++; *result += resultstr(d,'*','/','+',2);}
    if (((d[0]/d[1])/d[2])+d[3] == 24) {count++; *result += resultstr(d,'/','/','+',2);}

    if (((d[0]+d[1])+d[2])-d[3] == 24) {count++; *result += resultstr(d,'+','+','-',2);}
    if (((d[0]-d[1])+d[2])-d[3] == 24) {count++; *result += resultstr(d,'-','+','-',2);}
    if (((d[0]*d[1])+d[2])-d[3] == 24) {count++; *result += resultstr(d,'*','+','-',2);}
    if (((d[0]/d[1])+d[2])-d[3] == 24) {count++; *result += resultstr(d,'/','+','-',2);}
    if (((d[0]+d[1])-d[2])-d[3] == 24) {count++; *result += resultstr(d,'+','-','-',2);}
    if (((d[0]-d[1])-d[2])-d[3] == 24) {count++; *result += resultstr(d,'-','-','-',2);}
    if (((d[0]*d[1])-d[2])-d[3] == 24) {count++; *result += resultstr(d,'*','-','-',2);}
    if (((d[0]/d[1])-d[2])-d[3] == 24) {count++; *result += resultstr(d,'/','-','-',2);}
    if (((d[0]+d[1])*d[2])-d[3] == 24) {count++; *result += resultstr(d,'+','*','-',2);}
    if (((d[0]-d[1])*d[2])-d[3] == 24) {count++; *result += resultstr(d,'-','*','-',2);}
    if (((d[0]*d[1])*d[2])-d[3] == 24) {count++; *result += resultstr(d,'*','*','-',2);}
    if (((d[0]/d[1])*d[2])-d[3] == 24) {count++; *result += resultstr(d,'/','*','-',2);}
    if (((d[0]+d[1])/d[2])-d[3] == 24) {count++; *result += resultstr(d,'+','/','-',2);}
    if (((d[0]-d[1])/d[2])-d[3] == 24) {count++; *result += resultstr(d,'-','/','-',2);}
    if (((d[0]*d[1])/d[2])-d[3] == 24) {count++; *result += resultstr(d,'*','/','-',2);}
    if (((d[0]/d[1])/d[2])-d[3] == 24) {count++; *result += resultstr(d,'/','/','-',2);}

    if (((d[0]+d[1])+d[2])*d[3] == 24) {count++; *result += resultstr(d,'+','+','*',2);}
    if (((d[0]-d[1])+d[2])*d[3] == 24) {count++; *result += resultstr(d,'-','+','*',2);}
    if (((d[0]*d[1])+d[2])*d[3] == 24) {count++; *result += resultstr(d,'*','+','*',2);}
    if (((d[0]/d[1])+d[2])*d[3] == 24) {count++; *result += resultstr(d,'/','+','*',2);}
    if (((d[0]+d[1])-d[2])*d[3] == 24) {count++; *result += resultstr(d,'+','-','*',2);}
    if (((d[0]-d[1])-d[2])*d[3] == 24) {count++; *result += resultstr(d,'-','-','*',2);}
    if (((d[0]*d[1])-d[2])*d[3] == 24) {count++; *result += resultstr(d,'*','-','*',2);}
    if (((d[0]/d[1])-d[2])*d[3] == 24) {count++; *result += resultstr(d,'/','-','*',2);}
    if (((d[0]+d[1])*d[2])*d[3] == 24) {count++; *result += resultstr(d,'+','*','*',2);}
    if (((d[0]-d[1])*d[2])*d[3] == 24) {count++; *result += resultstr(d,'-','*','*',2);}
    if (((d[0]/d[1])*d[2])*d[3] == 24) {count++; *result += resultstr(d,'/','*','*',2);}
    if (((d[0]+d[1])/d[2])*d[3] == 24) {count++; *result += resultstr(d,'+','/','*',2);}
    if (((d[0]-d[1])/d[2])*d[3] == 24) {count++; *result += resultstr(d,'-','/','*',2);}
    if (((d[0]*d[1])/d[2])*d[3] == 24) {count++; *result += resultstr(d,'*','/','*',2);}
    if (((d[0]/d[1])/d[2])*d[3] == 24) {count++; *result += resultstr(d,'/','/','*',2);}

    if (((d[0]+d[1])+d[2])/d[3] == 24) {count++; *result += resultstr(d,'+','+','/',2);}
    if (((d[0]-d[1])+d[2])/d[3] == 24) {count++; *result += resultstr(d,'-','+','/',2);}
    if (((d[0]*d[1])+d[2])/d[3] == 24) {count++; *result += resultstr(d,'*','+','/',2);}
    if (((d[0]/d[1])+d[2])/d[3] == 24) {count++; *result += resultstr(d,'/','+','/',2);}
    if (((d[0]+d[1])-d[2])/d[3] == 24) {count++; *result += resultstr(d,'+','-','/',2);}
    if (((d[0]-d[1])-d[2])/d[3] == 24) {count++; *result += resultstr(d,'-','-','/',2);}
    if (((d[0]*d[1])-d[2])/d[3] == 24) {count++; *result += resultstr(d,'*','-','/',2);}
    if (((d[0]/d[1])-d[2])/d[3] == 24) {count++; *result += resultstr(d,'/','-','/',2);}
    if (((d[0]+d[1])*d[2])/d[3] == 24) {count++; *result += resultstr(d,'+','*','/',2);}
    if (((d[0]-d[1])*d[2])/d[3] == 24) {count++; *result += resultstr(d,'-','*','/',2);}
    if (((d[0]*d[1])*d[2])/d[3] == 24) {count++; *result += resultstr(d,'*','*','/',2);}
    if (((d[0]/d[1])*d[2])/d[3] == 24) {count++; *result += resultstr(d,'/','*','/',2);}
    if (((d[0]+d[1])/d[2])/d[3] == 24) {count++; *result += resultstr(d,'+','/','/',2);}
    if (((d[0]-d[1])/d[2])/d[3] == 24) {count++; *result += resultstr(d,'-','/','/',2);}
    if (((d[0]*d[1])/d[2])/d[3] == 24) {count++; *result += resultstr(d,'*','/','/',2);}
    if (((d[0]/d[1])/d[2])/d[3] == 24) {count++; *result += resultstr(d,'/','/','/',2);}

    // (a _ (b _ c)) _ d
    if ((d[0]-(d[1]+d[2]))+d[3] == 24) {count++; *result += resultstr(d,'-','+','+',3);}
    if ((d[0]*(d[1]+d[2]))+d[3] == 24) {count++; *result += resultstr(d,'*','+','+',3);}
    if ((d[0]/(d[1]+d[2]))+d[3] == 24) {count++; *result += resultstr(d,'/','+','+',3);}
    if ((d[0]-(d[1]-d[2]))+d[3] == 24) {count++; *result += resultstr(d,'-','-','+',3);}
    if ((d[0]*(d[1]-d[2]))+d[3] == 24) {count++; *result += resultstr(d,'*','-','+',3);}
    if ((d[0]/(d[1]-d[2]))+d[3] == 24) {count++; *result += resultstr(d,'/','-','+',3);}
    if ((d[0]+(d[1]*d[2]))+d[3] == 24) {count++; *result += resultstr(d,'+','*','+',3);}
    if ((d[0]-(d[1]*d[2]))+d[3] == 24) {count++; *result += resultstr(d,'-','*','+',3);}
    if ((d[0]*(d[1]*d[2]))+d[3] == 24) {count++; *result += resultstr(d,'*','*','+',3);}
    if ((d[0]/(d[1]*d[2]))+d[3] == 24) {count++; *result += resultstr(d,'/','*','+',3);}
    if ((d[0]+(d[1]/d[2]))+d[3] == 24) {count++; *result += resultstr(d,'+','/','+',3);}
    if ((d[0]-(d[1]/d[2]))+d[3] == 24) {count++; *result += resultstr(d,'-','/','+',3);}
    if ((d[0]*(d[1]/d[2]))+d[3] == 24) {count++; *result += resultstr(d,'*','/','+',3);}
    if ((d[0]/(d[1]/d[2]))+d[3] == 24) {count++; *result += resultstr(d,'/','/','+',3);}

    if ((d[0]+(d[1]+d[2]))-d[3] == 24) {count++; *result += resultstr(d,'+','+','-',3);}
    if ((d[0]-(d[1]+d[2]))-d[3] == 24) {count++; *result += resultstr(d,'-','+','-',3);}
    if ((d[0]*(d[1]+d[2]))-d[3] == 24) {count++; *result += resultstr(d,'*','+','-',3);}
    if ((d[0]/(d[1]+d[2]))-d[3] == 24) {count++; *result += resultstr(d,'/','+','-',3);}
    if ((d[0]+(d[1]-d[2]))-d[3] == 24) {count++; *result += resultstr(d,'+','-','-',3);}
    if ((d[0]-(d[1]-d[2]))-d[3] == 24) {count++; *result += resultstr(d,'-','-','-',3);}
    if ((d[0]*(d[1]-d[2]))-d[3] == 24) {count++; *result += resultstr(d,'*','-','-',3);}
    if ((d[0]/(d[1]-d[2]))-d[3] == 24) {count++; *result += resultstr(d,'/','-','-',3);}
    if ((d[0]+(d[1]*d[2]))-d[3] == 24) {count++; *result += resultstr(d,'+','*','-',3);}
    if ((d[0]-(d[1]*d[2]))-d[3] == 24) {count++; *result += resultstr(d,'-','*','-',3);}
    if ((d[0]*(d[1]*d[2]))-d[3] == 24) {count++; *result += resultstr(d,'*','*','-',3);}
    if ((d[0]/(d[1]*d[2]))-d[3] == 24) {count++; *result += resultstr(d,'/','*','-',3);}
    if ((d[0]+(d[1]/d[2]))-d[3] == 24) {count++; *result += resultstr(d,'+','/','-',3);}
    if ((d[0]-(d[1]/d[2]))-d[3] == 24) {count++; *result += resultstr(d,'-','/','-',3);}
    if ((d[0]*(d[1]/d[2]))-d[3] == 24) {count++; *result += resultstr(d,'*','/','-',3);}
    if ((d[0]/(d[1]/d[2]))-d[3] == 24) {count++; *result += resultstr(d,'/','/','-',3);}

    if ((d[0]+(d[1]+d[2]))*d[3] == 24) {count++; *result += resultstr(d,'+','+','*',3);}
    if ((d[0]-(d[1]+d[2]))*d[3] == 24) {count++; *result += resultstr(d,'-','+','*',3);}
    if ((d[0]*(d[1]+d[2]))*d[3] == 24) {count++; *result += resultstr(d,'*','+','*',3);}
    if ((d[0]/(d[1]+d[2]))*d[3] == 24) {count++; *result += resultstr(d,'/','+','*',3);}
    if ((d[0]+(d[1]-d[2]))*d[3] == 24) {count++; *result += resultstr(d,'+','-','*',3);}
    if ((d[0]-(d[1]-d[2]))*d[3] == 24) {count++; *result += resultstr(d,'-','-','*',3);}
    if ((d[0]*(d[1]-d[2]))*d[3] == 24) {count++; *result += resultstr(d,'*','-','*',3);}
    if ((d[0]/(d[1]-d[2]))*d[3] == 24) {count++; *result += resultstr(d,'/','-','*',3);}
    if ((d[0]+(d[1]*d[2]))*d[3] == 24) {count++; *result += resultstr(d,'+','*','*',3);}
    if ((d[0]-(d[1]*d[2]))*d[3] == 24) {count++; *result += resultstr(d,'-','*','*',3);}
    if ((d[0]/(d[1]*d[2]))*d[3] == 24) {count++; *result += resultstr(d,'/','*','*',3);}
    if ((d[0]+(d[1]/d[2]))*d[3] == 24) {count++; *result += resultstr(d,'+','/','*',3);}
    if ((d[0]-(d[1]/d[2]))*d[3] == 24) {count++; *result += resultstr(d,'-','/','*',3);}
    if ((d[0]*(d[1]/d[2]))*d[3] == 24) {count++; *result += resultstr(d,'*','/','*',3);}
    if ((d[0]/(d[1]/d[2]))*d[3] == 24) {count++; *result += resultstr(d,'/','/','*',3);}

    if ((d[0]+(d[1]+d[2]))/d[3] == 24) {count++; *result += resultstr(d,'+','+','/',3);}
    if ((d[0]-(d[1]+d[2]))/d[3] == 24) {count++; *result += resultstr(d,'-','+','/',3);}
    if ((d[0]*(d[1]+d[2]))/d[3] == 24) {count++; *result += resultstr(d,'*','+','/',3);}
    if ((d[0]/(d[1]+d[2]))/d[3] == 24) {count++; *result += resultstr(d,'/','+','/',3);}
    if ((d[0]+(d[1]-d[2]))/d[3] == 24) {count++; *result += resultstr(d,'+','-','/',3);}
    if ((d[0]-(d[1]-d[2]))/d[3] == 24) {count++; *result += resultstr(d,'-','-','/',3);}
    if ((d[0]*(d[1]-d[2]))/d[3] == 24) {count++; *result += resultstr(d,'*','-','/',3);}
    if ((d[0]/(d[1]-d[2]))/d[3] == 24) {count++; *result += resultstr(d,'/','-','/',3);}
    if ((d[0]+(d[1]*d[2]))/d[3] == 24) {count++; *result += resultstr(d,'+','*','/',3);}
    if ((d[0]-(d[1]*d[2]))/d[3] == 24) {count++; *result += resultstr(d,'-','*','/',3);}
    if ((d[0]*(d[1]*d[2]))/d[3] == 24) {count++; *result += resultstr(d,'*','*','/',3);}
    if ((d[0]/(d[1]*d[2]))/d[3] == 24) {count++; *result += resultstr(d,'/','*','/',3);}
    if ((d[0]+(d[1]/d[2]))/d[3] == 24) {count++; *result += resultstr(d,'+','/','/',3);}
    if ((d[0]-(d[1]/d[2]))/d[3] == 24) {count++; *result += resultstr(d,'-','/','/',3);}
    if ((d[0]*(d[1]/d[2]))/d[3] == 24) {count++; *result += resultstr(d,'*','/','/',3);}
    if ((d[0]/(d[1]/d[2]))/d[3] == 24) {count++; *result += resultstr(d,'/','/','/',3);}

    // a _ ((b _ c) _ d)
    if (d[0]-((d[1]+d[2])+d[3]) == 24) {count++; *result += resultstr(d,'-','+','+',4);}
    if (d[0]*((d[1]+d[2])+d[3]) == 24) {count++; *result += resultstr(d,'*','+','+',4);}
    if (d[0]/((d[1]+d[2])+d[3]) == 24) {count++; *result += resultstr(d,'/','+','+',4);}
    if (d[0]+((d[1]-d[2])+d[3]) == 24) {count++; *result += resultstr(d,'+','-','+',4);}
    if (d[0]-((d[1]-d[2])+d[3]) == 24) {count++; *result += resultstr(d,'-','-','+',4);}
    if (d[0]*((d[1]-d[2])+d[3]) == 24) {count++; *result += resultstr(d,'*','-','+',4);}
    if (d[0]/((d[1]-d[2])+d[3]) == 24) {count++; *result += resultstr(d,'/','-','+',4);}
    if (d[0]+((d[1]*d[2])+d[3]) == 24) {count++; *result += resultstr(d,'+','*','+',4);}
    if (d[0]-((d[1]*d[2])+d[3]) == 24) {count++; *result += resultstr(d,'-','*','+',4);}
    if (d[0]*((d[1]*d[2])+d[3]) == 24) {count++; *result += resultstr(d,'*','*','+',4);}
    if (d[0]/((d[1]*d[2])+d[3]) == 24) {count++; *result += resultstr(d,'/','*','+',4);}
    if (d[0]+((d[1]/d[2])+d[3]) == 24) {count++; *result += resultstr(d,'+','/','+',4);}
    if (d[0]-((d[1]/d[2])+d[3]) == 24) {count++; *result += resultstr(d,'-','/','+',4);}
    if (d[0]*((d[1]/d[2])+d[3]) == 24) {count++; *result += resultstr(d,'*','/','+',4);}
    if (d[0]/((d[1]/d[2])+d[3]) == 24) {count++; *result += resultstr(d,'/','/','+',4);}

    if (d[0]+((d[1]+d[2])-d[3]) == 24) {count++; *result += resultstr(d,'+','+','-',4);}
    if (d[0]-((d[1]+d[2])-d[3]) == 24) {count++; *result += resultstr(d,'-','+','-',4);}
    if (d[0]*((d[1]+d[2])-d[3]) == 24) {count++; *result += resultstr(d,'*','+','-',4);}
    if (d[0]/((d[1]+d[2])-d[3]) == 24) {count++; *result += resultstr(d,'/','+','-',4);}
    if (d[0]+((d[1]-d[2])-d[3]) == 24) {count++; *result += resultstr(d,'+','-','-',4);}
    if (d[0]-((d[1]-d[2])-d[3]) == 24) {count++; *result += resultstr(d,'-','-','-',4);}
    if (d[0]*((d[1]-d[2])-d[3]) == 24) {count++; *result += resultstr(d,'*','-','-',4);}
    if (d[0]/((d[1]-d[2])-d[3]) == 24) {count++; *result += resultstr(d,'/','-','-',4);}
    if (d[0]+((d[1]*d[2])-d[3]) == 24) {count++; *result += resultstr(d,'+','*','-',4);}
    if (d[0]-((d[1]*d[2])-d[3]) == 24) {count++; *result += resultstr(d,'-','*','-',4);}
    if (d[0]*((d[1]*d[2])-d[3]) == 24) {count++; *result += resultstr(d,'*','*','-',4);}
    if (d[0]/((d[1]*d[2])-d[3]) == 24) {count++; *result += resultstr(d,'/','*','-',4);}
    if (d[0]+((d[1]/d[2])-d[3]) == 24) {count++; *result += resultstr(d,'+','/','-',4);}
    if (d[0]-((d[1]/d[2])-d[3]) == 24) {count++; *result += resultstr(d,'-','/','-',4);}
    if (d[0]*((d[1]/d[2])-d[3]) == 24) {count++; *result += resultstr(d,'*','/','-',4);}
    if (d[0]/((d[1]/d[2])-d[3]) == 24) {count++; *result += resultstr(d,'/','/','-',4);}

    if (d[0]+((d[1]+d[2])*d[3]) == 24) {count++; *result += resultstr(d,'+','+','*',4);}
    if (d[0]-((d[1]+d[2])*d[3]) == 24) {count++; *result += resultstr(d,'-','+','*',4);}
    if (d[0]*((d[1]+d[2])*d[3]) == 24) {count++; *result += resultstr(d,'*','+','*',4);}
    if (d[0]/((d[1]+d[2])*d[3]) == 24) {count++; *result += resultstr(d,'/','+','*',4);}
    if (d[0]+((d[1]-d[2])*d[3]) == 24) {count++; *result += resultstr(d,'+','-','*',4);}
    if (d[0]-((d[1]-d[2])*d[3]) == 24) {count++; *result += resultstr(d,'-','-','*',4);}
    if (d[0]*((d[1]-d[2])*d[3]) == 24) {count++; *result += resultstr(d,'*','-','*',4);}
    if (d[0]/((d[1]-d[2])*d[3]) == 24) {count++; *result += resultstr(d,'/','-','*',4);}
    if (d[0]+((d[1]*d[2])*d[3]) == 24) {count++; *result += resultstr(d,'+','*','*',4);}
    if (d[0]-((d[1]*d[2])*d[3]) == 24) {count++; *result += resultstr(d,'-','*','*',4);}
    if (d[0]/((d[1]*d[2])*d[3]) == 24) {count++; *result += resultstr(d,'/','*','*',4);}
    if (d[0]+((d[1]/d[2])*d[3]) == 24) {count++; *result += resultstr(d,'+','/','*',4);}
    if (d[0]-((d[1]/d[2])*d[3]) == 24) {count++; *result += resultstr(d,'-','/','*',4);}
    if (d[0]*((d[1]/d[2])*d[3]) == 24) {count++; *result += resultstr(d,'*','/','*',4);}
    if (d[0]/((d[1]/d[2])*d[3]) == 24) {count++; *result += resultstr(d,'/','/','*',4);}

    if (d[0]+((d[1]+d[2])/d[3]) == 24) {count++; *result += resultstr(d,'+','+','/',4);}
    if (d[0]-((d[1]+d[2])/d[3]) == 24) {count++; *result += resultstr(d,'-','+','/',4);}
    if (d[0]*((d[1]+d[2])/d[3]) == 24) {count++; *result += resultstr(d,'*','+','/',4);}
    if (d[0]/((d[1]+d[2])/d[3]) == 24) {count++; *result += resultstr(d,'/','+','/',4);}
    if (d[0]+((d[1]-d[2])/d[3]) == 24) {count++; *result += resultstr(d,'+','-','/',4);}
    if (d[0]-((d[1]-d[2])/d[3]) == 24) {count++; *result += resultstr(d,'-','-','/',4);}
    if (d[0]*((d[1]-d[2])/d[3]) == 24) {count++; *result += resultstr(d,'*','-','/',4);}
    if (d[0]/((d[1]-d[2])/d[3]) == 24) {count++; *result += resultstr(d,'/','-','/',4);}
    if (d[0]+((d[1]*d[2])/d[3]) == 24) {count++; *result += resultstr(d,'+','*','/',4);}
    if (d[0]-((d[1]*d[2])/d[3]) == 24) {count++; *result += resultstr(d,'-','*','/',4);}
    if (d[0]*((d[1]*d[2])/d[3]) == 24) {count++; *result += resultstr(d,'*','*','/',4);}
    if (d[0]/((d[1]*d[2])/d[3]) == 24) {count++; *result += resultstr(d,'/','*','/',4);}
    if (d[0]+((d[1]/d[2])/d[3]) == 24) {count++; *result += resultstr(d,'+','/','/',4);}
    if (d[0]-((d[1]/d[2])/d[3]) == 24) {count++; *result += resultstr(d,'-','/','/',4);}
    if (d[0]*((d[1]/d[2])/d[3]) == 24) {count++; *result += resultstr(d,'*','/','/',4);}
    if (d[0]/((d[1]/d[2])/d[3]) == 24) {count++; *result += resultstr(d,'/','/','/',4);}

    // a _ (b _ (c _ d))
    if (d[0]-(d[1]+(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'-','+','+',5);}
    if (d[0]*(d[1]+(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'*','+','+',5);}
    if (d[0]/(d[1]+(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'/','+','+',5);}
    if (d[0]+(d[1]-(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'+','-','+',5);}
    if (d[0]-(d[1]-(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'-','-','+',5);}
    if (d[0]*(d[1]-(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'*','-','+',5);}
    if (d[0]/(d[1]-(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'/','-','+',5);}
    if (d[0]+(d[1]*(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'+','*','+',5);}
    if (d[0]-(d[1]*(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'-','*','+',5);}
    if (d[0]*(d[1]*(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'*','*','+',5);}
    if (d[0]/(d[1]*(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'/','*','+',5);}
    if (d[0]+(d[1]/(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'+','/','+',5);}
    if (d[0]-(d[1]/(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'-','/','+',5);}
    if (d[0]*(d[1]/(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'*','/','+',5);}
    if (d[0]/(d[1]/(d[2]+d[3])) == 24) {count++; *result += resultstr(d,'/','/','+',5);}

    if (d[0]+(d[1]+(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'+','+','-',5);}
    if (d[0]*(d[1]+(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'*','+','-',5);}
    if (d[0]/(d[1]+(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'/','+','-',5);}
    if (d[0]+(d[1]-(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'+','-','-',5);}
    if (d[0]-(d[1]-(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'-','-','-',5);}
    if (d[0]*(d[1]-(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'*','-','-',5);}
    if (d[0]/(d[1]-(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'/','-','-',5);}
    if (d[0]+(d[1]*(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'+','*','-',5);}
    if (d[0]-(d[1]*(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'-','*','-',5);}
    if (d[0]*(d[1]*(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'*','*','-',5);}
    if (d[0]/(d[1]*(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'/','*','-',5);}
    if (d[0]+(d[1]/(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'+','/','-',5);}
    if (d[0]-(d[1]/(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'-','/','-',5);}
    if (d[0]*(d[1]/(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'*','/','-',5);}
    if (d[0]/(d[1]/(d[2]-d[3])) == 24) {count++; *result += resultstr(d,'/','/','-',5);}

    if (d[0]+(d[1]+(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'+','+','*',5);}
    if (d[0]-(d[1]+(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'-','+','*',5);}
    if (d[0]*(d[1]+(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'*','+','*',5);}
    if (d[0]/(d[1]+(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'/','+','*',5);}
    if (d[0]+(d[1]-(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'+','-','*',5);}
    if (d[0]-(d[1]-(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'-','-','*',5);}
    if (d[0]*(d[1]-(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'*','-','*',5);}
    if (d[0]/(d[1]-(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'/','-','*',5);}
    if (d[0]+(d[1]*(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'+','*','*',5);}
    if (d[0]-(d[1]*(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'-','*','*',5);}
    if (d[0]/(d[1]*(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'/','*','*',5);}
    if (d[0]+(d[1]/(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'+','/','*',5);}
    if (d[0]-(d[1]/(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'-','/','*',5);}
    if (d[0]*(d[1]/(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'*','/','*',5);}
    if (d[0]/(d[1]/(d[2]*d[3])) == 24) {count++; *result += resultstr(d,'/','/','*',5);}

    if (d[0]+(d[1]+(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'+','+','/',5);}
    if (d[0]-(d[1]+(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'-','+','/',5);}
    if (d[0]*(d[1]+(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'*','+','/',5);}
    if (d[0]/(d[1]+(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'/','+','/',5);}
    if (d[0]+(d[1]-(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'+','-','/',5);}
    if (d[0]-(d[1]-(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'-','-','/',5);}
    if (d[0]*(d[1]-(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'*','-','/',5);}
    if (d[0]/(d[1]-(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'/','-','/',5);}
    if (d[0]+(d[1]*(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'+','*','/',5);}
    if (d[0]-(d[1]*(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'-','*','/',5);}
    if (d[0]*(d[1]*(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'*','*','/',5);}
    if (d[0]/(d[1]*(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'/','*','/',5);}
    if (d[0]+(d[1]/(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'+','/','/',5);}
    if (d[0]-(d[1]/(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'-','/','/',5);}
    if (d[0]*(d[1]/(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'*','/','/',5);}
    if (d[0]/(d[1]/(d[2]/d[3])) == 24) {count++; *result += resultstr(d,'/','/','/',5);}

    // Return count
    return count;
}

// Fungsi untuk menghasilkan semua kombinasi yang menghasilkan 24
int solver24(int array[4], string *result) {
    int length;
    int allcount = 0;
    int a = array[0];
    int b = array[1];
    int c = array[2];
    int d = array[3];;

    // Searching similar element
    // 1. No similar element (a b c d)
    if (a != b && a != c && a != d && b != c && b != d && c != d) {
        int ord[24][4] = {{a, b, c, d}, {a, b, d, c}, {a, c, b, d}, {a, c, d, b}, {a, d, b, c}, {a, d, c, b}, {b, a, c, d}, {b, a, d, c}, {b, c, a, d}, {b, c, d, a}, {b, d, a, c}, {b, d, c, a}, {c, a, b, d}, {c, a, d, b}, {c, b, a, d}, {c, b, d, a}, {c, d, a, b}, {c, d, b, a}, {d, a, b, c}, {d, a, c, b}, {d, b, a, c}, {d, b, c, a}, {d, c, a, b}, {d, c, b, a}};
        length = 24;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    }

    // 2. A pair of 2 similar element (a b c c)
    else if (a != b && a != c && a != d && b != c && b != d && c == d) {
        int ord[12][4] = {{a, b, c, d}, {a, c, b, d}, {a, c, d, b}, {b, a, c, d}, {b, c, a, d}, {b, c, d, a}, {c, a, b, d}, {c, a, d, b}, {c, b, a, d}, {c, b, d, a}, {c, d, a, b}, {c, d, b, a}};
        length = 12;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a != b && a != c && a != d && b == c && b != d && c != d) {
        int ord[12][4] = {{a, b, c, d}, {a, b, d, c}, {a, d, b, c}, {b, a, c, d}, {b, a, d, c}, {b, c, a, d}, {b, c, d, a}, {b, d, a, c}, {b, d, c, a}, {d, a, b, c}, {d, b, a, c}, {d, b, c, a}};
        length = 12;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a != b && a != c && a != d && b != c && b == d && c != d) { 
        int ord[12][4] = {{a, b, c, d}, {a, b, d, c}, {a, c, b, d}, {b, a, c, d}, {b, a, d, c}, {b, c, a, d}, {b, c, d, a}, {b, d, a, c}, {b, d, c, a}, {c, a, b, d}, {c, b, a, d}, {c, b, d, a}};
        length = 12;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a == b && a != c && a != d && b != c && b != d && c != d) {
        int ord[12][4] = {{a, b, c, d}, {a, b, d, c}, {a, c, b, d}, {a, c, d, b}, {a, d, b, c}, {a, d, c, b}, {c, a, b, d}, {c, a, d, b}, {c, d, a, b}, {d, a, b, c}, {d, a, c, b}, {d, c, a, b}};
        length = 12;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a != b && a == c && a != d && b != c && b != d && c != d) {
        int ord[12][4] = {{a, b, c, d}, {a, b, d, c}, {a, c, b, d}, {a, c, d, b}, {a, d, b, c}, {a, d, c, b}, {b, a, c, d}, {b, a, d, c}, {b, d, a, c}, {d, a, b, c}, {d, a, c, b}, {d, b, a, c}};
        length = 12;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a != b && a != c && a == d && b != c && b != d && c != d) {
        int ord[12][4] = {{a, b, c, d}, {a, b, d, c}, {a, c, b, d}, {a, c, d, b}, {a, d, b, c}, {a, d, c, b}, {b, a, c, d}, {b, a, d, c}, {b, c, a, d}, {c, a, b, d}, {c, a, d, b}, {c, b, a, d}};
        length = 12;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    }

    // 3. A pair of 3 similar element (a b b b)
    else if (a != b && b == c && b == d) {
        int ord[4][4] = {{a, b, c, d}, {b, a, c, d}, {b, c, a, d}, {b, c, d, a}};
        length = 4;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (b != a && a == c && a == d) {
        int ord[4][4] = {{b, a, c, d}, {a, b, c, d}, {a, c, b, d}, {a, c, d, b}};
        length = 4;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (c != a && a == b && a == d) {
        int ord[4][4] = {{c, a, b, d}, {a, c, b, d}, {a, b, c, d}, {a, b, d, c}};
        length = 4;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (d != a && a == b && a == c) {
        int ord[4][4] = {{d, a, b, c}, {a, d, b, c}, {a, b, d, c}, {a, b, c, d}};
        length = 4;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    }

    // 4. A pair of 4 similar element (a a a a)
    else if (a == b && a == c && a == d) {
        int ord[1][4] = {{a, b, c, d}};
        length = 1;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    }

    // 5. Two pair of 2 similar element (a a b b)
    else if (a == b && c == d && a != c) {
        int ord[6][4] = {{a, b, c, d}, {a, c, b, d}, {a, c, d, b}, {c, a, b, d}, {c, a, d, b}, {c, d, a, b}};
        length = 6;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a == c && b == d && a != b) {
        int ord[6][4] = {{a, c, b, d}, {a, b, c, d}, {a, b, d, c}, {b, a, c, d}, {b, a, d, c}, {b, d, a, c}};
        length = 6;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    } else if (a == d || b == c || a != b) {
        int ord[6][4] = {{a, d, b, c}, {a, b, d, c}, {a, b, c, d}, {b, a, d, c}, {b, a, c, d}, {b, c, a, d}};
        length = 6;
        for (int i = 0; i < length; i++) {
            allcount += solver24e(ord[i], result);
        }
    }

    return allcount;
}    

// Test and debugging
/*int main()
{
    // Pengolahan input
    string a, b, c, d, save;
    cin >> a >> b >> c >> d;
    int newa, newb, newc, newd,length, count;
    int (*order)[4];
    int add[4];
    add[0] = card2int(a);
    add[1] = card2int(b);
    add[2] = card2int(c);
    add[3] = card2int(d);

    //cout << add[1] << endl;
    //count = solver24e(add);
    //cout << count;
    count = solver24(add, &save);
    cout << count << endl;

    cout << save;

    return 0;
}*/

#endif