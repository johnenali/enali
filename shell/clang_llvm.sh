#!/bin/env bash
#1. Get the required tools
#2. Checkout LLVM
svn co http://llvm.org/svn/llvm-project/llvm/trunk llvm
#3. Checkout Clang
cd llvm/tools
svn co http://llvm.org/svn/llvm-project/cfe/trunk clang
cd ../..
#4. Checkout extra Clang Tools:(optional)
cd llvm/tools/clang/tools
svn co http://llvm.org/svn/llvm-project/clang-tools-extra/trunk extra
cd ../../../..
#5. Checkout Compiler-RT
cd llvm/projects
svn co http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt
cd ../..
#6. Build LLVM and Clang
mkdir build
cd build
../llvm/configure --enable-optimized CC=/usr/bin/gcc CXX=/usr/bin/g++
make
sudo make install
#7. Build libc++.so
cd ..
svn co http://llvm.org/svn/llvm-project/libcxx/trunk libcxx
cd libcxx/lib
./buildit
sudo cp libc++.so /usr/lib/
sudo ln -s /usr/lib/libc++.so.1.0 /usr/lib/libc++.so.1
sudo ln -s /usr/lib/libc++.so.1.0 /usr/lib/libc++.so
sudo cp -r ../include/ /usr/include/c++/v1/
cd ../..
#8. Build libc++abi.so
svn co http://llvm.org/svn/llvm-project/libcxxabi/trunk libcxxabi
cd libcxxabi/lib
./buildit
sudo cp libc++abi.so /usr/lib/
sudo ln -s /usr/lib/libc++abi.so.1.0 /usr/lib/libc++abi.so.1
sudo ln -s /usr/lib/libc++abi.so.1.0 /usr/lib/libc++abi.so
sudo cp -r ../include/ /usr/include/c++/v1/

