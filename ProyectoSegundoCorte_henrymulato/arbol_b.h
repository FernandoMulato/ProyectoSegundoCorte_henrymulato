#ifndef ARBOL_B_H
#define ARBOL_B_H
#define N 16

/**
* @file
* @brief Arbol B
* @author Henry Fernando Mulato Llanten <henrymulato@unicauca.edu.co>
* @copyright MIT License
*/

#include "arbol_n.h"
#include <vector>
#include <iterator>  // Incluye iterator para std::next

using arbol::arbol_n;
using std::vector;

namespace arbol {
	template <class T>
	/**
	* @brief Arbol B
	*/
	class arbol_b: public  arbol_n<T, N> {
		/** @brief Alias para la clase base */
		using parent = arbol_n<T, N>;		
		using nodo_n = typename parent::nodo_n;
		using dato_n = typename parent::dato_n;
	protected:
		
		/**
		* @brief Inserta un nuevo dato en un nodo
		* @param pos_padre Posicion de insercion en el padre
		* @param padre Padre del nodo en el cual se va a insertar el dato
		* @param n Nodo en el cual se va a insertar el dato
		* @param dato Dato a insertar
		*/
		virtual nodo_n * insertar(int pos_padre, nodo_n * padre, nodo_n * n, T dato){
			mostrarDatos(n);
			dato_n nD;
			// 1.el nodo n tiene espacio?
			if (!n->lleno()) {
				cout << "El nodo n tiene espacio " << endl;
				// 1.1.  si tiene espacio se compara con los datos en cada posición para mirar su posición, 
				// se inserta.
				for (auto it = n->datos.begin(); it != n->datos.end(); ++it) {
					auto& d = *it;
					auto next_it = std::next(it); // Obtén el siguiente iterador
					
					// si el dato es menor al valor de d
					if (dato < d.valor) {
						cout << "El dato " << dato << " es menor a " << d.valor << endl;
						nD.valor = dato; 
						n->datos.insert(it, nD); // se inserta el dato en el dato actual de la iteracion
						cout << "Se inserto correctamente el dato: " << dato << endl;
						mostrarDatos(n);
						return n;
					} else  if (dato > d.valor && dato < next_it->valor) { // si el dato es mayor al dato actual y menor que el siguiente
						cout << "El dato " << dato << " es mayor a " << d.valor << " y menor a " << next_it->valor<< endl;
						nD.valor = dato; 
						n->datos.insert(next_it, nD); // se inserta el dato en medio de estos datos
						cout << "Se inserto correctamente el dato: " << dato << endl;
						mostrarDatos(n);
						return n;
					} else if (dato > d.valor &&  next_it->valor == 0) { // si el dato es mayor al dato actual y el dato siguiente esta vacio
						cout << "El dato " << dato << " es mayor a " << d.valor << " y no tiene un valor siguiente " << endl;
						nD.valor = dato; 
						n->datos.insert(next_it, nD); // se inserta en el dato vacio
						cout << "Se inserto correctamente el dato: " << dato << endl;
						mostrarDatos(n);
						return n;
					}
				}
			} else {
				// 2. si el nodo n no tiene espacio
					// 2.1. n es hoja?
				if (n->hoja) {
					cout << "El nodo n es hoja " << endl;
					// 2.1.1. si el nodo_n esta lleno
					// 2.1.2. se divide el tamaño de los datos con dos y se toma el dato que esta en la posició N/2
					dato_n nM = n->datos.at(N/2);
					cout << "El dato del medio es : " << nM.valor << endl;
					// 2.1.3. se crea un nuevo nodo_n que tendra como primer elemento al dato de la posición N/2.
					// este nodo se convierte en la subraiz, lo que esta a la izquierda del dato N/2 se convierte en el
					// hijo izquierdo de la subraiz, y lo que esta en la derecha en el hijo derecho de la subraiz, en un nodo nuevo
					// Creación de nuevos nodos para subraíz e hijo derecho
					nodo_n* nuevaRaiz = new nodo_n();
					nodo_n* hijoDer = new nodo_n();
					
					nuevaRaiz->datos.push_back(nM); // se inserta el dato de la mitas en el nuevo nodo 
					cout << "El dato del nuevo nodo es : " << endl;
					mostrarDatos(nuevaRaiz);
					
					// datos de la derecha 
					vector<dato_n> datosDer = capturarDatosDer(n->datos, nM); // captura los datos de la derecha desde el dato en la mitad
					hijoDer->datos = datosDer;  // los datos del hijoDer pasan a hacer los datos de la derecha
					
					// datos de la izquierda
					vector<dato_n> datosIzq = capturarDatosIzq(n->datos, nM); // captura los datos de la izquierda desde el dato en la mitad
					
					nuevaRaiz->datos.at(0).izq = n; // el nodo n se convierte en el hijoIzq del nuevo nodo
					nuevaRaiz->datos.at(0).der = hijoDer; // el nodo hijoDer se convierte en el hijoDer del nuevo nodo
					
					n->datos = datosIzq; // los datos de n pasan a hacer los datos de la izquierda
					n->padre = nuevaRaiz; // el padre de n pasa a ser el nodo nuevaRaiz
					
					hijoDer->padre = nuevaRaiz; // el padre de hijoDer pasa a ser el nodo nuevaRaiz
					
					this->raiz = nuevaRaiz; // nuevaRaiz pasa hacer la nueva raiz del arbol
					
					return insertar(pos_padre, this->raiz, this->raiz->datos.at(pos_padre).der, dato); // se inserta recursivamente el dato en el hijoDer del dato
				} else {
					// 2.2 el nodo_n no es hoja?
					// 2.2.1 comparar el dato con los datos y mirar que posición le corresponde, hasta encontrar hoja 
				}
			}
			
			return n;
		}
		/**
		* @brief Se invoca luego de insertar un nuevo dato
		* @param n Nodo en el cual se inserto el nuevo dato
		*/
		void insertado(nodo_n * n) {
			// TODO
		}
		
