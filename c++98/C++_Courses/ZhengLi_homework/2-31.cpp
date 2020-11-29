#include<iostream>
using namespace std;

int main(){
	// struct Time1;
	// struct Time1 t1;
	class Time1;
	Time1 t1;
	cout<<"plase intput the year,month,day,hour,munite,second."<<endl;
	cin>>t1.year>>t1.month>>t1.day>>t1.hour>>t1.minute>>t1.second;

	cout<<"year:"<<t1.year<<' '<<"month:"<<t1.month<<"day:"<<t1.day<<
	"hour:"<<t1.hour<<"minute:"<<t1.minute<<"second:"<<t1.second<<endl;

}



class Time1 {
public:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

	};