#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using std::string;

namespace modelos {
	/**
	* @brief Clase que representa a una Persona
	*/
	class Persona {
	private:
		long identificacion;
		string nombres;
		string apellidos;
		string telefono;
		string direccion;
		long longitud;
		long latitud;
	public:
		// Constructor
		Persona(long id, const std::string& nombres, const std::string& apellidos,
				const std::string& telefono, const std::string& direccion,
				long longitud, long latitud)
			: identificacion(id), nombres(nombres), apellidos(apellidos),
			telefono(telefono), direccion(direccion),
			longitud(longitud), latitud(latitud) {}
		
	};
};

#endif
