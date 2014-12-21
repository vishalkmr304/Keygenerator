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
    if (a=*bit%16)
        *bit +=16-a;
    *bit/=16;
    if (a=*bit%4)
        *bit +=4-a;
    
    srand(time(NULL));
    uint16_t key[8];
    uint16_t *sequence = (uint16_t *) malloc (*bit*sizeof(uint16_t));
    
    uint16_t delta=rand() % *bit;
    int i;
    
    key[0]=rand();
    key[1]=rand();
    
    for(i=0;i<delta;i++)
        sequence[i]=rand()addmod;
    
    key[2]=rand();
    key[3]=rand();
    key[4]=rand();
    key[5]=rand();
    
    for(;i<*bit;i++)
        sequence[i]=rand()addmod;
    
    key[6]=rand();
    key[7]=rand();
    
	IDEA_multi_encrypt(sequence, key, *bit);
	
    
    return sequence;
    
    
}

