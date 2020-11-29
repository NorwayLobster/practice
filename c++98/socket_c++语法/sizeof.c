#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	
	int i;
	printf("sizeof i=%lu\n",sizeof i );
	printf("sizeof i=%lu\n",sizeof (i) );
	printf("sizeof i=%lu\n",sizeof (int) );
	// printf("sizeof i=%lu\n",sizeof int );

	return 0;
}