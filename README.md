Biên dịch và Debug cho stm32 trên visual studio code


Cài đặt các công cụ cần thiết:
1. Msys2

tải và cài đặt theo hướng dẫn tại: https://www.msys2.org/

chạy các lệnh sau:
    pacman -Sy pacman
    pacman -Syu

mở lại Msys2, chạy tiếp
    pacman -S make tar unzip mingw-w64-x86_64-toolchain mingw-w64-x86_64-make mingw-w64-x86_64-boost

Add path:
    C:\msys64\usr\bin
    C:\msys64\mingw64\bin
3. Pyocd
cài đặt python: https://www.python.org/ftp/python/3.12.0/python-3.12.0-amd64.exe
mở terminal, chạy:
    pip install -U pyocd
4. GNU Arm Embedded Toolchain
tải và cài đặt: https://developer.arm.com/downloads/-/gnu-rm
Add Path: 
    C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin
5. Cortex-Debug Extension 
mở cài đặt extension Cortex-Debug trên visual studio code
6. St-link
truy cập: https://github.com/stlink-org/stlink/releases/tag/v1.7.0
tải bản: stlink-1.7.0-x86_64-w64-mingw32.zip
giải nén và sửa thư mục thành ST-link (không cần thiết)
copy thư mục ST-link vào : C:\Program Files
Add Path: C:\Program Files\ST-link\bin

Thử nghiệm

TH1: không dùng pyocd.yaml

1. xoá file: pyocd.yaml, Drivers\Arm\Keil.STM32F1xx_DFP.2.4.1.pack
2. Trong makefile:
    bỏ command: St-flash
    đánh command: pyocd-flash
3. Trong ".vscode/launch.json:
    gán biến "servertype": "stutil"
4. biên dịch chương trình:     make
5. nạp chương trình:           make flash
6. Để debug: vào "Run and Debug"

TH2: Dùng pyocd.yaml

1. Trong makefile:
    đánh command: St-flash
    bỏ command: pyocd-flash
2. Trong ".vscode/launch.json:
    gán biến "servertype": "pyocd"
3. biên dịch chương trình:     make
4. nạp chương trình:           make flash
5. Để debug: vào "Run and Debug"

