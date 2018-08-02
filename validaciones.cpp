
#include<iostream>
using namespace std;

int tomarInt();
bool TipoInvalido(string);

int main()
{
	int numero;
	
	numero = tomarInt();
	cout<<"El Entero ingresado es: "<<numero<<endl;
	
	cin.get(); cin.get();
	return 0;
}

int tomarInt()
{
	string numero;
	bool esValido = false;
	while(! esValido)
	{
		try
		{
			cout<<"Ingrese un numero entero entre 0 y 9: ";
			getline(cin,numero);
			esValido =  TipoInvalido(numero);
			if(! esValido)
				throw numero;
		}
		catch(string e)
		{
			cout<<"\n\nEl numero Entero "<< e <<" No es valido."<<endl;
		}
	}
	return atoi(numero.c_str());
}

bool TipoInvalido(string numero)
{
	int i;
	int inicio = 0;
	if(numero.length() == 0)
		return 0;
		
	if(numero[0] == '+' || numero[0] == '-')
	{
		inicio=1;
		if(numero.length() == 1)
			return 0;
	}
	
	for(i=inicio; i < numero.length(); i++)
	{
		if(! isdigit(numero[i]))
		return 0;
	}
	
	return 1;
}
