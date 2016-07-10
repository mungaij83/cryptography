#include<math.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/**
This is a n example of Transposition cipher. It is an implementation of Rail Fence cipher

Reference: http://www.simonsingh.net/The_Black_Chamber/railfencecipher.html
*/
void print_array(char text[], int lines,int);
char* create_fence(char text[], int lines){
	int count=(int)ceil((float)strlen(text)/(float)lines);
	printf("Lines:%d\n",lines);
	printf("Len:%zi\n",strlen(text));
	printf("Columns: %d\n",count);
	printf("Rows:%d\n",lines);
	char *out=(char*)malloc(sizeof(char)*(lines*count));
	int i,j,pos,pos2;
	char c;
	for(i=0;i<lines;i++){
		for(j=0;j<count;j++){
			pos=i*count+j;
			pos2=j*lines+i;
			if(pos<count*lines && pos2<count*lines){
				c=text[pos2];
				printf("%c(%3d,%3d)",' ',pos,pos2);
				if(isblank(c)){
					out[pos]='^';
				}else{
					out[pos]=text[pos2];
				}
			}
			
		}
		printf("\n");
	}
	printf("\nSize: %zi\n",strlen(out));
	print_array(out,lines,count);
	return out;
}
void print_array(char text[], int lines,int cols){
	int i,j,pos;
	//printf("%s\n",text);
	int len=strlen(text);
	printf("Size:%d\n",len);
	for(i=0;i<lines;i++){
		for(j=0;j<cols;j++){
			pos=i*cols+j;
			//printf("%d=>(%d,%d)\n",pos,i,j);
			if(pos<lines*cols){
				printf("%4c",text[pos]);
			}
		}
		printf("\n");
	}
}
void decipher_fence(char text[], int lines){
	int count=(int)ceil((float)strlen(text)/(float)lines);
	printf("Lines:%d\n",lines);
	printf("Len:%zi\n",strlen(text));
	printf("Columns: %d\n",count);
	printf("Rows:%d\n",lines);
	char *out=(char*)malloc(sizeof(char)*(lines*count));
	int i,j,pos,pos2;
	char c;
	for(i=0;i<lines;i++){
		for(j=0;j<count;j++){
			pos=i*count+j;
			pos2=j*lines+i;
			if(pos<count*lines && pos2<count*lines){
				c=text[pos2];
				printf("%c(%3d,%3d)",' ',pos,pos2);
				if(isblank(c)){
					out[pos2]='.';
				}else{
					if(out[pos2]=='^'){
						out[pos2]=' ';
					}else{
						out[pos2]=text[pos]; //Reverse this
					}
				}
			}
			
		}
		printf("\n");
	}
	printf("\n");
	print_array(out,lines,count);
}
int main(int argc,char *argv[]){
char text[]="I was wodering how it can be done in C programming language. It is owe some, I can tell it. Not a bit";
int lines=7;
create_fence(text,lines);
return 0;
}
