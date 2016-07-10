#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "score.h"
/**
This is a simple algorithm to implement Kamasutra Cipher.

To construct the cipher alphabet, the letter A could be paired with any of the remaining 25 letters. Another letter could be paired with any of the remaining 23 letters. This continues until there is only 1 letter left. The number of keys is therefore 25 x 23 x ... x 1 = 7,905,853,580,625.

	1. Randomize alphabet
	2. For x in net_alpha
	3.	if is alpha x
	4		new_index=int(x)-A
	5.		out[index]=net_alpha[new_index]
	6. Done
Reference: http://www.simonsingh.net/The_Black_Chamber/kamasutra.html
*/

char* kama_encipher(char text[],char alphabet[]){
	int i;
	int A=(int)('A');
	int c;
	int index=0;
	char *crypt=(char*)malloc(strlen(text));
	printf("A:%d\n",A);
	printf("Size: %zi",strlen(text));
	for(i=0;i<strlen(text);i++){
		if(isalpha(text[i])){
			c=(int)(toupper(text[i])-A); //Calculate index of alphabet
			printf("Loc:%d->%d\n",c,index);
			crypt[index]=alphabet[c];
			index++;
		}
	}	
	return crypt;	
}

int main(int agrc, char*argv[]){
	char ALPHA[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	printf("Array:%s\n",ALPHA);
	char *text=shuffle_array(ALPHA);
	printf("Shuffled:%s\n",text);
	char str[]="Hello there"; 
	char *crypt=kama_encipher(str,text);
	printf("Crypt:%s\n",crypt);
	free(crypt);
	free(text);
}
