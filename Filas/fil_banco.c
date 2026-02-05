#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct cliente{
    int id;
    int horario_chegada;
    int comeco_atendimento;
    int horario_saida;
    int tempo_espera;
}cli;
typedef struct no{
    cli cliente;
    struct no *proximo;
}no;
typedef struct fila{
    no *primeiro;
    no *ultimo;
    int tamanho;
}fila;
typedef struct caixas{
     int id;
     cli cliente_atual;
     int ocioso;
     int ocupado;
     int tempo_res;
}boxs;

fila *criar_fila(){
      fila *nova=(fila *)malloc(sizeof(fila));
      nova->primeiro=NULL;
      nova->ultimo=NULL;
      nova->tamanho=0;
      return nova;
}
void enfileirar(fila *a,cli clie){
    no *cliente=(no *)malloc(sizeof(no));
    cliente->cliente=clie;
    cliente->proximo=NULL;
      if(a->primeiro==NULL){
        a->primeiro=cliente;
        a->ultimo=cliente;
      }
      else{
        a->ultimo->proximo=cliente;
        a->ultimo=cliente;
      }
      a->tamanho++;
}
cli desemfileirar(fila *a){
      cli valor_retorno =a->primeiro->cliente;
      a->primeiro=a->primeiro->proximo;
      if (a->primeiro==NULL){a->ultimo=NULL;}
      return valor_retorno;
}
int vazia(fila *a){
  return a->primeiro==NULL && a->ultimo==NULL;
}
int main(){
fila *fila_banco=criar_fila();
fila *fila_repat=fila_banco;
srand(time(NULL));
int funcionamento=8*60;
int total_clientes=0;
int tempo_espera;
boxs* caixas=(boxs *)malloc(5*sizeof(boxs));
for(int x=0;x<5;x++){
    caixas[x].id=x+1;
    caixas[x].ocioso=0;
    caixas[x].ocupado=0;
    caixas[x].tempo_res=0;
}
for(int minutos=0;minutos<funcionamento;minutos++){
    if(minutos > 0 && minutos % 10 == 0){
       cli novo_clie;
       novo_clie.id=++total_clientes;
       novo_clie.horario_chegada=minutos;
       novo_clie.horario_saida=-1;
       novo_clie.tempo_espera=-1;
       novo_clie.comeco_atendimento=0;
       enfileirar(fila_banco,novo_clie);
    }
   for(int x=0;x<5;x++){
     if(caixas[x].ocupado){
          caixas[x].tempo_res--;
        if(caixas[x].tempo_res==0){
            caixas[x].ocupado=0;
            caixas[x].cliente_atual.horario_saida=minutos;
            caixas[x].cliente_atual.tempo_espera=caixas[x].cliente_atual.comeco_atendimento -   caixas[x].cliente_atual.horario_chegada;
            printf("%d \n",caixas[x].cliente_atual.tempo_espera);
        }
     }
     if(!caixas[x].ocupado && !vazia(fila_banco)){
        cli proximo =desemfileirar(fila_banco);
        proximo.comeco_atendimento=minutos;
        caixas[x].ocupado=1;
        caixas[x].tempo_res=50+rand()%4;
        caixas[x].cliente_atual=proximo;

     }
     if(!caixas[x].ocupado){
        caixas[x].ocioso++;
     }
   }
}
printf("%d",total_clientes);
}