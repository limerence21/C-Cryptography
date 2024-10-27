#include"encryption.h"
#include<fstream>
#include<cctype>

using namespace std;

bool performCaesarCipher(string& content, bool encrypt){
    int shift = encrypt ? 3 : -3;

    for (char& ch: content) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }

    return true;
}


bool encryptFile(const string& filename, bool encrypt){
    //Membuka input file
    ifstream inFile(filename);
    if (!inFile){
        return false;
    }

    //Membaca isi dari file
    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (performCaesarCipher(content, encrypt)){
        // Membuat output File dan menulis modifikasi isi file
        ofstream outFile(encrypt ? "Terenkripsi_" + filename : "Terderkripsi_" + filename);
        if (!outFile) {
            return false;
        }

        outFile << content;

        outFile.close();

        return true;
    }
};