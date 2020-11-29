//
//  main.cpp
//  list deque array(静态数组)等模板
//  Created by ChengWang on 3/9/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <forward_list>
#include <string>
#include <iostream>

//以模板的方式重载
template<typename T>
//note:
//1.cout,cin,cerr等对象是全局对象，在main（）函数之前构建，
//2. 他们是对象语意，不可复制；
//3.返回是全局对象的引用，可以；
//4.若返回的是函数内局部对象的引用，错误；
//std::ostream operator<<(std::ostream& s, const std::forward_list<T>& v) {//区别: 返回引用与否，区别很大，
std::ostream & operator<<(std::ostream& s, const std::forward_list<T>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};//字符数组，输出时，到第一元素直接退出，因为遇到'\0'
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';//更改后，到第三个元素才退出
    }
    return s << ']';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // c++11 初始化器列表语法：
    std::forward_list<std::string> words0 {"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words0: " << words0 << '\n';
    std::forward_list<std::string> words1 ={"the", "frogurt", "is", "also", "cursed"};
    std::cout << "words1: " << words1 << '\n';

    // words2 == words1
    std::forward_list<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: " << words2 << '\n';
    
    // words3 == words1
    std::forward_list<std::string> words3(words1);
    std::cout << "words3: " << words3 << '\n';
    
    // words4 为 {"Mo", "Mo", "Mo", "Mo", "Mo"}
    std::forward_list<std::string> words4(5, "Mo");
    std::cout << "words4: " << words4 << '\n';
    return 0;
}
