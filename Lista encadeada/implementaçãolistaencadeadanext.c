#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node *next;
}Node;
union dadi{
       int inteiro;
       char carac;
       float flo;
}dadi;
typedef struct dado{
     union dadi val;
     int valor;
     
}dado;


void inserirInicio(Node **list,int valor){
    Node *no=(Node *)malloc(sizeof(Node));
    no->val=valor;
    if(*list!=NULL){
    no->next=*list;
    *list=no;
    return;
    }
    else{
    *list=no;}


    
}
void inserirFim(Node **list,int valor){
    Node *atual=*list;
   
    Node  *no=(Node *)malloc(sizeof(Node));
     no->val=valor;
    no->next=NULL;
    if(*list==NULL){
        *list=no;
        return;
    }
    while(atual->next!=NULL){

        atual=atual->next;
    }
    
    atual->next=no;
    
  

    

}
void inverter(Node **list){
Node *atual=*list;
Node *proximo_atual;
Node *proximo=NULL;
while(atual!=NULL){
     proximo_atual=atual->next;
     atual->next=proximo;
     proximo=atual;
    atual=proximo_atual;
}
*list=proximo;
}
void vetor_para_lista(Node **list,int *v,int n){
     for(int x=0;x<n;x++){
        inserirFim(list,v[x]);
     }
}
int  menor(Node *list){
    int x=list->val;
    Node *p=list;
    int i=0;
    int menor=0;
      while(p!=NULL){
        if((p->val)<x){
            x=p->val;
            menor=i;
        }
        i++;
       p=p->next;
      }
      return menor;

}
int  menoR(Node *list,int valor,int posi,int posi_certa){
         if (list->next==NULL)return posi_certa ;
         if(valor<list->next->val){
            return menoR(list->next,valor,posi+1,posi_certa);
         }
         else{
            
         return (menoR(list->next,list->next->val,posi+1,posi+1));}}

int lista_crescente(Node *list ){
     if(list->next==NULL) return 1;
     if(list->val<list->next->val)
        return lista_crescente(list->next);
     else{
        return 0;
     }
};
int lista234(Node *list){
     while(list->next!=NULL){
         if(list->val>list->next->val)return 0;
         list=list->next;
     }
     return 1;

}
/*  Supoe que a pisição seja valida ne fi  */
void remover_dalista(Node **list,int posicao){
    Node *atual=*list;
    if(posicao==0){
        *list=atual->next;
        free(atual);
        return;
    }
      
        int comecar=0;
        while(comecar!=posicao-1 && atual->next!=NULL){
            comecar+=1;
           atual= atual->next;
        }
        Node *lixo=atual->next;
        atual->next=lixo->next;
        free(lixo);

}
void inserirComEscolha(Node **list,int valor,int alvo){
     Node *atual=*list;
     Node *no=(Node *)malloc(sizeof(Node));
     no->val=valor;
     int posicao=0;
     while(posicao!=alvo && atual->next!=NULL){
        atual=atual->next;
        posicao++;
     }
     no->next=atual->next;
     atual->next=no;
}
void inserirComEscolha2(Node **list,int valor,int alvo){
     Node *atual=*list;
     Node *no=(Node *)malloc(sizeof(Node));
     no->val=valor;
     int posicao=0;
     while(posicao!=alvo-1 && atual->next!=NULL){
        atual=atual->next;
        posicao++;
     }
     no->next=atual->next;
     atual->next=no;
}
void remover_elementos(Node **list,int deletar){
           Node *atual=*list;
           Node *anterior=NULL;
           Node *temp=NULL;
           while (atual!=NULL){  
            if(atual->val==deletar){
                temp=atual;
                if(anterior==NULL){
                     
                    *list=atual->next;
                    
                }
                else{
                    
                     anterior->next=atual->next;
                    
                   

                }
           
            atual= atual->next;
            free(temp);
            }
            else{
                anterior=atual;
                atual=atual->next;
            }
                
           }
           
          
        


}
void remover_ele_R(Node **list,int deletar,Node *anterior){
          if(*list==NULL)return;
          Node *temp=*list;
            if((*list)->val==deletar){
                 if(anterior==NULL){
                    *list=(*list)->next;
                   remover_ele_R(list,deletar,anterior);
                 }
                 else{
                
                    anterior->next=(*list)->next;
                    remover_ele_R(&(anterior->next),deletar,anterior);
            
                 }
                free(temp);
          
            }
            else{
            remover_ele_R(&((*list)->next),deletar,anterior);}
}
void remover_elemento_minimo(Node **list){
      Node *atual=*list;
      Node *menoR=atual;
      Node *anterior_Menor=NULL;
      while(atual->next!=NULL){
        if(atual->next->val<menoR->val){
            menoR=atual->next;
            anterior_Menor=atual;
        }
        atual=atual->next;
      }
     if(anterior_Menor==NULL){
        *list=menoR->next;

     }
     else{
        anterior_Menor->next=menoR->next;
     }
      free(menoR);
}
void remover_elemento_minimoRe(Node **list,Node *anterior,Node *menor){
        if((*list)->next==NULL){
            
            if(anterior==NULL){
                *list=menor->next;
            }
            else{
              anterior->next=menor->next;
            }
               free(menor);
               return;
        }
            
        if (menor->val<(*list)->next->val){
            remover_elemento_minimoRe(&((*list)->next),anterior,menor);
        }
        else{
             anterior=menor;
            menor=(*list)->next;
            remover_elemento_minimoRe(&((*list)->next),anterior,menor);
        }
        
}
void vetor_to_list(int *v,Node **list,int n){
     Node *atual=*list;
      for(int x=0;x<n;x++){
        Node *no=(Node *)malloc(sizeof(Node));
        no->val=v[x];
        no->next=NULL;
        if(atual==NULL){
            atual=no;
            *list=atual;
        }
        else{
            atual->next=no;
            atual=atual->next;
        }
        

      }
      
}
void vetor_to_listRE(Node *anterior,Node **list,int *v,int n){
    if(n<=0) return;
    Node *no=(Node *)malloc(sizeof(Node));
    no->val=v[n-1];
    if(*list==NULL){
        *list=no;
    }
    else{
        no->next=anterior;
        
        *list=no;
     

    }
    vetor_to_listRE(no,&(((*list))),v,n-1);
    }
