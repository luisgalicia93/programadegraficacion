/*Programa para hacer tranformadas geometricas
Autores:
Alan Acosta
Luis Angel Galicia
*/
/*a) Elementos que debe cumplir el programa
1.  Se debe definir como parámetro  de entrada el número de puntos a graficar en el polígono, ejemplo 3,4,5,6
2. Definir como se tomaran las puntos a graficar si están en orden o en desorden
3. En caso de estar en orden,  la figura se cerrara con el punto A - N, donde N es el valor de la última coordenada
4. En caso de estar desordenados, definir un criterio para ordenar y dibujar  el polígono
5. Preguntar el tipo de transformación que se va a realizar, si es una a la vez o varias. En ambos casos aplicar lo que corresponda, si son varias deben de cumplirse las propiedades de las transformaciones
6. Dar como resultado final la aplicación de la transformación y/o transformaciones
*/
#include<iostream>
#include<conio.h>//prueba de modificacion
//#include "miniwin.h"
using namespace std;

int main(){
	int puntos_poligono[100][2];//arreglo para guardar los puntos
	int filas,columnas;
	columnas = 2;
	int puntopivote = 0;
	int pivote[1][2];
	int numPunto = -1;
	char orden=' ';
	char opcionpuntopivote=' ';
	cout<<"Programa de Transformaciones geometricas \n "; 
	cout<<"En este programa puede rotar, escalar y trasladar";
	cout<<"\nDigite el numero de puntos que desea graficar: "; cin>>filas;

	//prueba de miniwin
	/*miniwin::vredimensiona(200,200);
	miniwin::linea(0,0,200,200);
	refresca();*/


cout<<"va a hacer en orden el ingreso de los punntos de ser asi ingrese (s) si no (n)"<<endl;
    cin>>orden;
    

	
	//Rellenando la matriz	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin>>puntos_poligono[i][j];
		}
	} 

	if((orden=='s')or(orden=='S'))
    {
        cout<<"los: "<<filas<<" puntos se ingresaron en orden "<<endl;
    }
    else
    {
        
        cout<<"los: "<<filas<<" puntos se ingresaron en desorden "<<endl;
    }
	
	cout<<"\nCoordenadas a tranformar\n\n";
	
	for(int i=0;i<filas;i++){
	        numPunto++;
			cout<<numPunto;
		for(int j=0;j<columnas;j++){
			
			cout<<"("; cout<<puntos_poligono[i][j]<<")";
		}
		cout<<"\n";
	}

	cout<<"el punto pivote es uno de los puntos del poligono? de ser asi ingrese (s) si no (n)"<<endl;
    cin>>opcionpuntopivote;
    
	if((opcionpuntopivote=='s')or(opcionpuntopivote=='S'))
    {
        cout<<" el punto pivote se encuentra entre los puntos del poligono  "<<endl;
		cout<<"\n Cual sera el punto pivote?\n\n";
	cin>>puntopivote;
	while(puntopivote>=filas)//correcion de la evaluacion de la existencia del punto pivote 
	{
		cout<<"Ese punto no existe, elija otro...";
			cout<<"\n Cual sera el punto pivote?\n\n";
		    cin>>puntopivote;
	}
			cout<<"("<<puntos_poligono[puntopivote][0]<<",";
    cout<<puntos_poligono[puntopivote][1]<<")";
		
   }
	
       else
    {
        
        cout<<"el punto pivote no esta dentro de los puntos del poligono "<<endl;
		cout<<"ingresar el punto pivote"<<endl;
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<filas<<"]["<<j<<"]: ";
			cin>>puntos_poligono[filas][j];
		}

		cout<<"("<<puntos_poligono[filas][0]<<",";
    cout<<puntos_poligono[filas][1]<<")";
    }
	
	
    
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