	/*
	Name: TRABAJO FINAL
	Copyright: POLI JIC
	Author: POR: Santiago Olmedo, David Londo�o, Tom�s Pineda, Carlos Gonz�lez.
	Description: 
	Simular un parqueadero con una entrada y una salida con N celdas disponibles
	En cada celda se deben guardar los datos que permitan calcular el tiempo de estadia
	Igual se deben  guardar los datos de cu�nto tiempo estuvo ocupada cada celda por d�a
	Se debe usar la estructura de datos adecuada
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <locale.h>
#include "Metodos.h"

using namespace std;

int main(){
	setlocale(LC_CTYPE, "Spanish");
	int horaIngreso, minIngreso, segIngreso, Casillas, Pos11, Pos22, Pos33, i, q, Op, Floor, Cont1, Cont2, Cont3, r, Cent,posValidar1[30], posValidar2[30], posValidar3[30], pos[30];
	Casillas = 30;
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal=*localtime(&now);
	horaIngreso = nowLocal.tm_hour;
	minIngreso = nowLocal.tm_min;
	segIngreso = nowLocal.tm_sec;
	Floor = 0, Cont1 = 0, Cont2 = 0 , Cont3 = 0, i = 0;
	Slots Hora(horaIngreso, minIngreso, segIngreso);
	Slots Piso1(Casillas);
	Slots Piso2(Casillas);
	Slots Piso3(Casillas);
	Piso1.Poner();
	Piso2.Poner();
	Piso3.Poner();
	cout<<"\n\n\n\n\n\t\t\t\t  _*TRABAJO FINAL 2do Semestre ALG2*_\n 	"<<endl;
	cout<<"\n\n\t\t\t\t\tPor: Santiago Olmedo"<<endl;
	cout<<"\n\n\t\t\t\t\t      David Londo�o"<<endl;
	cout<<"\n\n\t\t\t\t\t      Tom�s Pineda"<<endl;
	cout<<"\n\n\t\t\t\t\t     Carlos Gonz�lez\n"<<endl;
	cout<<"\n\n\t\t\t\t";
	system("pause");
	system("cls");
	do
	{
		r = 1;
		Cent = 0;
		cout<<"\n\t\t\t  Hora de Ingreso Inicial "<<horaIngreso<<":"<<minIngreso<<":"<<segIngreso;
		
		
  		cout<<"\n \t\t___________________________________________________ \n";
  	 	cout<<"         	        _____________________________________	 "<<endl; 
    	cout<<" \t\t|       |				    |     |"; 
  		cout<<"\n\t\t|       |    	  PARQUEADERO 24/7          |     |\n"; 
  		cout<<" \t\t|       |            Ver. 1.0.0             |     |"<<endl; 
  		cout<<" \t\t|       |___________________________________|     |"<<endl; 
  		cout<<"\t\t___________________________________________________ \n";
  	 	cout<<" \t\t|   | 					          |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|1. | \tREGISTRAR VEHICULO AL PARQUEADERO   	  |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|2. | \tMOSTRAR PARQUEADERO                 	  |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|3. | \tVER TIEMPO DE USO DE LAS CASILLAS OCUPADAS|"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
 		cout<<" \t\t|4. | \tREGISTRAR SALIDA DE VEHICULO              |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
 		cout<<" \t\t|5. | \tSALIR DEL PARQUEADERO		          |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
 		cout<<" \t\t|   | 					          |"<<endl;
  		cout<<" \t\t|___|_____________________________________________| \n";
  		cout<<" \t\t|   | \tESPERANDO A INGRESO DE OPCION....         |"<<endl;
		cout<<" \t\t|___|_____________________________________________| \n";
      	cout<<"\n";
      	do{
        	cout<<"\t\tOPCION A INGRESAR\n ";
        	cout<<"\t\tEscriba: ";
			cin>>Op;
		}while(Op < 1 || Op > 5);
	
		switch(Op)
		{
			case 1: cout<<"�En qu� piso desea parquear? 1, 2 o 3."<<endl;
					do{	
						cout<<"Escriba: ";
						cin>>Floor;
					}while(Floor < 1 || Floor > 3);
					if(Floor == 1)
					{
						cout<<"\n\t\t\t\t  PISO 1\n\n";
						Piso1.MostrarParqueadero();
						cout<<"\n\n";
						if(Cont1 == 0)
						{
							cout<<"Ingrese la posici�n del parqueadero donde desee parquear."<<endl;	
							do{
								cout<<"Escriba: ";
								cin>>Pos11;
								posValidar1[i] = Pos11;
								pos[i] = Pos11;
							}while(Pos11 < 1 || Pos11 > 30);
						}
						else if(Cont1 >= 1)
						{
							cout<<"Ingrese la posici�n del parqueadero donde desee parquear."<<endl;	
							do{
								do{
									cout<<"Escriba: ";
									cin>>Pos11;
								}while(Pos11 < 1 || Pos11 > 30);
								posValidar1[i] = Pos11;
		            		    for(q = 0 ; q < i ; q++)
		            			{
                  					if(Pos11 != posValidar1[q]){
                       			 	 	Cent = 1;
                    				}
              				    }
                				if(Cent == 1)
                				{
                  					r = 0;
                  					pos[i] = Pos11;
               				    }
                				else 
               					{
               			        	cout<<"\nIngrese una posici�n que no est� ocupada."<<endl;
              					}
                
							}while(r == 1);	
						}
						Cont1++;
						i++;
						cout<<"\n";
						Piso1.EspacioParqueadero(Pos11);
					}
					/*
					else if(Floor == 2)
					{
						cout<<"\n\t\t\t\t  PISO 2\n\n";
						Piso2.MostrarParqueadero();
						cout<<"\n\n";
						cout<<"Ingrese la posici�n del parqueadero donde desee parquear."<<endl;	
						do{
							cout<<"Escriba: ";
							cin>>Pos;
						}while(Pos < 1 || Pos > 30);
						cout<<"\n";
						Piso2.EspacioParqueadero(Pos);
					}
					else if(Floor == 3)
					{
						cout<<"\n\t\t\t\t  PISO 3\n\n";
						Piso3.MostrarParqueadero();
						cout<<"\n\n";
						cout<<"Ingrese la posici�n del parqueadero donde desee parquear."<<endl;
						do{
							cout<<"Escriba: ";
							cin>>Pos;
						}while(Pos < 1 || Pos > 30);
						cout<<"\n";
						Piso3.EspacioParqueadero(Pos);
					}
					*/
					cout<<"\n";
					system("pause");
					system("cls");
					break;
			case 2: cout<<"�Qu� piso desea ver? Digite 1, 2 o 3"<<endl;
					do
					{
						cout<<"Digite: ";
						cin>>Floor;
					}while(Floor < 1 || Floor > 3);
					if(Floor == 1)
					{
						cout<<"VIENDO PISO 1\n\n";
						Piso1.MostrarParqueadero();
					}
					else if(Floor == 2)
					{
						cout<<"VIENDO PISO 2\n\n";
						Piso2.MostrarParqueadero();
					}
					else if(Floor == 3)
					{
						cout<<"VIENDO PISO 3\n\n";
						Piso3.MostrarParqueadero();
					}
					cout<<"\n";
					system("pause");
					system("cls");
					break;
			case 3: cout<<"Ingrese la posici�n del parqueadero que desee ";
					system("pause");
					system("cls");
					break;
			case 4: cout<<"Ingrese la posici�n del parqueadero que desee ";
					system("pause");
					system("cls");
					break;
			case 5:	Piso1.~Slots();
					Piso2.~Slots();
					Piso3.~Slots();
					cout<<"\nSaliendo del Programa... ";
					exit(EXIT_FAILURE);
					break;
		}
	}while(Op > 0 || Op < 5); 

	return 0;
}
