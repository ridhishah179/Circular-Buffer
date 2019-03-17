
/*========================================================================
** ring.h
** Circular buffer
** ECEN5813
**========================================================================*/
#include "stdio.h"
#include "stdlib.h"
#ifndef RING_H
#define RING_H

typedef struct
{
	char *Buffer;
	int Length;
	int Ini;
	int Outi;
	//int count;
} ring_t;

ring_t *init( int length );
int insert( ring_t *ring, char data );
int remove_data( ring_t *ring, char *data );
int entries( ring_t *ring );
#endif

