#include <stdio.h>
#include "elf.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage : parser elf_file\n");
        return 1;
    }

    struct Elf32_Ehdr header;
    FILE * f = fopen(argv[1], "rb");
    fread((void*)&header, sizeof(struct Elf32_Ehdr), 1, f);
    printf("e_ident = %s\n", header.e_ident);
    printf("e_type = %d\n", header.e_type);
    printf("e_machine = %d\n", header.e_machine);
    printf("e_version = %d\n", header.e_version);
    printf("e_entry = 0x%x\n", header.e_entry);
    printf("e_phoff = %d\n", header.e_phoff);
    printf("e_phnum = %d\n", header.e_phnum);

    struct Elf32_Phdr program_headers[header.e_phnum];
    fseek(f, header.e_phoff, SEEK_SET);
    for (int i = 0; i < header.e_phnum; i++)
    {
        struct Elf32_Phdr *h = &program_headers[i];
        fread((void*)h, sizeof(struct Elf32_Phdr), 1, f);
        printf("Program header %d : address = 0x%x, size = %d\n", i, h->p_vaddr, h->p_filesz);
    }

    fclose(f);
    return 0;
}