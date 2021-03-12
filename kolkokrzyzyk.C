#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>//obsluga plikow

using namespace std;

//tablica pol planszy
char pole[10] = {'0','1','2','3','4','5','6','7','8','9'};

void plansza();
int wynik();
void gracz_gracz();
int gracz_komputer();
int ruch_AI(char z, int g);
int ruch_gracza(char z, int g);
int wybor();

//funkcja glowna

int main()
{
	
	char numer;

	cout<<"Kolko Krzyzyk:\n"<<endl;
	cout<<"gracz vs gracz (1)"<<endl;
	cout<<"gracz vs komputer (2)"<<endl;
	cout<<"wyjdz z programu (3)"<<endl;

	do
	{	
	cin >> numer;

	switch(numer)
	{
	case '1':
		gracz_gracz();
		break;
	case '2':
		gracz_komputer();////////////////////////////////////////////////////////////// problem z error C2660??
		break;
	case '3':
		cout<<"Zapraszam ponownie!"<<endl;
		break;
	default:	                             
		cout<<"Wybierz ponownie!"<<endl;		
		break;
		
	}
	}while(numer != '3');
return 0;
}

// Rysowanie planszy

void plansza()
{
	system("clear");
	
	cout << "\nGracz 1 (X)  -  Gracz 2 (0)\n\n";
	cout << endl;

	cout << "         |     |     " << endl;
	cout << "      " << pole[1] << "  |  " << pole[2] << "  |  " << pole[3] << endl;

	cout << "    _____|_____|_____" << endl;
	cout << "         |     |     " << endl;

	cout << "      " << pole[4] << "  |  " << pole[5] << "  |  " << pole[6] << endl;

	cout << "    _____|_____|_____" << endl;
	cout << "         |     |     " << endl;

	cout << "      " << pole[7] << "  |  " << pole[8] << "  |  " << pole[9] << endl;

	cout << "         |     |     " << endl << endl;
}

// gra zakonczona z wynikiem 1
// gra zakonczona remisem 0
// gra nadal trwa -1

int wynik()
{
	if (pole[1] == pole[2] && pole[2] == pole[3])
		return 1;

	else if (pole[4] == pole[5] && pole[5] == pole[6])
		return 1;

	else if (pole[7] == pole[8] && pole[8] == pole[9])
		return 1;

	else if (pole[1] == pole[4] && pole[4] == pole[7])
		return 1;

	else if (pole[2] == pole[5] && pole[5] == pole[8])
		return 1;

	else if (pole[3] == pole[6] && pole[6] == pole[9])
		return 1;

	else if (pole[1] == pole[5] && pole[5] == pole[9])
		return 1;

	else if (pole[3] == pole[5] && pole[5] == pole[7])
		return 1;

	else if 
		(
		     pole[1] != '1' && pole[2] != '2' && pole[3] != '3' 
          && pole[4] != '4' && pole[5] != '5' && pole[6] != '6' 
          && pole[7] != '7' && pole[8] != '8' && pole[9] != '9'
		 )

		return 0;
	else
		return -1;
}

void gracz_gracz()
{
	int gracz = 1, wybor, i, kto_zaczyna;
	char znak;

	//wybor kto zaczyna
		do
		{
		cout << "Kto zaczyna X(1) czy 0(2)" << endl;
		cout << "Aby wybrac wpisz 1 lub 2" << endl;
		cin >> kto_zaczyna;
		if(kto_zaczyna == 1||2)
		{
		gracz = kto_zaczyna;
		}
		else 
		{
			cout<<"sprobuj ponownie"<<endl;
			getchar();
		}		
		}while((gracz != 1) && (gracz !=2));

	do
	{
		plansza();
		//wybor gracza	
		if(gracz = gracz%2)
			 gracz = 1;
		else 
			 gracz = 2;

		cout << "Gracz " << gracz << ", wybierz numer:  ";
		cin >> wybor;
		//przypisanie znaku graczowi
		
		if(znak = gracz == 1)
			znak = 'X';
		else 
			znak = '0';

		//wpisywanie znaku w dane pole planszy
		if (wybor == 1 && pole[1] == '1')
			pole[1] = znak;

		else if (wybor == 2 && pole[2] == '2')
			pole[2] = znak;

		else if (wybor == 3 && pole[3] == '3')
			pole[3] = znak;

		else if (wybor == 4 && pole[4] == '4')
			pole[4] = znak;

		else if (wybor == 5 && pole[5] == '5')
			pole[5] = znak;

		else if (wybor == 6 && pole[6] == '6')
			pole[6] = znak;

		else if (wybor == 7 && pole[7] == '7')
			pole[7] = znak;

		else if (wybor == 8 && pole[8] == '8')
			pole[8] = znak;

		else if (wybor == 9 && pole[9] == '9')

			pole[9] = znak;
		else
		{
			cout<<"Invalid move ";
			//cofniecie do poprzedniego gracza przed kolejnym przejsciem petli
			gracz--;
			cin.ignore();
			cin.get();
		}
		//czy wyjsc z petli
		i=wynik();
        //kolejny gracz
		gracz++;
	}while(i==-1);

	plansza();
	if(i==1)

		cout<<"==>\agracz "<<--gracz<<" wygral ";
	else
		cout<<"==>\aremis";

	cin.ignore();
	cin.get();
	

	 
}

