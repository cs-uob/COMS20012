#!/bin/sh
echo "Vlad Kirilovics, University of Bristol, 2026"
echo "START!"
set -e
installdir=$(pwd)

# Installing dependencies
echo "Step 1/7: Installing dependencies, be patient..."
sudo DEBIAN_FRONTEND=noninteractive apt update -qq > /dev/null 2>&1
sudo DEBIAN_FRONTEND=noninteractive apt install build-essential flex bison gperf libncurses5-dev zlib1g-dev libssl-dev wget texinfo gawk libmpc-dev libmpfr-dev libgmp-dev bmake git libc6-dev-i386 bmake -y -qq > /dev/null 2>&1
echo "Dependencies have been installed!"

# Download os161
echo "Step 2/7: Downloading os161"
echo "os161 download started..."
git clone https://github.com/uob-jh/os161.git --quiet > /dev/null 2>&1
cd os161
mkdir toolbuild
mkdir tools
mkdir tools/bin
echo "os161 download finished, patching..."
# Make all binutils that will be installed visible to all compilers and other software.
echo "export PATH=$installdir/os161/tools/bin:$PATH" >> "$HOME/.bashrc"
echo "export PATH=$installdir/os161/tools/bin:$PATH" >> "$HOME/.zshrc"
export PATH="$installdir/os161/tools/bin:$PATH"
# Patch legacy os161 C code.
sed -i 's/char c;/char c= 0;/g' userland/testbin/usemtest/usemtest.c
cd ..
echo "os161 is ready for binutils installation!"


# Install binutils
echo "Step 3/7: Installing binutils"
echo "Downloading binutils..."
wget http://www.os161.org/download/binutils-2.24+os161-2.1.tar.gz -q --show-progress
tar -xvzf binutils-2.24+os161-2.1.tar.gz > /dev/null 2>&1
rm binutils-2.24+os161-2.1.tar.gz
cd binutils-2.24+os161-2.1
find . -name '*.info' | xargs touch
touch intl/plural.c
echo "binutils downloaded and unarchived"
echo "Configuring binutils..."
./configure --disable-werror --target=mips-harvard-os161 --prefix=$installdir/os161/tools CFLAGS="-g -O2 -std=gnu89" > /dev/null 2>&1
echo "Compiling binutils - this can take a few minutes, wait patiently..."
make > /dev/null 2>&1
echo "binutils compiled! Installing binutils - wait patiently..."
make install > /dev/null 2>&1
cd ..
echo "binutils installed!"

# Install gcc4.8
echo "Step 4/7: Installing gcc"
echo "Downloading gcc..."
wget http://www.os161.org/download/gcc-4.8.3+os161-2.1.tar.gz -q --show-progress
tar -xvzf gcc-4.8.3+os161-2.1.tar.gz > /dev/null 2>&1
rm gcc-4.8.3+os161-2.1.tar.gz
cd gcc-4.8.3+os161-2.1
find . -name '*.info' | xargs touch
touch intl/plural.c
echo "gcc downloaded..."
cd ..
mkdir buildgcc
cd buildgcc
echo "Configuring gcc..."
../gcc-4.8.3+os161-2.1/configure --enable-languages=c,lto --nfp --disable-shared --disable-threads --disable-libmudflap --disable-libssp --disable-libstdcxx --disable-nls --target=mips-harvard-os161 --prefix=$installdir/os161/tools CFLAGS="-g -O2 -std=gnu89" CXXFLAGS="-g -O2 -std=gnu++98" > /dev/null 2>&1
echo "Building gcc - this can take a few minutes, wait patiently..."
gmake > /dev/null 2>&1
echo "Installing gcc - please wait..."
gmake install > /dev/null 2>&1
cd ..
echo "gcc installed!"

echo "Step 5/7: Installing gdb"
echo "Downloading gdb..."
wget http://www.os161.org/download/gdb-7.8+os161-2.1.tar.gz -q --show-progress
echo "gdb downloaded!"
tar -xvzf gdb-7.8+os161-2.1.tar.gz > /dev/null 2>&1
rm gdb-7.8+os161-2.1.tar.gz
cd gdb-7.8+os161-2.1
find . -name '*.info' | xargs touch
touch intl/plural.c
echo "Configuring gdb..."
./configure --disable-werror --target=mips-harvard-os161 --prefix=$installdir/os161/tools CFLAGS="-g -O2 -std=gnu89" CXXFLAGS="-g -O2 -std=gnu++98" --with-python=no > /dev/null 2>&1
echo "Patching gdb..."
if ! grep -q "include <string.h>" sim/common/gentmap.c; then
	sed -i '1i #include <string.h>' sim/common/gentmap.c
	echo "GDB code has been patched for GCC v14+ compatibility..."
else
	echo "No GDB code compatibility patch is required..."
fi
echo "Building gdb - this can take a few minutes, wait patiently..."
make > /dev/null 2>&1
echo "Installing gdb - please wait..."
make install > /dev/null 2>&1
cd ..
echo "gdb installed!"

# Install System161
echo "Step 6/7: Installing System161"
echo "Downloading System161..."
wget http://www.os161.org/download/sys161-2.0.8.tar.gz -q --show-progress
echo "System161 downloaded!"
tar -xvzf sys161-2.0.8.tar.gz > /dev/null 2>&1
rm sys161-2.0.8.tar.gz 
cd sys161-2.0.8
export CFLAGS="-fcommon"
echo "Configuring System161..."
./configure --prefix=$installdir/os161/tools mipseb > /dev/null 2>&1
echo "Building System161 - this can take a few minutes, wait patiently..."
make > /dev/null 2>&1
echo "Installing System161 - please wait..."
make install > /dev/null 2>&1
cd ..
echo "System161 installed!"


# Build os161
echo "Step 7/7: building os161 userland..."
cd os161
./configure > /dev/null 2>&1
bmake > /dev/null 2>&1
bmake install > /dev/null 2>&1
echo "os161 userland build completed! Please close all terminal windows now."

