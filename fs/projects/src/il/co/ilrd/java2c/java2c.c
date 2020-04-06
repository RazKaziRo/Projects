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

#define BUFFER_SIZE 80

typedef void (*vFunc_t)(void*);

enum
{
	CLONE,		
   	EQUALS,
   	FINALIZ,
   	GET_CLASS,
	HASCODE,
	NOTIFY,		
	NOTIFAY_ALL,
	TO_STRING,
	WAIT,
	SAY_HELLO,
	NUM_MASTERS
};

typedef struct Class{

    char *name;
	size_t size;
	struct Class *super;
	vFunc_t (*vFuncTable)[];

}class_t;

typedef struct Object{

	class_t* metadata;

}object_t;

typedef struct Animal{
	
	object_t animal_meta;
	int num_legs;
	int num_masters;
	int ID;

}animal_t;

typedef struct Dog
{
	animal_t dog_meta;
	int num_legs;

}dog_t;

typedef struct Cat
{
	animal_t cat_meta;
	char *colors;
	
}cat_t;

typedef struct Legendery
{
	cat_t legendery_meta;
	
}legendery_t;

static int g_animal_counter = 0;
int g_animal_loaded = 0, g_dog_loaded = 0, g_cat_loaded, g_legendery_loaded = 0;
char g_buffer[BUFFER_SIZE];

/* / -- Object Functions -- / */

void objectClone(object_t *this){}
void objectEquals(object_t *this){}
void objectFinalize(object_t *this){
	free(this);
}
void objectGetClass(object_t *this){}
void objectHashCode(object_t *this){}
void objectNotify(object_t *this){}
void objectNotifyAll(object_t *this){}
void objectToString(object_t *this){}
void objectWait(object_t *this){}


static void ResetBuffer(){

	memset(&g_buffer, 0, BUFFER_SIZE);
}

static void foo(animal_t *a)
{
	(*a->animal_meta.metadata->vFuncTable)[TO_STRING](a);
	printf("%s\n",g_buffer);
	ResetBuffer();
}

void AnimalShowCounter()
{
	printf("%d\n", g_animal_counter);
}

void AnimalSayHello(animal_t *this)
{
	printf("Animal Hello!\n");
	printf("I have %d legs\n", this->num_legs);
}

void AnimalInstanceBlock(animal_t *this)
{
	printf("Instance initialization block Animal \n");
}

void AnimalStaticBlock()
{
	if (0 == g_animal_loaded)
	{
		printf("Static block Animal 1 \n");
		printf("Static block Animal 2 \n");
		g_animal_loaded = 1;
	}	
}

void AnimalToString(animal_t *this)
{
	sprintf(g_buffer, "Animal with ID: %d", this->ID);
}

void AnimalCtor(animal_t *this)
{	
	AnimalStaticBlock();

	if (this->ID == 0)
	{
	AnimalInstanceBlock(this);
	printf("Animal Ctor \n");
	this->ID = ++g_animal_counter;
	this->num_legs = 5;
	this->num_masters = 1;
	(*this->animal_meta.metadata->vFuncTable)[SAY_HELLO](this);
	(*this->animal_meta.metadata->vFuncTable)[TO_STRING](this);
	AnimalShowCounter();
	printf("%s\n",g_buffer);
	ResetBuffer();
	printf("il.co.ilrd.java2c.%s@%p \n",this->animal_meta.metadata->name,this);
	}
}

void AnimalCtorB(animal_t *this, int num_masters)
{	
	AnimalStaticBlock();
	AnimalInstanceBlock(this);
	printf("Animal Ctor int \n");
	this->num_legs = 5;
	this->num_masters = num_masters;
	this->ID = ++g_animal_counter;
}

int AnimalgetNumMasters(animal_t *this) 	
{
	return this->num_masters;
}

void AnimalFinalize(animal_t *this)
{
	printf("finalize Animal with ID:  %d \n", this->ID);
	objectFinalize((object_t*)this);
}

/* / -- Dog Methods -- / */

void DogInstanceBlock(dog_t *this)
{
	printf("Instance initialization block Dog \n");
} 

void DogStaticBlock()
{
	if (0 == g_dog_loaded)
	{
		printf("Static block Dog \n");
		g_dog_loaded = 1;
	}	
}

