#include <fstream>

using namespace std;

struct Date {
	int monnday, day ,year;

};
int main(int argc, char const *argv[])
{	
	Date dt={6,10, 92};
	ofstream file;
	file.open("date.dat", ios_base::binary);
	file.write(reinterpret_cast<char*> (&dt), sizeof(dt));
	file.close().
	return 0;
	
}