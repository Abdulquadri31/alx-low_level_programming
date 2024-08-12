#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error_and_exit(const char *msg, const char *file);
void print_elf_header(const Elf64_Ehdr *header);

/**
 * main - Displays the information contained in the ELF header of an ELF file
 * @argc: The number of command-line arguments
 * @argv: The array of command-line argument strings
 *
 * Return: 0 on success, exits with status code 98 on error.
 */
int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error_and_exit("Error: Can't read from file", argv[1]);
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        close(fd);
        print_error_and_exit("Error: Can't read from file", argv[1]);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
    {
        close(fd);
        print_error_and_exit("Error: Not an ELF file", argv[1]);
    }

    print_elf_header(&header);
    close(fd);
    return (0);
}

/**
 * print_error_and_exit - Prints an error message and exits with status code 98
 * @msg: The error message to print
 * @file: The file that caused the error
 */
void print_error_and_exit(const char *msg, const char *file)
{
    dprintf(STDERR_FILENO, "%s %s\n", msg, file);
    exit(98);
}

/**
 * print_elf_header - Prints the ELF header information
 * @header: The ELF header to print
 */
void print_elf_header(const Elf64_Ehdr *header)
{
    int i;

    printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("Invalid class\n");
    }

    printf("Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("Invalid data encoding\n");
    }

    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    default:
        printf("Other\n");
    }

    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                              ");
    switch (header->e_type)
    {
    case ET_NONE:
        printf("No file type\n");
        break;
    case ET_REL:
        printf("Relocatable file\n");
        break;
    case ET_EXEC:
        printf("Executable file\n");
        break;
    case ET_DYN:
        printf("Shared object file\n");
        break;
    case ET_CORE:
        printf("Core file\n");
        break;
    default:
        printf("Unknown\n");
    }

    printf("Entry point address:               0x%lx\n", header->e_entry);
}
