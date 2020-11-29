//program 12.1.2.2.cpp   构造函数和数组
class  CTest {
	public:
		CTest( int n) { }           //构造函数(1)
		CTest( int n, int m) { }    //构造函数(2) 
         CTest() { }                 //构造函数(3)
};
int main(){
	CTest  array1[3] = { 1, CTest(1,2) };	// 三个元素分别用构造函数(1),(2),(3)初始化 
	CTest  array2[3]={ CTest(2,3), CTest(1,2) ,1}; //三个元素分别用(2),(2),(1)初始化 
	CTest * pArray[3] = { new CTest(4), new CTest(1,2)};
     //两个元素指向的对象分别用 (1),(2)初始化 
	return 0;
}

