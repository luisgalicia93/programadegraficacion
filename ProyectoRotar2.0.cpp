#include<iostream>
#include<conio.h>//prueba de modificacion
#include<math.h>


using namespace std;

int main(){
	float PI = 3.14159265;
	float puntos_poligono[100][2];//arreglo para guardar los puntos
	float rotar[100][20] ;
	float punto_pivote[1][2];
	float coordenadaRotar[100][2];
	int filas,columnas;
	columnas = 2;
	int puntopivote = 0;
	int pivote[1][2];
	int numPunto = -1;
	char orden=' ';
	char opcionpuntopivote=' ';
	float radianes = 0 ;
	int angulo = 0;
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
      numPunto =-1;

	
	
    
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
		
			cout<<"\nEl punto pivote es uno de los puntos del poligono? de ser asi ingrese (s) si no (n)"<<endl;
			
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
	punto_pivote[0][0]= puntos_poligono[puntopivote][0];
	punto_pivote[0][1]= puntos_poligono[puntopivote][1];
			cout<<"("<<punto_pivote[0][0]<<",";
    cout<<punto_pivote[0][1]<<")";
		
   }
	
       else
    {
        
        cout<<"el punto pivote no esta dentro de los puntos del poligono: "<<endl;
		cout<<"ingresar el punto pivote"<<endl;
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<filas<<"]["<<j<<"]: ";
			cin>>puntos_poligono[filas][j];
		}
        puntos_poligono[filas][0] = punto_pivote[0][0];
    	puntos_poligono[filas][1] = punto_pivote[0][1];
		cout<<"("<<punto_pivote[0][0]<<",";
        cout<<punto_pivote[0][1]<<")";
    }
		
	cout<<"\nDigite los grados que rotaran los puntos:";
	cin>>angulo;
	if (angulo == 360 ){
		cout<< "Los puntos quedaron de la misma forma en que los agregó";
		
	} if (angulo >360) {
		cout<<"Ese angulo no existe, digite un angulo valido";
		cin>>angulo;
	} else{
		
	  
		cout<<"\nAngulo: "<<angulo<<"\n";
		cout<<"Rotacion de "<<angulo<<" grados de "<<filas<<" puntos \n"<<radianes;
	}
	radianes = (angulo * PI) /180;

		
		for(int i=0;i<filas;i++){
			numPunto++;
			cout<<numPunto;
		for(int j=0;j<columnas;j++){
			coordenadaRotar[i][0] = puntos_poligono[i][0] - punto_pivote[0][0]; // x
			coordenadaRotar[i][1] = puntos_poligono[i][1] - punto_pivote[0][1]; // y

			
			if (j == 0){

	
				rotar[i][0] = (coordenadaRotar[i][0] * cos(radianes)) - (coordenadaRotar[i][1] * sin(radianes)) + punto_pivote[0][0];
				
			} 	else {
							

				rotar[i][1] = (coordenadaRotar[i][0] * sin(radianes)) + (coordenadaRotar[i][1] * cos(radianes)) + punto_pivote[0][1];

			}
				
			cout<<"("; cout<<rotar[i][j]<<")";
		}
		cout<<"\n";
	} 
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
