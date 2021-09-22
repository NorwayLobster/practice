#include<bits/stdc++.h>
/*
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
实现 LRUCache 类：

LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 

进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class LRUCache {
public:
    LRUCache(int capacity) {

    }
    
    int get(int key) {

    }
    
    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
//
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity)
    :_capacity(capacity)
    ,_size(0){
    }
    
    int get(int key) {
        if(lru_hash.find(key)==lru_hash.end()){
            return -1;
        }
        //update value and location
        auto iter=lru_hash[key];
        auto p=*iter;
        lru_list.erase(iter);
        lru_list.push_front(p);
        lru_hash[key]=lru_list.begin();

        return p.second;
    }
    
    void put(int key, int value) {
        if(lru_hash.find(key)==lru_hash.end()){//new insert
            if(_size+1>_capacity){
                expire();
            }
            lru_list.push_front(make_pair(key, value));
            lru_hash[key]=lru_list.begin();
            _size++;
        }else{// alread have
            //update location
            auto iter=lru_hash[key];
            lru_list.erase(iter);
            lru_list.push_front(make_pair(key,value));
            lru_hash[key]=lru_list.begin();
        }
    }
private:
    void expire(){
        //delete 
        auto p=lru_list.back();
        lru_list.pop_back();

        lru_hash.erase(p.first);//delete a element from hash
        _size--;
    }
private:
    int _size;
    int _capacity;
    unordered_map<int, list<pair<int,int>>::iterator> lru_hash;//key, iter
    list<pair<int,int>> lru_list;//key, val
};
int main(){
    cout<<"hello world!"<<endl;
    cout<<"hello"<<endl;
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
   cout<<"get 1:"<<lRUCache.get(1)<<endl;    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
   cout<<"get 2:"<<lRUCache.get(2)<<endl;    // 返回 1
    // lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
   cout<<"get 1:"<<lRUCache.get(1)<<endl;    // 返回 1
    // lRUCache.get(1);    // 返回 -1 (未找到)
   cout<<"get 3:"<<lRUCache.get(3)<<endl;    // 返回 1
    // lRUCache.get(3);    // 返回 3
   cout<<"get 4:"<<lRUCache.get(4)<<endl;    // 返回 1
    // lRUCache.get(4);    // 返回 4
    return 0;
}