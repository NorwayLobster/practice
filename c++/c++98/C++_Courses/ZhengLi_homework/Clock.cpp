// Sample4-1
#include <iostream>
using namespace std;

class Clock
{
public:
	// Clock();
	// ~Clock();

	void setTime(int newH=0, int newM=0, int newS =0 );
	void showTime();

private:
	int hour, minute, second;
};


inline void Clock:: showTime(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

void Clock:: setTime(int newH, int newM, int newS )
{
	hour=newH;
	minute=newM;
	second=newS;
}





int main(int argc, char const *argv[])
{
	Clock myClock;
	myClock.setTime();
	myClock.showTime();

	cout<<endl;
	int a[3];
	cout<<"plase input time: hour minute second:";
	cin>>a[0]>>a[1]>>a[2];
	myClock.setTime(a[0],a[1],a[2]);
	myClock.showTime();

	cout<<endl;
	myClock.setTime(23,47,22);
	myClock.showTime();



	return 0;
}