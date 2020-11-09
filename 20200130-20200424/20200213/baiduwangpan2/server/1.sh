ps -elf|grep tcpserver|awk '{print $4}'|xargs kill -9
./main 192.168.54.207 2000  4 10
