#include <iostream>
#include <string>
#include <vector>

constexpr char inicio{ 'a' };                       //Inicio o "indice" de lo grafos.

int obtenerEntero(std::string mensaje) {
    int entrada{ 0 };
    std::cout << mensaje;
    std::cin >> entrada;
    std::cin.ignore(32767, '\n');                                       //Remueve cualquier caractér no válido antes de obtener cualquier linea.

    return entrada;
}

char obtenerChar(std::string mensaje) {
    char entrada{ inicio };
    std::cout << mensaje;
    std::cin >> entrada;
    std::cin.ignore(32767, '\n');                                       //Remueve cualquier caractér no válido antes de obtener cualquier linea.
    
    return entrada;
}


int main() {

    int numNodos{ obtenerEntero("Ingrese el numero de nodos del grafo: ")};

    std::vector<std::vector<int>> grafo ( numNodos, std::vector<int>(numNodos, -1) );       // Crea una matriz de numNodos x numNodos y llena todas las celdas con -1.

    char nodoInicial{ obtenerChar("Ingrese el cracter del nodo inicial: ") };

    char nodoFinal{ obtenerChar("Ingrese el caracter del nodo final: ") };

    std::string linea { };
    while (linea.compare("cancel")) {
        std::cout << "Ingrese uno de los vertices del grafo o comente 'cancel' para terminar: ";
        std::getline(std::cin, linea);

        char nodo1{ linea[0] };
        char nodo2{ linea[2] };
        std::string pesoVertice{ linea.substr(4) };
        int peso{ std::stoi(pesoVertice) };

        grafo[inicio - nodo1][inicio - nodo2] = peso;
        grafo[inicio - nodo2][inicio - nodo1] = peso;           //Guardamos los pesos del grafo.
    }

    return 0;
}