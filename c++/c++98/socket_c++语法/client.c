#include "func.h"

int main(int argc, char *argv[])
{
		if(3!=argc)
		{
				perror("args error\n");
				return -1;
		}
		struct socektaddr_in socket
