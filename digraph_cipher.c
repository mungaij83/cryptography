#include "score.h"
#include <stdio.h>
char** digraph_encrypt(char **text,Table ** table){
	int rows=sizeof(text)/strlen(text[0]);
	int cols=strlen(text[0])/sizeof(text[0][0]);
	//printf("Rows:%d\nColumns:%d\n",rows,cols);
	char **crypt=(char**)malloc(rows*sizeof(char*));
	int A=(int)'A';
	int i,j,k;
	for(i=0;i<rows*cols;i++){
		crypt[i]=(char*)malloc(3);
		j=text[i][0]-A;
		k=text[i][1]-A;
		crypt[i][0]=table[k][j].ch1;
		crypt[i][1]=table[k][j].ch2;
	}
	return crypt;
}
int main(int argc,char*argv[]){
	char ALPHA[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int key1=3,key2=6,i,rows;
	Table **table=digraph_table(ALPHA,key1,key2);
	//printf("HERE\n");
	print_table(table);
	printf("\n");
	char text[]="Hello world kenya";
	char **digraphs=splitn(text,2);
	printf("\t\tDigraphs:\t\t");
	for(i=0;i<strlen(text)/2;i++){
		printf("%4s",digraphs[i]);
	}
	printf("\n\t\tCrypt:\t\t");
	char **crypt=digraph_encrypt(digraphs,table);
	for(i=0;i<strlen(text)/2;i++){
		printf("%s",crypt[i]);
	}
	printf("\n\t\tCleaning.....\n");
	rows=sizeof(digraphs)/strlen(digraphs[0]);
	printf("\t\tRows1:%d\n",rows);
	for(i=0;i<rows;i++){
		free(digraphs[i]);
	}
	free(digraphs);
	rows=sizeof(crypt)/strlen(crypt[0]);
	printf("\t\tRows2:%d\n",rows);
	for(i=0;i<rows;i++){
		free(crypt[i]);
	}
	rows=strlen(ALPHA);
	printf("\t\tRows0:%d\n",rows);
	for(i=0;i<26;i++){
		printf("%d->\n",i);
		free(table[i]);
	}
	//free(table);
	//free(crypt);
	return 0;
}
