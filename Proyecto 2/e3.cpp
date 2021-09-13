#include<iostream>
#include<string.h>
#include <iomanip>
using namespace std;
double funcion(double x,double y);
//definimos los valores constantes
struct boleta{
    
    double alfa;
    double It;
    double con;
}ecuacion;

int main(){
//definimos con double ya que trabajamos con digitos grandes
double k1,k2,k3,k4,x[12],n,y[12],s;
//definimos para los valores iniciales
       x[0]=0;
       y[0]=50000;
       ecuacion.It=0.01;
       ecuacion.alfa=0.03;
       ecuacion.con=0.00000015;
    cout<<"El número de individuos en una población se mide cada año. Sea P (t) la población en el año t.";
    cout<<"Sea α la tasa de natalidad y suponga que la tasa de mortalidad β es proporcional al";
    cout<<"tamaño de la población, es decir, β = γP (t), donde γ es una constante.";
    cout<<"Tenemos los datos\n";

    cout<<"α = 3 × 10–2\n";
    cout<<"γ = 1.5 × 10–7\n";

    cout<<"Ingrese para encontrar la población después de n años.  n = ";
    cin>>n;
    
    cout<<endl;

    for(int i=1;i<n;i++){
            x[i]=x[0]+(i)*ecuacion.It;    
    }

    cout<<"Población inicial : 50 000\n";
//Utilizamos el metodo de Runge-Kutta 
    for(int i=0;i<n;i++){
            k1=ecuacion.It*funcion(x[i],y[i]);
            k2=ecuacion.It*funcion(x[i]+ecuacion.It/2,y[i]+k1/2);
            k3=ecuacion.It*funcion(x[i]+ecuacion.It/2,y[i]+k2/2);
            k4=ecuacion.It*funcion(x[i]+ecuacion.It,y[i]+k3/2);

            s=(k1+2*k2+2*k3+k4)/6;
            y[i+1]=y[i]+s;
//Escribe la población para los años siguientes
            cout<<"Después de "<<i+1<<" años : Población = ";
            cout<<setprecision(5)<<y[i+1];
            cout<<endl;
    }

return 0;
}

//ejecuta la funcion de poblacion P '( t ) = αP ( t ) - γ [ P ( t )] 2
double funcion(double x,double y){
int a;

     a=y*ecuacion.alfa-y*y*ecuacion.con;
   
return a;
}
