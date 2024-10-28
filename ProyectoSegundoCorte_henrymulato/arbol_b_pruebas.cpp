/**
* @file
* @brief Implementacion de las pruebas sobre arboles n-arios
* @author Erwin Meza Vega <emezav@unicauca.edu.co>
* @copyright MIT License
*/


#include <iostream>
#include "arbol_b_pruebas.h"

using std::cout;
using std::endl;

using arbol::arbol_b;


namespace arbol_b_pruebas {
	void iniciar() {
		cout << "Prueba de insercion "<< endl;
		prueba_insercion();
		cout << "===================="<< endl;
		
		//cout << "Prueba de eliminacion "<< endl;
		//prueba_eliminacion();
		//cout << "===================="<< endl;
	}
	
	arbol_b<int> crear();
	
	void prueba_insercion() {
		
		arbol_b<int> a = crear();
		
		cout << "inorden: ";
		a.inorden(cout);
		cout << endl;		
		
	}
	
	void prueba_eliminacion() {
		
		arbol_b<int> a = crear();
		
		cout << "inorden: ";
		a.inorden(cout);
		cout << endl;
		
		//a.eliminar(85);
		//a.eliminar(86);
		//a.eliminar(90);
		
		a.eliminar(77);
		a.eliminar(80);
		a.eliminar(52);
		a.eliminar(58);
		a.eliminar(60);
		a.eliminar(75);
		a.eliminar(50);
		
		
	}
	
	arbol_b<int> crear() {
		arbol_b<int> a;
		a.insertar(50);
		a.insertar(75);
		a.insertar(20);
		a.insertar(30);
		a.insertar(60);
		a.insertar(58);
		a.insertar(52);
		a.insertar(90);
		a.insertar(80);
		a.insertar(77);
		a.insertar(85);
		a.insertar(86);
		a.insertar(92);
		a.insertar(102);
		a.insertar(10);
		a.insertar(87);
		a.insertar(110);
		return a;
	}
};
