//Refer to https://blog.csdn.net/imxiangzi/article/details/45871949
#include <stdio.h>
#include <dlfcn.h>
#include "ctest.h"

int main(int argc, char *argv[])
{
	void *lib_handle;	/*  */
	double (*fn)(int *);
	int x;
	char *error;

	/* open shared library libctest.so, RTLD_LAZY: bind, error return NULL, no focus on error "unresolved symbols" */
	lib_handle = dlopen("/opt/lib/libctest.so", RTLD_LAZY);
	if(!lib_handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	/* acquire address of shared library loaded, error return NULL */
	fn = dlsym(lib_handle, "ctest2");
	if((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	(*fn)(&x);
	printf("Valx=%d\n",x);

	dlclose(lib_handle);
	return 0;
}