void DogCtor(dog_t *this)
{
	DogStaticBlock();
	AnimalCtorB((animal_t*)this, 2);
	DogInstanceBlock(this);
	this->num_legs = 4;

	printf("Dog Ctor \n");
}

void DogSayHello(dog_t *this)
{
	printf("Dog Hello! \n");
	printf("I have %d legs \n", this->num_legs);
}

void DogToString(dog_t *this)
{
	sprintf(g_buffer, "Dog with ID: %d", ((animal_t*)this)->ID);
}

void DogFinalize(dog_t *this)
{
	printf("finalize Dog with ID:  %d \n", ((animal_t*)this)->ID);
	AnimalFinalize((animal_t*)this);
}

/* / -- Cat Methods -- / */

void CatInstanceBlock(cat_t *this)
{	
	if (((animal_t*)this)->ID == 0)
	{
		((animal_t*)this)->num_masters = 5;
	}
}

void CatStaticBlock(cat_t *this)
{	
	if (0 == g_cat_loaded)
	{
		printf("Static block Cat \n");
		g_cat_loaded = 1;
	}
}

void CatCtorB(cat_t *this, char *colors)
{	
	CatStaticBlock(this);
	CatInstanceBlock(this);
	AnimalCtor((animal_t*)this);

	((cat_t*)this)->colors = colors;
	printf("Cat Ctor with color: %s \n", this->colors);
}

void CatCtor(cat_t *this)
{	
	CatStaticBlock(this);
	CatInstanceBlock(this);
	((animal_t*)this)->num_masters = 2;
	CatCtorB(this, "black");
	AnimalCtor((animal_t*)this);

	printf("Cat Ctor \n");
}

void CatToString(cat_t *this)
{
	sprintf(g_buffer, "Cat with ID: %d", ((animal_t *)this)->ID);
}

void CatFinalize(cat_t *this)
{
	printf("finalize Cat with ID: %d\n", ((animal_t*)this)->ID);
	AnimalFinalize((animal_t*)this);
}

/* /-- Legendery Methods -- / */

void LegenderyStaticBlock()
{
	if (0 == g_legendery_loaded)
	{
		printf("Static block Legendery Animal\n");
		g_legendery_loaded = 1;
	}
}

void LegenderyCtor(legendery_t *this)
{
	LegenderyStaticBlock();
	CatCtor((cat_t*)this);
	printf("Legendery Ctor \n");
}

void LegendaryToString(legendery_t *this)
{
	sprintf(g_buffer, "LegendaryAnimal with ID: %d", ((animal_t *)this)->ID);
}

void LegenderySayHello(legendery_t *this)
{
	printf("Legendery Hello! \n");
}

void LegenderyFinalize(legendery_t *this)
{
	printf("finalize LegendaryAnimal with ID: %d\n", ((animal_t*)this)->ID);
	CatFinalize((cat_t*)this);
}

/* /-- Virtual Tables -- / */

vFunc_t objectVTable[] = {	(vFunc_t)&objectClone, 
          				  	(vFunc_t)&objectEquals,
							(vFunc_t)&objectFinalize,
							(vFunc_t)&objectGetClass,
							(vFunc_t)&objectHashCode,
							(vFunc_t)&objectNotify,
							(vFunc_t)&objectNotifyAll,
							(vFunc_t)&objectToString,
							(vFunc_t)&objectWait};

vFunc_t animalVTable[] = {	(vFunc_t)&objectClone, 
          				  	(vFunc_t)&objectEquals,
							(vFunc_t)&AnimalFinalize,
							(vFunc_t)&objectGetClass,
							(vFunc_t)&objectHashCode,
							(vFunc_t)&objectNotify,
							(vFunc_t)&objectNotifyAll,
							(vFunc_t)&AnimalToString,
							(vFunc_t)&objectWait,
							(vFunc_t)&AnimalSayHello,
							(vFunc_t)&AnimalgetNumMasters,
							};