		/**
		* @brief Elimina un dato en un nodo
		* @param n Nodo en el cual se puede encontrar el dato
		* @param dato Dato a eliminar
		*/
		void eliminar(nodo_n * n, T dato) {
			// Si este nodo es nulo, terminar
			cout << "Eliminar " << dato << endl;
			if (n == nullptr) {
				return;
			}
			// TODO
		}
		
		/** 
		* @brief Se invoca luego de eliminar un dato
		* @param padre Padre del nodo en el cual se elimino el dato
		*/
		void eliminado(nodo_n * padre) {
			
		}
		
		/** 
		* @brief Muestra los datos almacenados en un nodo
		* @param n nodo el cual se va a mostrar sus datos
		*/
		void mostrarDatos(nodo_n * n) const {
			cout << "[";
			for (auto & d : n->datos) {
				cout << d.valor << " ";
			}
			cout << "]";
			cout << endl;  
		}
		
		/** 
		* @brief Captura los elementos de la izquierda de un vector a partir de un dato n
		* @param vN vector del que se va a tomar los elementos 
		* @param n dato desde donde se inicia el procedimiento
		*/
		vector<dato_n> capturarDatosIzq(const std::vector<dato_n>& vN, const dato_n& n) {
			std::vector<dato_n> datosIzq;
			for (auto it = vN.begin(); it != vN.end(); ++it) {
				if (it->valor == n.valor) {
					break;  // Detén el recorrido cuando encuentras el dato central
				}
				datosIzq.push_back(*it);  // Agrega elementos a la izquierda del dato central
			}
			return datosIzq;
		}
		
		/** 
		* @brief Captura los elementos de la derecha de un vector a partir de un dato n
		* @param vN vector del que se va a tomar los elementos 
		* @param n dato desde donde se inicia el procedimiento
		*/
		vector<dato_n> capturarDatosDer(const std::vector<dato_n>& vN, const dato_n& n) {
			std::vector<dato_n> datosDer;
			bool found = false;
			for (auto it = vN.begin(); it != vN.end(); ++it) {
				if (found) {
					datosDer.push_back(*it);  // Agrega elementos a la derecha del dato central
				}
				if (it->valor == n.valor) {
					found = true;  // Marca el inicio de los elementos a la derecha
				}
			}
			return datosDer;
		}
	public:
			/**
			* @brief Inserta un nuevo dato en el arbol
			* @param dato Dato a insertar
			*/
			void insertar(T dato){
				cout << "Tratando de insertar a " << dato << endl;
				// 1. si el arbol no exite se crea un nuevo nodo_n y se agrega como primero dato el dato
				if (this->raiz == nullptr) {
					this->raiz = new nodo_n;  // Creamos un nodo_n
					dato_n nD;
					nD.valor = dato; 
					this->raiz->datos.insert(this->raiz->datos.begin(), nD);   // Insertamos `dato` en el nuevo nodo
					cout << "El dato " << dato << " se convierte en el primer dato de la raiz"<< endl;
					return;
				}
				// 2. si el arbol contiene al dato se retorna nada 
				if (this->raiz->contiene(dato)) {
					cout << "El arbol ya contiene al dato " << dato << endl;
					return;
				}
				// 3. si el arbol existe al dato se llama al metodo privado
				this->insertar(0, nullptr, this->raiz, dato);
			}
				
			/**
			* @brief Elimina un dato del arbol
			* @param dato Dato a eliminar
			*/
			void eliminar(T dato) {
				this->eliminar(this->raiz, dato);
				// TODO
			}
	};
};

#endif
