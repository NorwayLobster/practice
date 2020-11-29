//program 3.8.1.cpp 求兄弟数
#include <iostream>
using namespace std;
int main()
{	
	int n,m;
	cin >> n >> m;
	int i,j;
	for( i = n; i < m ; ++i )  
		 for( j = i + 1; j <= m; ++j ) 
		 	  if( i * j % (i + j) == 0 ) //为真则说明发现兄弟数
				  goto Done;
Done:    
    if( i == m )
   	    cout << "No solution.";
   	else
	    cout << i << "," << j ;
	return 0;
}

