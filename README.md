# hashlib-cpp

## Giới thiệu
- Hashlib C++ là thư viện tự build dựa trên thư openssl của trình biên dịch mingw64 c++
- Với cú pháp ngắn gọn y như hashlib python giúp hash 1 cách nhanh chóng 

## Cách dùng 
- Đưa file hashlib.h vào đường dẫn sau
```bash
msys64\mingw64\include\c++\14.1.0\hashlib.h
```

## Lệnh biên dịch 
```bash
g++ test_hashlib.cpp -o test_hashlib.exe -lssl -lcrypto
```
