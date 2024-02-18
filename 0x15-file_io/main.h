#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
/**
 * _strlen - string length
 * @s: the string to get the length
 *
 * Return: int the string's length
 */
int _strlen(char *s);


/**
 * closeFd - Close a file descriptor.
 * @fd: The file descirptor to close.
 */
void closeFd(int fd);


/**
 * is_elf - Checks if a file referenced by a file
 *          descriptor is an ELF file.
 *
 * @fd: The open file descriptor of the file to test.
 *
 * Return: 1 if the file is an ELF otherwise 0.
 */
char is_elf(int fd);


/**
 * print_elf_header - Prints the header of the ELF file
 *                    referenced by the file descriptor fd.
 * @fd: The file descriptor.
 */
void print_elf_header(int fd);


/**
 * is_elf - Checks if a file referenced by a file
 *          descriptor is an ELF file.
 *
 * @fd: The open file descriptor of the file to test.
 *
 * Return: 1 if the file is an ELF otherwise 0.
 */
char is_elf(int fd);


/**
 * print_elf_header - Prints the header of the ELF file
 *                    referenced by the file descriptor fd.
 * @fd: The file descriptor.
 */
void print_elf_header(int fd);


/**
 * print_elf_magic - Prints the ELF magic number from
 *                   the header.
 * @headers: The ELF file header.
 */
void print_elf_magic(const char *headers);

/**
 * print_elf_class - Prints the class of the ELF file
 *                   (32-bit or 64-bit).
 * @headers: The ELF file header.
 */
void print_elf_class(const char *headers);

/**
 * print_elf_data - Prints the endianness of the data
 *                  in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_data(const char *headers);

/**
 * print_elf_version - Prints the version of the ELF
 *                     file format.
 * @headers: The ELF file header.
 */
void print_elf_version(const char *headers);

/**
 * print_elf_os_abi - Prints the operating system and
 *                    ABI of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_os_abi(const char *headers);

/**
 * print_elf_abi_version - Prints the ABI version of
 *                         the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_abi_version(const char *headers);

/**
 * print_elf_type - Prints the type of the ELF file
 *                  (e.g., executable, shared object).
 * @headers: The ELF file header.
 */
void print_elf_type(const char *headers);

/**
 * print_elf_machine - Prints the machine architecture
 *                     of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_machine(const char *headers);

/**
 * print_elf_version_1 - Prints the version 1 field from
 *                       the ELF file header.
 * @headers: The ELF file header.
 */
void print_elf_version_1(const char *headers);

/**
 * print_elf_entry_point - Prints the entry point address
 *                         of the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_entry_point(const char *headers);

/**
 * print_elf_start_of_prog - Prints the start of program
 *                           headers in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_start_of_prog(const char *headers);

/**
 * print_elf_start_of_section - Prints the start of section
 *                              headers in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_start_of_section(const char *headers);

/**
 * print_elf_flags - Prints the flags field from the ELF
 *                   file header.
 * @headers: The ELF file header.
 */
void print_elf_flags(const char *headers);

/**
 * print_elf_size - Prints the size of the ELF file header.
 * @headers: The ELF file header.
 */
void print_elf_size(const char *headers);

/**
 * print_elf_size_of_prog_headers - Prints the size of
 *                                  program headers in
 *                                  the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_size_of_prog_headers(const char *headers);

/**
 * print_elf_num_prog_headers - Prints the number of program
 *                              headers in the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_num_prog_headers(const char *headers);

/**
 * print_elf_size_of_section_headers - Prints the size of
 *                                     section headers in
 *                                     the ELF file.
 * @headers: The ELF file header.
 */
void print_elf_size_of_section_headers(const char *headers);

/**
 * print_elf_num_section_headers - Prints the number of
 *                                 section headers in the
 *                                 ELF file.
 * @headers: The ELF file header.
 */
void print_elf_num_section_headers(const char *headers);

/**
 * print_elf_num_section_header_tb_idx - Prints the section
 *                                       header string table
 *                                       index from the ELF
 *                                       file header.
 * @headers: The ELF file header.
 */
void print_elf_num_section_header_tb_idx(const char *headers);



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
);

const char *OS_ABI[19] = {
	"UNIX - System V",
	"UNIX - HP-UX",
	"UNIX - NetBSD",
	"UNIX - Linux",
	"UNIX - GNU Hurd",
	NULL,
	"UNIX - Solaris",
	"UNIX - AIX (Monterey)",
	"UNIX - IRIX",
	"UNIX - FreeBSD",
	"UNIX - Tru64",
	"UNIX - Novell Modesto",
	"UNIX - OpenBSD",
	"UNIX - OpenVMS",
	"UNIX - NonStop Kernel",
	"UNIX - AROS",
	"UNIX - FenixOS",
	"UNIX - Nuxi CloudABI",
	"UNIX - Stratus Technologies OpenVOS",
};


const char *OBJ_FILE_TYPES[5] = {
	"NONE (Unknown file)",
	"REL (Relocatable file)",
	"EXEC (Executable file)",
	"DYN (Shared object file)",
	"CORE (Core file)",
};

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
const char *get_machine_architecture(int machine);

#endif /* MAIN_H  */
