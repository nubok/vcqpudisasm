#include <stdio.h>
#include <stdlib.h>

#define UTIL_ARCH_LITTLE_ENDIAN 1
#define UTIL_ARCH_BIG_ENDIAN    0
#include <gallium/drivers/vc4/vc4_qpu.h>

int main(void)
{
    char line[4096];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        const uint64_t insn = strtoull(line, NULL, 0);

        vc4_qpu_disasm(&insn, 1);
        /*
    * vc4_qpu_disasm prints the output to stderr; see
    * https://gitlab.freedesktop.org/mesa/mesa/-/blob/main/src/gallium/drivers/vc4/vc4_qpu_disasm.c
    */
        fprintf(stderr, "\n");
    }

    return 0;
}
