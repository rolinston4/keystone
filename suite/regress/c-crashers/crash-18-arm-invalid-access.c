#include <keystone/keystone.h>
int main(int argc, char **argv) {
  int ks_arch = KS_ARCH_ARM, ks_mode = KS_MODE_LITTLE_ENDIAN;
  unsigned char assembly[] = {
    'C', 'p', 'S', 'Q', 'H', 'K', ' ', 'a', 'S', 'R',
    ' ', 'C', 0x00,
  };
  ks_engine *ks;
  ks_err err = ks_open(ks_arch, ks_mode, &ks);
  if (!err) {
    size_t count, size;
    unsigned char *insn;
    if (ks_asm(ks, (char *)assembly, 0, &insn, &size, &count))
      printf("ERROR: failed on ks_asm() with error = %s, code = %u\n", ks_strerror(ks_errno(ks)), ks_errno(ks));
    ks_free(insn);
  }
  ks_close(ks);
  return 0;
}
