#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct  Node {
    char name[20];
    int  score;
    struct Node *next;
};

void add(char* name, int score, struct Node *node){
    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newnode->name, name);
    newnode->score = score;
    newnode->next = NULL;
    struct Node* p = node;
    while(p->next != NULL){ p = p->next;}
    p->next = newnode;
}

void delete(char* name, struct Node *node){
    for(struct Node *p = node,*q = node->next;q != NULL; p= p->next,q = q->next){
        if(strcmp(q->name,name)==0){
            p->next = q->next;
            break;
        }
    }
  
}

void print(struct Node *node){
    struct Node *p = node->next;
    while(p != NULL){
        printf("%s %d\n",p->name,p->score);
        p = p->next;
    } 
}

int main() {
    char command[10];
    char name[20];
    int score;
    struct Node *LinkeedList = (struct Node*) malloc(sizeof(struct Node));
    LinkeedList->next = NULL;
    do{
        scanf("%s",command);
        if(strcmp(command, "quit")== 0)
            break;
        else if(strcmp(command, "print")==0){
            print(LinkeedList);
            continue;
        }
        scanf("%s",name);
        if(strcmp(command, "delete")==0){
            delete(name, LinkeedList);
            continue;
        }
        scanf("%d",&score);
        if(strcmp(command, "add")==0){
            add(name,score,LinkeedList);
            continue;
        }
    }while(strcmp(command, "quit")!= 0);
    while (LinkeedList != NULL)
    {
        free(LinkeedList);
        LinkeedList = LinkeedList->next;
    }
    return 0;
}
