#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
      int val;
      struct Node *next;
      
}Node;

void inserir_no_ini(Node **lista,int valor){
   Node *no=(Node *)malloc(sizeof(Node));
   no->val=valor;
   if(*lista==NULL){*lista=no; (*lista)->next=*lista;   }
   else{
      no->next=*lista;
       Node *atual=*lista;
       while(atual->next!=*lista){
            atual=atual->next;
          }
        atual->next=no;
        *lista=no;


   }
}
void inserir_no_fim(Node **lista,int valor){
          Node *atual=*lista;
          Node *no=(Node *)malloc(sizeof(Node));
          no->val=valor;
          while(atual->next!=*lista){
            atual=atual->next;
          }
          atual->next=no;
          no->next=*lista;
          
}
   void princip(Node **list,int n,int k){
      if((*list)->next==*list || k==1){  return ;}
      if((n+1)==k){
         Node *eliminado=(*list)->next;
         (*list)->next=eliminado->next;
         *list=(*list)->next;
         free(eliminado);
         princip(&(*list),1,k);

      }
      else{
         *list=(*list)->next;
         princip(&(*list),n+1,k);
      }
}
int jopeus(int n,int k){
     if(n<=1)return 1;
     if(k==1)return n;
     return (jopeus(n-1,k)+k-1)%n+1;
}
int main(){
 
 
}
