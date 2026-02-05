#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int tamanho(int *fim,int *ini,int n){
     while(!(cheia(fim,ini,n))){
             (*fim)++;
     }

}
int vazia(int *fim,int *ini){
    return *fim==*ini;
}
int cheia(int *fim,int *ini,int n){
    if(((*fim+1)%n)==*ini){ printf("Cheia\n"); return 1;}
    
}
void inserir(int *v,int valor,int *fim,int n,int *ini){
      if(cheia(fim,ini,n))return;
      v[(*fim)++]=valor;
      if(*fim==n){ *fim=0;}
};
int remover(int *v,int *ini,int n,int *fim){
    if(vazia(fim,ini)){return;}
      (*ini)++;
      if((*ini)==n){*ini=0;}
      return v[(*ini)-1];
}
int main(){
int vetor[5];
int fim=0;
int ini=0;
inserir(vetor,12,&fim,5,&ini);
int d=remover(vetor,&ini,5,&fim);
printf("%d",d);
}
