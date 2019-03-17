
#include <stdio.h>
#include <stdlib.h>
#include "../Include/ring.h"

ring_t *init( int length )

{	

	

	if (length <= 0)

	{
		printf("length<0 error\n");
		return NULL; 
	}

	ring_t *ringbuff= malloc(sizeof(ring_t));
	if(ringbuff == NULL)

	{
		printf("pointer allocation failed in init\n");
		return NULL;
	}

	ringbuff->Buffer = (char*)malloc(sizeof(length));

	if(ringbuff->Buffer==NULL)

	{
		
		return NULL;
	}

	

	else

	{	
		
		ringbuff->Length = length;
		ringbuff->Ini = 0;
		ringbuff->Outi = 0;

	}
	return ringbuff;
}


int insert( ring_t *ring, char data )

{

	if(((ring->Ini+1)%ring->Length )==ring->Outi)

	{

	printf("buffer full\n");
	return -1;

	}

	

	 else if(ring->Ini== ring->Length-1)

    {

		ring->Buffer[ring->Ini]= data;
		printf("inserted at position=%d, element=%d\n",ring->Ini,ring->Buffer[ring->Ini]);
		ring->Ini=0;
		
		return 0;

    }

    

    else

    {

		ring->Buffer[ring->Ini]= data;
		printf("inserted at position=%d, element=%d\n",ring->Ini,ring->Buffer[ring->Ini]);		
		ring->Ini++;

		return 0;

    }
	
}



int remove_data( ring_t *ring, char *data )

{
	
	
	if(ring->Ini==ring->Outi) 

	{		
		printf("empty buffer");
		return -1;
	}

	

	else if(ring->Outi==(ring->Length)-1)

    {
		*data = ring->Buffer[ring->Outi];
		
		printf("removed %d\n",ring->Buffer[ring->Outi]);
		ring->Outi=0;
		
		return 0;
    }

    

    else

    {
		*data = ring->Buffer[ring->Outi];	
		printf("removed %d\n",ring->Buffer[ring->Outi]);
		ring->Outi++;
	
		return 0;
    }
}



int entries( ring_t *ring )

{

	int entry;
	
	if(ring->Ini >= ring->Outi)
	{
		entry = ring->Ini - ring->Outi;
	}
	else
	{
		entry = ring->Length-(ring->Outi - ring->Ini);
	}
	printf("Number of entries: %d\n",entry);

}