vFunc_t dogVTable[] = {		(vFunc_t)&objectClone, 
          					(vFunc_t)&objectEquals,
							(vFunc_t)&DogFinalize,
							(vFunc_t)&objectGetClass,
							(vFunc_t)&objectHashCode,
							(vFunc_t)&objectNotify,
							(vFunc_t)&objectNotifyAll,
							(vFunc_t)&DogToString,
							(vFunc_t)&objectWait,
							(vFunc_t)&DogSayHello,
							(vFunc_t)&DogFinalize
							};

vFunc_t catVTable[] = {		(vFunc_t)&objectClone, 
          				  	(vFunc_t)&objectEquals,
							(vFunc_t)&CatFinalize,
							(vFunc_t)&objectGetClass,
							(vFunc_t)&objectHashCode,
							(vFunc_t)&objectNotify,
							(vFunc_t)&objectNotifyAll,
							(vFunc_t)&CatToString,
							(vFunc_t)&objectWait,
							(vFunc_t)&AnimalSayHello,
							};

vFunc_t legenderyVTable[] = {(vFunc_t)&objectClone, 
          				  	(vFunc_t)&objectEquals,
							(vFunc_t)&LegenderyFinalize,
							(vFunc_t)&objectGetClass,
							(vFunc_t)&objectHashCode,
							(vFunc_t)&objectNotify,
							(vFunc_t)&objectNotifyAll,
							(vFunc_t)&LegendaryToString,
							(vFunc_t)&objectWait,
							(vFunc_t)&LegenderySayHello,
							(vFunc_t)&LegenderyFinalize
							};

class_t object_meta = {"Object", sizeof(object_t), NULL, &objectVTable};
class_t animal_meta = {"Animal", sizeof(animal_t), &object_meta, &animalVTable};
class_t dog_meta = {"Dog", sizeof(dog_t), &animal_meta, &dogVTable};
class_t cat_meta = {"Cat", sizeof(cat_t),&animal_meta, &catVTable};
class_t legendery_meta = {"LegendaryAnimal", sizeof(legendery_t), &cat_meta, &legenderyVTable};

object_t *ObjectAlloc(class_t *metadata)
{
	object_t *object = (object_t *)calloc(metadata->size, 1); 
	object->metadata = metadata;

	return object;
}

int main(){

	object_t *obj;
	animal_t* array[5];

	animal_t *animal = (animal_t*)ObjectAlloc(&animal_meta);
	dog_t *dog = (dog_t*)ObjectAlloc(&dog_meta);
	cat_t *cat = (cat_t*)ObjectAlloc(&cat_meta);
	legendery_t *la = (legendery_t*)ObjectAlloc(&legendery_meta);
	int i = 0;

	AnimalCtor(animal);
	DogCtor(dog);
	CatCtor(cat);
	LegenderyCtor(la);

	AnimalShowCounter();

	printf("%d\n", animal->ID);
	printf("%d\n",((animal_t*)dog)->ID);
	printf("%d\n",((animal_t*)cat)->ID);
	printf("%d\n",((animal_t*)la)->ID);

	array[0] = (animal_t*)ObjectAlloc(&dog_meta);
	DogCtor((dog_t*)array[0]);

	array[1] = (animal_t*)ObjectAlloc(&cat_meta);
	CatCtor((cat_t*)array[1]);

	array[2] = (animal_t*)ObjectAlloc(&cat_meta);
	CatCtorB((cat_t*)array[2],"white");

	array[3] = (animal_t*)ObjectAlloc(&legendery_meta); 
	LegenderyCtor((legendery_t*)array[3]);
	
	array[4] = (animal_t*)ObjectAlloc(&animal_meta);
	AnimalCtor(array[4]);



	for(i = 0; i < 5; ++i)
	{
		(*(array[i])->animal_meta.metadata->vFuncTable)[SAY_HELLO](array[i]);
		printf("%d\n", AnimalgetNumMasters(array[i]));
	}

	for(i = 0; i < 5; ++i)
	{
		foo(array[i]);
	}

	printf("After gc \n");

	for(i = 4; i >= 0; --i)
	{ 
		(*(array[i])->animal_meta.metadata->vFuncTable)[FINALIZ](array[i]);
	}	

	LegenderyFinalize(la);
	CatFinalize(cat);
	DogFinalize(dog);
	AnimalFinalize(animal);
}
