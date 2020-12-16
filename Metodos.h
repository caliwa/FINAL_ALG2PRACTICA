#include <iostream>
#include <conio.h>
#include <ctime>
#include "ClaseSlots.h"

using namespace std;


Slots::Slots(int n)
{
	Limite = n-1;
	Tope = -1;
	vec = new int[n];	
}

Slots::Slots(int hor, int min, int seg)
{
	Horas = hor;
	Minutos = min;
	Segundos = seg;
}

Slots::Slots(int tiempoSeg, int Floor){
	cout<<"Piso: "<<Floor<<endl; 
	Horas = tiempoSeg/3600; 
	tiempoSeg %= 3600;
	Minutos = tiempoSeg / 60;
	Segundos = tiempoSeg % 60;
}

Slots::~Slots(){
}

void Slots::DiferenciaTiempo(int hor, int min, int seg)
{
	int horaSalida, minSalida, segSalida, Cent; 
	Cent = 0;
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal=*localtime(&now);
	horaSalida = nowLocal.tm_hour;
	minSalida = nowLocal.tm_min;
	segSalida = nowLocal.tm_sec;
	if(segSalida < seg)
	{
		minSalida = minSalida - 1;
		segSalida = (segSalida + 60) - seg;		
	}
	else
	{
		segSalida = segSalida - seg;
	}
	
	if(horaSalida == hor && minSalida > min && segSalida > seg)
	{
		
		(minSalida - 1) - min;
		(segSalida + 6) - seg;
		cout<<"Tiempo estando el vehículo parqueado: "<<minSalida<<":"<<segSalida;
		Cent = 1;
	}
	else if(horaSalida == hor && minSalida > min && segSalida < seg)
	{
		minSalida - min;
		segSalida - seg;
		cout<<"Tiempo estando el vehículo parqueado: "<<minSalida<<":"<<segSalida;
		Cent = 1;
	}
	if(Cent == 0)
	{
		cout<<"Hora: "<<horaSalida<<":"<<minSalida<<":"<<segSalida;
	}
}

/*void Slots::ConfirmarEntrada()
{
	cout<<"En que piso ha puesto su coche?";
	cout<<"Donde ha puesto su vehiculo?, diga la posicion"<<endl;
	
	
	if(b==false)
	{
		Tope++;
		vec[Tope] = d;
	}
	else
	{
		cout<<"La pila esta llena";
	}
	
}
*/
void Slots::EspacioParqueadero(int d)
{
	int i;
	int horaIngreso, minIngreso, segIngreso, segConvert;
	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal=*localtime(&now);
	horaIngreso = nowLocal.tm_hour * 3600;
	minIngreso = nowLocal.tm_min * 60;
	segIngreso = nowLocal.tm_sec;
	segConvert = horaIngreso + minIngreso + segIngreso;
	
	for(i = 0 ; i < 30 ; i++)
	{
		if(d == i)
		{
			vec[d-1] = segConvert;
		}	
	}

}


bool Slots::ParqueaderoLleno()
{
	if(Tope>=Limite)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}


bool Slots::ParqueaderoVacio()
{
	bool b = false;
	if(Tope==-1)
	{
		b = true;
	}
	return (b);
}

int Slots::QuitarParqueadero()
{
	int r = vec[0], i = 1;
	while(i <= Tope)
	{
		vec[i-1] = vec[i];
		i++;
	}
	Tope--;
	return r;
}



void Slots::Poner()
{
	int i;
	bool b = ParqueaderoLleno();
	for(i = 0 ; i < 30 ; i++){
		if(b==false)
		{
			Tope++;
			vec[Tope] = i+1;
		}
		else
		{
			cout<<"El parqueadero está lleno.";
		}
	}
}


void Slots::Apilar(int d)
{
	bool b = ParqueaderoLleno();
	if(b==false)
	{
		Tope++;
		vec[Tope] = d;
	}
	else
	{
		cout<<"El parqueadero está lleno.";
	}
}



void Slots::MostrarParqueadero()
{
	int cont, i;
	cont = 0;
	for(i = 0 ; i < 30 ; i++)
	{	
		if(cont == 10 || cont == 20 || cont == 20)
		{
			cout<<"\n\n";
		}
		if(vec[i] == i+1)
		{
			cout<<i+1;
			cout<<"\t";	
		}
		else
		{
			cout<<"X";
			cout<<"\t";	
		}
		cont++;
	}
}

void Slots::Llenar(Slots A)
{
	while(A.ParqueaderoVacio() == false)
	{
		EspacioParqueadero(A.QuitarParqueadero());
	}
}

void Slots::mostrarHora(){
	cout<<"La hora es: "<<Horas<<":"<<Minutos<<":"<<Segundos<<endl;
}



int Slots::GetLimite()
{
	return Limite;
}

void Slots::SetLimite(int l)
{
	Limite = l;
}


int Slots::GetVector()
{
	return *vec;
}

void Slots::SetVector(int v)
{
	*vec=v;
}

int Slots::GetHoras()
{
	return Horas;
}
void Slots::SetHoras(int h)
{
	Horas = h;
}

int Slots::GetMinutos()
{
	return Minutos;
}

void Slots::SetMinutos(int m)
{
	Minutos = m;
}

int Slots::GetSegundos()
{
	return Segundos;
}

void Slots::SetSegundos(int s)
{
	Segundos = s;
}



