#include <iostream>
using namespace std;
main (){
	int n;
	cout <<"introduzca la cantidad de datos que quiere ingresar: "; cin >>n;
	double X[n],Y[n],tempx[5]={20.0,31.5,50.0,71.8,91.3},tempy[5]={761,847,874,917,1018};
	cout << "ingrese los valores de la temperatura: "<< endl;
	for (int i =0;i<n;i++){
		cin >> X[i];
	}cout << endl;
	cout << "ingrese los valores de la resistencia: "<< endl;
	for (int i =0;i<n;i++){
		cin >> Y[i];
	}cout << endl;
	cout << "Temperatura"<< "		"<< "Resistencia"<< endl;
	for (int i =0;i<n;i++){
		cout << X[i]<<"			";
		cout << Y[i]<<endl;
}

	double sumaxy=0,sumax=0,sumay=0,promediox,promedioy,sumax2=0;
	double esumaxy=0,esumax=0,esumay=0,epromediox,epromedioy,esumax2=0;
	for (int i=0;i<n;i++){
		sumax=sumax+X[i];
		sumay=sumay+Y[i];
		sumaxy=sumaxy+X[i]*Y[i];
		sumax2=sumax2+X[i]*X[i];
	}
	promediox=sumax/n;
	promedioy=sumay/n;
	
	for(int i=0;i<5;i++){
		esumax=esumax+tempx[i];
		esumay=esumay+tempy[i];
		esumaxy=esumaxy+tempx[i]*tempy[i];
		esumax2=esumax2+tempx[i]*tempx[i];
	}
	epromediox=esumax/5;
	epromedioy=esumay/5;
	double m=(sumaxy-sumax*promedioy)/(sumax2-sumax*promediox);
	cout << "la pendiente es: "<<m<< endl;
	double b=promedioy-m*promediox;
	cout << "el intercepto con el eje 'y' inicial es: "<<b<<endl;
	cout << "la recta es: "<<m<<"x + "<<b<< endl<< endl;

	cout << "los datos del cuadro son: "<< endl;
	cout << "Temperatura"<< "		"<< "Resistencia"<< endl;
	for (int i =0;i<n;i++){
		cout << tempx[i]<<"			";
		cout << tempy[i]<<endl;
}
	cout << "la ecuacion de la recta usando los datos del cuadro es: ";
	double em=(esumaxy-esumax*epromedioy)/(esumax2-esumax*epromediox);
	double eb=epromedioy-em*epromediox;
	cout <<em<<"x + "<<eb<< endl;
}
