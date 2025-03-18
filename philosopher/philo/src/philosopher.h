#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

	typedef struct s_cowboy
	{
		pthread_t	thread;
		char		*name;
	}				t_cowboy;

	#include <unistd.h>
	#include <stdio.h>
	#include <pthread.h>
	#include <stdlib.h>
	#include <limits.h>

#endif