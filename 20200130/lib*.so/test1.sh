export LIBRARY_PATH="lib/:$LIBRARY_PATH"
echo $LIBRARY_PATH
export LD_LIBRARY_PATH="lib/:$LD_LIBRARY_PATH"
echo $LD_LIBRARY_PATH
path=/home/cheng/20200130/lib*.so/lib
g++ -o main main.cpp -L $path -lcheng -Wl,-rpath=$path -I include  #-L 指定编译时库地址， -Wl,-rpath=... 指定编译时库地址
