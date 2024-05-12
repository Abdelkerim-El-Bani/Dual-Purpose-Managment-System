#include <stdio.h>
#include <stdlib.h>
#include "cabinet.h"

patient* head = NULL;

int main()
{

head = load_patients();

choixEspace();

return 0;
}


