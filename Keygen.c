//
//  Keygen.c
//  Keygenerator
//
//  Created by ivan sarno on 04/12/14.
//  Copyright (c) 2014 ivan sarno. All rights reserved.
//

#include "Keygen.h"



uint16_t *keygen(int *bit)
{
    
    int a;
    if ((a=*bit%16))
        *bit +=16-a;
    *bit/=16;
    if ((a=*bit%4))
        *bit +=4-a;
    
    srand((unsigned int)time(NULL));
    uint16_t key[8];
    uint16_t *sequence = (uint16_t *) malloc (*bit*sizeof(uint16_t));
    
    uint16_t delta=rand() % *bit; //extracts random number as delta
    int i;
    
    key[0]=rand(); //random key to IDEA
    key[1]=rand();
    
    for(i=0;i<delta;i++) //compose a 16 bit int with parity of 16 random number
	{
		for (a=0;a<15;a++)
		sequence[i]=(sequence[i]<<1)+(rand()%2);
	}
	
    
    key[2]=rand(); //other key extract after delta number of sequence
    key[3]=rand();
    key[4]=rand();
    key[5]=rand();
    
    for(;i<*bit;i++)
	{
		for (a=0;a<15;a++)
			sequence[i]=(sequence[i]<<1)+(rand()%2);
	}
	
    key[6]=rand();
    key[7]=rand();
    
	IDEA_multi_encrypt(sequence, key, *bit); //encrypt the sequence with IDEA and random key
	
    
    return sequence;
    
    
}

