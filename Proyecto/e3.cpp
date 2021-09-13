#include<iostream>
using namespace std;
void MatrizElevada(float Matriz[][20],float Markov[][20],int k,float Matriz1[][20]);   
      //Aqui se analiza para k-bordes

int main(){
int n,k,m=0,j;
float Markov[20][20],a,b,Matriz1[20][20],Matriz[20][20];

cout<<"Esto es unacadena de Markov si tomamos como estado el número de objetos en el contenedor A y dejamos que Pij sea el probabilidad de que una bola se transfiera de A a B si hay i bolas en el contenedor\n";
cout<<"Ingrese el numero de objetos en el contenedor A= ";cin>>k;
      for(int i=0;i<k+1;i++){
      //hace nula la matriz
              for(int j=0;j<k+1;j++){
              Markov[i][j]=0;}
                          }
a=k;b=m;
      for(int i=0;i<k;i++){
      j=i+1;
      //Lee la cantidad de vértices
      Markov[i][j]=a/(a+b);
      b++;a--;
      Markov[j][i]=b/(a+b);
                          }
     
cout<<"La matriz de transición P es :\n ";                               
      for(int i=0;i<k+1;i++){
              for(int j=0;j<k+1;j++){              
              cout<<Markov[i][j]<<"\t ";}
              cout<<endl;   }
cout<<"(Pn)=(P^n) :\n "; 
cout<<"La probabilidad de llegar de un estado i a un estado j \n";  
//probabilidad de pasar de un estado a otro estado mediante n pasos  
cout<<"Ingrese el valor n(número de pasos) \n n=";cin>>n;             

      for(int i=0;i<k;i++){
              for(int j=0;j<k;j++){
              Matriz1[i][j]=Markov[i][j];}   
                          }
                          
cout<<"Para de n pasos, (P^n) es : \n ";
 
      for(int i=0;i<n;i++){
      //k-bordes
              if(i==n-1){
      //Ingresa para el valor requerido k
                      for(int i=0;i<k;i++){
                              for(int j=0;j<k;j++){              
                              cout<<Matriz1[i][j]<<" \t";}
                      cout<<endl; 
                                          }
                        }
              else{       
      MatrizElevada(Matriz,Markov,k,Matriz1);
      //Nos lleva a una función
                   
              
              for(int i=0;i<k;i++){
                      for(int j=0;j<k;j++){
                      Matriz1[i][j]=Matriz[i][j];}   
                                  }
                          }
                  }                                             
return 0;             
}                         

void MatrizElevada(float Matriz[][20],float Markov[][20],int k,float Matriz1[][20]){
      //K-borde

      for (int i=0;i<k;i++){
      //Multiplica las matrices k-veces
               for (int j=0;j<k;j++){
               Matriz[i][j]=0;
                        for (int l=0;l<k;l++){
                        Matriz[i][j]=Matriz[i][j]+Matriz1[i][l]*Markov[l][j];}
                                    }
                          } 
}                         