int gracz_komputer()
{
	
	int gracz = 1,i;
	char znak;
	
	cout << "Kto zaczyna X(1) czy 0(2)" << endl;
	cout << "Aby wybrac wpisz 1 lub 2" << endl;
	cin >> gracz;
	system("clear");
	//Petla gry gracz vs pc
	do
	{			
	    plansza();
		//wybor kto zaczyna i przypisanie znaku
		if((gracz == 1) || (gracz == 2))
			{
			if(gracz == 1)
			znak = 'X';
			else 
			znak = '0';
			}
		else 
			{
			cout<<"sprobuj ponownie"<<endl;
			return gracz_komputer();
			}		
		
	if(gracz == 1)
	{		
	int wybor=0;
	cout <<"Graczu wybierz numer"<<endl;
	cin >> wybor;

	if (wybor == 1 && pole[1] == '1')
			pole[1] = znak;

		else if (wybor == 2 && pole[2] == '2')
			pole[2] = znak;

		else if (wybor == 3 && pole[3] == '3')
			pole[3] = znak;

		else if (wybor == 4 && pole[4] == '4')
			pole[4] = znak;

		else if (wybor == 5 && pole[5] == '5')
			pole[5] = znak;

		else if (wybor == 6 && pole[6] == '6')
			pole[6] = znak;

		else if (wybor == 7 && pole[7] == '7')
			pole[7] = znak;

		else if (wybor == 8 && pole[8] == '8')
			pole[8] = znak;

		else if (wybor == 9 && pole[9] == '9')

			pole[9] = znak;
		else
		{
			cout<<"Invalid move ";
			//cofniecie do poprzedniego gracza przed kolejnym przejsciem petli
			gracz--;
			cin.ignore();
			cin.get();
		}
	int wynik();		
	}

	else if(gracz == 2)
	{		
	int wybor=0;

	srand( time( NULL ) );
	int wybrana_liczba=(rand() % 9 ) + 1;

	wybor = wybrana_liczba;

	if (wybor == 1 && pole[1] == '1')
			pole[1] = znak;

		else if (wybor == 2 && pole[2] == '2')
			pole[2] = znak;

		else if (wybor == 3 && pole[3] == '3')
			pole[3] = znak;

		else if (wybor == 4 && pole[4] == '4')
			pole[4] = znak;

		else if (wybor == 5 && pole[5] == '5')
			pole[5] = znak;

		else if (wybor == 6 && pole[6] == '6')
			pole[6] = znak;

		else if (wybor == 7 && pole[7] == '7')
			pole[7] = znak;

		else if (wybor == 8 && pole[8] == '8')
			pole[8] = znak;

		else if (wybor == 9 && pole[9] == '9')

			pole[9] = znak;
		else
		{
			//cofniecie do poprzedniego gracza przed kolejnym przejsciem petli
			gracz++;
		}
		int wynik();						
		}		
		//czy wyjsc z petli
		i=wynik();
		if((gracz == 1) || (gracz == 3))
		{
			gracz = 2;
		}
		else if((gracz == 2) || (gracz == 0))
		{
			gracz = 1;
		}
	plansza();
	}while(i==-1);

	if(i==1)

		cout<<"==>\agracz "<<--gracz<<" wygral ";
	else
		cout<<"==>\aremis";

	return 0;
}




