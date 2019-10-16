#include "varmap.h"

varmap::varmap()
{	
	for (int i = 0; i < VARMAP_MAX_LENGTH; i++)
		va[i] = 0;
	size = 0;
}

void varmap::insert(string key, float v)
{
	if (this->exsit(key))
		return;
	size++;
	ka[size] = key;
	va[size] = new variable(v);
}

void varmap::insert(string key, string str)
{
	if (this->exsit(key))
		return;
	size++;
	ka[size] = key;
	va[size] = new variable(str);
}

/*void varmap::insert(string key, string* list, int n)
{
	variable b[VARMAP_MAX_LENGTH];
	if (this->exsit(key))
		return;
	for (int i = 0; i < n; i++) {
		if (!this->exsit(list[i]))
			return;
		b[i] = variable(*this->get(list[i]));
	}
	size++;
	ka[size] = key;
	va[size] = new variable(b, n);

}*/



void varmap::insert_copy(string key_from, string key_to)
{
	if (!this->exsit(key_from))
		return;
	if (this->exsit(key_to))
		return;
	size++;
	ka[size] = key_to;
	va[size] = new variable(*(this->get(key_from)));
}

variable* varmap::at(string key)
{
	for (int i = 0; i < size; i++) {
		if (ka[i] == key)
			return va[i];
	}
	return 0;
}



bool varmap::exsit(string key)
{
	for (int i = 0; i < size; i++) {
		if (ka[i] == key)
			return true;
	}
	return false;
}

void varmap::print(string key)
{
	if (!this->exsit(key))
		return;
	this->get(key)->print();
}

varmap::~varmap()
{
}


