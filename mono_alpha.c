#include "score.h"
#include<stdio.h>
#include<ctype.h>
/**
Implementation of  mono-alphabetic cipher (Substitution cipher)

To construct the cipher alphabet, the letter A could be represented as any of the 26 letters. The letter B could be represented as any of the remaining 25 letters, C could be represented as any of the remaining 24 letters, and so on until the entire cipher alphabet has been formed. The total number of keys is therefore 26 x 25 x 24 x ... x 1 = 403,291,461,126,605,635,584,000,000.

Reference: http://www.simonsingh.net/The_Black_Chamber/monoalphabetic.html
*/
char *mono_encrypt(char text[],char alphabet[]){
	int i,c;
	int A=(int)('A');
	int index=0;
	char *crypt=(char*)malloc(strlen(text));
	for(i=0;i<strlen(text);i++){
		if(isalpha(text[i])){
			c=toupper(text[i])-A;
			crypt[index]=alphabet[c];
			index++;
		}else{
			crypt[index]=text[i];
			index++;
		}
	}
	return crypt;
}
char *mono_decrypt(char crypt[],char alpha[],char or[]){
	int i,c,c2;
	int A=(int)('A');
	int index=0;
	char *text=(char*)malloc(strlen(crypt));
	for(i=0;i<strlen(crypt);i++){
		if(isalpha(crypt[i])){
			c=index_of_char(crypt[i],alpha);
			//printf("%3d->",c);
			if(c!=-1)
				text[index]=or[c];
			index++;
		}else{
			text[index]=crypt[i];
			index++;
		}
	}
	return text;
}
int main(int argc,char argv[]){
	char ALPHA[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//printf("Main Size:%zi\n",strlen(ALPHA));	
	char *alphabet=shuffle_array(ALPHA);
	char text[]="Hello world! Was wordering how this can be true for anything. But it is true in either way and I apreciate.";
	printf("Plain Text:\t%10s\n",text);
	char *crypt=mono_encrypt(text,alphabet);
	printf("Alpha:\t\t%10s\n",ALPHA);
	printf("Mono Alpha:\t%10s\n",alphabet);
	printf("Crypt:\t\t%10s\n",crypt);
	char *ctext=mono_decrypt(crypt,alphabet,ALPHA);
	printf("DCrypt:\t\t%10s\n",ctext);
	double *freq=frequencies(text,ALPHA);
	int i;
	//printf("\t");
	for(i=0;i<26;i++){
		printf("%6c=>%10f\n",ALPHA[i],freq[i]);
	}
	printf("\n");
	free(freq);
	free(ctext);
	free(crypt);
	free(alphabet);
	return 0;
}
