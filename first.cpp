#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <iomanip>
#include <cstring>
#include <clocale>

int askOption();
bool arithmetic();
bool geometric();
bool askForBack();
double value(double x);
int valueInt(int n);

using namespace std;

const auto hConsole = GetStdHandle(STD_OUTPUT_HANDLE );

int main() {
    bool isBack;

    setlocale(LC_CTYPE, "spanish");

    do {
        isBack = false;

        system("cls");
        SetConsoleTextAttribute(hConsole, 13); /// Cambia de color el texto a morado claro
        cout << "\t\t" << "+---------------++------------------++----------------+" << endl;
        cout << "\t\t" << "|---------------||     SUCESIÓN     ||----------------|" << endl;
        cout << "\t\t" << "+----------++---++------------------++---++-----------+" << endl;
        cout << "\t\t" << "|----------|| 1) ARITMÉTICA              ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
        cout << "\t\t" << "|----------|| 2) GEOMÉTRICA              ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------+" << endl;
        cout << "\t\t" << "|----------|| 3) SALIR                   ||-----------|" << endl;
        cout << "\t\t" << "+----------++----------------------------++-----------+" << endl << endl;

        /// Main menu.
        switch (askOption()) {
            case 1:
                if (arithmetic()) {
                    isBack = true;
                } else {
                    isBack = false;
                }
                break;
            case 2:
                if (geometric()) {
                    isBack = true;
                } else {
                    isBack = false;
                }
                break;
            case 3:
                cout << "Good Bye!!!!\n";
                return 0;
            default:
                SetConsoleTextAttribute(hConsole, 13);
                cout << "Error seleccionando una opción.\n";
                cout << "Por favor revise las opciones al inicio del programa\n";
                isBack = true;
        }
        if(!(isBack)) {
            continue;
        } else {
            isBack = askForBack();
        }

    } while (isBack);

    return 0;
}

///Función para preguntar al usuario si desea correr nuevamente el programa.
bool askForBack() {
    char isBack[1];

    cout << endl;

    SetConsoleTextAttribute(hConsole, 13);
    cout << "Desea usted regresar al inicio del programa? S para SI, cualquier otra tecla para salir." << endl;
    SetConsoleTextAttribute(hConsole, 12);

    cin >> isBack;
    if (strcmp(isBack, "s") != 0 && strcmp(isBack, "S") != 0) {
        cout << "\nBye...";
        return false;
    }
    return true;
}

///Función utilizada para obtener las opción seleccionada en el switch
int askOption() {
    int option;

    SetConsoleTextAttribute(hConsole, 13); /// Cambia de color el texto a morado claro
    cout << "\t"<<"Seleccione una opción ---> ";

    cin.clear();
    SetConsoleTextAttribute(hConsole, 12); /// Cambia de color el texto a rojo claro
    if (!(cin >> option) || option <= 0 ) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        return 0;
    }else {
        cout << endl;
        return option;
    }
}

