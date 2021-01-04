#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	struct T {};
	cout<<sizeof(struct T)<<endl;
	return 0;
}




stack<char>p1,p2;
    stack<int>re;
    char tmp;
    cout<<"welcome using the system!!!"<<endl;
    cout<<"you can input any number if you want!!!\n";
    cout<<endl;
    cout<<"please input the first number(q as the end):\t";
    cin>>tmp;
    while(tmp!='q'){
        p1.push(tmp);
        cin>>tmp;
    }

    cout<<"please input the second number(q as the end):\t";

    cin>>tmp;
    while(tmp!='q'){
        p2.push(tmp);
        cin>>tmp;
    }
    cout<<"the input number has done!!!\n";






using namespace std;

int main (){
    
    int n,t;
    int a[n];
    cin>>n>>t;
    for (int i=0; i<=n;++i)
    { cin>>a[0];   
    }
    
    b[i]=quickSort(a[n]);
    int sum=0;
    int temp=0;
    int i=0;
    while(sum>=t){
        temp=sum;
    sum+=a[i];
        
    ++i;}
    int Max=temp+b[n];
    return Max;

}

int quickSort(int a[], int p, int r)
{
if (p<r)
{ q= divide(int a[n],int p, int r);
 divide(a[n], p-1,q-1);
 divide( a[n],int p, int r);
}
}
int divide(int a[n],int p, int r);