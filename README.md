/*Programa para hacer tranformadas geometricas
Autores:
Alan Acosta
Luis Angel Galicia
*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[100][2],filas,columnas;
	columnas = 2;
	int puntopivote = 0;
	int pivote[1][2];
	int numPunto = -1;
	cout<<"Programa de Transformaciones geometricas \n "; 
	cout<<"En este programa puede rotar, escalar y trasladar";
	cout<<"\nDigite el numero de puntos que desea graficar: "; cin>>filas;

	
	//Rellenando la matriz	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
		}
	} 
	
	cout<<"\nCoordenadas a tranformar\n\n";
	
	for(int i=0;i<filas;i++){
	        numPunto++;
			cout<<numPunto;
		for(int j=0;j<columnas;j++){
			
			cout<<"("; cout<<numeros[i][j]<<")";
		}
		cout<<"\n";
	}
	
	cout<<"\n Cual sera el punto pivote?\n\n";
	cin>>puntopivote;
	for(int i=0;i<filas;i++){
		if(puntopivote > i+1){
			cout<<"Ese punto no existe, elija otro...";
			cout<<"\n Cual sera el punto pivote?\n\n";
		    cin>>puntopivote;
		}
   }
	cout<<"("<<numeros[puntopivote][0]<<",";
    cout<<numeros[puntopivote][1]<<")";
    
int opcion = 0;
do{
	cout<<"\n\n--------------Opciones de tranformadas-----------------------\n";
	cout<<"   1. Rotar \n";
	cout<<"   2. Escalar \n";
	cout<<"   3. Trasladar \n";
	cout<<"   4. Salir \n ";
	cout<<"\nQue tranformada desea realizar (1-4)\n";
	cin>>opcion;
	
	switch(opcion){
		case 1: cout<<"------------Rotamiento--------------";
		break;
		
		case 2: cout<<"------------Escalamiento--------------";
		break;
		
		case 3: cout<<"------------Traslacion--------------";
		break;
		default: cout<<"Esa opcion no está en el menu, vuelva a elegir";
	
	}
	
} while(opcion != 4);

	
	getch();
	return 0;
}
