#include "basic.h"
#include "derived.h"
#include <stdio.h>
#include <cstdlib>
using namespace std;

typedef void (*p_fun)(void); // define a function pointer

int main(void)
{
	p_fun foo = NULL;
	Base1 b1;
	Base1 *ptr_b1 = &b1;
	int *p_class_table = (int *)(&b1);
	int *p_vtable = (int *)(*p_class_table);
	int star_p_class_table = *p_class_table;
	int star_p_vtable = *p_vtable;
	//p_fun = *p_vtable; // ERROR
	printf("ptr_b1 = %d\n", &b1); // address of object d
	printf("p_class_table = %d\n", p_class_table); // address of object d
	printf("*p_class_table = %d\n", star_p_class_table); // the first element in the member table(which is an address)
	printf("p_vtable = %d\n", p_vtable);
	printf("*p_vtable = %d\n", star_p_vtable); // the first element in the v-table(which is a function address)
	foo = (p_fun)*((int *)*(int *)(&b1)); // ===== when +5, the private virtual function will be called
	foo(); // call the virtual function in Base1
	printf("\n");

	Derive_cover d;
	ptr_b1 = &d;
	p_class_table = (int *)(&d);
	p_vtable = (int *)(*p_class_table);
	star_p_class_table = *p_class_table;
	star_p_vtable = *p_vtable;
	printf("ptr_d = %d\n", &d);
	printf("p_class_table = %d\n", p_class_table);
	printf("*p_class_table = %d\n", star_p_class_table);
	printf("p_vtable = %d\n", p_vtable);
	printf("*p_vtable = %d\n", star_p_vtable);
	foo = (p_fun)*((int *)*(int *)(&d));
	foo();

	// call the same destructor at last
	system("pause");
	return 0;
}