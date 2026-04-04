#include <iostream>
#include <fstream>
#include <hashlib.h>

using namespace std;
using namespace hashlib;

const string content = R"(Xin chào nha)";

int main() {
    string data = content;
    string key = "secret"; // dùng cho HMAC

    // ===== Tạo file "test.txt" =====
    {
        ofstream fout("test.txt", ios::binary);
        fout << content;
    }

    // ===== Hash trực tiếp từ chuỗi =====
    cout << "md5:      " << md5(data).hexdigest() << endl;
    cout << "sha1:     " << sha1(data).hexdigest() << endl;
    cout << "sha224:   " << sha224(data).hexdigest() << endl;
    cout << "sha256:   " << sha256(data).hexdigest() << endl;
    cout << "sha384:   " << sha384(data).hexdigest() << endl;
    cout << "sha512:   " << sha512(data).hexdigest() << endl;

    // ===== SHA3 =====
    cout << "sha3-224: " << sha3_224(data).hexdigest() << endl;
    cout << "sha3-256: " << sha3_256(data).hexdigest() << endl;
    cout << "sha3-384: " << sha3_384(data).hexdigest() << endl;
    cout << "sha3-512: " << sha3_512(data).hexdigest() << endl;

    // ===== BLAKE2 =====
    cout << "blake2b:  " << blake2b(data).hexdigest() << endl;
    cout << "blake2s:  " << blake2s(data).hexdigest() << endl;

    // ===== HMAC =====
    cout << "HMAC-SHA256: " << hmac(key, data, "sha256") << endl;
    cout << "HMAC-SHA1:   " << hmac(key, data, "sha1") << endl;

    // ===== Hash file =====
    cout << "Hash file (md5):      " << hash_file("test.txt", "md5") << endl;
    cout << "Hash file (sha1):     " << hash_file("test.txt", "sha1") << endl;
    cout << "Hash file (sha224):   " << hash_file("test.txt", "sha224") << endl;
    cout << "Hash file (sha256):   " << hash_file("test.txt", "sha256") << endl;
    cout << "Hash file (sha384):   " << hash_file("test.txt", "sha384") << endl;
    cout << "Hash file (sha512):   " << hash_file("test.txt", "sha512") << endl;
    cout << "Hash file (sha3-256): " << hash_file("test.txt", "sha3-256") << endl;
    cout << "Hash file (blake2b512): " << hash_file("test.txt", "blake2b512") << endl;

    return 0;
}

// cách biên dịch 
// g++ test_hashlib.cpp -o test_hashlib -lssl -lcrypto
// hoặc
// clang++ test_hashlib.cpp -o test_hashlib -lssl -lcrypto
