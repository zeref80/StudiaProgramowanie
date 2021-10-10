#include <iostream>
#include <math.h>

using namespace std;

float a;
float b;
float c;
float delta;



int main()
{
  //  setlocale(LC_CTYPE, "Polish");

    cout<<"Program bedzie zwracac miejsca zerowe funkcji kwadratowej postaci ax^2+bx+c"<<endl;
    cout<<"Prosze stosowac sie do polecen wyswietlanych ne ekranie"<<endl;

    cout << "Podaj wspolczynnik a: "<<endl;
    cin >> a;


    while (a == 0) {
        cout << "To nie jest funkcja kwadratowa " ;
        cout << "Podaj prosze ponownie wspolczynnik a: "<<endl;
        cin >> a;
    }

    cout << "Podaj wspolczynnik b: ";
    cin >> b;
    cout << "Podaj wspolczynnik c: ";
    cin >> c;

    delta=(b*b)-(4*a*c);

    if (delta<0)
    {
        cout << "Ta funkcja nie ma punktu przeciecia z osia OX. Jej wspolrzedne wierzcholka to: " << "(" <<-b/(2*a )<< "," << -delta/(4*a)<<")";
    }
    else if (delta>0)
    {
        cout << "Ta funkcja ma 2 rozne pierwiastki rzeczywiste: " <<"X1= "<<(-b-sqrt(delta))/(2*a)<<" oraz X2= "<<(-b+sqrt(delta))/(2*a)<<endl;
        cout << "Wspolrzedne wierzcholka to: " <<"("<<-b/(2*a)<<","<< (4*a)<<")";
    }
    else
    cout << "Ta funkcja ma tylko 1 rozwiazanie, ktore jest jednoczesnie wierzcholkiem funkcji: " << "("<<-b/(2*a)<<","<< -delta/(4*a)<<")";
    cout << endl;

    return 0;
}
