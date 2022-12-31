/*
 * @Date: 2022-03-13 19:08:49
 * @LastEditors: ChengWang
 * @LastEditTime: 2022-03-13 19:09:22
 * @FilePath: /undefined/Users/chengwang/shoppe2.cc
 */
/*
 * @Date: 2022-03-13 19:08:49
 * @LastEditors: ChengWang
 * @LastEditTime: 2022-03-13 19:08:49
 * @FilePath: /undefined/Users/chengwang/shoppe2.cc
 */
#include<stdc++.h>
#include<mutex>
#include<condition>

using namespace std;
//step1: 
/*
// Producer/ consumer model

// 1: we have a shared string pool , for example: List<string> pool
// 2: Producer:   put string into the pool every time
// 3: consumer:   get string and print itt every time
// 4: pool has upper limitation.  100 max
//   so producer have to wait until available slots
//   and consumer have to wait until available elements

*/

int main(){
    //step1:
    vector<string> task_pool;
    pthread_condition cond;
    pthread_cond_init();
    pthread_mutex m= pthread_mutex_create(...,&cond);

    //step2
    auto enterFuncConsumer=[](string s)->{
        while(1){
            pthread_mutex_lock()
            while(1){
                if(v.len()>0){
                cout<<"s:"<<s<<endl;
                s=v.back();
                cout<<"str:"<<s<<endl;
                v.pop_back();
                break;
                }else{
                    pthread_cond_wait()
                }
            }
            pthread_mutex_lock()
            pthread_cond_broadcast();
        }
        }
    //step2:
        auto enterFuncProduer=[](string s)->{
        while(1){
            pthread_mutex_lock()
            while(1){
                if(v.len()<MAX_NUM){
                cout<<"s:"<<s<<endl;
                v.push_back("hello");
                break;
                }else{
                    pthread_cond_wait()
                }
            }
            pthread_mutex_lock()
            pthread_cond_broadcast();
        }
        }

    //step3:
    pthread_pid producer=pthread_create(nullptr, ..., enterFunc);
    pthread_pid consumer=pthread_create(nullptr, ..., enterFunc);

    prouder.start();
    consumer.start();

    produer.join();
    consumer.join();
    return 0;
}