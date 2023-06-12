#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_elf(unsigned char *e_id);
void print_magic(unsigned char *e_id);
void print_class(unsigned char *e_id);
void print_data(unsigned char *e_id);
void print_version(unsigned char *e_id);
void print_abi(unsigned char *e_id);
void print_os(unsigned char *e_id);
void print_type(unsigned int e_type, unsigned char *e_id);
void print_entry(unsigned long int e_entry, unsigned char *e_id);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file
 * @e_id: A ptr to an array containing the ELF magic no.'s
 *
 * return: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_id)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_id[i] != 127 && e_id[i] != 'E' && e_id[i] != 'L' && e_id[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header
 * @e_id: A ptr to an array containing the ELF magic no.'s
 *
 * return: Magic numbers are separated by spaces
 */
void print_magic(unsigned char *e_id)
{
	int i;

	printf("  Magic:			");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("02x", e_id[id]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF header
 * @e_id: A pointer to an array containing the ELF class
 */
void print_class(unsigned char *e_id)
{
	printf("  Class:			");

	switch (e_id[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header
 * @e_id: A ptr to an array containing the ELF class
 */
void print_data(unsigned char *e_id)
{
	printf("  Data:				");

	switch (e_id[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x\n", e_id[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header
 * @e_id: A ptr to an array containing the ELF version
 */
void print_version(unsigned char *e_id)
{
	printf("  Version:			%d:", e_id[EI_VERSION]);
	
	switch (e_id[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_abi - Prints ABI of an ELF header.
 * @e_id: A pointer to an array containing the ELF version.
 */
void print_abi(unsigned char *e_id)
{
	printf("  ABI Version:			%d\n", e_id[EI_ABIVERSION]);
}

/**
 * print_os - Prints the OS/ABI of an ELF header
 * @e_id: A pointer to an array containing the ELF ver
 */
void print_os(unsigned char *e_id)
{
	printf("  OS/ABI:				");

	switch (e_id[EI_OSABI])
	{
	case: ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLOARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_id[EI_OSABI]);
	}
}

/**
 * print_type - Prints the type of an ELF header
 * @e_type: The ELF type
 * @e_id: A ptr to an array containing the ELF class
 */
void print_type(unsigned int e_type, unsigned char *e_id)
{
	if (e_id[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:					");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point
 * @e_entry: The address of the ELF entry point
 * @e_id: A ptr to an array containing the ELF class
 */
void print_entry(unsigned long int e_entry, unsigned char *e_id)
{
	printf("  Entry point address:				");

	if(e_id[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%3lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file
 * @elf: The file description
 *
 * return: exit code 98
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in elf header
 * @argc: no. of arguments
 * @argv: an array
 *
 * Return: 0 on success or exit code 98
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int i, j;

	i = open(argv[1], O_RDONLY);
	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(i);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	j = read(i, header, sizeof(Elf64_Ehdr));
	if (j == -1)
	{
		free(header);
		close_elf(i);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_id);
	printf("ELF Header:\n");
	print_magic(header->e_id);
	print_class(header->e_id);
	print_data(header->e_id);
	print_version(header->e_id);
	print_os(header->e_id);
	print_abi(header->e_id);
	print_type(header->e_type, header->e_id);
	print_entry(header->e_entry, header->e_id);

	free(header);
	close_elf(i);
	return (0);
}
