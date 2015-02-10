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

the security of generated key in not guaranteed

on Windows offers a minor security

Remember to set your OS in define file, default is Unix

64 bit only :)


Details of the Algorithm

-extracts a sequence of random number

-first number is used as delta for key selection

-second, third, and the last 2 number are 4 of 8 key of IDEA cipher

-the position of the other 4 key depends on the delta value

-from the other number is obtained a sequence of parity bit

-this sequence is encrypted with IDEA and returned as output
