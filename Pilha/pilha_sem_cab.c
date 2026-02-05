#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha{
         int c;
         struct pilha *seg;
}pilha;
void empilhar(pilha ** p,int valor){
    pilha *no=malloc(sizeof(pilha));
    no->c=valor;
    if(*p==NULL){
      *p=no;
    }
    else{
        no->seg=*p;
        *p=no;
    }
}
void inserirP(char *v,char n,int *t){
    v[(*t)++]=n;
}
int removerP(int *v,int *t){
     int x;
   x= v[--(*t)];
   return x;
   
}
int desempilhar(pilha **p){
    if(*p==NULL){
        printf("Está vazia.");
        return;
    }
    else{
     int x=(*p)->c;
     *p=(*p)->seg;
     return x;
     }

}
int TTT (int x[], int n) {
if (n == 0) return 0;
if (x[n] > 0) return x[n] + TTT (x, n - 1);
else return TTT (x, n - 1); }
int TTT2 (int *x, int n) {
    int soma=0;
    int t=n+1;
   for(int y=n;y>0;y--){
      soma+=removerP(x,&t);
   }
   return soma;
}
int main(){
    int v[5]={2,2,3,4,3};
    printf("%d",TTT2(v,4));
  }

 

