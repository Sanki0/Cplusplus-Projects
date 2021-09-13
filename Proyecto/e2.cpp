#include<iostream>
using namespace std;
void MatrizAdyacente(int C_V,int C_ver[],int V,int Conector[][20]);
      //Aqui se definen los pares de vertices y se construye la matriz
void MatrizElevada(int Matriz[][20],int Conector[][20],int V,int Matriz1[][20]);   
      //Aqui se analiza para k-bordes

int main(){
int C_ver[20],V,C_V,Conector[20][20],Matriz1[20][20],Matriz[20][20],k;  
cout<<"Coloque número de vértices V=";cin>>V;
      //ingresa la variable V(vertices)
    
      for(int i=0;i<V;i++){
      //Lee la cantidad de vértices
      C_ver[i]=i;
                          }
        
cout<<"La colección de vértices ordenados son: ";  
  
      for(int i=0;i<V;i++){
      //Describe la colección de vertices
      cout<<C_ver[i]<<"\t";
                          }
cout<<endl;                          
cout<<"Definir la cantidad de arcos dirgidos : ";cin>>C_V;
MatrizAdyacente(C_V,C_ver,V,Conector); 
      //Nos lleva a una función 
cout<<"Número de formas en que se puede llegar a cada vértice desde cualquier otro vértice siguiendo k bordes por algún valor de k.\n";
cout<<"A continuación ingrese k=";cin>>k;  
           
      for(int i=0;i<V;i++){
      //La matriz de adyacencia se deposita en otra matriz
              for(int j=0;j<V;j++){
              Matriz1[i][j]=Conector[i][j];}   
                          }
cout<<endl;

      for(int i=0;i<k;i++){
      //k-bordes
              if(i==k-1){
      //Ingresa para el valor requerido k
                      for(int i=0;i<V;i++){
                              for(int j=0;j<V;j++){              
                              cout<<Matriz1[i][j]<<" ";}
                      cout<<endl; 
                                          }
                        }
                     
      MatrizElevada(Matriz,Conector,V,Matriz1);
      //Nos lleva a una función
                   
              
              for(int i=0;i<V;i++){
                      for(int j=0;j<V;j++){
                      Matriz1[i][j]=Matriz[i][j];}   
                                  }
                          }
                        
return 0;        
} 
   

void MatrizAdyacente(int C_V,int C_ver[],int V,int Conector[][20])
{
cout<<"Definir los pares de vértices que representan arcos dirigidos: \n";  
int A1,A2;
      
      for(int i=0;i<V;i++){
      //hace nula la matriz
              for(int j=0;j<V;j++){
                      Conector[i][j]=0;}
                          }
                          
      for(int i=0;i<C_V;i++){
      //coloca 1 segun posición del arco dirigido
      cout<<"El vertice V(A)=";cin>>A1;
      cout<<"tiene un arco dirigido hacia V(B)=";cin>>A2;cout<<"\n";
      Conector[A1][A2]=1;
                            }           
cout<<"La matriz de adyacencia es:\n";
                         
      for(int i=0;i<V;i++){
      //Escribe la matriz de adyacencia
              for(int j=0;j<V;j++){   
              cout<<Conector[i][j]<<" ";}
      cout<<endl;       
                          }
cout<<endl;     
}



void MatrizElevada(int Matriz[][20],int Conector[][20],int V,int Matriz1[][20]){
      //K-borde

      for (int i=0;i<V;i++){
      //Multiplica las matrices k-veces
               for (int j=0;j<V;j++){
               Matriz[i][j]=0;
                        for (int k=0;k<V;k++){
                        Matriz[i][j]=Matriz[i][j]+Matriz1[i][k]*Conector[k][j];}
                                    }
                          } 
}











