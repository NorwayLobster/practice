//
//  main.cpp
//  std::rand()
//
//  Created by ChengWang on 3/5/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int maxSize=10;
    int timeSize=2;
    //    srand(1);
    srand((unsigned)time(NULL));
    printf("%d\n",RAND_MAX);
    for(int j=0;j<timeSize;++j){
        for(int i = 0; i < maxSize;i++ )
            {
                cout<<rand()/RAND_MAX<<" ";
//                cout<<rand()%(100-10)+10<<" ";
            }
        
            cout<<endl;
    }
    return 0;

}