void lista_to_vetor(Node **list,int *v,int n){
        Node *atual=*list;
        for(int x=0;x<n;x++){
            v[x]=atual->val;
            atual=atual->next;
        }
}
void lista_pra_VR(Node **list,int *v,int teto,int inicio){
   if(inicio>=teto)return;
   
    v[inicio]=(*list)->val;
     lista_pra_VR(&((*list)->next),v,teto,inicio+1);
   
}
void copia(Node *list,Node **lista){
    if(list==NULL)return;
     Node *no=(Node *)malloc(sizeof(Node));
     no->val=list->val;  
     if (*lista==NULL){
        (*lista)=no;
         copia(list->next,lista);
     }
     else{
        (*lista)->next=no;
         copia(list->next,&(*lista)->next);
     }
    
}
int msmCont(Node *list,Node *lista){
       if(list==NULL && lista==NULL)return 1;  /*abcde*/
       if(list->val!=lista->val)return 0;
           msmCont(list->next,lista->next);
}
void concate(Node *list,Node *lista){
       if(list->next==NULL){
            list->next=lista;
            return;
       }
       concate(list->next,lista);
}
void inersiob(Node **list){
     Node *anterior=NULL;
     Node *temp;
     Node *atual=*list;
     while(atual!=NULL){
          temp=atual->next;
          atual->next=anterior;
          anterior=atual;
          atual=temp;
     }
     *list=anterior;
}
void MeioDaLista(Node *list){
      Node *m=list;
      while(list!=NULL && list->next!=NULL){
        m=m->next;
        list=list->next->next;

      }
      printf("%d",m->val);
}
void liberation(Node **list){
     if((*list)==NULL)return;
     Node *temp=*list;
     *list=(*list)->next;
     free(temp);
     liberation(list);
}
int main(){
Node *ist = NULL;
Node *nula=NULL;
int v[5]={1,2,3,4,5};
vetor_to_listRE(nula,&ist,v,5);
Node *mula=NULL;
copia(ist,&mula);
mula->val=2;
MeioDaLista(ist);
liberation(&ist);





}
