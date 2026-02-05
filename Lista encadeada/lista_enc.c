#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct jj{
    int val;
    int b;
}jj;

typedef struct Node{
      int val;
      struct Node *next;
      struct Node *prev;
      
      

}Node;
void begin(Node **list,int valor){
    Node *no=(Node *)malloc(sizeof(Node));
     no->val=valor;
    no->next=*list;
    if(*list!=NULL) (*list)->prev=no;

    no->prev=NULL;
  
   *list=no;
   
     }

void fim(Node **list,int valor){
    Node *no=(Node *)malloc(sizeof(Node));
    Node *interacao=*list;
    while(interacao->next!=NULL){
    interacao=interacao->next;
    }
    interacao->next=no;
    no->val=valor;
    no->next=NULL;
    no->prev=interacao;


}
void inverter(Node **list){
     Node * anterior=NULL;
    Node * repeat=*list;
     Node *temp;
     while(repeat!=NULL){
          temp=repeat->prev;
          repeat->prev=repeat->next;
          repeat->next=temp;
          repeat=repeat->prev;
     }
     *list=temp->prev;

}
void remover(int posicao,Node **list){
       Node *p=*list;
       Node *penultimo;
       Node * ultimo;
       int x=1;
       while(p!=NULL && posicao!=x){

             x++;
        
             p=p->next;
       }
       if(p->prev==NULL){
       
         ultimo=p->next;
          *list=ultimo;
         ultimo->prev=NULL;
        
       }
        else if(p->next==NULL){
        penultimo=p->prev;
        penultimo->next=NULL;
         

       }
       else{
       penultimo=p->prev;
        penultimo->next=p->next;
        ultimo=p->next;
        ultimo->prev=penultimo;}
       free(p);
      
       
}
int main(){
Node *list=NULL;
begin(&list,12);
begin(&list,3);
begin(&list,2);
remover(1,&list);
printf("Primeiro elemento: %d\n",list->val);


}