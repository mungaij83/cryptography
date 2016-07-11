#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include "score.h"
char *encipher_vigenere(char **table,char *text,char*key){
	int size=strlen(text);
	printf("Size:%d\n",size);	
	char *crypt=(char*)malloc(size*sizeof(char));
	int i=0,idx=0,j,k;	
	while(i<size){
		if(idx==strlen(key)){
			idx=0;
		}
		j=toupper(key[idx])-'A';
		k=toupper(text[i])-'A';
		printf("(%3d,%3d)  %4c =>%3c\n ",j,k,table[j][k],key[idx]);
		crypt[i]=table[j][k];
		idx++;
		i++;
	}
	return crypt;
}
int main(int argc,char*argv[]){
	char key[]="CHARLES";
	char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char **table=vigenere_table(alpha,key);
	print_vigenere(table,key);
	char text[]="Divert Troops To East Ridge";
	char *r=remove_ws(text);
	printf("RepFree: %s\n",r);
	char *crypt=encipher_vigenere(table,r,key);
	printf("Crypt:%s\n",crypt);

	free(r);
	free(crypt);	
	int idx,i;
	for(i=0;i<strlen(key);i++){
		idx=toupper(key[i])-'A';
		free(table[idx]);
	}
	free(table);
	return 0;
}
