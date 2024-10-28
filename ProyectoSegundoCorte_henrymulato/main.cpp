/**
* @file
* @brief 
* @author Henry Fernando Mulato Llanten <henrymulato@unicauca.edu.co>
* @copyright MIT License
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "arbol_b_pruebas.h"
#include "modelos.h"


using modelos::Persona;

using std::cin;
using std::cout;
using std::endl;

// usar split
void cargarCSV(const std::string& nombreArchivo) {
	std::ifstream archivo(nombreArchivo);
	std::string linea;
	
	if (!archivo.is_open()) {
		std::cerr << "No se pudo abrir el archivo." << std::endl;
		return;
	}
	
	while (std::getline(archivo, linea)) {
		std::stringstream ss(linea);
		std::string valor;
		std::vector<std::string> fila;
		
		while (std::getline(ss, valor, ',')) {
			fila.push_back(valor);
		}
		
		// Procesar la fila (imprimir, almacenar, etc.)
		for (const auto& val : fila) {
			std::cout << val << " ";
		}
		std::cout << std::endl;
	}
	
	archivo.close();
}

int main (int argc, char *argv[]) {
	
	arbol_b_pruebas::iniciar();
	/*int opcion;
	directorio_personas<int> direcPersonas;
	
	do {
		cout << "=============== Directorio de Personas ==================" << endl;
		cout << "1. Cargar archivo" << endl;
		cout << "2. Buscar una persona" << endl;
		cout << "3. Salir" << endl;
		cout << "-> ";
		cin >> opcion;
		
		switch (opcion) {
			case 1: 
				cargarCSV("documentoPrueba.csv");
				break; 
			case 2:
				direcPersonas.buscar(1041465329); // falta logica
				break; 
			case 3: 
				break;
			default: 
				cout << "Ingreso un valor incorrecto" << endl;
			
		}
	} while (opcion != 1 && opcion != 2 && opcion != 3);*/
	
return 0;
}

