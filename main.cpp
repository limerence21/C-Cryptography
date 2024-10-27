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

    if (mode == 'e' || mode == 'E'){
        if (encryptFile(filename, true)){
            cout << "File berhasil dienkripsi." << endl;
        }else {
            cerr << "Error: Gagal mengenkripsi file." << endl;
        }
    } else if (mode == 'd' || mode == 'D'){
        if (encryptFile(filename, false)){
            cout << "File berhasil didekripsi." << endl;
        } else{
            cerr << "Error: Gagal mendekripsi file." << endl;
        }
    } else{
        cerr << "Error: Input Mode tidak valid." << endl;
    }

    return 0;
};