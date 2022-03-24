//programa de graficacion 
//comentario de prueba 
//segundo comentario de prueba
/* Les envío la rúbrica de evaluación del primer parcial 


a) Elementos que debe cumplir el programa
1.  Se debe definir como parámetro  de entrada el número de puntos a graficar en el polígono, ejemplo 3,4,5,6
2. Definir como se tomaran las puntos a graficar si están en orden o en desorden
3. En caso de estar en orden,  la figura se cerrara con el punto A - N, donde N es el valor de la última coordenada
4. En caso de estar desordenados, definir un criterio para ordenar y dibujar  el polígono
5. Preguntar el tipo de transformación que se va a realizar, si es una a la vez o varias. En ambos casos aplicar lo que corresponda, si son varias deben de cumplirse las propiedades de las transformaciones
6. Dar como resultado final la aplicación de la transformación y/o transformaciones
*/
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
using namespace std;
int main()
{   int puntos[100];
    char orden=' ';
    int cuantos_puntos;
    cout<<"Programa de graficacion"<<endl;
    cout<<"ingrese la cantidad de puntos del poligono"<<endl;
    cin>>cuantos_puntos;
    cout<<"va a hacer en orden el ingreso de los punntos de ser asi ingrese (s) si no (n)"<<endl;
    cin>>orden;
    if((orden=='s')or(orden=='S'))
    {
        cout<<"los: "<<cuantos_puntos<<" puntos se ingresaran en orden "<<endl;
    }
    else
    {
        
        cout<<"los: "<<cuantos_puntos<<" puntos se ingresaran en desorden "<<endl;
    }

    getch();

    return 0;
}