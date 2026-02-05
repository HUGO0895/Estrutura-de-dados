#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct fila{
    int val;
    struct fila  *seg;
}no;
void inserir(no*head,no **ini,no**fim,int valor){
    no *novo_no=malloc(sizeof(no));
    novo_no->val=valor;
    if(head->seg==NULL){
        novo_no->seg=novo_no;
        head->seg=novo_no;
        *ini=novo_no;
        *fim=novo_no;
            
     }
    else{
       no * aux=head->seg;
       while(aux->seg!=*ini){
        aux=aux->seg;
       }
       novo_no->seg=*ini;
       aux->seg=novo_no;
       aux=aux->seg;
       *fim=aux;


    }

}
int remover(no *head,no **ini,no **fim){
    no *eliminado=*ini;
    int x=eliminado->val;
    (*ini)=(*ini)->seg;
    head->seg=*ini;
    (*fim)->seg=*ini;
    free(eliminado);
    return x;

}
int main(){
no cabeca,*fim,*ini;
cabeca.seg=NULL;
inserir(&cabeca,&ini,&fim,12);
inserir(&cabeca,&ini,&fim,13);
inserir(&cabeca,&ini,&fim,14);
remover(&cabeca,&ini,&fim);
printf("%d\n",fim->seg->val);
printf("%d",ini->seg->seg->val);



}