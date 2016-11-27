#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define BUFSIZE 1000

typedef struct elem{
	char item[BUFSIZE];
	struct elem *next;
}node;

typedef struct{
	node *head, *tail;
	int size;
}list;


void init (list *);
void append(list*, char *);
node* itemAt(list,int);
int check(list* ,char*);
void recursion(list *, FILE *);

int main(){
	list l;
	FILE *ifp;
	
	printf("buffer1\n");
	
	ifp = fopen("inputFile.cpp", "r");
	printf("buffer2\n");
	if(ifp==NULL){
		perror("Error while opening the file. \n");
		exit(EXIT_FAILURE);
	}
	
	init(&l);
	
	recursion(&l, ifp);
	
	
	printf("buffer3\n");
	fclose(ifp);
	
	return 0;
}

void init(list *l){
	l->size=0;
	l->head = l->tail = NULL;
}

void append(list *l, char *t){
	node *n=malloc(sizeof(node));
	
	strcpy(n->item,t);
	n->next=NULL;
	
	if(l->size==0){
		l->head = l->tail = n;
	}
	else{
		l->tail->next=n;
		l->tail=n;
		
	}
	l->size++;
	
}


 node* itemAt(list l, int pos){
    node *tmp = l.head;
    int i = 1;

    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

int check(list *l,char* t){
    node *n = l->head;

	int i,flag=0;

	while(n!=NULL){
        if(strcmp(n->item,t)==0){
       		return 1;
		}
	n=n->next;

	}
	return -1;
}

void recursion(list *l, FILE *fp){
	
	FILE *ofp = fopen("outputFile1.txt", "a");
	char buff[BUFSIZE];
	char *last_token, *line;
	int c;
	
	
	printf("buffer5\n");
	//fprintf(ofp,"\n");
	
	while(fgets(buff,BUFSIZE-1,fp)!=NULL){
		printf("buffer6\n");
		strcpy(line,buff);
		printf("\n%s\n%s\n", line, buff);
		
		last_token = strtok(buff, "\" ");
		printf("\ntoken --> %s\n\n",last_token);
		
		printf("buffer7\n");
		

		if(strcmp(last_token,"#include")==0){
			c = check(l,line);
			printf("buffer7.1\n");
				
			if(c!=1){
				append(l,line);
		//	fprintf(ofp,"\n");
		}
			printf("buffer8\n");
			
			last_token = strtok(NULL, "\" ");
			printf("Realtoken --- %s\n",last_token);
			
		FILE *hfp = fopen(last_token, "r"); //"sample.h"
		printf("buffer9\n");
		
		//fprintf(ofp,"\n"); 
		recursion(l,hfp);
		
		//fprintf(ofp,"\n"); 
		}
		
		else{
			
			fprintf(ofp,"%s", line);
			printf("%s", line);
			
			//if(strcmp(last_token, " ")==0)
			//fprintf(ofp,"\n");
			 
		}	
	}
	
			
	 fprintf(ofp,"\n"); 
    
	fclose(ofp);
	//fclose(hpf);
}
