#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>

using std::string;
using std::vector;


/**
* @brief Divide un texto por los delimitadores especificados
* @param text Cadena a dividir
* @param delimiters Caracteres delimitadores
* @param include_delims Si true, incluye los delimitadores
* @param Vector de subcadenas
*/
vector<string> split(string text,
					 string delimiters,
					 bool include_delims=false) {
	
	// Vector de subcadenas
	vector<string> tokens;
	
	// Subcadena
	string token;
	
	// delimitador
	string opchar;
	
	// Posicion inicial de busqueda
	size_t pos = 0;
	
	// Siguiente posicion del delimitador
	size_t nextPos;
	
	
	nextPos = string::npos;
	
	// 1. Buscar la siguiente posicion de alguno de los delimitadores
	while ((nextPos = text.find_first_of(delimiters, pos)) != string::npos) {
		// 1.1 Obtener el delimitador
		opchar =  std::string(1, text[nextPos]);
		// 1.1.1 Obtener la subcadena entre pos y nextPos
		token = text.substr(pos, nextPos - pos);
		// 1.1.2 Si la subcadena no es vacia,
		// adicionar al vector de subcadenas
		if (token.length() > 0) {
			tokens.push_back(token);
		}
		// 1.1.3 Si se deben incluir los delimitadores
		// adicionarlo al vector de subcadenas
		if (include_delims) {
			tokens.push_back(opchar);
		}
		// Avanzar la posicion de busqueda
		pos = nextPos + 1;
		
	}
	// 2. Tomar la subcadena entre el ultimo delimitador
	// y el final de la cadena
	token = text.substr(pos, nextPos);
	if (token.length() > 0) {
		tokens.push_back(token);
	}
	return tokens;
}
					 
#endif
