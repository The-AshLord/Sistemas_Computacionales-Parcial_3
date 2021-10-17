#include <stdio.h>
#include <stdlib.h>
#include "cat.h"
#include "dog.h"
#include "canary.h"

int main(int argc, char const *argv[])
{
	//Crea un Gato llamado Hopkins y un Perro llamado Alfred 
	Cat* hopkins = CAT_create("Hopkins");
	Dog* alfred = DOG_create("Alfred");
	//Tambíen vamos a Crear un Canario Llamado Tweety
	Canary* tweety = CANARY_create("Tweety");

	// Suscripción al evento SPEAK
	alfred->smell(alfred, hopkins);
	tweety->see(tweety,hopkins);

	// Publicación del evento 
	hopkins->speak(hopkins);

	//Destruye a Hopkins y a Alfred liberando su epsacio de memoría.
	hopkins->destroy(hopkins);
	alfred->destroy(alfred);
	//Finalmente Destruimos a Tweety.
	tweety->destroy(tweety);

	return EXIT_SUCCESS;
}

