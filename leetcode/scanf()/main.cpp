//
//  main.cpp
//  scanf()
//
//  Created by ChengWang on 1/23/20.
//  Copyright © 2020 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //    note:
    //         scanf():出错时，返回EOF即-1；正确执行时，返回成功读取的数的个数
    
    //    %d 不会匹配字符，scanf返回0 0不等于-1， true， 死循环
    int i,k;
    char cha;
    int ret=scanf("%d %c",&i,&cha);
    printf("cha:%c\ni:%i\n",cha,i);
    
    while(scanf("%d",&i)!=EOF){
        printf("i:%d\n",i);
    }
    
    scanf("%d",&i);
    printf("i:%d\n",i);
    
    scanf("%d",&k);
    printf("k:%d\n",k);
    fflush(0);
    //    fflush(stdin);
    int ret1=scanf("%c%d",&cha,&k);
    printf("cha:%c$\n",cha);
    printf("ret:%d\n",ret);
    

    return 0;
}
