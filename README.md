# elf-parser
A simple parser for ELF files format (Both types are supported ELF32 and ELF64)

## Usage of the library
~~~c
...
struct SELF elfData;

	if (PElf(argv[1]) != ELF_VALID)
		return fprintf(stderr,
			       "%s:  formatted doesn't look like an elf \n",
			       argv[0]);

	ElfStruct(&elfData);	// Get 16 bytes of information
	if (elfData.classElf != ELFCLASS64)
		return fprintf(stderr,
			       "%s is a 32 bit ELF, the parser only supports ELF 64 bits version\n",
			       argv[1]);

	puts("Elf Header :");
	// Magic header elf
	printf(" Magic:");
	for (int8_t i = 0; i < EI_NIDENT; i++)
		printf(" %02x", ElfMagic()[i]);
	puts("");		// \n
	if (elfData.elf64Header->e_version == EV_CURRENT)
		printf(" Version: %i (Current)\n",
		       elfData.elf64Header->e_version);
	else
		printf(" Version: %i \n", elfData.elf64Header->e_version);
	printf(" Entry Point: 0x%x\n", elfData.elf64Header->e_entry);
	printf(" Start of program headers: %lu\n",
	       elfData.elf64Header->e_phoff);
	printf(" Start of section headers: %lu\n",
	       elfData.elf64Header->e_shoff);
	printf(" ABI Version: 0x%x\n",
	       elfData.elf64Header->e_ident[EI_ABIVERSION]);
	printf(" Flags : 0x%x\n", elfData.elf64Header->e_flags);
	printf(" Size of this header: %i\n", elfData.elf64Header->e_ehsize);
	printf(" Size of program headers: %i\n",
	       elfData.elf64Header->e_phentsize);
	printf(" Number of program headers: %i\n",
	       elfData.elf64Header->e_phnum);
	printf(" Size of section headers: %i\n",
	       elfData.elf64Header->e_shentsize);
	printf(" Number of section headers: %i\n",
	       elfData.elf64Header->e_shnum);
...
~~~

## Information

- This project has been wrote by [VitorMob](https://github.com/VitorMob)
- And forked from here: [relf](https://github.com/VitorMob/relf)


In his words:

*This parser is just a project I'm keeping to study elf format, the features for now are: elf header*

## How to compile

~~~bash
mkdir build
cd build
cmake ..
make
~~~

## How to use the sample

~~~diff
./elf_parser ./elf_parser
+ For looking inside of
~~~

