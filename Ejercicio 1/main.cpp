#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Empleado {
    int cedula;
    string nombre;
    int tipo;
    double salarioHora;
    int horasLaboradas;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;
};

int main() {
    vector<Empleado> empleados;
    char continuar;

    do {
        Empleado emp;
        cout << "Ingrese el numero de cedula: ";
        cin >> emp.cedula;
        cout << "Ingrese el nombre del empleado: ";
        cin.ignore();
        getline(cin, emp.nombre);
        cout << "Ingrese el tipo de empleado (1-Operario, 2-Técnico, 3-Profesional): ";
        cin >> emp.tipo;
        cout << "Ingrese el salario por hora: ";
        cin >> emp.salarioHora;
        cout << "Ingrese la cantidad de horas laboradas: ";
        cin >> emp.horasLaboradas;

        emp.salarioOrdinario = emp.salarioHora * emp.horasLaboradas;

        switch (emp.tipo) {
            case 1:
                emp.aumento = emp.salarioOrdinario * 0.15;
                break;
            case 2:
                emp.aumento = emp.salarioOrdinario * 0.10;
                break;
            case 3:
                emp.aumento = emp.salarioOrdinario * 0.05;
                break;
            default:
                emp.aumento = 0;
        }

        emp.salarioBruto = emp.salarioOrdinario + emp.aumento;
        emp.deduccionCCSS = emp.salarioBruto * 0.0917;
        emp.salarioNeto = emp.salarioBruto - emp.deduccionCCSS;

        empleados.push_back(emp);

        cout << fixed << setprecision(2);
        cout << "\nDatos del empleado:\n";
        cout << "Cedula: " << emp.cedula << endl;
        cout << "Nombre Empleado: " << emp.nombre << endl;
        cout << "Tipo Empleado: " << emp.tipo << endl;
        cout << "Salario por Hora: " << emp.salarioHora << endl;
        cout << "Cantidad de Horas: " << emp.horasLaboradas << endl;
        cout << "Salario Ordinario: " << emp.salarioOrdinario << endl;
        cout << "Aumento: " << emp.aumento << endl;
        cout << "Salario Bruto: " << emp.salarioBruto << endl;
        cout << "Deduccion CCSS: " << emp.deduccionCCSS << endl;
        cout << "Salario Neto: " << emp.salarioNeto << endl;

        cout << "\n¿Desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    // Estadísticas
    int operarios = 0, tecnicos = 0, profesionales = 0;
    double acumuladoOperarios = 0, acumuladoTecnicos = 0, acumuladoProfesionales = 0;

    for (int i = 0; i < empleados.size(); ++i) {
        const Empleado& emp = empleados[i];
        if (emp.tipo == 1) {
            operarios++;
            acumuladoOperarios += emp.salarioNeto;
        } else if (emp.tipo == 2) {
            tecnicos++;
            acumuladoTecnicos += emp.salarioNeto;
        } else if (emp.tipo == 3) {
            profesionales++;
            acumuladoProfesionales += emp.salarioNeto;
        }
    }

    cout << fixed << setprecision(2);
    cout << "\nEstadisticas:\n";
    cout << "1) Cantidad Empleados Tipo Operarios: " << operarios << endl;
    cout << "2) Acumulado Salario Neto para Operarios: " << acumuladoOperarios << endl;
    cout << "3) Promedio Salario Neto para Operarios: " << acumuladoOperarios / operarios << endl;
    cout << "4) Cantidad Empleados Tipo Técnico: " << tecnicos << endl;
    cout << "5) Acumulado Salario Neto para Tecnicos: " << acumuladoTecnicos << endl;
    cout << "6) Promedio Salario Neto para Tecnicos: " << acumuladoTecnicos / tecnicos << endl;
    cout << "7) Cantidad Empleados Tipo Profesional: " << profesionales << endl;
    cout << "8) Acumulado Salario Neto para Profesional: " << acumuladoProfesionales << endl;
    cout << "9) Promedio Salario Neto para Profesionales: " << acumuladoProfesionales / profesionales << endl;

    return 0;
}

