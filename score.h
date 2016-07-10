#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
void swap(char *a,char *b){
	char tmp=*b;
	*b=*a;
	*a=tmp;
}
char * shuffle_array(char text[]){
	srand(time(NULL));
	//printf("SHUFF: %zi\n",strlen(text));
	char *curr=(char*)malloc((strlen(text)+1)*sizeof(char));
	strcpy(curr,text);
	int i;
	for(i=0;i<strlen(text)-1;i++){
		int j=rand()%(i+1);
		//printf("(%d->%d)\t",j,i);
		if(i!=j)
			swap(&curr[i],&curr[j]);		
	}
	return curr;
}
int index_of_char(char alpha,char alphabet[]){
	int i;		
	for(i=0;i<26;i++){
		if(alpha==toupper(alphabet[i])){
			return i;
		}
	}
	return -1;
}
double* frequencies(char text[],char letters[]){
	int *frequencies;
	int size=strlen(letters);
	//printf("Size:%d\n",size);
	frequencies=(int*)malloc(size*sizeof(int));
	double *freq=(double*)malloc(size*sizeof(double));
	int i,c;
	int len=strlen(text);
	for(i=0;i<size;i++){
		frequencies[i]=0;
		freq[i]=0.0;
	}

	for(i=0;i<len;i++){
		if(isalpha(text[i])){
			c=index_of_char(toupper(text[i]),letters);
			if(c!=-1){
				frequencies[c]++;
				//printf("%d->",c);
			}
		}
	}

	for(i=0;i<size;i++){
		if(frequencies[i]>0){
			freq[i]=((float)frequencies[i]/(float)(len))*100;
			//printf("(%0.2f=>%d)",freq[i],frequencies[i]);
		}
	}
	
	free(frequencies);
	return freq;
}
char* encrypt_caesar(char text[],int key){
	int A=(int)('A');
	int Z=(int)('Z');
	char *crypt=(char*)malloc(strlen(text));
	int i;
	int index=0;
	char c;
	for(i=0;i<strlen(text);i++){
		if(isalpha(text[i])){ //Skip other characters
			c=toupper(text[i])+key;
			if(c>Z){ //Rounf to the end
				crypt[index]=(char)(A+(c-Z)-1);	
			}else{
				crypt[index]=(char)c;
			}
			index++;
		}
	}
	return crypt;
}
typedef struct{
	char ch1;
	char ch2;
}Table; 
Table **digraph_table(char *alpha,int key1,int key2){
	int size=strlen(alpha);
	Table **out=(Table**)malloc(size*sizeof(Table *));
	char *alpha1=encrypt_caesar(alpha,key1);
	char *alpha2=encrypt_caesar(alpha,key2);
	int i,j;
	//printf("\tStarts\nSize:%i\nApha1:\t%10s\nAlpha2:\t%10s\n",size,alpha1,alpha2);
	for(i=0;i<size;i++){
		out[i]=(Table*)malloc(size*sizeof(Table));
		for(j=0;j<size;j++){
			out[i][j].ch1=alpha1[i];
			out[i][j].ch2=alpha2[j];
			//printf("(%c,%c) ",out[i][j].ch1,out[i][j].ch2);
		}
		//printf("\n");
	}
	//printf("\tFinish\n");
	free(alpha1);
	free(alpha2);
	return out;
}
void print_n(char c, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%c",c);
	}
	printf("\n");
}
void print_table(Table **table){
	int i,j;
	int A=(int)('A');
	printf("\t--------------------------Digraph Table-------------------------------------- \n\t");
	for(i=0;i<26;i++){
		printf("%4c",i+A);
	}
	printf("\n\t");
	print_n('-',26*4+5);
	for(i=0;i<26;i++){
		printf("\t%c  ",i+A);
		for(j=0;j<26;j++){
			printf("%c%c%2c",table[i][j].ch1,table[i][j].ch2,'|');
		}
		printf("\n");
	}
}
char * readn(char *str,int *index, int n){
	int i=0;
	int nn=*index;
	char *nw=(char*)malloc(n);
	while(i<n && nn<strlen(str)){
		if(isalpha(str[nn])){ //Skip other characters here
			nw[i]=toupper(str[nn]);			
			//printf("Index: %d->",*index);
			i++;
		}
		nn++;
		(*index)++;
	}
	while(i<n){ //Add padding
		nw[i]='X';
		i++;
	}
	//printf("\n");
	return nw;
}
char **splitn(char *stri,int n){
	int len=(int)(ceil((float)strlen(stri)/(float)n));
	int index=0,i,j;
	char *temp;
	char **text=(char**)malloc(len*sizeof(char *));
	for(i=0;i<len;i++){
		text[i]=(char*)malloc((n+1)*sizeof(char));
		temp=readn(stri,&index,n);
		strcpy(text[i],temp);
		free(temp);
	}
	return text;	
}
