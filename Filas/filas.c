#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int remover(int *v,int *s){
   int  x=v[(*s)++];
    return x;
}
void inserir(int *v,int *t,int valor){
    v[(*t)++]=valor;
}
int *Distâncias (int **A, int n, int o) {
int *d, x, y ;
int *f, s, t;
d = malloc (n * sizeof (int)); 
for (x = 0; x < n; x++) d[x] = -1;
d[o] = 0;
f = malloc (n * sizeof (int));
s = 0; t = 1; f[s] = o;
while (s < t) {
/* f[s..t-1] é uma fila de cidades */
x = f[s++];
for (y = 0; y < n; y ++)
if (A[x][y ] == 1 && d[y ] == -1) {                                 
d[y ] = d[x] + 1;
f[t++] = y ;
}
}
free (f);
return d;
}  
typedef struct{
       int x;
       int y;

}coo;
coo feitas[100];
int inicio=0;
int fim=1;
void inserir1(int z,int j){
      feitas[fim].x=z;
      feitas[fim].y=j;
      fim++;
}
coo  remover2(){
    return feitas[inicio++];
}
int main(){
int mapa[10][10] = {
    { 0,  0, -1,  0,  0,  0,  0,  0,  0,  0},
    { 0, -1,  0,  0, -1, -1, -1,  0, -1,  0},
    { 0,  0,  0, -1,  0,  0,  0,  0, -1,  0},
    {-1, -1,  0,  0,  0, -1, -1, -1, -1,  0},
    { 0,  0,  0, -1,  0,  0,  0,  0,  0,  0},
    { 0, -1, -1, -1, -1, -1, -1, -1, -1,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    { 0, -1, -1, -1, -1, -1, -1, -1, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
mapa[0][0]=1;
inserir1(0,0);
int nx;
int ny;
while(inicio<fim){
        coo atual=remover2();

        if(atual.x==9 && atual.y==9){
            break;
        }
        for(int d=0;d<4;d++){
           nx=atual.x+dx[d];
           ny=atual.y+dy[d];
            if(mapa[nx][ny]==0 && nx>=0 && nx<=9 && ny>=0 && ny<=9){
                mapa[nx][ny]=1;
                printf("x=%d,y=%d\n",nx,ny);
                inserir1(nx,ny);
            }
        }

}
}
