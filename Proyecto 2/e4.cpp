#include<iostream>
#include<string.h>
#include <iomanip>
using namespace std;

void obtenerDatos();
void mostrarMenu();
void imprimeComprobante(int p);

struct boleta{
    
     char menu[20];
     float precio;
     float impuesto;
     
}menuLista[8],boleta,seleccion[8];



int main(){int p,n;
obtenerDatos(); 

    cout<<"----BIENVENIDO----\n";
    cout<<"A continuacion le presentaremos la lista del mes\n";
   
mostrarMenu();   
    
    p=0;
    
    do{
    cin>>n;    
    strcpy(seleccion[p].menu, menuLista[n-1].menu);
    seleccion[p].precio=menuLista[n-1].precio;
     
    p++;    
    }while(n!=0);
    
    cout<<"Articulos seleccionados\n";  
    cout<<endl;   
       
imprimeComprobante(p-1);


    return 0;
}


void obtenerDatos(){

    strcpy(menuLista[0].menu, "1.huevo simple");      menuLista[0].precio=1.45;
    strcpy(menuLista[1].menu, "2.tocino y huevo");    menuLista[1].precio=2.45;
    strcpy(menuLista[2].menu, "3.Muffin");            menuLista[2].precio=0.99;
    strcpy(menuLista[3].menu, "4.Tostada francesa");  menuLista[3].precio=1.99;
    strcpy(menuLista[4].menu, "5.Cesta de frutas");   menuLista[4].precio=2.49;
    strcpy(menuLista[5].menu, "6.Cereal");            menuLista[5].precio=0.69;
    strcpy(menuLista[6].menu, "7.Cafe");              menuLista[6].precio=0.50;
    strcpy(menuLista[7].menu, "8.Te");                menuLista[7].precio=0.75;
    
}

void mostrarMenu(){

    for(int i=0;i<8;i++){
            cout<<"$"<<menuLista[i].precio<<"\t----";
            cout<<menuLista[i].menu;
        
    cout<<endl;    
    }
    
    cout<<"para seleccionar un articulo escriba el digito que lo acompaña.(si termino de seleccionar presione 0)\n";  
    
}

void imprimeComprobante(int p){
float S=0;

    for(int i=0;i<p;i++){
            S=S+seleccion[i].precio;
    } 
    boleta.impuesto=S*5/100;
    
    for(int i=0;i<p;i++){
            cout<<"$"<<seleccion[i].precio<<"\t----";
            cout<<seleccion[i].menu;
        
    cout<<endl;    
    }
    
    cout<<"$"<<setprecision(2)<<boleta.impuesto<<"\t----";
    cout<<"Impuesto\n";
            
    cout<<"Precio total = ";
    cout<<setprecision(3)<<S+boleta.impuesto;    
    

}
