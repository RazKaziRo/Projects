/*
 * Author: Raz KaziRo
 * Purpose: Answares for Java2C .
 * Date: 26.03.2020
 * Language: C
 * Reviewer: 
 */

#include <stdio.h> /*printf()*/
#include <string.h> /*strcat()*/
#include <stdlib.h> /*malloc()*/

typedef void (*vFunc_t)(void*);

typedef struct CLASS{

    char *name;
	size_t size;
	struct CLASS *super;
	vFunc_t (*vFuncTable)[];

}class_t;

typedef struct OBJECT{

	class_t* metadata;

}object_t;


typedef struct ANIMAL{
	
	object_t animal_meta;
	int num_legs;
	int num_masters;
	int ID;

}animal_t;


static int animal_counter = 0;

char *AtoString(void *this)
{	
	char *id_buffer = malloc(sizeof(((animal_t*)this)->ID));
	itoa(this->ID, id_buffer,2);

	char *string = strcat("Animal with ID:", id_buffer);
	free(id_buffer);
	id_buffer = NULL;

	return string;
}
void ShowCounter()
{
	printf("%d\n", animal_counter);
}

void ASayHello(void *this)
{
	printf("Animal Hello!\n");
	printf("%d\n", ((animal_t*)this)->num_legs);
}


void AnimalActorA(animal_t *this)
{
	printf("Animal Ctor\n");
	this->ID = ++animal_counter;
	ASayHello(this);
	
}

void AnimalActorB(animal_t *this, int num_masters)
{
	printf("Animal Ctor int \n");

}

int getNumMasters(animal_t *this)
{

}

// -- Object Functions -- //
void objectClone(void *param){}
void objectEquals(void *param){}
void objectFinalize(void *param){}
void objectGetClass(void *param){}
void objectHashCode(void *param){}
void objectNotify(void *param){}
void objectNotifyAll(void *param){}
void objectToString(void *param){}
void objectWait(void *param){}


//-- Virtual Tables -- //
vFunc_t objectVTable[] = {	&objectClone, 
          				  	&objectEquals,
							&objectFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&objectToString,
							&objectWait};

vFunc_t animalVTable[] = {	&objectClone, 
          				  	&objectEquals,
							&objectFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&objectToString,
							&objectWait,
							(vFunc_t)&AnimalActorA,
							&ASayHello,
							};

class_t object_meta = {"Object", sizeof(object_t), NULL, &objectVTable};
class_t animal_meta = {"Animal", sizeof(animal_t), &object_meta, &animalVTable};


object_t *ObjectAlloc(class_t *metadata)
{
	object_t *obj = (object_t *)calloc(metadata->size, 1); 
	obj->metadata = metadata;

	return obj;
}

int main(){

	//object_t *object = ObjectAlloc(&object_meta);
	animal_t *animalA = (animal_t*)ObjectAlloc(&animal_meta);
	printf("%d\n", animalA->ID);
	
}