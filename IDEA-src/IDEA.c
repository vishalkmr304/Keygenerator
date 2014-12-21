//
//  IDEA.c
//  IDEA
//
//  Created by ivan sarno on 02/12/14.
//  Copyright (c) 2014 ivan sarno. All rights reserved.
//

#include "IDEA.h"

//single instance encrypt fun
void IDEA_single_encrypt(uint16_t *message, uint16_t *key)
{
    uint16_t subkey[56];
    keycreate(key,subkey);
    int i;
    for(i=0;i<7;i++)
        Round(message, subkey+(6*i));
    Finalround(message, subkey+(6*i));
}

//single instance decrypt fun
void IDEA_single_decrypt(uint16_t *message, uint16_t *key)
{
    uint16_t subkey[56];
    deckey(key,subkey);
    int i;
    for(i=0;i<7;i++)
        Round(message, subkey+(6*i));
    Finalround(message, subkey+(6*i));

}

//single instance encrypt or decript fun with extern generation of subkey, to reuse the same
void IDEA_crypt(uint16_t *message, uint16_t *subkey)
{
	
	int i;
	for (i = 0; i<7; i++)
		Round(message, subkey + (6 * i));
	Finalround(message, subkey + (6 * i));

}

//multi inscance encrypt fun to process mor block with same key
void IDEA_multi_encrypt(uint16_t *message, uint16_t *key, const int num)
{
	uint16_t subkey[56];
	keycreate(key, subkey);
	int i;
	for (i = 0; i < num; i += 4)
		IDEA_crypt(message + i, subkey);
}


//multi inscance decrypt fun to process mor block with same key
void IDEA_multi_decrypt(uint16_t *message, uint16_t *key,const int num)
{
	uint16_t subkey[56];
	deckey(key, subkey);
	int i;
	for (i = 0; i < num ; i += 4)
		IDEA_crypt(message + i, subkey);

}