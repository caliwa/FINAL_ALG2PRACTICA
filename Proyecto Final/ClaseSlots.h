#include <iostream>

using namespace std;

class Slots{
	private:
		int Limite;
		int Tope;
		int *vec;
		int Horas, Minutos, Segundos;
	public:
		Slots(int);
		Slots(int, int); //PA LOS SEGUNDOS
		Slots(int, int, int);
		~Slots();
		int GetLimite();
		void SetLimite(int l);
		int GetTope();
		void SetTope(int t);
		int GetVector();
		void SetVector(int v);
		int GetHoras();
		void SetHoras(int h);
		int GetMinutos();
		void SetMinutos(int m);
		int GetSegundos();
		void SetSegundos(int s);
		bool ParqueaderoVacio();
		void Acumulador(int d,int sec);
		void MostrarAcumulador(int d);
		void EspacioParqueadero(int d);
		bool ParqueaderoLleno();
		void MostrarParqueadero();
		int QuitarParqueadero();
		void DiferenciaTiempo(int d, Slots A);
		void Poner();
		void Apilar(int d);
 };
 
 
