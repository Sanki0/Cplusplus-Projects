#include<iostream>
using namespace std;
void PoliceDepartment(int n, int m);
 main (){
	for(int i=0;i<3;i++){
		int a,b;
		//a es la cantidad de presos y b es la cantidad de pistas
		cout<<"ingrese la cantidad de presos que hay en la comisaria "<<i+1<<": ";
		cin>>a; 
		cout<<"ingrese la cantidad de tipo de pista de los presos: ";
		cin>>b;
		PoliceDepartment(a,b);
		cout<< "----------"<<endl;
	}
}


void PoliceDepartment(int n, int m){
	//n es el numero de presos y m es el numero de pistas 
	char A[n][m];
	//relleno los datos de la matriz (el tipo de pista de cada preso)
	for (int i=0;i<n;i++){
		cout << "ingrese los tipos de pista del preso "<< i+1<<": "<<endl;
		for (int j=0;j<m;j++){
			cin >>A[i][j];
		}
	}
double pa=0,pb=0,pc=0,pt=0,ma=0,mc=0,mb=0,cantidad[n][3],sumA=0,sumB=0,sumC=0;
	//ma es la cantidad de tipo de pista A, lo mismo aplica para mb, mc(por preso)
	// pa es la cantidad de puntos totales de A, lo mismo para pb,pc
//declaro la matriz cantidad para poder sumar la cantidad de los tipos de variable
//sumA esla cantidad de tipo de pista A, lo mismo aplica para mb, mc(por comisaria)

//inicializo todos los elementos de la matriz cantidad en 0
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cantidad[i][j]=0;
		}
	}
	
	
//hallo la cantidad de puntos totales y la cantidad del tipo de pista por preso
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (A[i][j]=='A'){
				pa=20+pa;
				ma++;
				cantidad[i][0]=ma;

			}
			else if (A[i][j]=='B'){
				pb=15+pb;
				mb++;
				cantidad[i][1]=mb;

			}
			else if (A[i][j]=='C'){
				pc=30+pc;
				mc++;
				cantidad[i][2]=mc;

			}
		}
		
	// ct es la cantidad total de puntos que sumopara saber el status del preso
	pt=pa+pb+pc;

	if(pt>=85){
		cout<<"el estatus del preso "<<i+1<< " es: "<<"culpable"<<endl;
	}
	else if(pt<85 && pt>65){
		cout<<"el estatus del preso "<<i+1<< " es: "<<"sospechoso de alto riesgo"<<endl;
	}
	else if (pt<=65){
		cout<<"el estatus del preso "<<i+1<< " es: "<<"sospechoso de bajo riesgo"<<endl;
	}

	pa=0;pb=0;pc=0;pt=0;
	ma=0;mc=0;mb=0;
	}
	
	//hallo las cantidades de cada una dde las variables en toda la comisaria
	for(int i=0;i<n;i++){
		sumA=sumA+cantidad[i][0];
		sumB=sumB+cantidad[i][1];
		sumC=sumC+cantidad[i][2];
	}


	//la cantidad de presos se definio en la matriz A
	cout << "la cantidad de presos que hay es: "<<n<<endl;
	
	//hallo el tipo de pista mas frecuente
	if(sumA>sumB &&sumA>sumC){
		cout << "el tipo de pista mas frecuente es: A"<<endl;
	}
	else if(sumB>sumA &&sumB>sumC){
		cout << "el tipo de pista mas frecuente es: B"<<endl;
	}
	else if(sumC>sumA &&sumC>sumB){
		cout << "el tipo de pista mas frecuente es: C"<<endl;
	}
	
	// declaro el porcentaje en double para que se vean los decimales
	double porcentajeA, porcentajeB=(sumB*100)/(m*n) ,porcentajeC=(sumC*100)/(m*n) ;
	
	porcentajeA=(sumA*100)/(m*n);
	cout << "el porcentaje de A es: "<<porcentajeA<<"%"<< endl;
	cout << "el porcentaje de B es: "<<porcentajeB<<"%"<< endl;
	cout << "el porcentaje de C es: "<<porcentajeC<<"%"<< endl;
	


}


