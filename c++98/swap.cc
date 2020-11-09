 ///
 /// @file    swap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 00:40:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;
#if 0
int swap(int x, int y)
{
	int tmp=x;
	x=y;
	y=tmp;
	return 0;
}
#endif

int swap(int *x, int *y)
{
	int tmp=*x;
	*x=*y;
	*y=tmp;
	return 0;
}

#if 1
int swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
	return 0;
}
#endif

int main(int argc, char**argv)
{
	if(3!=argc)
	{
		perror("args error\n");
		exit(0);
	}
	int x,y;
	std::cin>>x>>y;
	cout<<"before swap:"<<endl;
	cout<<"x="<<x<<",y="<<y<<endl;
	
//	swap(&x,&y);
	swap(x,y);
	cout<<"after swap:"<<endl;
	cout<<"x="<<x<<",y="<<y<<endl;

	for(int i=0;i<argc;++i)
	{
		printf("argv[%d]=%s\n",i,argv[i]);
	}

	return 0;
}
