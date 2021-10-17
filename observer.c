#include "observer.h"
//Pareciera como si el observer fuera una plantilla de de diferentes Metodos. pero no estoy seguro

//destruye el observer 
static void _destroy(Observer* this)
{
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}


static void _notify(Observer *this, int type, void * subject)
{
	this->notifyImpl(this->impl, type, subject);
}

//Todo lo que se necesita para crear un Observador 
Observer* observerNew(void* impl, void (*notifyImpl)(void*, int, void*))
{
	Observer* this = (Observer *) malloc(sizeof(*this));

	this->destroy = _destroy;
	this->notify = _notify;
	this->impl = impl;
	this->notifyImpl = notifyImpl;

	return this;
}