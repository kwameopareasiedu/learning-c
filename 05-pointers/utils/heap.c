#define HEAP_MEM_SIZE 10240

static char heap_mem[HEAP_MEM_SIZE];
static char *heap_ptr = heap_mem;

char* alloc(int size) {
  if (heap_ptr + size <= heap_mem + HEAP_MEM_SIZE) {
    char *address = heap_ptr;
    heap_ptr += size;
    return address;
  }

  return 0;
}

void free(char *addr) {
  if (addr >= heap_mem && addr < heap_mem + HEAP_MEM_SIZE) {
    heap_ptr = addr;
  }
}