#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Esta función revisa si un número está en base 2
bool correcto(string numero) {
    for (char digito : numero) {
        if (digito != '0' && digito != '1') {
            return false;
        }
    }
    return true;
}

// Esta función convierte de base 10 a base 2
void dab(int decimal) {
    int binario[32];
    int i = 0;
    while (decimal > 0) {
        binario[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    cout << "El número en binario es: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binario[j];
    }
    cout << endl;
}

// Esta función convierte de base 2 a base 10
void bad(string binario) {
    int decimal = 0;
    int base = 1;
    int length = binario.length();
    for (int i = length - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += base;
        } else if (binario[i] != '0') {
            cout << "El número ingresado no pertenece a base 2." << endl;
            return;
        }
        base *= 2;
    }
    cout << "El número en decimal es: " << decimal << endl;
}

int main() { //Esta es la función principal
    int opcion;
    string numero;

    do { // Repite el menú hasta ingresar la opción 3
        cout << "=== Conversor de bases ===" << endl;
        cout << "1. Convertir de base 10 a base 2" << endl;
        cout << "2. Convertir de base 2 a base 10" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese un número en base 10: ";
                cin >> numero;
                if (!numero.empty() && numero.find_first_not_of("0123456789") == string::npos) { //Verifica si está en decimal
                    int decimal = stoi(numero);
                    dab(decimal);
                } else {
                    cout << "El número ingresado no pertenece a base 10." << endl;
                }
                break;
            case 2:
                cout << "Ingrese un número en base 2: ";
                cin >> numero;
                if (correcto(numero)) {
                    bad(numero);
                } else {
                    cout << "El número ingresado no pertenece a base 2." << endl;
                }
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, intente nuevamente." << endl;
                break;
        }
        cout << endl;
    } while (opcion != 3);

    return 0;
}
