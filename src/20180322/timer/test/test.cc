///
/// @file    test.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-04-22 14:04:37
///

// @file    1.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2016-04-06 10:08:45
///

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/eventfd.h>
#include <sys/poll.h>

#define handle_error(msg) \
	do {\
		perror(msg);\
		exit(EXIT_FAILURE);\	
	} while(0)

int main(int argc, char **argv)
{
	uint64_t u;
	int efd = eventfd(10, 0);
	if(-1 == efd)
	{
		handle_error("eventfd");
	}

	int ret = fork();
	if(0 == ret)
	{
		struct pollfd pfd;
		pfd.fd = 0;
		//pfd.events = POLLIN;
		for(int j = 1; j < argc; ++j)
		{
			printf("Child writing %s to efd\n", argv[j]);
			u = atoll(argv[j]);
			ssize_t s = write(efd, &u, sizeof(uint64_t));
			if(s != sizeof(uint64_t))
			{
				handle_error("write");
			}
			//sleep(1);
			poll(&pfd, 1, 1000);
		}
		printf("Child completed write loop\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		struct pollfd ppfd;
		ppfd.fd = 0;
		ppfd.events = POLLIN;
		for(int ii = 0; ii < argc - 1; ++ii)
		{
			ssize_t s = read(efd, &u, sizeof(uint64_t));
			if(s != sizeof(uint64_t))
			{
				handle_error("read");
			}
			poll(&ppfd, 1, 2000);
			printf("Parent read %llu from efd\n", u);
		}
		exit(EXIT_SUCCESS);
	}
}


