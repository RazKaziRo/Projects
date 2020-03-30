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
	SAY_HELLO

}obj_vfunc_idx_t;

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

typedef struct ToString
{
	object_t *obj;
	char ret_buffer[100];

}to_str_t;

static int g_counter = 0;
static int g_animal_loaded = 0, g_dog_loaded = 0, g_cat_loaded, g_legendery_loaded = 0;

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

static void foo(animal_t *a)
{
	to_str_t *to_str_pack = malloc(sizeof(*to_str_pack));
	to_str_pack->obj = (object_t*)a;

	(*((animal_t*)a)->animal_meta.metadata->vFuncTable)[TO_STRING](to_str_pack);
	printf("%s\n",to_str_pack->ret_buffer);
}

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
	if (0 == g_animal_loaded)
	{
		printf("Static block Animal 1 \n");
		printf("Static block Animal 2 \n");
		g_animal_loaded = 1;
	}	
}

void AnimalToString(void *pack)
{
	char id_buffer[sizeof(((animal_t *)((to_str_t *)pack)->obj)->ID)];

	strcat(((to_str_t *)pack)->ret_buffer ,"Animal with ID: ");
	sprintf(id_buffer, "%d", ((animal_t *)((to_str_t *)pack)->obj)->ID);
	strcat(((to_str_t *)pack)->ret_buffer, id_buffer);
}

void AnimalCtor(void *this)
{	
	to_str_t *to_str_pack = malloc(sizeof(*to_str_pack));
	to_str_pack->obj = this;

	AnimalStaticBlock();

	if (((animal_t*)this)->ID == 0)
	{
	AnimalInstanceBlock(this);
	printf("Animal Ctor \n");
	((animal_t*)this)->ID = ++g_counter;
	(*((animal_t*)this)->animal_meta.metadata->vFuncTable)[SAY_HELLO](this);
	(*((animal_t*)this)->animal_meta.metadata->vFuncTable)[TO_STRING](to_str_pack);
	ShowCounter();
	printf("%s\n",to_str_pack->ret_buffer);
	printf("il.co.ilrd.java2c.%s@%p \n",((animal_t*)this)->animal_meta.metadata->name,this);
	}

}

void AnimalCtorB(void *this, int num_masters)
{	
	AnimalStaticBlock();
	AnimalInstanceBlock(this);
	printf("Animal Ctor int \n");
	((animal_t*)this)->num_masters = num_masters;
	((animal_t*)this)->ID = ++g_counter;
}

int getNumMasters(void *this) 	
{
	return ((animal_t*)this)->num_masters;
}

void AnimalFinalize(void *this)
{
	printf("finalize Animal with ID:  %d \n", ((animal_t*)this)->ID);
	objectFinalize(this);
}

/* / -- Dog Methods -- / */

void DogInstanceBlock(void *this)
{
	printf("Instance initialization block Dog \n");
	((animal_t*)this)->num_legs = 4;
} 

void DogStaticBlock()
{
	if (0 == g_dog_loaded)
	{
		printf("Static block Dog \n");
		g_dog_loaded = 1;
	}	
}

void DogCtor(void *this)
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

void DogToString(void *pack)
{
	char id_buffer[sizeof(((animal_t *)((to_str_t *)pack)->obj)->ID)];

	strcat(((to_str_t *)pack)->ret_buffer ,"Dog with ID: ");
	sprintf(id_buffer, "%d", ((animal_t *)((to_str_t *)pack)->obj)->ID);
	strcat(((to_str_t *)pack)->ret_buffer, id_buffer);
}

void DogFinalize(void *this)
{
	printf("finalize Dog with ID:  %d \n", ((animal_t*)this)->ID);
	AnimalFinalize(this);
}

/* / -- Cat Methods -- / */

void CatInstanceBlock(void *this)
{	
	if (((animal_t*)this)->ID == 0)
	{
	((animal_t*)this)->num_masters = 5;
	}
}

