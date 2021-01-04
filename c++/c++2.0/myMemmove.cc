 ///
 /// @file    myMemmove.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-05-11 17:18:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;
void myMemmove(void * dst,const void * src,size_t n){
	if(NULL==src||NULL==dst||0==n) return ;
	if(src==dst) return ;
	char*psrc=(char*) src;
	char*pdst=(char*) dst;
	if(psrc<pdst){
		while(n--){//p+0,p+1,...,p+n-1
			*(pdst+n)=*(psrc+n);
		}
	}else{
		size_t i=0;
		while(i<n){
			*(pdst+i)=*(psrc+i);
		}
	}
}
int main(){
	char a[]="helllooooooooo";
	char b[]="bbbbbbbbbbbfadsfadsfasd";
	myMemmove(b,a,sizeof(a));
	cout<<"b:"<<b<<endl;
	return 0;
}
