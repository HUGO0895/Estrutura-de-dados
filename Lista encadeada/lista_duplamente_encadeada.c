#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
      int val;
      struct Node *next;
      struct Node *prev;
      
}Node;
typedef struct dupl_enc{
    Node *cabeca;
    Node *cauda;
}Dupla;
void inserir_inicio(Dupla *lista,int valor){
      Node *antigo_P=lista->cabeca;
      Node *novo_no=(Node *)malloc(sizeof(Node));
      novo_no->val=valor;
      novo_no->prev=NULL;
      if(antigo_P==NULL){ lista->cabeca=novo_no; lista->cauda=novo_no; }
      else {
        novo_no->next=antigo_P;
        antigo_P->prev=novo_no;
        lista->cabeca=novo_no;
      }


}
void inverter(Dupla *lista,Node *nos){
      if (nos==NULL) {
        Node *tempo= lista->cabeca;
         lista->cabeca=lista->cauda;
          lista->cauda=tempo;
          return;
        }
     Node * temp=nos->next;
     nos->next=nos->prev;
     nos->prev=temp;
     inverter(lista,nos->prev);
}
void inserir_final(Dupla *lista,int valor){
     Node *final= lista->cauda;
     Node *novo_no=(Node *)malloc(sizeof(Node));
     novo_no->val=valor;
     novo_no->next=NULL;
     final->next=novo_no;
     novo_no->prev=final;
     lista->cauda=novo_no;
}
int main(){
Dupla lista;
inserir_inicio(&lista,160);
inserir_inicio(&lista,161);
inserir_inicio(&lista,162);
inserir_final(&lista,159);
printf("%d",);

}
