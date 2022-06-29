/**
* @file elf.h
* @author VitorMob
* @date 13 Mar 2022
* @copyright 2022 VitorMob
* @brief simple parser for analisys binary ELF for student
*/

#pragma once

#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>
#include <elf.h>

#include <parser/elferr.h>

struct SELF {
	Elf32_Ehdr *elf32Header;
	Elf64_Ehdr *elf64Header;
	int classElf;
};

//=================== functions usage for parser elf ===================
int LookELF(const char *);		// pass elf for analisys
void ElfStruct(struct SELF *);	// get header information elf
char *ElfMagic();				// return pointer array magic elf
void EndELF();					// finalize all resources used for parser the elf structure
