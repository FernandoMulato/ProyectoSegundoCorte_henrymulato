/**
* @file
* @brief Arbol n-ario
*/
#ifndef ARBOL_N_H
#define ARBOL_N_H

#include <iostream>
#include <cstddef>
#include <vector>

using std::cout;
using std::endl;

using std::ostream;
using std::vector;

namespace arbol {
	template <class T, int data_limit>
	/**
	* @brief Arbol n-ario
	*/
	class arbol_n {
		
	protected:
		// Declaracion hacia adelante de un nodo
		struct nodo_n;
		
		/**
		* @brief Dato almacenado en un nodo de arbol-n
		*/
		struct dato_n {
			T valor; /*!< Valor almacenado */
			nodo_n * izq = nullptr; /*!< Apuntador al hijo izquierdo del dato */
			nodo_n * der = nullptr; /*!< Apuntador al hijo derecho del dato */
			
			/** 
			* @brief Sobrecarga del operador ==
			* @param rhs Dato a comparar
			* @return true si el valor almacenado en este dato es igual al dato
			*/
			bool operator==(T rhs) {
				return valor == rhs;
			}
			
			/** 
			* @brief Sobrecarga del operador =
			* @param rhs Dato a comparar
			* @return true si el valor almacenado en este dato es diferente al dato
			*/
			bool operator!=(T rhs) {
				return valor != rhs;
			}
			
			/** 
			* @brief Sobrecarga del operador <
			* @param rhs Dato a comparar
			* @return true si el valor almacenado en este dato es menor al dato
			*/
			bool operator<(T rhs) {
				return valor < rhs;
			}
			
			/** 
			* @brief Sobrecarga del operador <
			* @param rhs Dato a comparar
			* @return true si el valor almacenado en este dato es menor o igual al dato
			*/
			bool operator<=(T rhs) {
				return valor <= rhs;
			}
			
			/** 
			* @brief Sobrecarga del operador <
			* @param rhs Dato a comparar
			* @return true si el valor almacenado en este dato es mayor al dato
			*/
			bool operator>(T rhs) {
				return valor > rhs;
			}
			
			/** 
			* @brief Sobrecarga del operador <
			* @param rhs Dato a comparar
			* @return true si el valor almacenado en este dato es mayor o igual al dato
			*/
			bool operator>=(T rhs) {
				return valor >= rhs;
			}
		};
		
		/**
		* @brief Nodo 
		*/
		struct nodo_n {
			int altura = 1; /*!< Altura del sub arbol que comienza en este nodo */
			bool hoja = true; /*!< Verdadero si este nodo no tiene hijos */
			vector<dato_n> datos; /*!< Lista de datos dentro de este nodo */
			nodo_n * padre = nullptr; /*!< Referencia al nodo padre */
			int limite = data_limit; /*!< Cantidad maxima de datos que se pueden almacenar en este nodo */
			
			/**
			* @brief Verifica si este nodo contiene un dato
			* @param dato a buscar
			* @return true si este nodo contiene el dato, false en caso contrario
			*/
			bool contiene(T dato) {
				for (auto & d: datos) {
					if (d == dato) {
						return true;
					}
				}
				return false;
			}
			
			int conteo() {
				return datos.size();
			}
			
			bool lleno() {
				return (datos.size() == data_limit);
			}
			
			bool vacio() {
				return datos.size() == 0;
			}
			
			dato_n & ultimo() {
				return datos[datos.size() - 1];
			}
			
			dato_n & primero() {
				return datos[0];
			}
			
			friend ostream & operator<<(ostream & os, nodo_n & n) {
				os << "[";
				for (auto d: n.datos) {
					os << " " << d.valor;
				}
				os << " ]";
				return os;
			}
		};
		
		/**
		* @brief Raiz del arbol.
		*/
		nodo_n * raiz = nullptr;
		
		/** @brief Limite de datos en un nodo */
		int limite = data_limit;		
		
		ostream & inorden (ostream & os, nodo_n * n){
			if (n == nullptr) { return os;}
			
			for (size_t i = 0; i < n->datos.size(); i++) {
				// Sub arbol izquierdo
				if (i == 0) {
					inorden(os, n->datos[i].izq);
				}
				//Dato
				os << n->datos[i].valor << " ";
				// Sub arbol derecho
				inorden(os, n->datos[i].der);
				
			}			
			return os;
		}
			
	public:
				
				/**
				* @brief Recorrido inorden del arbol
				* @param os Fujo de salida
				* @return Flujo de salida luego de enviar el arbol
				*/
				virtual ostream & inorden(ostream & os) {
					return this->inorden(os, this->raiz);
				}
	};
};

#endif
