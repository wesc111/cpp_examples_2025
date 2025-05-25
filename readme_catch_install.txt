
# commands to install Catch2:
git clone https://github.com/catchorg/Catch2
cd Catch2
mkdir build
cd build
cmake .. -DBUILD_TESTING=Off
sudo make install
sudo cp /usr/local/lib/libCatch2* /usr/lib

# installs files in /usr/local/lib, /usr/local/include/catch2, /usr/local/share/doc/Catch2
# copy files into /usr/lib to make it simple for linking

following command compiles and links everything:
clang++ -I./src -I/usr/local/include src/fibo_catch.cpp -o fibo_catch.out -std=c++20 -Wall -lCatch2Main -lCatch2