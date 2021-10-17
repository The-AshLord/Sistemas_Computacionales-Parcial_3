#include "canary.h"


//Destruye al Canario 
static void _destroy(Canary* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}


//Evento _see que le permite al canario ver al(los) Gato(s)
static void _see(Canary * this, Cat* cat)
{
	cat->registerObserver(cat, this->observer);
	printf("%s Just saw %s\n", this->name, cat->name);
}


//Evento que se "ejecuta" cuando el Canario escucha a un Gato
static void _handleCatEvent(Canary* this, Cat* cat)
{
	printf("%s\n just heard %s\n", this->name, cat->name);
}


//Cuándo el Canario es notificado, imprime que escuchó al Gato
static void _notify(Canary* this, int numero, void* subject) 
{
	_handleCatEvent(this, (Cat*) subject);
}


//Todo lo necesario para crear un Canario
Canary* CANARY_create(char* dogsName)
{
	Canary* this = (Canary*) malloc(sizeof(*this));

	this->name = dogsName;
	this->see = _see;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}
