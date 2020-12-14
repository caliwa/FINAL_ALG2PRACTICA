#include "Nodo.h"
#include <iostream>

using namespace std;

class Lista
{
	//Atributo
	Nodo * Punta;
	private:
	int *vec;
	//Métodos
	public:
	Lista()
	{
		Punta = NULL;
	}
	
	~Lista(){
	}
	
	void ParqueaderoSlots(int n)
	{
		vec = new int[n];
	}
	
	void insertarFinal(int valor)
	{
	    Nodo * t, * q = new Nodo();
	 
	    q->SetDato(valor);
	    q->SetLiga(NULL);
	 
	    if(Punta==NULL)
	    {
	        Punta = q;
	    }
	    else
	    {
	        t = Punta;
	        while(t->GetLiga()!=NULL)
	        {
	            t = t->GetLiga();
	        }
	        t->SetLiga(q);
	    }
	}
	void Encolar(int d)
	{
		 Nodo * x = new Nodo();
		 
		 x->SetDato(d);
		 
		if(Punta==NULL)
		{
			Punta = x;
		}
		else
		{
			x->SetLiga(Punta);
			Punta = x;
		}
	}
	void ordenarLista()
	{
		Nodo *actual, *siguiente = new Nodo();
	    int t;
	    
	    actual = Punta;
	    while(actual->GetLiga() != NULL)
	    {
	        siguiente = actual->GetLiga();
	          
	        while(siguiente!=NULL)
	        {
	            if(actual->GetDato() > siguiente->GetDato())
	            {
	                t = siguiente->GetDato();
	                siguiente->SetDato(actual->GetDato());
	                actual->SetDato(t);          
	            }
	            siguiente = siguiente->GetLiga();                    
	        }   
	        actual = actual->GetLiga();
	        siguiente = actual->GetLiga();
	           
	   	}
	}
	
	void MostraLista()
	{
		Nodo *p = Punta;
		int i = 0;
		if(p == NULL)
		{
			cout<<"Lista Vacia";
		}
		else
		{
			while(p != NULL)
			{
				cout <<' '<< i+1 <<") "<< p->GetDato() <<endl;
				p = p->GetLiga();
				i++;
			}
		}

	}
	

	
};
