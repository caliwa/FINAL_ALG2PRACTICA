#include <iostream>
using namespace std;
class Nodo
{
	//Atributos
	private:
	int Dato;
	Nodo * Liga;
	
	//M�todos
	public:
	Nodo()
	{
		Dato = 0;
		Liga = NULL;
	}
	Nodo(int d, Nodo *l)
	{
		Dato = d;
		Liga = l;
	}
	
	int GetDato()
	{
		return Dato;
	}
	
	void SetDato(int d)
	{
		Dato = d;
	}
	
	Nodo * GetLiga()
	{
		return Liga;
	}
	
	void SetLiga(Nodo * l)
	{
		Liga = l;
	}
	
};
