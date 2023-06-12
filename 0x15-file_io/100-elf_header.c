#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * _strncmp - compare two strings
 * @s1: first string
 * @s2: second string
 * @n: the max number of bytes to compare
 *
 * Return: 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

/**
 * close - close a file and print err
 * @f: the file to close
 */
void close(int f)
{
	if (close(f) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close file\n", 22);
	exit(98);
}

/**
 * read - read from a file and print an error message upon failure
 * @f: the file descriptor to read from
 * @buff: the buffer to write to
 * @count: the number of bytes to read
 */
void read(int f, char *buff, size_t count)
{
	if (read(f, buff, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	close(f);
	exit(98);
}

/**
 * elf_magic - print ELF magic
 * @header: the ELF header
 */
void elf_magic(const unsigned char *header)
{
	unsigned int i;

	if (_strncmp((const char *) header, ELFMAG, 4))
	{
		write((STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n Magic:	");

	for (i = 0; i < 16; i++)
	printf("%02x%c", header[i], i < 15 ? ' ' : '\n');
}

/**
 * elf_class - print ELF class
 * @header: the ELF header
 *
 * Return:32 or 64
 */
size_t elf_class(const unsigned char *header)
{
	printf(" %-34s ", "Class:");

	if (header[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (header[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", header[EI_CLASS]);
	return (32);
}

/**
 * elf_data - print ELF data
 * @header: the ELF header
 *
 * return: 1 or 0
 */
int elf_data(const unsigned char *header)
{
	printf(" %-34s ", "Data:");

	if (header[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (header[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

/**
 * elf_version - print ELF version
 * @header: the ELF header
 */
void elf_version(const unsigned char *header)
{
	printf(" %-34 %u", "Version:", header[EI_VERSION])
	
		if (header[EI_VERSION] == EV_CURRENT)
			printf(" (current)\n");
		else
			printf("\n");
}

/**
 * elf_osabi - print ELF OS/ABI
 * @header: the ELF header
 */
void elf_osabi(const unsigned char *header)
{
	const char *os_tbl[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf(" %-34s ", "OS/ABI:");

	if (header[EI_OSABI] < 19)
		printf("%s\n", os_tbl[(unsigned int) header[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", header[EI_OSABI]);
}

/**
 * elf_abi - print ELF ABI version
 * @header: the ELF header
 */
void elf_abi(const unsigned char *header)
{
	printf(" %-34s %u\n", "ABI Version:", header[EI_ABIVERSION]);
}

/**
 * elf_type - print ELF type
 * @header: the ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_type(const unsigned char *header, int big_endian)
{
	char *type_tbl[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf(" %-34s ", "Type:");

	if(big_endian)
		type = 0x100 * header[16] + header[17];
	else
		type = 0x100 * header[17] + header[16];

	if (type < 5)
		printf("%s\n", type_tbl[type];
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if(type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - print entry point address
 * @header: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness 
 */
void elf_entry(const unsigned char *header, size_t bit_mode, int big_endian)
{
	int addr = bit_mode / 8;

	printf(" %-34s 0x", "Entry point address:");

	if (big_endian)
	{
		while (addr && !*(header))
			--addr, ++header;
		printf("%x", *header & 0xff);

		while (--addr > 0)
			printf("%02x", *(++header) & 0xff);
	}
	else
	{
		header += addr;

		while (addr && !*(--header))
			--addr;

		printf("%x", *header & 0xff);

		while (--addr > 0)
			printf("%02x", *(--header) & 0xff);
	}

	printf("\n");
}

/**
 * main - contents to another file
 * @argc: count
 * @argv: vector
 *
 * Return:0
 */
int main(int argc, const char *argv[])
{
	unsigned char buffer[18];
	unsigned int bit;
	int big_endian;
	int f;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	f = open(argv[1], O_RDONLY);
	if (f == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}

	read(f, (char *) buffer, 18);

	elf_magic(buffer);
	bit = elf_class(buffer);
	big_endian = elf_data(buffer);
	elf_version(buffer);
	elf_os(buffer);
	elf_abi(buffer);
	elf_type(buffer, big_endian);

	lseek(f, 24, SEEK_SET);
	read(f, (char *) buffer, bit / 8);

	elf_entry(buffer, bit, big_endian);

	close(f);

	return (0);
}
