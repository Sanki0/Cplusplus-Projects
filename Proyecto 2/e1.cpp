#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generar(int x[50][50],int y[50][50], int m,int n, int to);
void imprimir(int x[50][50], int m, int n);
void ciclo(int x[50][50],int y[50][50], int m,int n);

main (){
	int m,n,to,tablero1[50][50], tablero2[50][50];
	cout << "ingrese las filas: "; cin>>m;
	cout << "ingrese las columnas: "; cin>>n;
	cout << "ingrese la cantidad de organismos que desea: "; cin>>to;
	generar(tablero1,tablero2,m,n,to);
	cout << "ciclo 1: "<< endl;
	imprimir(tablero1,m,n);

	for(int i=0;i<4;i++){
		cout<<"ciclo "<< i+2<<": "<<endl;
		ciclo(tablero1,tablero2,m,n);
		imprimir(tablero1,m,n);
	}
	cout << "-----------";
}

void generar(int x[50][50],int y[50][50], int m,int n, int to){
		
	srand(time(NULL));
	int m1,n1;
	for (int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			x[i][j]=0;
			y[i][j]=0;
		}
	}
	while(to>0){
		bool re=true;
		while (re){
			m1=rand()%m;
			n1=rand()%n;
			if(x[m1][n1]==0){
				x[m1][n1]=1;
				re=false;
			}
		}
		to--;
	}
}

void imprimir(int x[50][50], int m, int n){
	for (int i=0;i<m;i++){
		cout << "|";
		for (int j=0;j<n;j++){
			if(x[i][j]==1){
				cout << "O";
			}
			else{
				cout<< " ";
			}
		}
		cout <<"|"<< endl;
	}
}

void ciclo(int x[50][50],int y[50][50], int m,int n){
	for(int i=0;i<m;i++){
		for (int j=0;j<n;j++){
				int c=0;// cuenta los organismos existentes alrededor del organismo actual
			if(x[i-1][j-1]==1){
				c++;
			}
			if(x[i-1][j]==1){
				c++;
			}
			if(x[i-1][j+1]==1){
				c++;
			}
			if(x[i][j-1]==1){
				c++;
			}
			if(x[i][j+1]==1){
				c++;
			}
			if(x[i+1][j-1]==1){
				c++;
			}
			if(x[i+1][j]==1){
				c++;
			}
			if(x[i+1][j+1]==1){
				c++;
			}
			//-------------------
			if(c==3 ||c==2){
				y[i][j]=1;
			}
			else{
				y[i][j]=0;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			x[i][j]=y[i][j];
			y[i][j]=0;
		}
	}
}
