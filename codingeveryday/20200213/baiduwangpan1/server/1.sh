#ps -elf|grep tcpserver|awk '{print $4}'|xargs kill -9
./server 192.168.54.204 2000  4 
