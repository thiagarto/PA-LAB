#include <iostream>
#include <set>
#include <sstream>
#include "DTFecha.h"
#include "PaginaWeb.h"
#include "ChatGPT.h"
#include "Libro.h"
#include "Estudiante.h"
#include "DTInfoEstudiante.h"

using namespace std;


Informacion* buscarInfo(set<Informacion*>& lista, int id) {
    for (Informacion* info : lista) {
        if (info->getId() == id)
            return info;
    }
    return nullptr;
}

Estudiante* buscarEstudiante(set<Estudiante*>& lista, int ci) {
    for (Estudiante* est : lista) {
        if (est->getCI() == ci)
            return est;
    }
    return nullptr;
}

int main() {
    set<Informacion*> infoList;
    set<Estudiante*> estudianteList;

    int opcion;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Crear informacion\n";
        cout << "2. Crear estudiante\n";
        cout << "3. Relacionar estudiante con informacion\n";
        cout << "4. Mostrar toda la informacion\n";
        cout << "5. Listar informacion por estudiante y fecha\n";
        cout << "6. Listar info con termino especifico (punto h)\n";
        cout << "7. Eliminar informacion\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            int id, dia, mes, anio, tipo;
            string titulo, link, texto, pregunta, respuesta, resumen, linea;
            cout << "ID: "; cin >> id;
            cout << "Fecha (dia mes anio): "; cin >> dia >> mes >> anio;
            cin.ignore();
            DTFecha fecha(dia, mes, anio);

            cout << "Tipo: 1) PaginaWeb  2) ChatGPT  3) Libro: ";
            cin >> tipo;
            cin.ignore();

            if (tipo == 1) {
                cout << "Titulo: "; getline(cin, titulo);
                cout << "Link: "; getline(cin, link);
                cout << "Texto: "; getline(cin, texto);
                infoList.insert(new PaginaWeb(id, fecha, titulo, link, texto));

            } else if (tipo == 2) {
                cout << "Pregunta: "; getline(cin, pregunta);
                cout << "Respuesta: "; getline(cin, respuesta);
                infoList.insert(new ChatGPT(id, fecha, pregunta, respuesta));

            } else if (tipo == 3) {
                cout << "Titulo: "; getline(cin, titulo);
                cout << "Autores (separados por coma): "; getline(cin, linea);
                set<string> autores;
                stringstream ss(linea);
                while (getline(ss, texto, ',')) {
                    autores.insert(texto);
                }
                cout << "Resumen: "; getline(cin, resumen);
                infoList.insert(new Libro(id, fecha, titulo, autores, resumen));
            }

        } else if (opcion == 2) {
            int ci;
            string nombre, email;
            cout << "CI: "; cin >> ci;
            cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Email: "; getline(cin, email);
            estudianteList.insert(new Estudiante(nombre, ci, email));

        } else if (opcion == 3) {
            int ci, id;
            cout << "CI del estudiante: "; cin >> ci;
            cout << "ID de la informacion: "; cin >> id;

            Estudiante* est = buscarEstudiante(estudianteList, ci);
            Informacion* info = buscarInfo(infoList, id);

            if (est != nullptr && info != nullptr) {
                est->agregarInformacion(info);
                cout << "Informacion vinculada correctamente.\n";
            } else {
                cout << "No se encontro estudiante o informacion.\n";
            }

        } else if (opcion == 4) {
            cout << "\n--- Toda la informacion guardada ---\n";
            for (Informacion* info : infoList) {
                cout << info->toString() << "\n\n";
            }

        } else if (opcion == 5) {
            int ci, d, m, a;
            cout << "CI del estudiante: "; cin >> ci;
            Estudiante* est = buscarEstudiante(estudianteList, ci);
            if (est == nullptr) {
                cout << "Estudiante no encontrado.\n";
                continue;
            }

            cout << "Fecha (dia mes anio): "; cin >> d >> m >> a;
            DTFecha desde(d, m, a);

            set<string> lista = est->listarInfo(desde);
            cout << "\n--- Informacion desde " << desde.toString() << " ---\n";
            for (const string txt : lista) {
                cout << txt << "\n\n";
            }

        } else if (opcion == 6) {
            string termino;
            cout << "Ingrese el termino a buscar: ";
            getline(cin, termino);

            set<DTInfoEstudiante> resultados;

            for (Informacion* info : infoList) {
                string texto = info->toString();

                if (texto.find(termino) != string::npos) {
                    set<Estudiante*> relacionados = info->getEstudiantes();

                    for (Estudiante* est : relacionados) {
                        resultados.insert(DTInfoEstudiante(est->getCI(), est->getNombre(), info->getId()));
                    }
                }
            }

            cout << "\n--- Estudiantes que guardaron informacion con '" << termino << "' ---\n";
            if (resultados.empty()) {
                cout << "Nadie guardo informacion con ese termino.\n";
            } else {
                for (DTInfoEstudiante dti : resultados) {
                    cout << dti.toString() << endl;
                }
            }
            } else if (opcion == 7) {
                int id;
                cout << "ID de la informacion a eliminar: ";
                cin >> id;

                Informacion* info = buscarInfo(infoList, id);
                if (info == nullptr) {
                cout << "Informacion no encontrada.\n";
            } else {
                // Eliminar los vínculos desde los estudiantes
                set<Estudiante*> relacionados = info->getEstudiantes();
                for (Estudiante* est : relacionados) {
                // Esta parte requiere que la clase Estudiante tenga un método para quitar la información
                est->quitarInformacion(info);
            }

                // Eliminar del set y liberar memoria
                infoList.erase(info);
                delete info;

                cout << "Informacion eliminada correctamente.\n";
                }
            }


    } while (opcion != 8);

    for (Informacion * info : infoList) delete info;
    for (Estudiante * est : estudianteList) delete est;


    return 0;

}
