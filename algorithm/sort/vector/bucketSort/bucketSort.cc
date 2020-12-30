//
/// @file    bucketSort.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-03-02 22:53:04
///

#include <bits/stdc++.h>
using namespace std;
void generateRandomArray(vector<int> &v, int maxSize, int maxValue);
void print(vector<int> & v);
void bucketSort(vector<int> &v,vector<int>&res){
	int len=v.size();
	vector<int>::iterator maxValueIter=max_element(v.begin(),v.end());
	vector<int>::iterator minValueIter=min_element(v.begin(),v.end());
	int a=*maxValueIter-*minValueIter;
	//vector<int> bucket(a,0);
	vector<int> bucket(*maxValueIter-*minValueIter+1,0);
	for(int i=0;i<len;++i){
//fuck: i++ ???fuck		++bucket[v[i++]];
		++bucket[v[i]-*minValueIter];
	}
	for(int i=0;i<bucket.size();++i){
		while(bucket[i]-->0){
//			res.push_back(i);
			res.push_back(i+*minValueIter);	
		}
	}
}

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, bubbleSorting!\n";
	int testTime = 5;
	int maxSize = 11;
	int maxValue = 1000;
	vector<int> v;
	v.reserve(maxSize);
	bool succeed = true;
	srand((unsigned)time(NULL));
	for (int i = 0; i < testTime; i++) {
		v.clear();//用完后每次都要清理
		generateRandomArray(v, maxSize, maxValue);
		vector<int> v1(v);
		vector<int> v2(v);
		print(v);
		//        print(v1);
		//        print(v2);
		sort(v2.begin(),v2.end());
		//        selectSort_v1(v1);
		//        selectSort_v2(v1);
		vector<int> res;
		bucketSort(v1,res);
		printf("\n");
		print(res);
		print(v2);
		printf("\n");
		if (!equal(v2.begin(), v2.end(), res.begin())){
			//        if (v1!=v2){
			succeed = false;
			print(res);
			print(v2);
			//            cout<<endl;
			break;
		}
		//            cout<<endl;
		}
		cout<<(succeed ? "Nice!" : "Fucking fucked!");
		cout<<endl;
		return 0;
	}

	void generateRandomArray(vector<int> &v, int maxSize, int maxValue){
		//    srand((unsigned)time(NULL));
		for(int i = 0; i < maxSize;i++ )
			v.push_back(rand()%(maxValue-10)+10);
	}

	void print(vector<int> & v)
	{
		copy(v.begin(), v.end(), ostream_iterator<int> (cout," "));
		//    std::copy(to_vector.begin(), to_vector.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << '\n';
	}


