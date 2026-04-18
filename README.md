# hashlib-cpp

## Giới thiệu
- Hashlib C++ là thư viện tự build dựa trên thư openssl của trình biên dịch mingw64 c++
- Với cú pháp ngắn gọn y như hashlib python giúp hash 1 cách nhanh chóng 

<img width="1919" height="1079" alt="image" src="https://github.com/user-attachments/assets/95c6d7e4-27e9-4964-b18e-1a4b61134b40" />

## Cách dùng 
- Đưa file hashlib.h vào đường dẫn sau
```bash
msys64\mingw64\include\c++\14.1.0\hashlib.h
```

## Lệnh biên dịch 
```bash
g++ test_hashlib.cpp -o test_hashlib.exe -lssl -lcrypto
```
