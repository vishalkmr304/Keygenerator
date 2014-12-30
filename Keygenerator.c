//
//  main.c
//  Keygenerator
//
//  Created by ivan sarno on 04/12/14.
//  Copyright (c) 2014 ivan sarno. All rights reserved.
//

#include <stdio.h>
#include "Keygen.h"

int main(int argc,char **argv)
{
    int bit;
    if (argc<2)
    {
        printf("insert number of bits required\n");
#ifdef Unix
        scanf("%d", &bit);
#endif
        
#ifdef Windows
        scanf_s("%d", &bit);
#endif
    }
    else
    {
        bit=atoi(argv[1]);
    }
    
    uint16_t *sequence=keygen(&bit);
    
#ifdef Unix
    FILE *out = fopen("output", "wb");
#endif
    
#ifdef Windows
    FILE *out;
    fopen_s(&out,"output", "wb");
#endif
    
    fwrite(sequence, sizeof(uint16_t), bit, out);
    

    fclose(out);
    
    
    return 0;


}
