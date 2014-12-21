Keygenerator
============

Random key generator algorithm by me, based on C rand fun and IDEA-cipher

Keygenerator is stand alone program that takes as input number of bit you need

and return output file with binary key in current directory

Keygenerator è un programma autonomo che prende in input il numero di bit richiesti 

e restituisce un file output con la chiave binaria nella cartella corrente

Keygen is a function with

input:  a pointer to number of bit you need

output: unsigned 16 bit int pointer, extra random bit are add to complete last int, the pointer input is updated with the actual number of uint16

!!!ATTENTION!!!
algorithm security not proven formally and the security of generated key in not guaranteed

NOT WORK on Windows

64 bit only

