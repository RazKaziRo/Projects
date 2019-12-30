#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "random.h"

int main() {

	printf("%d", get_random_number());
    return 0;
}