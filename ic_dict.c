// ic_dict.c - dictionary
#include <assert.h>
#include <string.h>
#include "ic_dict.h"

// compare counted strings
int keycmp(const char* a, const char* b, size_t n)
{
	return a[0] != b[0] ? a[0] - b[0] : strncmp(a + 1, b + 1, n - 1);
}
int test_keycmp(void)
{
	assert (0 == keycmp("0", "0"));

	return 0;
}

struct ic_dict_entry {
	char key[256];
	size_t size;
	char data[1];
};

typedef struct _ic_dict_struct {
	// linked list of dictionaries
	struct _ic_dict_struct *prev *next;	
	size_t items, 
	char data[]; // dict entries
} ic_dict_struct;