/// Función que trabaja con la sucesión geométrica
bool geometric() {
    int n;
    double init;
    double numerator;
    double denominator;

    system("cls"); // Limpia la consola
    SetConsoleTextAttribute(hConsole, 10); // Cambia de color el texto a verde
    cout << "\t\t" << "+------------------------------------------------------+" << endl;
    cout << "\t\t" << "|--------------|| SUCESIÓN GEOMÉTRICA ||---------------|" << endl;
    cout << "\t\t" << "+----------++--++---------------------++--++-----------+" << endl;
    cout << "\t\t" << "|----------|| 1) INGRESAR VALORES         ||-----------|" << endl;
    cout << "\t\t" << "+----------++-----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| 2) MENU PRINCIPAL           ||-----------|" << endl;
    cout << "\t\t" << "+----------++-----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| 3) SALIR                    ||-----------|" << endl;
    cout << "\t\t" << "+----------++-----------------------------++-----------+" << endl << endl;

    switch (askOption()) {
        case 1:
            system("cls");
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese el valor inicial: ";
            SetConsoleTextAttribute(hConsole, 12);
            init = value(init);

            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese el numerador de la razón común: ";
            SetConsoleTextAttribute(hConsole, 12);
            numerator = value(numerator);

            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese el denominador de la razón común: ";
            SetConsoleTextAttribute(hConsole, 12);
            denominator = value(denominator);

            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese el número de términos que quiere que se muestren: ";
            SetConsoleTextAttribute(hConsole, 12);
            n = valueInt(n);

            for (int i = 1; i <= n; ++i) {
                SetConsoleTextAttribute(hConsole, 5);
                cout << "\t\t" << "a" << setfill('0') << setw(2) << i;
                SetConsoleTextAttribute(hConsole, 12);
                cout << " = ";
                SetConsoleTextAttribute(hConsole, 9);
                printf("%0.2f", (init * pow((numerator / denominator), i - 1)));
                cout << endl;
            }
            return true;
        case 2:
            return true;
        case 3:
            cout << "Good Bye!!!!\n";
            return false;
        default:
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Error seleccionando una opción.\n";
            cout << "Por favor revise las opciones...\n";
            return true;
    }
}


/// Función que trabaja con la sucesión aritmética
bool arithmetic() {
    int n;
    double init;
    double d;

    system("cls"); // Limpia la consola
    SetConsoleTextAttribute(hConsole, 10); // Cambia de color el texto a verde
    cout << "\t\t" << "+------------------------------------------------------+" << endl;
    cout << "\t\t" << "|--------------|| SUCESION ARITMÉTICA ||---------------|" << endl;
    cout << "\t\t" << "+----------++--++---------------------++--++-----------+" << endl;
    cout << "\t\t" << "|----------|| 1) INGRESAR VALORES         ||-----------|" << endl;
    cout << "\t\t" << "+----------++-----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| 2) MENU PRINCIPAL           ||-----------|" << endl;
    cout << "\t\t" << "+----------++-----------------------------++-----------+" << endl;
    cout << "\t\t" << "|----------|| 3) SALIR                    ||-----------|" << endl;
    cout << "\t\t" << "+----------++-----------------------------++-----------+" << endl << endl;

    switch (askOption()) {
        case 1:
            system("cls");
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese el valor inicial: ";
            SetConsoleTextAttribute(hConsole, 12);
            init = value(init);

            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese la diferencia: ";
            SetConsoleTextAttribute(hConsole, 12);
            d = value(d);

            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t\t" << "--> Ingrese el número de términos que quiere que se muestren: ";
            SetConsoleTextAttribute(hConsole, 12);
            n = valueInt(n);

            for (int i = 1; i <= n; ++i) {
                SetConsoleTextAttribute(hConsole, 5);
                cout << "\t\t" << "a" << setfill('0') << setw(2) << i;
                SetConsoleTextAttribute(hConsole, 12);
                cout << " = ";
                SetConsoleTextAttribute(hConsole, 9);
                printf("%0.2f", init);
                cout << endl;
                init += d;
            }
            return true;
        case 2:
            return true;
        case 3:
            cout << "Good Bye!!!!\n";
            return false;
        default:
            SetConsoleTextAttribute(hConsole, 10);
            cout << "Error seleccionando una opción.\n";
            cout << "Por favor revise las opciones...\n";
            return true;
    }

}

/// Función para obtener los valores tipo double
double value(double x) {

    do {
        if (!(cin >> x) || x <= 0 ) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto...\n";
        }else {
            cout << endl;
            break;
        }
    }while (true);

    return x;
}

/// Función para obtener los valores tipo int
int valueInt(int n) {
    do {
        if (!(cin >> n) || n <= 0 ) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            cout << "\nError... Valor incorrecto...\n";
        }else {
            cout << endl;
            break;
        }
    }while (true);

    return n;
}
