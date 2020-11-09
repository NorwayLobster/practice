 ///
 /// @file    test.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-09-10 05:36:55
 ///
 
// main.cpp
#include <iostream>
#include <gtest/gtest.h>
#include "Link.hpp"
#include "func.hpp"

using namespace std;

//全局事件
class GlobalTest:public testing::Environment{

public:
	virtual void SetUp(){ cout<<"GlobalTest::SetUp()"<<endl; }
	virtual void TearDown(){ cout<<"GlobalTest::TearDown()"<<endl; }
};



TEST(IsAbsTest,HandlerTrueReturn){
	EXPECT_TRUE(Abs(-1) != 1) << "Abs(-1)=1";
//	ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1"; //ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
//
	ASSERT_FALSE(Abs(1) == 1) <<"Abs(1)=1";
	ASSERT_FALSE(Abs(1) == 1) <<"Abs(1)=1";

	ASSERT_TRUE(Abs(-1) == 1) << "Abs(-1)=1";

	ASSERT_FALSE(Abs(-2) == -2); //期待结果是false
	ASSERT_EQ(Abs(1),Abs(-1));
	ASSERT_NE(Abs(-1),0);
	ASSERT_LT(Abs(-1),2);
	ASSERT_GT(Abs(-1),0);
	ASSERT_LE(Abs(-1),2);
	ASSERT_GE(Abs(-1),0);
}


//func test
TEST(test_add, is_equal)
{
    EXPECT_EQ(3, add(1, 2));
    ASSERT_EQ(3, add(1, 2));
}

//
TEST(test_prime, is_true) {
    EXPECT_TRUE(is_prime(5));
    ASSERT_TRUE(is_prime(5));
    EXPECT_TRUE(is_prime(3));
}

TEST(test_prime, is_false) {
    ASSERT_FALSE(is_prime(4));
    EXPECT_FALSE(is_prime(4));
}



class TestMap:public testing::Test{
	public:
	//添加日志
	static void SetUpTestCase() { cout<<"TestMap::SetUpTestCase"<<endl; }
	static void TearDownTestCase() { cout<<"TestMap::TearDownTestCase"<<endl; }

	virtual void SetUp() //TEST跑之前会执行SetUp
	{
		cout<<"TestMap::SetUp"<<endl;
		test_map.insert(make_pair(1,0));
		test_map.insert(make_pair(2,1));
		test_map.insert(make_pair(3,2));
		test_map.insert(make_pair(4,3));
		test_map.insert(make_pair(5,4));
	}

	virtual void TearDown() //TEST跑完之后会执行TearDown
	{
		cout<<"TestMap::TearDown"<<endl;
		test_map.clear();
	}

	map<int,int> test_map;
};

//1.
TEST_F(TestMap,Find) //此时使用的是TEST_F宏
{
	map<int,int>::iterator it=test_map.find(1);
	ASSERT_NE(it,test_map.end());
}

//2.
TEST_F(TestMap,Size){
	ASSERT_EQ(test_map.size(),5);
}



class TestLink:public testing::Test{
public:
	//添加日志
	static void SetUpTestCase() { cout<<"SetUpTestCase"<<endl; }
	static void TearDownTestCase() { cout<<"TearDownTestCase"<<endl; }

	virtual void SetUp(){
		cout<<"SetUp"<<endl;
		for(int i=1;i<=5;i++){ link.PushBack(i); }
	}

	virtual void TearDown(){
		cout<<"TearDown"<<endl;
		link.Destroy();
	}

	Link link;
};



TEST_F(TestLink,PushBack){
	ASSERT_FALSE(link.pHead == NULL);
	link.PushBack(9);
	LinkNode *res=link.FindNode(9);
	ASSERT_FALSE(res == NULL);
}

TEST_F(TestLink,PopBack){
	for(int i=1;i<=5;i++){ link.PopBack(); }
}

TEST_F(TestLink,FindNode){
	ASSERT_TRUE(link.FindNode(3));
	ASSERT_TRUE(link.FindNode(2));
	ASSERT_TRUE(link.FindNode(4));
	ASSERT_TRUE(link.FindNode(5));
	ASSERT_TRUE(link.FindNode(1));
	ASSERT_FALSE(link.FindNode(7));
}

TEST_F(TestLink,Delete){
	ASSERT_FALSE(link.pHead == NULL);
	ASSERT_TRUE(link.Delete(3) == true);
	ASSERT_TRUE(link.Delete(9) == false);
}

TEST(FuncDeathTest,nullPtr){
	ASSERT_DEATH(func_null(),"");
}

GTEST_API_ int main(int argc, char ** argv){
	testing::InitGoogleTest(&argc, argv);//将命令行参数传递给gtest

	testing::Environment* env=new GlobalTest();
	testing::AddGlobalTestEnvironment(env);

	return RUN_ALL_TESTS(); //RUN_ALL_TESTS()运行所有测试案例
}
