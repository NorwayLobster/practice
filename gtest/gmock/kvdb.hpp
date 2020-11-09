 ///
 /// @file    kvdb.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-09-20 22:04:58
 ///
 
#ifndef LDB_KVDB_MOCK_H
#define LDB_KVDB_MOCK_H
#include <iostream>
using namespace std;

class KVDB {
public:
    std::string get(const std::string &key) const;
    Status set(const std::string &key, const std::string &value);
    Status remove(const std::string &key);
};
#endif //LDB_KVDB_MOCK_H