void CatStaticBlock(void *this)
{	
	if (0 == g_cat_loaded)
	{
		printf("Static block Cat \n");
		g_cat_loaded = 1;
	}
}

void CatCtorB(void *this, char *colors)
{	
	CatStaticBlock(this);
	CatInstanceBlock(this);
	AnimalCtor(this);

	((cat_t*)this)->colors = colors;
	printf("Cat Ctor with color: %s \n", ((cat_t*)this)->colors);

}

void CatCtor(void *this)
{	
	CatStaticBlock(this);
	CatInstanceBlock(this);
	((animal_t*)this)->num_masters = 2;
	CatCtorB(this, "black");
	AnimalCtor(this);

	printf("Cat Ctor \n");
}

void CatToString(void *pack)
{
	char id_buffer[4];

	strcat(((to_str_t *)pack)->ret_buffer ,"Cat with ID: ");
	sprintf(id_buffer, "%d", ((animal_t *)((to_str_t *)pack)->obj)->ID);
	strcat(((to_str_t *)pack)->ret_buffer, id_buffer);
}

void CatFinalize(void *this)
{
	printf("finalize Cat with ID: %d\n", ((animal_t*)this)->ID);
	objectFinalize(this);
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

void LegenderyCtor(void *this)
{
	LegenderyStaticBlock();
	CatCtor(this);
	printf("Legendery Ctor \n");
}

void LegendaryToString(void *pack)
{
	char id_buffer[sizeof(((animal_t *)((to_str_t *)pack)->obj)->ID)];

	strcat(((to_str_t *)pack)->ret_buffer ,"LegendaryAnimal with ID: ");
	sprintf(id_buffer, "%d", ((animal_t *)((to_str_t *)pack)->obj)->ID);
	strcat(((to_str_t *)pack)->ret_buffer, id_buffer);
}

void LegenderySayHello(void *this)
{
	printf("Legendery Hello! \n");
}

void LegenderyFinalize(void *this)
{
	printf("finalize LegendaryAnimal with ID: %d\n", ((animal_t*)this)->ID);
	objectFinalize(this);
}

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
							&AnimalToString,
							&objectWait,
							&AnimalSayHello,
							&AnimalFinalize,
							};

vFunc_t dogVTable[] = {		&objectClone, 
          				  	&objectEquals,
							&objectFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&DogToString,
							&objectWait,
							&DogSayHello,
							&DogFinalize
							};

vFunc_t catVTable[] = {		&objectClone, 
          				  	&objectEquals,
							&CatFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&CatToString,
							&objectWait,
							&AnimalSayHello
							};

vFunc_t legenderyVTable[] = {&objectClone, 
          				  	&objectEquals,
							&CatFinalize,
							&objectGetClass,
							&objectHashCode,
							&objectNotify,
							&objectNotifyAll,
							&LegendaryToString,
							&objectWait,
							&LegenderySayHello,
							&LegenderyFinalize
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

	ShowCounter();

	printf("%d\n", animal->ID);
	printf("%d\n",((animal_t*)dog)->ID);
	printf("%d\n",((animal_t*)cat)->ID);
	printf("%d\n",((animal_t*)la)->ID);

	array[0] = (animal_t*)ObjectAlloc(&dog_meta);
	DogCtor(array[0]);

	array[1] = (animal_t*)ObjectAlloc(&cat_meta);
	CatCtor(array[1]);

	array[2] = (animal_t*)ObjectAlloc(&cat_meta);
	CatCtorB(array[2],"white");

	array[3] = (animal_t*)ObjectAlloc(&legendery_meta); 
	LegenderyCtor(array[3]);
	
	array[4] = (animal_t*)ObjectAlloc(&animal_meta);
	AnimalCtor(array[4]);

	for(i = 0; i < 5; ++i)
	{
		(*(array[i])->animal_meta.metadata->vFuncTable)[SAY_HELLO](array[i]);
		printf("%d\n", getNumMasters(array[i]));
	}

	for(i = 0; i < 5; ++i)
	{
		foo(array[i]);
	}
}