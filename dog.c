#include "dog.h"

//Destruye al Pero 
static void _destroy(Dog* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

//Evento _smell que le permite a la clase Perro oler a otros animales
static void _smell(Dog * this, Cat* cat)
{
	cat->registerObserver(cat, this->observer);
	printf("%s Just smelled %s\n", this->name, cat->name);
}

//Evento que se "ejecuta" cuando el perro escucha a un Gato
static void _handleCatEvent(Dog* this, Cat* cat)
{
	printf("%s\n just heard %s\n", this->name, cat->name);
}
//Cuándo el perro es notificado, imprime que escuchó al Gato
static void _notify(Dog* this, int numero, void* subject) {
	_handleCatEvent(this, (Cat*) subject);
}

//Todo lo necesario para crear un Perro xd
Dog* DOG_create(char* dogsName)
{
	Dog* this = (Dog*) malloc(sizeof(*this));

	this->name = dogsName;
	this->smell = _smell;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}
