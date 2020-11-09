 ///
 /// @file    mainMock.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-09-20 22:04:34
 ///
 
#include <iostream>
#include "kvdb.hpp"

using namespace std;
class MockKVDB : public KVDB {
public:
    MockKVDB() {
    }

    MOCK_METHOD1(remove, Status(const std::string&));
    MOCK_METHOD2(set, Status(const std::string&, const std::string&));
    MOCK_METHOD1(get, std::string (const std::string&));
};

TEST_F(TestKVDB, setstr) {
    EXPECT_CALL(*kvdb, set(_,_)).WillRepeatedly(Return(Status::SUCCESS));

    ASSERT_EQ(kvdb->set("1", "happen"), Status::SUCCESS);
    ASSERT_EQ(kvdb->set("2", "lee"), Status::SUCCESS);
    ASSERT_EQ(kvdb->set("happen", "1"), Status::SUCCESS);
    ASSERT_EQ(kvdb->set("lee", "2"), Status::SUCCESS);
}

TEST_F(TestKVDB, getstr) {
    EXPECT_CALL(*kvdb, get(_)) \
            .WillOnce(Return("happen"))
            .WillOnce(Return("lee"))
            .WillOnce(Return("1"))
            .WillOnce(Return("2"));

    ASSERT_STREQ(kvdb->get("1").c_str(), "happen");
    ASSERT_STREQ(kvdb->get("2").c_str(), "lee");
    ASSERT_STREQ(kvdb->get("happen").c_str(), "1");
    ASSERT_STREQ(kvdb->get("lee").c_str(), "2");
}

TEST_F(TestKVDB, remove) {
    EXPECT_CALL(*kvdb, remove(_)).WillOnce(Return(Status::SUCCESS)).
            WillOnce(Return(Status::FAIL));
    EXPECT_CALL(*kvdb, get(_)) \
            .WillOnce(Return(""));

    ASSERT_EQ(kvdb->remove("1"), Status::SUCCESS);
    ASSERT_EQ(kvdb->get("1"), "");
    ASSERT_EQ(kvdb->remove("1"), Status::FAIL);
}
