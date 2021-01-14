#include <iostream>
using namespace std;

int main(){
    cout<<"The char of ASCII CODE between 32 and 127 are blow:"<<endl;
    char a;
    short c;
	int b;
    long d;
    float g;
    double e;
    long long f;



    	cout<<"char:"<<sizeof(char)<<"\n";
        cout<<"bool:"<<sizeof(bool)<<"\n";
        cout<<'\n';

    	cout<<"short:"<<sizeof(short)<<"\n";
    	cout<<"int:"<<sizeof(int)<<"\n";
    	cout<<"long:"<<sizeof(long)<<"\n";

        cout<<"unsinged short:"<<sizeof(unsigned short)<<"\n";
        cout<<"unsinged int:"<<sizeof(unsigned int)<<"\n";
        cout<<"unsinged long:"<<sizeof(unsigned long)<<"\n";
        cout<<"long long:"<<sizeof(long long)<<"\n";

        cout<<'\n';
    	cout<<"float:"<<sizeof(float)<<"\n";
    	cout<<"double:"<<sizeof(double)<<"\n";


    	cout<<'\n';

    	cout<<"char:"<<sizeof(a)<<"\n";
    	cout<<"short:"<<sizeof(c)<<"\n";
    	cout<<"int:"<<sizeof(b)<<"\n";
    	cout<<"long:"<<sizeof(d)<<"\n";
    	cout<<"float:"<<sizeof(g)<<"\n";
    	cout<<"double:"<<sizeof(e)<<"\n";
    	cout<<"long long:"<<sizeof(f)<<"\n";


    cout<<"end"<<endl;

    return 0;
}
