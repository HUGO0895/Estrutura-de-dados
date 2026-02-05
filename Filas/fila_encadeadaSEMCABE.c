#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct fila{
    int val;
    struct fila  *seg;
}no;
void inserir(no **ini,int valor,no **fim){
        no * novo=(no *)malloc(sizeof(no));
        novo->val=valor;
        novo->seg=NULL;
        if(*ini==NULL){
            *ini=novo;
            *fim=novo;
        }
        else{
            (*fim)->seg=novo;
            *fim=novo;
        }
}
int remover(no **ini,no **fim){
        no *aRemover=*ini;
        int x=aRemover->val;
        if(aRemover==NULL){
            return;
        }
        *ini=aRemover->seg;
        free(aRemover);
        if(*ini==NULL) *fim=NULL;
        return x;
}
int vazia(no **ini,no **fim){
    return *ini==NULL && *fim==NULL;
}

int main(){
  
}