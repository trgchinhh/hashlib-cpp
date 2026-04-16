#include <iostream>
#include <windows.h>
#include <limits>
#include <hashlib.h>

using namespace std;
using namespace hashlib;

const string banner = R"( ╔═════════════════════════════════╗
 ║          Hashlib C++            ║
 ║  Simple C++ Hash Generator      ║
 ║  Author : Truong Chinh          ║
 ║  Github : Github.com/trgchinhh  ║
 ╚═════════════════════════════════╝

)";

void clear(){
    system("cls");
}

void dungchuongtrinh(){
    cout << "\n\tNhấn phím enter để tiếp tục ..."; 
    getchar();
}

void inbanner(const string tenbanner){
    stringstream ss(tenbanner);
    string line;
    while (getline(ss, line)) {
        cout << line << endl;
    }
}

void inputdata(string& data){
    inbanner(banner);
    cout << " [?] Nhập dữ liệu: ";
    getline(cin, data);
}

void display_data(string data){
    cout << " [+] Data: " << data << "\n\n";
}

void menu(string data){
    const int somuc = 14;
    display_data(data);
    string menu[somuc] = {
        " [01] Enter new data",
        " [02] Hash Md5",
        " [03] Hash Sha1",
        " [04] Hash Sha224",
        " [05] Hash Sha256",
        " [06] Hash Sha384",
        " [07] Hash Sha512",
        " [08] Hash Sha3-224",
        " [09] Hash Sha3-256",
        " [10] Hash Sha3-384",
        " [11] Hash Sha3-512",
        " [12] Hash Blake2b",
        " [13] Hash Blake2s",
        " [14] Exit\n"
    };
    for(int i = 0; i < somuc; i++){
        cout << menu[i] << endl;
    }
}

void hashlib_cpp(){
    int chon;
    string data;
    if(data.empty()){
        inputdata(data);
    }

    while(true){
        clear();
        inbanner(banner);

        menu(data);
        cout << " [-] Nhập lựa chọn: ";
        int chon; cin >> chon;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // hiển thị hash realtime
        if(chon == 14){
            cout << "\n" << "Goodbye !!!" << endl;
            exit(0);
        } else if(chon == 1){
            system("cls");
            inputdata(data);
            continue;
        } else if(chon > 1 and chon < 14){
            cout << "\n\tResult: ";
            if(chon == 2) cout << md5(data).hexdigest();
            else if(chon == 3) cout << sha1(data).hexdigest();
            else if(chon == 4) cout << sha224(data).hexdigest();
            else if(chon == 5) cout << sha256(data).hexdigest();
            else if(chon == 6) cout << sha384(data).hexdigest();
            else if(chon == 7) cout << sha512(data).hexdigest();
            else if(chon == 8) cout << sha3_224(data).hexdigest();
            else if(chon == 9) cout << sha3_256(data).hexdigest();
            else if(chon == 10) cout << sha3_384(data).hexdigest();
            else if(chon == 11) cout << sha3_512(data).hexdigest();
            else if(chon == 12) cout << blake2b(data).hexdigest();
            else if(chon == 13) cout << blake2s(data).hexdigest();
            cout << endl;
        } else {
            cout << "Nhập sai !" << endl;
            exit(0);
        }

        dungchuongtrinh();
    }
}

int main() {
    hashlib_cpp();
    return 0;
}
