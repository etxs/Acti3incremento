#include <iostream>

using namespace std;
class Fecha
{ 
private:
	int dia;
	int mes;
	int year;
public:
	void setDia();
	void setMes();
	void setYear();
	bool setBisiesto ();
	void setFechita();
	void setIncremento();
};

void Fecha::setFechita()
{
	cout << "\t------------------------------" << endl;
	cout << "\n\tIngrese el year : ";
	cin >> year;
	cout << "\tIngrese el mes : ";
	cin >> mes;
	cout << "\tIngrese el dia : ";
	cin >> dia;
	cout << "\t------------------------------" << endl;
	system("cls");
	system("pause");
	cout << "\n\n\tFecha: " << year << "/" << mes << "/" << dia << endl;
	{
		cout << "\t------------------------------" << endl;
		cout<<"\nEl year es: ";
		setYear();
		cout<<"\nEl mes es: ";
		setMes();
		cout<<"\nEl dia es: ";
		setDia();
		cout << "\t------------------------------" << endl;
		system("pause");
		system("cls");
		system("pause");
		cout<<"Incremento: ";
		setIncremento();
	}
}

void Fecha::setDia()
{
	if (mes == 1 || mes == 3 || mes == 5 || mes ==7 || mes ==8 || mes == 10 || mes == 12)
	{
		if (dia>0 || dia<=31)
		{ 
		cout<<"Dia valido\n";
		}
	}
	else if (setBisiesto() == true)
	{
		if (mes==2 && dia<=29)
			{
				cout<<"Dia valido\n";
			}
		else if (mes==2 && dia>=29)
			{
				cout<<"Dia invalido\n";
			}		
	}
}	

void Fecha::setMes()
{
	if (mes>=1 && mes<=12)
	{ 
		cout<<"Mes valido\n";
	}
	else if (mes>12)
	{
		cout<<"Mes invalido\n";
	}
}

bool Fecha::setBisiesto()
{
	if(year%4 !=0)
	{
		return false;
	}
	else if(year%100 !=0)
	{
		return true;
	}
	else if(year%400 !=0)
	{
		return false;
	}
	else 
	{
		return true;
	}
}

void Fecha::setYear()
{
	if(setBisiesto() == false)
	{
		cout<<"Year valido y no es un year bisiesto\n";
	}
	else if (setBisiesto() == true)
	{
		cout<<"Year valido y es un year bisiesto\n";
	}
}

void Fecha::setIncremento()
{
    dia++;
    if(dia>31)
    {
       dia=1;
       mes++;//el mes es el siguiente
       if(mes>12) //si después de sumar el mes es mayor a 12
       {
          mes=1;  //el mes es enero
          year++;  //año siguiente
       }
    }
    else if(dia==29 && mes == 2) //si es febrero y después de incrementar el día es 29
         {
            dia=1;
            mes++;
         }
    else if(dia==31 && (mes==4 || mes==6 || mes==9 || mes==11))//si el día es 31 y es un mes de 30 días                
         {
            dia=1;  
            mes++;
         }	
    cout << dia << "/" << mes << "/" << year << endl; //se muestra la fecha que sera despues
}

int main (){
	system("color B8");
	Fecha fechita;
	fechita.setFechita();
}