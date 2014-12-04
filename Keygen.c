//
//  Keygen.c
//  Keygenerator
//
//  Created by ivan sarno on 04/12/14.
//  Copyright (c) 2014 ivan sarno. All rights reserved.
//

#include "Keygen.h"



typeint2 *keygen(int bit)
{
    
    int a;
    if (a=bit%16)
        bit +=a;
    bit/=16;
    if (a=bit%4)
        bit +=a;
    
    srand(time(NULL));
    typeint2 key[8];
    typeint2 *sequence = (typeint2 *) malloc (bit*sizeof(typeint2));
    typeint temp[4];
    
    uint16_t delta=rand() % bit;
    int i;
    
    key[0]=rand();
    key[1]=rand();
    
    for(i=0;i<delta;i++)
        sequence[i]=rand()addmod;
    
    key[2]=rand();
    key[3]=rand();
    key[4]=rand();
    key[5]=rand();
    
    for(;i<bit;i++)
        sequence[i]=rand()addmod;
    
    key[6]=rand();
    key[7]=rand();
    
    bit/=4;
    for(i=0;i<bit;i+=4)
    {
        temp[0]=sequence[i];
        temp[1]=sequence[i+1];
        temp[2]=sequence[i+2];
        temp[3]=sequence[i+3];
        
        IDEAencrypt(temp,key);
        
        sequence[i]=temp[0];
        sequence[i+1]=temp[1];
        sequence[i+2]=temp[2];
        sequence[i+3]=temp[3];

        
    }
    
    return sequence;
    
    
}

