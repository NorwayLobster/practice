 ///
 /// @file    cpu.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-04 10:48:27
 ///
 
#include <iostream>
#include <unistd.h>
#include <sys/sysinfo.h>

int sysconf(_SC_NPROCESSORS_CONF);/* 返回系统可以使用的核数，但是其值会包括系统中禁用的核的数目，因 此该值并不代表当前系统中可用的核数 */
//int sysconf(_SC_NPROCESSORS_ONLN);/* 返回值真正的代表了系统当前可用的核数 */

/* 以下两个函数与上述类似 */

int get_nprocs_conf (void);/* 可用核数 */
int get_nprocs (void);/* 真正的反映了当前可用核数 */
