#include <stdio.h>
#include "main.h"
#include <elf.h>

/**
 * main - Displays the information contained in the ELF header
 *        at the start of an ELF file.
 *
 * @argc: Number of Arguments passed to the program.
 * @argv: Arguments.
 *
 * Return: 0 on success and 98 on failure.
 */
int main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename.\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Unable to open the file.\n");
		exit(98);
	}

	if (is_elf(fd))
		print_elf_header(fd);
	else
	{
		dprintf(STDERR_FILENO, "The file is not an ELF.\n");
		exit(98);
	}

	exit(EXIT_SUCCESS);
}

/**
 * is_elf - Checks if a file referenced by a file
 *          descriptor is an ELF file.
 *
 * @fd: The open file descriptor of the file to test.
 *
 * Return: 1 if the file is an ELF otherwise 0.
 */
char is_elf(int fd)
{
	char magic[4];

	if (read(fd, magic, 4) == -1)
	{
		dprintf(STDERR_FILENO, "Error reading file headers.\n");
		exit(98);
	}

	return (magic[0] == 0x7f && magic[1] == 0x45 &&
			magic[2] == 0x4c && magic[3] == 0x46);
}



/**
 * print_elf_header - Prints the header of the ELF file
 *                    referenced by the file descriptor fd.
 * @fd: The file descriptor.
 */
void print_elf_header(int fd)
{
	const int ELF_HEADER_SIZE = 64;
	char headers[64];

	lseek(fd, 0, SEEK_SET);
	if (read(fd, headers, ELF_HEADER_SIZE) != ELF_HEADER_SIZE)
	{
		dprintf(STDERR_FILENO, "Unable to read the file header.\n");
		exit(98);
	}

	printf("ELF Header:\n");
	print_elf_magic(headers);
	print_elf_class(headers);
	print_elf_data(headers);
	print_elf_version(headers);
	print_elf_os_abi(headers);
	print_elf_abi_version(headers);
	print_elf_type(headers);
	print_elf_machine(headers);
	print_elf_version_1(headers);
	print_elf_entry_point(headers);
	print_elf_start_of_prog(headers);
	print_elf_start_of_section(headers);
	print_elf_flags(headers);
	print_elf_size(headers);
	print_elf_size_of_prog_headers(headers);
	print_elf_num_prog_headers(headers);
	print_elf_size_of_section_headers(headers);
	print_elf_num_section_headers(headers);
	print_elf_num_section_header_tb_idx(headers);
}


/**
 * print_elf_magic - Prints the ELF magic number from the header.
 * @headers: The ELF file header.
 */
void print_elf_magic(const char *headers)
{
	int i = 0;

	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x%c", headers[i], i == 15 ? '\n' : ' ');
}

/**
 * print_elf_class - Prints the class of the ELF file (32-bit or 64-bit).
 * @headers: The ELF file header.
 */
void print_elf_class(const char *headers)
{
	printf("  Class:                             ");
	if (headers[4] == 1)
		printf("ELF32\n");
	else if (headers[4] == 2)
		printf("ELF64\n");
	else
		printf("INVALID");
}

/**
 * print_elf_data - Prints the endianness of the data in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_data(const char *headers)
{
	printf("  Data:                              ");
	if (headers[5] == 1)
		printf("2's complement, little endian\n");
	else if (headers[5] == 2)
		printf("2's complement, big endian\n");
}

/**
 * print_elf_version - Prints the version of the ELF file format.
 * @headers: The ELF file header.
 */
void print_elf_version(const char *headers)
{
	printf("  Version:                           ");
	printf("%d%s\n", headers[6], headers[6] == 1 ? " (current)" : "");
}

/**
 * print_elf_os_abi - Prints the operating system and ABI of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_os_abi(const char *headers)
{
	printf("  OS/ABI:                            ");
	if (headers[7] > 0x12)
		printf("INVALID\n");
	else
		printf("%s\n", OS_ABI[headers[7] & 0xFF]);
}

/**
 * print_elf_abi_version - Prints the ABI version of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_abi_version(const char *headers)
{
	printf("  ABI Version:                       ");
	printf("%d\n", headers[8] & 0xFF);
}

/**
 * print_elf_type - Prints the type of the ELF file
 *                  (e.g., executable, shared object).
 * @headers: The ELF file header.
 */
void print_elf_type(const char *headers)
{
	unsigned int type = 0;

	type = read_bytes(headers, 16, 17);
	printf("  Type:                              ");
	printf("%s\n", OBJ_FILE_TYPES[type]);
}

/**
 * print_elf_machine - Prints the machine architecture of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_machine(const char *headers)
{
	unsigned int e_machine;

	e_machine = read_bytes(headers, 18, 19);
	printf("  Machine:                           ");
	printf("%s\n", get_machine_architecture(e_machine));
}

/**
 * print_elf_version_1 - Prints the version 1 field from the
 *                       ELF file header.
 * @headers: The ELF file header.
 */
void print_elf_version_1(const char *headers)
{
	printf("  Version:                           ");
	printf("0x%01x\n", read_bytes(headers, 20, 23));
}

