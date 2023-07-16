#define BYTE_LEN 8

int setbits(int x, int p, int n, int y) {
  int pos = p + 1;
  int off = pos - n;

  return ((x >> pos) << pos) | ((y & ~(~0 << n)) << off) | (x & ~(~0 << off));
}

int invertbits(int x, int p, int n) {
  int pos = p + 1;
  int off = pos - n;
  int y = (x >> off) & ~(~0 << n);

  return setbits(x, p, n, ~y);
}

int bitlen(int x) {
  int len = 0;

  while (x != 0) {
    x >>= 1;
    len++;
  }

  return len;
}

int rightrot(int x, int n) {
  int len = BYTE_LEN * sizeof(int);
  int shift = len - n;

  return ((x & ~(~0 << n)) << shift) | (x >> n);
}
