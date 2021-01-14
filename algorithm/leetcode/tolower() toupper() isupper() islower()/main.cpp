//
//  main.cpp
//  tolower() toupper() isupper() islower()
//
//  Created by ChengWang on 1/4/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <cctype>
using std::tolower;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    char a=tolower('2');
    printf("%c\n",a);
    char b=tolower('A');
    printf("%c\n",b);
    
    return 0;
}
