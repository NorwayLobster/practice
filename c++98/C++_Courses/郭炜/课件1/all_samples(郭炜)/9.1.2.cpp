//program 9.1.2.cpp 奥数问题
#include <iostream> 
#include <string>
using namespace std;
const int LETTER_NUM = 5;
bool taken[10]; //标志数组，taken[i]表示数字i是否已被用于替换某个字母，即被占用
int val[LETTER_NUM]; 
//val[0]表示'A'被替换成的数字，val[1]表示'B'被替换成的数字，以此类推
int StringToInt( const string & s)
{  //求字符串中s字母被替换成数字后代表的整数
	if( s.length() > 1 &&  val[s[0]-'A'] == 0)
		return -1;  //有前导0则返回-1表示s不合法
	int intVal = 0;
	for(int i = 0; i < s.length(); ++i)
		intVal = intVal * 10 + val[s[i]-'A'];
	return intVal;
}
int main()
{
	int n;
    string s1,s2,s3;
	cin >> n;
	while(n--) {
		cin >> s1 >> s2 >> s3;
		for(val[0] = 0; val[0] <= 9; ++ val[0]) { //尝试字母A的所有替换法
			taken[val[0]] = true; //标记数字val[0]已经被占用，不能再用来替换其他字母
			for(val[1] = 0; val[1] <= 9; ++ val[1]) { //尝试字母B的所有替换法
				if( taken[val[1]]) 
					continue; //若数字val[1]已经被占用，则不能用来替换字母B 
				taken[val[1]] = true;
				for(val[2] = 0; val[2] <= 9; ++ val[2]) {
					if( taken[val[2]])
						continue;
					taken[val[2]] = true;
					for(val[3] = 0; val[3] <= 9; ++ val[3]) {
						if( taken[val[3]])
							continue;
						for(val[4] = 0; val[4] <= 9; ++ val[4]) {
							if( taken[val[4]])
								continue;
							int n1 = StringToInt(s1);
							int n2 = StringToInt(s2);
							int n3 = StringToInt(s3);
							if( n1 >= 0 && n2 >= 0 && n3 >= 0 && n1 + n2 == n3 ) {
								cout << n1 << "+" << n2 << "=" << n3 << endl;
								goto Found;
							}
						}		
						taken[val[3]] = false;
					}
					taken[val[2]] = false;
				}
				taken[val[1]] = false; //试下一个数字前，要解除对数字val[1]的占用
			} 
			taken[val[0]] = false; //试下一个数字前，要解除对数字val[0]的占用
		}
		cout << "No Solution" << endl;
Found: ;
	}
	return 0;
}

