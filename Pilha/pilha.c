#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilha{
         char c;
         struct pilha *seg;
}pilha;
void inserirP(char *v,char n,int *t){
    v[(*t)++]=n;
}
char removerP(char *v,int *t){
     char x;
   x= v[--(*t)];
   return x;
   
}
void inverter(char *c){
    int e=0;
     char temp;
     int guardar;
     int x=0;
      while(x<=strlen(c)){
        guardar=x;
        if(c[guardar]==' ' || c[guardar]=='\0'){
            guardar--;
         while(e<guardar){
            temp=c[e];
            c[e]=c[guardar];
            c[guardar]=temp;
          e++;
          guardar--;
         }
         e=x+1;
        }
        
        x++;
      }
}
void inverterP(char *s){
    int ultimo_x=0;
    int t=0;
    int n=strlen(s);
   char *pilha=malloc(sizeof(char)*strlen(s)+1);
   for(int x=0;x<=strlen(s);x++){
   
        if(s[x]==' '|| s[x]=='\0'){
           while(ultimo_x<=x-1){
             s[ultimo_x]=removerP(pilha,&t);
             ultimo_x+=1;
           }
           ultimo_x=x+1;
           
        }
         if(s[x]!=' ' && s[x]!='\0'){
       inserirP(pilha,s[x],&t); }
      
   }
   
}
int parentesesCe(char *s){
  int x,n=strlen(s);
  int t=0;
  char *pilha=malloc(sizeof(char)*n);
  for(x=0;s[x]!='\0';x++){
         switch(s[x]){
           
           case ')':if('('==pilha[t-1]){pilha[--t];break;}
           case '}':if('{'==pilha[t-1]){pilha[--t];break;}
           default:if(s[x]=='(')pilha[t++]=s[x]; 
         
         }
  }
  free(pilha);
  return t==0;
}
char * infi_to_pofix(char *s){
int j,i;
int n=strlen(s);
char *infi=malloc(sizeof(char)*(n+3));
infi[0]='(';
infi[n+1]=')';
for(int y=1;y<n+1;y++){
    infi[y]=s[y-1];
    
}
infi[n+3]='\0';
char *pofi=malloc(sizeof(char)*n);
char *p=malloc(sizeof(char)*n);
char x;
int t=0;
p[t++]=infi[0];
for(j=0,i=1;infi[i]!='\0';i++){
   switch (infi[i]){
    case '(':p[t++]=infi[i];break;
    case ')':while(1){
              x=p[--t];
             if (x=='(')break;
             pofi[j++]=x;
                }break;
    case '+':
    case '-': while(1){
              x=p[t-1];
               if (x=='(')break;
                --t;
             pofi[j++]=x;
                       }
              p[t++]=infi[i];
              break;
    case '/':
    case '*':while(1){
              x=p[t-1];
               if (x == '(' || x == '+' || x == '-')break;
                --t;
             pofi[j++]=x;
                       }
              p[t++]=infi[i];
              break;
      default: pofi[j++]=infi[i];
   }
   
}
pofi[j]='\0';
free(p);
return pofi;
}
int aAz(char c){
   int x=1;
    for(int y=65;y<91;y++){
       if(c==(char)y){
         return x;
       }
       x++;
    }
     
}
int contaposf(char *s){
 int n=strlen(s);
int *pilha=malloc(sizeof(int)*n);
int t=0;
for(int x=0;x<n;x++){
   switch (s[x]){
      case'+':pilha[t-2]=pilha[t-2]+pilha[t-1]; pilha[t-1]=0; t--;
      break;
      case'-':pilha[t-2]=pilha[t-2]-pilha[t-1]; pilha[t-1]=0; t--;
      break;
      case'*':pilha[t-2]=pilha[t-2]*pilha[t-1]; pilha[t-1]=0; t--;
      break;
      case'/':pilha[t-2]=pilha[t-2]/pilha[t-1]; pilha[t-1]=0; t--;
      break;
      default: pilha[t++]=aAz(s[x]);
   }
}

return pilha[0];
}
void empilhar(pilha *cabeca,char valor){
         pilha *no=malloc(sizeof(no));
         no->c=valor;
         no->seg=cabeca->seg;
         cabeca->seg=no;
}
char desempilhar(pilha *cabeca){
        pilha *no=cabeca->seg;
        char x=no->c;
        cabeca->seg=no->seg;
        free(no);
        return x;
}
char ver_ultimo(pilha *p){
   if(p->seg!=NULL){
     char x=p->seg->c;
    return x;}
   else{
      return '\0';
   }
    
}
char * infi_to_pofix2(char *s){
int j,i;
int n=strlen(s);
char *infi=malloc(sizeof(char)*(n+3));
infi[0]='(';
infi[n+1]=')';
for(int y=1;y<n+1;y++){
    infi[y]=s[y-1];
    
}
infi[n+3]='\0';
char *pofi=malloc(sizeof(char)*n);
pilha  *p=malloc(sizeof(pilha));
char x;
int t=0;
empilhar(p,infi[0]);
for(j=0,i=1;infi[i]!='\0';i++){
   switch (infi[i]){
    case '(':empilhar(p,infi[i]);break;
    case ')':while(1){
              x=desempilhar(p);
             if (x=='(')break;
             pofi[j++]=x;
                }break;
    case '+':
    case '-': while(1){
              x=ver_ultimo(p);
               if (x=='(')break;
                desempilhar(p);
             pofi[j++]=x;
                       }
              empilhar(p,infi[i]);
              break;
    case '/':
    case '*':while(1){
              x=ver_ultimo(p);
               if (x == '(' || x == '+' || x == '-')break;
                desempilhar(p);
             pofi[j++]=x;
                       }
              empilhar(p,infi[i]);
              break;
      default: pofi[j++]=infi[i];
   }
   
}
pofi[j]='\0';
free(p);
return pofi;}
int parentesesCe2(char *s){
  int x,n=strlen(s);
  pilha *palha=malloc(sizeof(pilha));
  for(x=0;s[x]!='\0';x++){
         switch(s[x]){
           
           case ')':if('('==ver_ultimo(palha)){desempilhar(palha);break;}
           case '}':if('{'==ver_ultimo(palha)){desempilhar(palha);break;}
           default:empilhar(palha,s[x]); 
         
         }
  }
  
  return palha->seg==NULL;
}
int main(){

  }

 

