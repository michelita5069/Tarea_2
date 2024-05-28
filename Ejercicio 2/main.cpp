#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Venta {
    int factura;
    int cedula;
    string nombre;
    int localidad;
    int cantidadEntradas;
    double subtotal;
    double cargosServicios;
    double totalPagar;
};

int main() {
    vector<Venta> ventas;
    char continuar;
    int cantidadSol = 0, cantidadSombra = 0, cantidadPreferencial = 0;
    double acumuladoSol = 0, acumuladoSombra = 0, acumuladoPreferencial = 0;

    do {
        Venta venta;
        cout << "Ingrese el numero de factura: ";
        cin >> venta.factura;
        cout << "Ingrese la cedula del comprador: ";
        cin >> venta.cedula;
        cout << "Ingrese el nombre del comprador: ";
        cin.ignore();
        getline(cin, venta.nombre);
        cout << "Ingrese la localidad (1-Sol Norte/Sur, 2-Sombra Este/Oeste, 3-Preferencial): ";
        cin >> venta.localidad;
        cout << "Ingrese la cantidad de entradas (máximo 4): ";
        cin >> venta.cantidadEntradas;

        if (venta.cantidadEntradas > 4) {
            cout << "Error: La cantidad de entradas no puede exceder 4." << endl;
            continue;
        }

        switch (venta.localidad) {
            case 1:
                venta.subtotal = venta.cantidadEntradas * 10500;
                venta.cargosServicios = venta.cantidadEntradas * 1000;
                venta.totalPagar = venta.subtotal + venta.cargosServicios;
                cantidadSol += venta.cantidadEntradas;
                acumuladoSol += venta.subtotal;
                break;
            case 2:
                venta.subtotal = venta.cantidadEntradas * 20500;
                venta.cargosServicios = venta.cantidadEntradas * 1000;
                venta.totalPagar = venta.subtotal + venta.cargosServicios;
                cantidadSombra += venta.cantidadEntradas;
                acumuladoSombra += venta.subtotal;
                break;
            case 3:
                venta.subtotal = venta.cantidadEntradas * 25500;
                venta.cargosServicios = venta.cantidadEntradas * 1000;
                venta.totalPagar = venta.subtotal + venta.cargosServicios;
                cantidadPreferencial += venta.cantidadEntradas;
                acumuladoPreferencial += venta.subtotal;
                break;
            default:
                cout << "Error: Localidad invalida." << endl;
                continue;
        }

        ventas.push_back(venta);

        cout << fixed << setprecision(2);
        cout << "\nDatos de la venta:\n";
        cout << "Numero de Factura: " << venta.factura << endl;
        cout << "Cedula: " << venta.cedula << endl;
        cout << "Nombre Comprador: " << venta.nombre << endl;
        cout << "Localidad: ";
        switch (venta.localidad) {
            case 1:
                cout << "Sol Norte/Sur" << endl;
                break;
            case 2:
                cout << "Sombra Este/Oeste" << endl;
                break;
            case 3:
                cout << "Preferencial" << endl;
                break;
        }
        cout << "Cantidad de Entradas: " << venta.cantidadEntradas << endl;
        cout << "Subtotal: " << venta.subtotal << endl;
        cout << "Cargos por Servicios: " << venta.cargosServicios << endl;
        cout << "Total a Pagar: " << venta.totalPagar << endl;

        cout << "\n¿Desea ingresar otra venta? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    cout << fixed << setprecision(2);
    cout << "\nEstadisticas:\n";
    cout << "Cantidad Entradas Localidad Sol Norte/Sur: " << cantidadSol << endl;
    cout << "Acumulado Dinero Localidad Sol Norte/Sur: " << acumuladoSol << endl;
    cout << "Cantidad Entradas Localidad Sombra Este/Oeste: " << cantidadSombra << endl;
    cout << "Acumulado Dinero Localidad Sombra Este/Oeste: " << acumuladoSombra << endl;
    cout << "Cantidad Entradas Localidad Preferencial: " << cantidadPreferencial << endl;
    cout << "Acumulado Dinero Localidad Preferencial: " << acumuladoPreferencial << endl;

    return 0;
}