/**
 * print_elf_entry_point - Prints the entry point address
 *                         of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_entry_point(const char *headers)
{
	int addr;

	addr = headers[4] == 1 ?
		read_bytes(headers, 24, 27) :
		read_bytes(headers, 24, 31);

	printf("  Entry point address:               ");
	printf("0x%0x\n", addr);
}

/**
 * print_elf_start_of_prog - Prints the start of program headers
 *                           in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_start_of_prog(const char *headers)
{
	int addr;

	addr = headers[4] == 1 ?
		read_bytes(headers, 28, 31) :
		read_bytes(headers, 32, 39);
	printf("  Start of program headers:          ");
	printf("%d (bytes into file)\n", addr);
}

/**
 * print_elf_start_of_section - Prints the start of section headers
 *                              in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_start_of_section(const char *headers)
{
	int addr;

	addr = headers[4] == 1 ?
		read_bytes(headers, 32, 35) :
		read_bytes(headers, 40, 47);
	printf("  Start of section headers:          ");
	printf("%d (bytes into file)\n", addr);
}


/**
 * print_elf_flags - Prints the flags field from the ELF file header.
 * @headers: The ELF file header.
 */
void print_elf_flags(const char *headers)
{
	int flags;

	flags = headers[4] == 1 ?
		read_bytes(headers, 36, 39) :
		read_bytes(headers, 48, 51);
	printf("  Flags:                             ");
	printf("0x%x\n", flags);
}

/**
 * print_elf_size - Prints the size of the ELF file header.
 * @headers: The ELF file header.
 */
void print_elf_size(const char *headers)
{
	int size;

	size = headers[4] == 1 ?
		read_bytes(headers, 40, 41) :
		read_bytes(headers, 52, 53);

	printf("  Size of this header:               ");
	printf("%d (bytes)\n", size);
}

/**
 * print_elf_size_of_prog_headers - Prints the size of program
 *                                  headers in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_size_of_prog_headers(const char *headers)
{
	int size;

	size = headers[4] == 1 ?
		read_bytes(headers, 42, 43) :
		read_bytes(headers, 54, 55);

	printf("  Size of program headers:           ");
	printf("%d (bytes)\n", size);
}

/**
 * print_elf_num_prog_headers - Prints the number of program headers
 *                              in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_num_prog_headers(const char *headers)
{
	int count;

	count = headers[4] == 1 ?
		read_bytes(headers, 44, 45) :
		read_bytes(headers, 56, 57);
	printf("  Number of program headers:         ");
	printf("%d\n", count);
}

/**
 * print_elf_size_of_section_headers - Prints the size of section headers
 *                                     in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_size_of_section_headers(const char *headers)
{
	int count;

	count = headers[4] == 1 ?
		read_bytes(headers, 46, 47) :
		read_bytes(headers, 58, 59);

	printf("  Size of section headers:           ");
	printf("%d (bytes)\n", count);
}


/**
 * print_elf_num_section_headers - Prints the number of section headers
 *                                 in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_num_section_headers(const char *headers)
{
	int count;

	count = headers[4] == 1 ?
		read_bytes(headers, 48, 49) :
		read_bytes(headers, 60, 61);

	printf("  Number of section headers:         ");
	printf("%d\n", count);
}

/**
 * print_elf_num_section_header_tb_idx - Prints the section header string
 *                                       table index from the ELF file
 *                                       header.
 * @headers: The ELF file header.
 */
void print_elf_num_section_header_tb_idx(const char *headers)
{
	int value;

	value = headers[4] == 1 ?
		read_bytes(headers, 50, 51) :
		read_bytes(headers, 62, 63);

	printf("  Section header string table index: ");
	printf("%d\n", value);
}


/**
 * read_bytes - Reads `to - from` bytes from the headers
 *              array, taking into account the endianness.
 * @headers: The elf header data.
 * @from: The first index to read (inclusif).
 * @to: The last index to read (inclusif).
 *
 * Return: An int representing the read data.
 */
unsigned int read_bytes(
		const char *headers,
		unsigned int from,
		unsigned int to
		)
{
	unsigned int value = 0, i;

	i = from;
	for (i = 0; i <= to - from; i++)
	{
		value <<= 8;
		if (headers[5] == 1)
			value |= headers[to - i] & 0xFF;
		else
			value |= headers[from + i] & 0xFF;
	}

	return (value);
}


/**
 * get_machine_architecture - Returns the corresponding machine
 *                            architecture string based on the number.
 *
 * @machine: The number representing the architecture
 *           (e.g., ELFOSABI_SYSV).
 *
 * Return: A pointer to a string representing the human-readable
 *         machine architecture. Returns "An unknown machine"
 *         for unsupported machine numbers.
 */
const char *get_machine_architecture(int machine)
{
	switch (machine)
	{
		case EM_NONE: return "An unknown machine";
		case EM_M32: return "AT&T WE 32100";
		case EM_SPARC: return "Sun Microsystems SPARC";
		case EM_386: return "Intel 80386";
		case EM_68K: return "Motorola 68000";
		case EM_88K: return "Motorola 88000";
		case EM_860: return "Intel 80860";
		case EM_MIPS: return "MIPS RS3000 (big-endian only)";
		case EM_PARISC: return "HP/PA";
		case EM_SPARC32PLUS: return "SPARC with enhanced instruction set";
		case EM_PPC: return "PowerPC";
		case EM_PPC64: return "PowerPC 64-bit";
		case EM_S390: return "IBM S/390";
		case EM_ARM: return "Advanced RISC Machines";
		case EM_SH: return "Renesas SuperH";
		case EM_SPARCV9: return "SPARC v9 64-bit";
		case EM_IA_64: return "Intel Itanium";
		case EM_X86_64: return "Advanced Micro Devices x86-64";
		case EM_VAX: return "DEC Vax";
		default: return "An unknown machine";
	}
}
