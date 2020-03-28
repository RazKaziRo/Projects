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
typedef enum VFUNCIDX
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
	ANIMAL_SAY_HELLO,
	ANIMAL_TO_STRING

}obj_vfunc_idx_t;

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

typedef struct DOG
{
	object_t dog_meta;

}dog_t;

typedef struct CAT
{
	object_t cat_meta;
	char *colors;
	
}cat_t;


static int g_counter = 0;
static int g_animal_loaded = 0, g_dog_loaded = 0, g_cat_loaded;

static void ShowCounter()
{
	printf("%d\n", g_counter);
}

void AnimalSayHello(void *this)
{
	printf("Animal Hello!\n");
	printf("I have %d legs\n", ((animal_t*)this)->num_legs);
}

void AnimalInstanceBlock(void *this)
{
	printf("Instance initialization block Animal \n");
	((animal_t*)this)->num_legs = 5;
	((animal_t*)this)->num_masters = 1;
}

void AnimalStaticBlock()
{
	if(0 == g_animal_loaded)
	{
		printf("Static block Animal 1 \n");
		printf("Static block Animal 2 \n");
		g_animal_loaded = 1;
	}	
}

void AnimalCtor(void *this)
{	
	AnimalStaticBlock();
	AnimalInstanceBlock(this);
	printf("Animal Ctor \n");
	((animal_t*)this)->ID = ++g_counter;
	AnimalSayHello(this);
	ShowCounter();
}

void AnimalCtorB(void *this, int num_masters)
{	
	AnimalStaticBlock();
	AnimalInstanceBlock(this);
	printf("Animal Ctor int \n");
	((animal_t*)this)->num_masters = num_masters;
	((animal_t*)this)->ID = ++g_counter;
}

int getNumMasters(animal_t *this)
{
	return this->num_masters;
}

void AnimalToString(void *param)
{
		/*
	char *id_buffer = malloc(sizeof(((animal_t*)this)->ID));
	itoa(this->ID, id_buffer,2);

	char *string = strcat("Animal with ID:", id_buffer);
	free(id_buffer);
	id_buffer = NULL;

	return string;*/
}

void AnimalFinalize(void *this)
{
	printf("finalize Animal with ID:  %d \n", ((animal_t*)this)->ID);
}

/* / -- Dog Methods -- / */

void DogInstanceBlock(void *this)
{
	printf("Instance initialization block Dog \n");
	((animal_t*)this)->num_legs = 4;
} 

void DogStaticBlock()
{
	if(0 == g_dog_loaded)
	{
		printf("Static block Dog \n");
		g_dog_loaded = 1;
	}	
}

void DogCtor(dog_t *this)
{
	DogStaticBlock();
	AnimalCtorB(this, 2);
	DogInstanceBlock(this);
	printf("Dog Ctor \n");
}

void DogSayHello(void *this)
{
	printf("Dog Hello! \n");
	printf("I have %d legs \n", ((animal_t*)this)->num_legs);
}

void DogFinalize(void *this)
{
	printf("finalize Dog with ID:  %d \n", ((animal_t*)this)->ID);
	AnimalFinalize(this);
}

/* / -- Cat Methods -- / */

void CatInstanceBlock(void *this)
{	
	AnimalInstanceBlock(this);
	((animal_t*)this)->num_masters = 5;
}

void CatStaticBlock(void *this)
{	
	if(0 == g_cat_loaded)
	{
		printf("Static block Cat \n");
		g_cat_loaded = 1;
	}
}

void CatCtorB(void *this, char *colors)
{	
	CatStaticBlock(this);
	((cat_t*)this)->colors = colors;
	printf("Cat Ctor with color: %s \n", ((cat_t*)this)->colors);

}

void CatCtor(void *this)
{	
	CatStaticBlock(this);
	CatInstanceBlock(this);
	AnimalCtor(this);
	((cat_t*)this)->colors = "black";
	printf("Cat Ctor \n");
	((animal_t*)this)->num_masters = 2;
}

/* / -- Object Functions -- / */
void objectClone(void *param){}
void objectEquals(void *param){}
void objectFinalize(void *param){}
void objectGetClass(void *param){}
void objectHashCode(void *param){}
void objectNotify(void *param){}
void objectNotifyAll(void *param){}
void objectToString(void *param){}
void objectWait(void *param){}

/* /-- Virtual Tables -- / */
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
							&AnimalSayHello,
							&AnimalToString,
							};

vFunc_t dogVTable[] = {	&objectClone, 
          				  	&objectEquals,
							&objectFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&objectToString,
							&objectWait,
							&DogSayHello,
							};

vFunc_t catVTable[] = {	&objectClone, 
          				  	&objectEquals,
							&objectFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&objectToString,
							&objectWait
							};

class_t object_meta = {"Object", sizeof(object_t), NULL, &objectVTable};
class_t animal_meta = {"Animal", sizeof(animal_t), &object_meta, &animalVTable};
class_t dog_meta = {"Dog", sizeof(dog_t), &animal_meta, &dogVTable};
class_t cat_meta = {"Cat", sizeof(cat_t),&animal_meta, &catVTable};

object_t *ObjectAlloc(class_t *metadata)
{
	object_t *object = (object_t *)calloc(metadata->size, 1); 
	object->metadata = metadata;

	return object;
}

int main(){

	object_t *object;

	animal_t *animalA = (animal_t*)ObjectAlloc(&animal_meta);
	dog_t *dogA = (dog_t*)ObjectAlloc(&dog_meta);
	cat_t *catA = (cat_t*)ObjectAlloc(&cat_meta);

	AnimalCtor(animalA);

	DogCtor(dogA);

	CatCtor(catA);

	/* /(*animalA->animal_meta.metadata->vFuncTable)[ANIMAL_SAY_HELLO](animalA); */
	ShowCounter();

	printf("%d\n", animalA->ID);
	printf("%d\n",((animal_t*)dogA)->ID);
	
}