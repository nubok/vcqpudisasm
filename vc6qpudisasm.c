#include <stdio.h>
#include <stdlib.h>

/* From Mesa */
#include <broadcom/qpu/qpu_disasm.h>
#include <util/ralloc.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: vc6qpudisas version\n\nVersions known to work are 33, 41 and 42.\n");
        return -1;
    }

    struct v3d_device_info devinfo = {
        .ver = (uint8_t) atoi(argv[1]),
    };

    char line[4096];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        const unsigned long long insn = strtoull(line, NULL, 0);

        const char *disasm = v3d_qpu_disasm(&devinfo, insn);

        puts(disasm);

        ralloc_free((void*) disasm);
    }

    return 0;
}
