#include<iostream>
#include<conio.h>//prueba de modificacion
#include<math.h>
#define PI 3.14159265

using namespace std;

int main(){
	float puntos_poligono[100][2];//arreglo para guardar los puntos
	float rotar[100][20] ;
	float punto_pivote[1][2];
	int filas,columnas;
	columnas = 2;
	int puntopivote = 0;
	int pivote[1][2];
	int numPunto = -1;
	char orden=' ';
	char opcionpuntopivote=' ';
	int radianes = 0 ;
	float angulo = 0.0;
	float desplazamientox=0.0;
	float desplazamientoy=0.0;
	float escalamiento=1.0;
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
        
        cout<<"el punto pivote no esta dentro de los puntos del poligono "<<endl;
		cout<<"ingresar el punto pivote"<<endl;
		for(int j=0;j<columnas;j++){
			cout<<"Digite un numero ["<<filas<<"]["<<j<<"]: ";
			cin>>puntos_poligono[filas][j];
		}
        punto_pivote[0][0]=puntos_poligono[filas][0] ;
    	punto_pivote[0][1]=puntos_poligono[filas][1]; 
		cout<<"("<<punto_pivote[0][0]<<",";
        cout<<punto_pivote[0][1]<<")";
    }
		
	
	
    /*se tienen que acumular las trasformaciones en variables globales antes de trasformase para que la tras
	formacion correspondiente se realice solo una vez, por el principio de addicion */
int opcion = 0;
do{
	cout<<"\n\n--------------Opciones de tranformadas-----------------------\n";
	cout<<"   1. Rotar \n";
	cout<<"   2. Escalar \n";
	cout<<"   3. Trasladar \n";
	cout<<"   4. Salir \n ";
	cout<<"\nQue tranformada desea realizar (1-4)\n";
	cin>>opcion;
	
	switch(opcion){//revisar opcion de rotamiento 
		case 1: cout<<"------------Rotamiento--------------";
		/**/
		float angulotemp=0.0;
	cout<<"\nDigite los grados que rotaran los puntos:";
	cin>>angulotemp;
	angulo=angulo+angulotemp;//para acumular los angulos de rotamiento
	
	
		break;
		
		case 2: cout<<"------------Escalamiento--------------"<<endl;
				float es;
				es=1.0;
				cout<<"ingrese el factor de escala"<<endl;
				cin>>es;
				cout<<"factor de escalamiento:"<<es<<endl;
				//para el escalamiento acumulado
				escalamiento=escalamiento*es;
		break;
		
		case 3: cout<<"------------Traslacion--------------";
		float x,y;
		cout<<"ingrese desplazamiento en x"<<endl;
		cin>>x;
		cout<<"ingrese desplazamiento en y"<<endl;
		cin>>y;
		//para el desplazamiento acumulado 
		desplazamientox=desplazamientox+x;
		desplazamientoy=desplazamientoy+y;
	
	
		break;
		default: cout<<"Esa opcion no est� en el menu, vuelva a elegir";
	
	}
	
} while(opcion != 4);

//aqui se hacen los desplazamientos acumulados en una sola vez 
for(int i=0;i<filas;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(j%2==0)
				{puntos_poligono[i][j]=puntos_poligono[i][j]+desplazamientox;}
				else
				{puntos_poligono[i][j]=puntos_poligono[i][j]+desplazamientoy;}
			}
		}
//aqui se hacen los escalamientos acumulados en una sola vez

for(int i=0;i<filas;i++)
		{
			for(int j=0;j<2;j++)
			{
				float temp=0.0;
				temp=((puntos_poligono[i][j]-punto_pivote[0][j])*escalamiento);
				puntos_poligono[i][j]=temp+punto_pivote[0][j];
				
				
			}
		}

//aqui se hacen las rotaciones acumuladas de una sola vez
/*
if (angulo == 360 ){
		cout<< "Los puntos quedaron de la misma forma en que los agreg�";
		
	} if (angulo >360) {
		cout<<"Ese angulo no existe, digite un angulo valido";
		cin>>angulo;
	} else{
		cout<<"\nAngulo: "<<angulo<<"\n";
		cout<<"Rotacion de "<<angulo<<" grados de "<<filas<<" puntos \n";
	}
	radianes = angulo * PI /180;
		
		for(int i=0;i<filas;i++){
			numPunto++;
			cout<<numPunto;
		for(int j=0;j<columnas;j++){
			if (j == 0){
				
				rotar[i][0] = punto_pivote[0][0] + ((puntos_poligono[i][0] - punto_pivote[0][0] ) * cos(radianes)) -
				              ((puntos_poligono[i][1] - punto_pivote[0][1] ) * sin(radianes));
				
			} 	
			   if (j == 1){
				
				rotar[i][1] = punto_pivote[0][1] + ((puntos_poligono[i][0] - punto_pivote[0][0] ) * sin(radianes)) +
				              ((puntos_poligono[i][1] - punto_pivote[0][1] ) * cos(radianes));
			}
				
			cout<<"("; cout<<rotar[i][j]<<")";
		}
		cout<<"\n";
*/


//aqui se imprimen los puntos despues de todas las trasformaciones 

		cout<<"los puntos despues de las trasformaciones"<<endl;
				for(int i=0;i<filas;i++){
	        //numPunto++;
			//cout<<numPunto;
			
		for(int j=0;j<columnas;j++){
			
			cout<<"("; cout<<puntos_poligono[i][j]<<")";
		}cout<<endl;}
		
	getch();
	return 0;
}
