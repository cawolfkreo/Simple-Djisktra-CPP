#include <iostream>
#include <string>
#include <vector>

namespace constants {
    constexpr char inicio{ 'a' };                       //Inicio o "indice" de lo grafos.
}

int obtenerEntero(std::string mensaje) {
    int entrada{ 0 };
    std::cout << mensaje;
    std::cin >> entrada;
    std::cin.ignore(32767, '\n');                                       //Remueve cualquier caractér no válido antes de obtener cualquier linea.

    return entrada;
}

char obtenerChar(std::string mensaje, char inicio) {
    char entrada{ inicio };
    std::cout << mensaje;
    std::cin >> entrada;
    std::cin.ignore(32767, '\n');                                       //Remueve cualquier caractér no válido antes de obtener cualquier linea.
    
    return entrada;
}

void populateGraph(std::vector<std::vector<int>> &graph, char inicio) {
    std::string linea{ };
    while (true) {
        std::cout << "Ingrese uno de los vertices del grafo o comente 'cancel' para terminar: ";
        std::getline(std::cin, linea);

        if (!linea.compare("cancel")) {
            break;
        }

        char nodo1{ linea[0] };
        char nodo2{ linea[2] };
        std::string pesoVertice{ linea.substr(4) };
        int peso{ std::stoi(pesoVertice) };

        graph[nodo1 - inicio][nodo2 - inicio] = peso;
        graph[nodo2 - inicio][nodo1 - inicio] = peso;                   //Guardamos los pesos del grafo.
    }
}

void djisktra(std::vector<std::vector<int>>& graph, char startingNode, char finishNode, char inicio) {
    std::vector path{ std::vector<char>(0) };

    //TODO: hacer el algoritmo!!
}

int main() {

    int numNodos{ obtenerEntero("Ingrese el numero de nodos del grafo: ")};

    std::vector<std::vector<int>> grafo ( numNodos, std::vector<int>(numNodos, -1) );       // Crea una matriz de numNodos x numNodos y llena todas las celdas con -1.

    char nodoInicial{ obtenerChar("Ingrese el caracter del nodo inicial: ", constants::inicio) };

    char nodoFinal{ obtenerChar("Ingrese el caracter del nodo final: ", constants::inicio) };

    populateGraph(grafo, constants::inicio);

    djisktra(grafo, nodoInicial, nodoFinal, constants::inicio);

    return 0;
}