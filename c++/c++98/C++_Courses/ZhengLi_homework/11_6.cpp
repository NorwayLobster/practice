#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<class T>
inline string toString(const T&v){
	ostringstream os;
	os<<v;
	return os.str();
}

int main(int argc, char const *argv[])
{
	string str1= toString(5);
	cout<<str1<<endl;
	string str2=toString(1.2);
	cout<<str2<<endl;
	cout<<str2+str1<<endl;
	cout<<(str2<str1)<<endl;

	cout<<"use of stirng:"<<endl;
	string s1="123", s2;
	s2+=s1;//123
	s1="abc";
	s1+=s2;//abc123
	s1+="def";//abc123def
	cout<<"1)"<<s1<<endl;
	if(s2<s1)
		cout<<"2)s2<s1"<<endl;
	else 
		cout<<"2)s2>=s1"<<endl;
	s2[1]='A';
	s1="XYZ"+s2;
	string s3= s1+s2;
	cout<<"3)"<<s3<<endl;
	cout<<"4)"<<s3.size()<<endl;
	string s4= s3.substr(1,3);

	cout<<"5)"<<s4<<endl;
	char str[20];
	strcpy(str,s4.c_str());
	cout<<"6)"<<str<<endl;

	return 0;
}