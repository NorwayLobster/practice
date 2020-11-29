#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int count=101,k;
	char flag ;
	cout<<1<<'\n'<<2<<endl;

	for (int i = 3; i < count; ++i)
	{   flag=false;
		k=sqrt(i);
		for (int j = 2; j <= k && !flag; ++j)
				{
					if(i%j==0)
						flag=true;
				}	
		if (!flag)
		cout<<i<<endl;	
	}
}




// int main(int argc, char const *argv[])
// {
// 	int count=101;
// 	char flag ;
// 	cout<<1<<" is a prime number."<<'\n'<<2<<" is a prime number."<<endl;
// 	int i=3,j,k;
// 	while(i<=100)
// 	{
// 		flag=false;
// 		j=2;
// 		k=sqrt(i);
// 		while(j<=k && !flag)
// 		{
// 			if(i%j==0)
// 			{
// 				flag=true;
// 				// break;
// 			}
// 			++j;
// 		}//while2
// 		if(!flag)
// 			cout<<i<<" is a prime number."<<endl;
// 		++i;
// 	}//while1

// 	return 0;
// }








// int main(int argc, char const *argv[])

// {
// 	int k;
// 	char flag ;
// 	cout<<1<<" is a prime number."<<'\n'<<2<<" is a prime number."<<endl;
// 	int i=3,j;
// 	do
// 	{
// 		flag=false;
// 		j=2;
// 		k=sqrt(i);//improve the efficience, i.e save time 
// 		do
// 		{
// 			if(i%j==0)
// 			{
// 				flag=true;
// 				// break;
// 			}
// 			++j;
// 		}while(j<=k && !flag);//while2
// 		if(!flag)
// 			cout<<i<<" is a prime number."<<endl;
// 		++i;
// 	}while(i<=100);//while1

// 	return 0;
// }