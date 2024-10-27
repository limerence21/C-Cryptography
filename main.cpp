#include<iostream>
#include"encryption.h"

using namespace std;

int main(){
    string filename;
    char mode;

    cout << "Masukan nama file: ";
    getline(cin >> ws, filename);

    cout << "Enskripsi (e) atau Deksripsi (d)? : ";
    cin >> mode;

    return 0;
};