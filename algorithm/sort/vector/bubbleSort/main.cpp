//
//  main.cpp
//  bubbleSort
//
//  Created by ChengWang on 11/24/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void generateAarry(vector<int> & v, int maxSize,int maxValue);
void bubbleSort(vector<int> & v);
void bubbleSort_0(vector<int> & v);
void bubbleSort_1(vector<int> & v);
void bubbleSort_2(vector<int> & v);
void bubbleSort_3(vector<int> & v);
void bubbleSort_4(vector<int> & v);
void bubbleSort_5(vector<int> & v);
void bubbleSort_6(vector<int> & v);
void bubble_sort(vector<int> & v);
void print(const vector<int> &);
void bubblesort20201130(vector<int>&v);

int main(int argc, const char * argv[]) {
    //    srand(time(NULL));
    srand((unsigned int)time(NULL));
    // insert code here...
    std::cout << "Hello, World!\n";
    int cnt=10;
    int maxSize=200;
    int maxValue=5000;
    
    vector<int> v(maxSize,-1);
    
    //    for(int i=0;i<v.size();++i)
    //        printf("%d ",v[i]);
    printf("\n");
    bool succeed=true;
    for(int i=0;i<cnt;++i){
        v.clear();//用完后每次都要清理
        generateAarry(v, maxSize,maxValue);
        vector<int> v1(v);
        vector<int> v2(v);
        printf("before:");
        print(v);
        sort(v1.begin(),v1.end());
        printf("after v1:");
        print(v1);
        //        bubbleSort(v2);
        //        bubbleSort_1(v2);
        //        bubbleSort_2(v2);
        //        bubbleSort_3(v2);
        //        bubbleSort_4(v2);
        //        bubbleSort_5(v2);
//        bubbleSort_6(v2);
        // bubble_sort(v2);
        bubblesort20201130(v2);
        printf("after v2:");
        print(v2);
        for(int i=0;i<v1.size();++i){
            if(!equal(v1.begin(),v1.end(),v2.begin())){
                succeed=false;
                break;
            }
        }
        if(!succeed){
            printf("fucking fuck!\n");
            printf("before:");
            print(v);
            printf("after right:");
            print(v1);
            printf("after wrong:");
            print(v2);
        }
    }
    printf("NICE!\n");
    return 0;
}
void generateAarry(vector<int> & v, int maxSize,int maxValue){
    for(int i=0;i<maxSize;++i){
        //        printf("%d ",rand()%maxValue);
        v.push_back(rand()%maxValue);
    }
}

//void generateRandomArray(vector<int> &v, int maxSize, int maxValue){
////    srand((unsigned)time(NULL));
//    for(int i = 0; i < maxSize;i++ )
//        v.push_back(rand()%(maxValue-10)+10);
//}

//void print(const vector<int> &v){
//    for(int i=0;i<(int)v.size();++i){
//        printf("%d ",v[i]);
//    }
//    printf("\n");
//}

void print(const vector<int> & v)
{
    copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
//    std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

void bubbleSort(vector<int> & v)
{
    int len=v.size();
    for(int i=(int)v.size()-1;i>=0;--i){
        for(int j=0;j<i;++j){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
    }
}

//最优，最简洁，最直观,记忆版
void bubble_sort(vector<int>&v){
    int len=v.size();
    for(int i=len-1;i>0;--i){
		bool sorted=true;
        for(int j=1;j<=i;++j){
            if(v[j-1]>v[j]){
				sorted=false;
				swap(v[j-1],v[j]);
			}
		}
		if(sorted) 
			break;
    }
}



//从小---->大
void bubbleSort_0(vector<int> & v){
    for(int i=0;i<(int)v.size();++i){
        for(int j=0;j<v.size()-i-1;++j){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
    }
}

//优化1：其实只需要v.size()-1遍，则完成
void bubbleSort_1(vector<int> & v){
    for(int i=0;i<(int)v.size()-1;++i){
        for(int j=0;j<v.size()-i-1;++j){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
    }
}

//优化2：加哨兵
void bubbleSort_2(vector<int> & v){
    bool flag=true;
    for(int i=0;i<(int)v.size()-1;++i){
        for(int j=0;j<v.size()-i-1;++j){
            if(v[j]>v[j+1]){
                flag=false;
                swap(v[j],v[j+1]);
            }
        }
        if(flag) break;//
    }
}

//优化3：加有序区左边界
void bubbleSort_3(vector<int> & v){
    bool flag=true;
    size_t sortedBoundry=v.size()-1;
    int lastExchageIndex=-1;
    for(int i=0;i<(int)v.size()-1;++i){
        for(int j=0;j<sortedBoundry;++j){
            if(v[j]>v[j+1]){
                flag=false;
                swap(v[j],v[j+1]);
                lastExchageIndex=j;
            }
        }
        sortedBoundry=(size_t)lastExchageIndex;
        if(flag) break;//
    }
}

//优化4： 减弱版 鸡尾酒排序，即 交换的方向，先从左-->右，再从右-->左；
void bubbleSort_4(vector<int> & v){
    for(int i=0;i<(int)v.size()/2;++i){
        bool flag=true;
        for(int j=0;j<v.size()-i-1;++j){
            if(v[j]>v[j+1]){
                flag=false;
                swap(v[j],v[j+1]);
            }
        }
        if(flag) break;//
        
        flag=true;
        for(int j=(int)v.size()-i-1;j>0;--j){
            if(v[j-1]>v[j]){
                flag=false;
                swap(v[j-1],v[j]);
            }
        }
        if(flag) break;//
    }
}

//优化5： 鸡尾酒排序，即 交换的方向，先从左-->右，再从右-->左；
//       注意：有序区在两边同时存在
void bubbleSort_5(vector<int> & v){
    for(int i=0;i<(int)v.size()/2;++i){
        bool flag=true;
        for(int j=i;j<v.size()-i-1;++j){
            if(v[j]>v[j+1]){
                flag=false;
                swap(v[j],v[j+1]);
            }
        }
        if(flag) break;//
        
        flag=true;
        for(int j=(int)v.size()-i-1;j>i;--j){
            if(v[j-1]>v[j]){
                flag=false;
                swap(v[j-1],v[j]);
            }
        }
        if(flag) break;//
    }
}
//优化6： 鸡尾酒排序 + 有序边界（lastLeftExchangeIndex和lastRightExchangeIndex)

void bubbleSort_6(vector<int> & v){
    int lastRightExchangeIndex=-1,lastLeftExchangeIndex=-1;
    int RightBoundry=(int)v.size()-1,LeftBoundry=0;
    for(int i=0;i<(int)v.size()/2;++i){
        bool flag=true;
        for(int j=i;j<RightBoundry;++j){
            if(v[j]>v[j+1]){
                flag=false;
                swap(v[j],v[j+1]);
                lastRightExchangeIndex=j;
            }
        }
        RightBoundry=lastRightExchangeIndex;
        if(flag) break;//
        
        flag=true;
        for(int j=(int)v.size()-i-1;j>LeftBoundry;--j){
            if(v[j-1]>v[j]){
                flag=false;
                swap(v[j-1],v[j]);
                lastLeftExchangeIndex=j;
            }
        }
        LeftBoundry=lastLeftExchangeIndex;
        if(flag) break;//
    }
}



///exercise 20201130
void bubblesort20201130(vector<int>&v){
    int len=v.size();
    for(int i=len-1;i>=0;--i){
        bool sorted=true;
        for(int j=1;j<=i;++j){
            if(v[j-1]<v[j]){
                sorted=false;
                swap(v[j-1],v[j]);
            }
        }
        if(sorted)
            break;
    }
}