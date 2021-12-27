#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

#include "mu-mips.h"

uint32_t ins_hold = 0x0;
bool end_p = false;
int c = 0;
int forward=0;
int jmpBy = 0;
int ENABLE_FORWARDING = 0; // forwarding is off by default
bool same = false;
bool branch;
uint32_t ALU=0x0;


char * getReg(int temp){
	if(temp == 0){
		return "$zero";
	}else if(temp == 1){
		return "$at";
	}else if(temp == 2){
		return "$v0";
	}
	else if(temp == 3){
		return "$v1";
	}
	else if(temp == 4){
		return "$a0";
	}
	else if(temp == 5){
		return "$a1";
	}
	else if(temp == 6){
		return "$a2";
	}
	else if(temp == 7){
		return "$a3";
	}
	else if(temp == 8){
		return "$t0";
	}
	else if(temp == 9){
		return "$t1";
	}
	else if(temp == 10){
		return "$t2";
	}
	else if(temp == 11){
		return "$t3";
	}
	else if(temp == 12){
		return "$t4";
	}
	else if(temp == 13){
		return "$t5";
	}
	else if(temp == 14){
		return "$t6";
	}
	else if(temp == 15){
		return "$t7";
	}
	else if(temp == 16){
		return "$s0";
	}
	else if(temp == 17){
		return "$s1";
	}
	else if(temp == 18){
		return "$s2";
	}
	else if(temp == 19){
		return "$s3";
	}
	else if(temp == 20){
		return "$s4";
	}
	else if(temp == 21){
		return "$s5";
	}
	else if(temp == 22){
		return "$s6";
	}
	else if(temp == 23){
		return "$s7";
	}
	else if(temp == 24){
		return "$t8";
	}
	else if(temp == 25){
		return "$t9";
	}
	else if(temp == 26){
		return "$k0";
	}
	else if(temp == 27){
		return "$k1";
	}
	else if(temp == 28){
		return "$gp";
	}
	else if(temp == 29){
		return "$sp";
	}
	else if(temp == 30){
		return "$fp";
	}
	else if(temp == 31){
		return "$ra";
	}
	return NULL;
}




/***************************************************************/
/* Print out a list of commands available                                                                  */
/***************************************************************/
void help() {        
	printf("------------------------------------------------------------------\n\n");
	printf("\t**********MU-MIPS Help MENU**********\n\n");
	printf("sim\t-- simulate program to completion \n");
	printf("run <n>\t-- simulate program for <n> instructions\n");
	printf("rdump\t-- dump register values\n");
	printf("reset\t-- clears all registers/memory and re-loads the program\n");
	printf("input <reg> <val>\t-- set GPR <reg> to <val>\n");
	printf("mdump <start> <stop>\t-- dump memory from <start> to <stop> address\n");
	printf("high <val>\t-- set the HI register to <val>\n");
	printf("low <val>\t-- set the LO register to <val>\n");
	printf("print\t-- print the program loaded into memory\n");
	printf("show\t-- print the current content of the pipeline registers\n");
	printf("?\t-- display help menu\n");
	printf("quit\t-- exit the simulator\n\n");
	printf("------------------------------------------------------------------\n\n");
}

/***************************************************************/
/* Read a 32-bit word from memory                                                                            */
/***************************************************************/
uint32_t mem_read_32(uint32_t address)
{
	int i;
	for (i = 0; i < NUM_MEM_REGION; i++) {
		if ( (address >= MEM_REGIONS[i].begin) &&  ( address <= MEM_REGIONS[i].end) ) {
			uint32_t offset = address - MEM_REGIONS[i].begin;
			return (MEM_REGIONS[i].mem[offset+3] << 24) |
					(MEM_REGIONS[i].mem[offset+2] << 16) |
					(MEM_REGIONS[i].mem[offset+1] <<  8) |
					(MEM_REGIONS[i].mem[offset+0] <<  0);
		}
	}
	return 0;
}

/***************************************************************/
/* Write a 32-bit word to memory                                                                                */
/***************************************************************/
void mem_write_32(uint32_t address, uint32_t value)
{
	int i;
	uint32_t offset;
	for (i = 0; i < NUM_MEM_REGION; i++) {
		if ( (address >= MEM_REGIONS[i].begin) && (address <= MEM_REGIONS[i].end) ) {
			offset = address - MEM_REGIONS[i].begin;

			MEM_REGIONS[i].mem[offset+3] = (value >> 24) & 0xFF;
			MEM_REGIONS[i].mem[offset+2] = (value >> 16) & 0xFF;
			MEM_REGIONS[i].mem[offset+1] = (value >>  8) & 0xFF;
			MEM_REGIONS[i].mem[offset+0] = (value >>  0) & 0xFF;
		}
	}
}

/***************************************************************/
/* Execute one cycle                                                                                                              */
/***************************************************************/
void cycle() {                                                
	handle_pipeline();
	//CURRENT_STATE = NEXT_STATE;
	CYCLE_COUNT++;
}

/***************************************************************/
/* Simulate MIPS for n cycles                                                                                       */
/***************************************************************/
void run(int num_cycles) {                                      
	
	if (RUN_FLAG == FALSE) {
		printf("Simulation Stopped\n\n");
		return;
	}

	printf("Running simulator for %d cycles...\n\n", num_cycles);
	int i;
	for (i = 0; i < num_cycles; i++) {
		if (RUN_FLAG == FALSE) {
			printf("Simulation Stopped.\n\n");
			break;
		}
		cycle();
	}
}

/***************************************************************/
/* simulate to completion                                                                                               */
/***************************************************************/
void runAll() {                                                     
	if (RUN_FLAG == FALSE) {
		printf("Simulation Stopped.\n\n");
		return;
	}

	printf("Simulation Started...\n\n");
	while (RUN_FLAG){
		cycle();
	}
	printf("Simulation Finished.\n\n");
}

/***************************************************************/ 
/* Dump a word-aligned region of memory to the terminal                              */
/***************************************************************/
void mdump(uint32_t start, uint32_t stop) {          
	uint32_t address;

	printf("-------------------------------------------------------------\n");
	printf("Memory content [0x%08x..0x%08x] :\n", start, stop);
	printf("-------------------------------------------------------------\n");
	printf("\t[Address in Hex (Dec) ]\t[Value]\n");
	for (address = start; address <= stop; address += 4){
		printf("\t0x%08x (%d) :\t0x%08x\n", address, address, mem_read_32(address));
	}
	printf("\n");
}

/***************************************************************/
/* Dump current values of registers to the teminal                                              */   
/***************************************************************/
void rdump() {                               
	int i; 
	printf("-------------------------------------\n");
	printf("Dumping Register Content\n");
	printf("-------------------------------------\n");
	printf("# Instructions Executed\t: %u\n", INSTRUCTION_COUNT);
	printf("# Cycles Executed\t: %u\n", CYCLE_COUNT);
	printf("PC\t: 0x%08x\n", CURRENT_STATE.PC);
	printf("-------------------------------------\n");
	printf("[Register]\t[Value]\n");
	printf("-------------------------------------\n");
	for (i = 0; i < MIPS_REGS; i++){
		printf("[R%d]\t: 0x%08x\n", i, CURRENT_STATE.REGS[i]);
	}
	printf("-------------------------------------\n");
	printf("[HI]\t: 0x%08x\n", CURRENT_STATE.HI);
	printf("[LO]\t: 0x%08x\n", CURRENT_STATE.LO);
	printf("-------------------------------------\n");
}

/***************************************************************/
/* Read a command from standard input.                                                               */  
/***************************************************************/
void handle_command() {                         
	char buffer[20];
	uint32_t start, stop, cycles;
	uint32_t register_no;
	int register_value;
	int hi_reg_value, lo_reg_value;

	printf("MU-MIPS SIM:> ");

	if (scanf("%s", buffer) == EOF){
		exit(0);
	}

	switch(buffer[0]) {
		case 'S':
		case 's':
			if (buffer[1] == 'h' || buffer[1] == 'H'){
				show_pipeline();
			}else {
				runAll(); 
			}
			break;
		case 'M':
		case 'm':
			if (scanf("%x %x", &start, &stop) != 2){
				break;
			}
			mdump(start, stop);
			break;
		case '?':
			help();
			break;
		case 'Q':
		case 'q':
			printf("**************************\n");
			printf("Exiting MU-MIPS! Good Bye...\n");
			printf("**************************\n");
			exit(0);
		case 'R':
		case 'r':
			if (buffer[1] == 'd' || buffer[1] == 'D'){
				rdump();
			}else if(buffer[1] == 'e' || buffer[1] == 'E'){
				reset();
			}
			else {
				if (scanf("%d", &cycles) != 1) {
					break;
				}
				run(cycles);
			}
			break;
		case 'I':
		case 'i':
			if (scanf("%u %i", &register_no, &register_value) != 2){
				break;
			}
			CURRENT_STATE.REGS[register_no] = register_value;
			NEXT_STATE.REGS[register_no] = register_value;
			break;
		case 'H':
		case 'h':
			if (scanf("%i", &hi_reg_value) != 1){
				break;
			}
			CURRENT_STATE.HI = hi_reg_value; 
			NEXT_STATE.HI = hi_reg_value; 
			break;
		case 'L':
		case 'l':
			if (scanf("%i", &lo_reg_value) != 1){
				break;
			}
			CURRENT_STATE.LO = lo_reg_value;
			NEXT_STATE.LO = lo_reg_value;
			break;
		case 'P':
		case 'p':
			print_program(); 
			break;
		case 'f':
		case 'F':
			if(scanf("%d",&ENABLE_FORWARDING)!=1){
				break;
			}
			ENABLE_FORWARDING == 0 ? printf("Forwarding OFF\n") : printf("Forwarding ON\n");
			break;
		default:
			printf("Invalid Command.\n");
			break;
	}
}

/***************************************************************/
/* reset registers/memory and reload program                                                    */
/***************************************************************/
void reset() {   
	int i;
	/*reset registers*/
	for (i = 0; i < MIPS_REGS; i++){
		CURRENT_STATE.REGS[i] = 0;
	}
	CURRENT_STATE.HI = 0;
	CURRENT_STATE.LO = 0;
	
	for (i = 0; i < NUM_MEM_REGION; i++) {
		uint32_t region_size = MEM_REGIONS[i].end - MEM_REGIONS[i].begin + 1;
		memset(MEM_REGIONS[i].mem, 0, region_size);
	}
	
	/*load program*/
	load_program();
	
	/*reset PC*/
	INSTRUCTION_COUNT = 0;
	CURRENT_STATE.PC =  MEM_TEXT_BEGIN;
	NEXT_STATE = CURRENT_STATE;
	RUN_FLAG = TRUE;
}

/***************************************************************/
/* Allocate and set memory to zero                                                                            */
/***************************************************************/
void init_memory() {                                           
	int i;
	for (i = 0; i < NUM_MEM_REGION; i++) {
		uint32_t region_size = MEM_REGIONS[i].end - MEM_REGIONS[i].begin + 1;
		MEM_REGIONS[i].mem = malloc(region_size);
		memset(MEM_REGIONS[i].mem, 0, region_size);
	}
}

/**************************************************************/
/* load program into memory                                                                                      */
/**************************************************************/
void load_program() {                   
	FILE * fp;
	int i, word, j;
	uint32_t address;

	/* Open program file. */
	fp = fopen(prog_file, "r");
	if (fp == NULL) {
		printf("Error: Can't open program file %s\n", prog_file);
		exit(-1);
	}

	/* Read in the program. */

	i = 0;
	j=0;
	while( fscanf(fp, "%x\n", &word) != EOF ) {
		address = MEM_TEXT_BEGIN + i;
		mem_write_32(address, word);
		printf("%d. writing 0x%08x into address 0x%08x (%d)\n", j, word, address, address);
		i += 4;
		j++;
	}
	PROGRAM_SIZE = i/4;
	printf("Program loaded into memory.\n%d words written into memory.\n\n", PROGRAM_SIZE);
	fclose(fp);
}

/************************************************************/
/* maintain the pipeline                                                                                           */ 
/************************************************************/
void handle_pipeline()
{
	/*INSTRUCTION_COUNT should be incremented when instruction is done*/
	/*Since we do not have branch/jump instructions, INSTRUCTION_COUNT should be incremented in WB stage */
	
	WB();
	MEM();
	EX();
	ID();
	IF();
	
}

/************************************************************/
/* writeback (WB) pipeline stage:                                                                          */ 
/************************************************************/
void WB() //MEM_WB
{
	if(MEM_WB.wb == 1){
		switch(MEM_WB.type){
			case 0: // R
				//print_instruction(MEM_WB.IR);
				//printf("\tCase 0, Register=%d, Valve=%x\n", (MEM_WB.IR & 0x001F0000) >> 16, MEM_WB.ALUOutput);
				CURRENT_STATE.REGS[MEM_WB.RD] = MEM_WB.ALUOutput;
				break;
			case 1: // i
				//printf("Case 1\nRegister=%d\n", (MEM_WB.IR & 0x001F0000) >> 16);
				CURRENT_STATE.REGS[MEM_WB.RT] = MEM_WB.ALUOutput;
				break;
			case 2: // LOAD
				//printf("WB STAGE:\nRD=%d\nLMD=%x\n",MEM_WB.RD, MEM_WB.ALUOutput);
				CURRENT_STATE.REGS[MEM_WB.RT] = MEM_WB.LMD;
				break;
			case 4:
				CURRENT_STATE.HI = MEM_WB.HI;
				CURRENT_STATE.LO = MEM_WB.LO;
				break;
			case 100:
				// "Skip case"
				break;
		}
		//CURRENT_STATE.HI = MEM_WB.HI;
		//CURRENT_STATE.LO = MEM_WB.LO;
		
		
		if((IF_ID.IR != 0) && (MEM_WB.IR == ins_hold) && !ENABLE_FORWARDING){
			IF_ID.id = 1;
			EX_MEM.RT = 300;
			EX_MEM.RD = 300;
			EX_MEM.RS = 300;
			MEM_WB.RegWrite = 0;

			//CURRENT_STATE.PC = CURRENT_STATE.PC-4;

		}
		if(branch){
			IF_ID.id = 1;
		}
		if((forward == 1) && ENABLE_FORWARDING){
			ALU=MEM_WB.ALUOutput;
		}
	}
		
	//INSTRUCTION_COUNT++;
}

/************************************************************/
/* memory access (MEM) pipeline stage:                                                          */ 
/************************************************************/
void MEM() // EX_MEM > MEM_WB
{
	if(EX_MEM.m == 1){
		switch(EX_MEM.opcode){
			case 0x00000020:
				// LB
				if(EX_MEM.left){
					printf("# LB\n");
					EX_MEM.LMD = mem_read_32(EX_MEM.ALUOutput) & 0x000000FF;
					EX_MEM.LMD = (EX_MEM.LMD & 0x00000080) == 0x80 ? 0xFFFFFF00 | EX_MEM.LMD : EX_MEM.LMD;
				}
				break;	
			case 0x00000021:
				if(EX_MEM.left){
					printf("# LH\n");
					EX_MEM.LMD = mem_read_32(EX_MEM.ALUOutput) & 0x0000FFFF;
					EX_MEM.LMD = (EX_MEM.LMD & 0x00008000) == 0x8000 ? 0xFFFF0000 | EX_MEM.LMD : EX_MEM.LMD;	
				}
				break;
			case 0x00000023:
				if(EX_MEM.left){
					printf("# LW\n");
					EX_MEM.LMD = mem_read_32(EX_MEM.ALUOutput);
					//printf("MEM Stage:\nLocation=%x\n LW LMD=%x\n",EX_MEM.ALUOutput,EX_MEM.LMD);
				}
				break;
			case 0x0000002B:
				// SW
				printf("# SW\n");
				//printf("offset=%d\nbase=%d\nvalue=%x\n[rt]=%x\n", offset, base, location, value);
				mem_write_32(EX_MEM.ALUOutput, EX_MEM.B);
				break;
			case 0x00000028:
				// SB
				printf("# SB\n");
				//printf("offset=%d\nbase=%d\nvalue=%d\nrt=%d\n", offset, base, value, rt);
				mem_write_32(EX_MEM.ALUOutput, EX_MEM.B & 0x000000FF);
				break;

			case 0x00000029:
				// SH
				printf("# SH\n");
				//printf("offset=%d\nbase=%d\nvalue=%d\nrt=%d\n", offset, base, value, rt);
				mem_write_32(EX_MEM.ALUOutput, EX_MEM.B & 0x0000FFFF);
				break;
		}
		
		
	}
	MEM_WB.LMD = EX_MEM.LMD;
	MEM_WB.ALUOutput = EX_MEM.ALUOutput;
	MEM_WB.IR = EX_MEM.IR;
	MEM_WB.HI = EX_MEM.HI;
	MEM_WB.LO = EX_MEM.LO;
	MEM_WB.type = EX_MEM.type;
	MEM_WB.RS = EX_MEM.RS;
	MEM_WB.RT = EX_MEM.RT;
	MEM_WB.RD = EX_MEM.RD;
	MEM_WB.RegWrite = EX_MEM.RegWrite;
	MEM_WB.wb = EX_MEM.wb;
	// if forwarding is enabled, and a load-use stall occurred, this just stops the stalling
	if(ENABLE_FORWARDING){
		IF_ID.id = 1;
		EX_MEM.RT = 300;
		EX_MEM.RD = 300;
		EX_MEM.RS = 300;
		MEM_WB.RegWrite = 0;
	}

}

/************************************************************/
/* execution (EX) pipeline stage:                                                                          */ 
/************************************************************/
void EX() //ID_EX > EX_MEM
{
	if(ID_EX.ex == 1 && !branch){
		uint32_t target, value;
		uint32_t highBits = 0xFFFFFFFF;
		int64_t temp;

		// if forwarding is enabled, the variable forward tells us which 
		// which register to forward the result into
		// 1 = RS = A
		// 2 = RT = B
		// 3 = RS = A after a load-use stall
		// 4 = RT = B after a load-use stall
		if(ENABLE_FORWARDING){
			switch(forward){
				case 1:
					printf("MEM_WB.ALUOutput=%x\n",MEM_WB.ALUOutput);
					ID_EX.A = ALU;
					break;
				case 2:
					ID_EX.B = EX_MEM.ALUOutput;
					break;
				case 3:
					ID_EX.A = EX_MEM.LMD;
					break;
				case 4:
					ID_EX.B = EX_MEM.LMD;
			}
		}

		switch(ID_EX.opcode){
			case 0x00000020: 
				// ADD
				if(ID_EX.right){ 
					printf("# ADD\n");
					ID_EX.ALUOutput = ID_EX.A + ID_EX.B;
					//printf("ADD result = %x\n",ID_EX.ALUOutput);
					ID_EX.type = 0;
					

				// LB	
				}else if(ID_EX.left){
					printf("# LB\n");
					
					value = ID_EX.A + ID_EX.imm;
					ID_EX.ALUOutput = value;
					ID_EX.type = 2;
				}
				break;
			case 0x00000021:
				// ADDU
				if(ID_EX.right){ 
					printf("# ADDU\n");
					ID_EX.ALUOutput = ID_EX.A + ID_EX.B;
					//printf("\tAfter:\n\t[rd]=0x%x\n", NEXT_STATE.REGS[rd]);
					ID_EX.type = 0;
				// LH
				}else{
					printf("# LH\n");
					
				
					value = ID_EX.A + ID_EX.imm;
					ID_EX.ALUOutput = value;
					ID_EX.type = 2;
				}
				break;
				
			case 0x00000008:
				// JR7fff
				if(IF_ID.right){
					IF_ID.id = 0;
					branch = true;
					printf("# JR\n");
					jmpBy = ID_EX.A - (CURRENT_STATE.PC);
					printf("RS=%x, jmpBy=%x\n",ID_EX.A, jmpBy);
				}
				// ADDI
				else{
					printf("# ADDI\n");
					//printf("ADDI %u %u %u\n", rs, rt, ID_EX.imm);
					ID_EX.ALUOutput = ID_EX.A + ID_EX.imm;
					ID_EX.type = 1;
					//printf("ADDI\nrs=%d\nrt=%d\nID_EX.imm=%d\n[rs]=%d\n[rt]=%d\nvalue=%d\n",rs,rt,ID_EX.imm,NEXT_STATE.REGS[rt], ID_EX.A, value);
				}
				break;
			case 0x00000009:
				// JALR
				if(ID_EX.right){
					//ID_EX.type = 0;
					IF_ID.id = 0;
					branch = true;
					printf("# JALR\n");
					//ID_EX.ALUOutput = CURRENT_STATE.PC; // ################################# <- this works with forwarding on but not off ???????????????????????????????????????
					CURRENT_STATE.REGS[ID_EX.RD] = CURRENT_STATE.PC; // already at PC+8 ###### <- this works with forwarding off but not on ???????????????????????????????????????
					jmpBy =  ID_EX.A - (CURRENT_STATE.PC);
				// ADDIU
				}else{
					printf("# ADDIU\n");
					//printf("A=%x, B=%x\n",ID_EX.A, ID_EX.imm);
					ID_EX.ALUOutput = ID_EX.A + ID_EX.imm;
					ID_EX.type = 1;
					//printf("ADDIU result=%x\n",ID_EX.ALUOutput);
				}
				break;
				
			case 0x00000022:
				//SUB
				printf("# SUB\n");
				ID_EX.ALUOutput = ID_EX.A - ID_EX.B;
				ID_EX.type = 0;
				break;
				
			case 0x00000023:
				// SUBU
				if(ID_EX.right){
					printf("# SUBU\n");
					ID_EX.ALUOutput = ID_EX.A - ID_EX.B;
					ID_EX.type = 0;

				// LW
				}else{
					printf("# LW\n");
					ID_EX.ALUOutput = ID_EX.A + ID_EX.imm;
					//printf("LW result=%x\n",ID_EX.ALUOutput);
					ID_EX.type = 2;
				}
				break;
				
			case 0x00000018:
				// MULT
				printf("# MULT\n");
				// check if previous instruction was MFHI or MFLO
				if((ID_EX.prevIns == 0x00000010) | (ID_EX.prevIns == 0x00000012)){
					printf("MULT: result is undefined.\n");
				}else{
					ID_EX.type = 4;
					temp = ID_EX.A * ID_EX.B; // temp is 64 bits
					ID_EX.HI = (temp & 0xFFFFFFFF00000000) >> 32;	// get high bits
					ID_EX.LO = (temp & 0x00000000FFFFFFFF) & 0xFFFFFFFF;	// get low bits
				}
				break;
				
			case 0x00000019:
				// MULTU 
				printf("# MULTU\n");
				// check if previous instruction was MFHI or MFLO
				if((ID_EX.prevIns == 0x00000010) | (ID_EX.prevIns == 0x00000012)){
					printf("MULTU: result is undefined.\n");
				}else{
					ID_EX.type = 4;
					temp = ID_EX.A * ID_EX.B; // temp is 64 bits
					ID_EX.HI = (temp & 0xFFFFFFFF00000000) >> 32;	// get high bits
					ID_EX.LO = temp & 0x00000000FFFFFFFF;		// get low bits
				}
				break;
				
			case 0x0000001A: 
				// DIV
				printf("# DIV\n");
				//check if previous instruction was MFHI or MFLO
				if((ID_EX.prevIns == 0x00000010) | (ID_EX.prevIns == 00000012)){
					printf("DIV: result is undefined.\n");
				}else{
					// check for division by 0
					if(ID_EX.B == 0){
						printf("DIV: cannot divide by 0.\n");
					}else{
						ID_EX.type = 4;
						ID_EX.HI = ID_EX.A / ID_EX.B; // Div = A/B
						ID_EX.LO = ID_EX.A % ID_EX.B; // REM = A%B
					}
				}
				break;
				
			case 0x0000001B: 
				// DIVU
				printf("# DIVU\n");
				//check if previous instruction was MFHI or MFLO
				if((ID_EX.prevIns == 0x00000010) | (ID_EX.prevIns == 00000012)){
					printf("DIV: result is undefined.\n");
				}else{
					// check for division by 0
					if(ID_EX.B == 0){
						printf("DIV: cannot divide by 0.\n");
					}else{
						ID_EX.type = 4;
						ID_EX.HI = ID_EX.A / ID_EX.B; // Div = A/B
						ID_EX.LO = ID_EX.A % ID_EX.B; // REM = A%B
					}
				}
				break;
				
			case 0x00000024:
				// AND
				printf("# AND\n");
				ID_EX.ALUOutput = ID_EX.A & ID_EX.B;
				//printf("AND A=%x, B=%x, result=%x\n",ID_EX.A, ID_EX.B,ID_EX.ALUOutput);
				ID_EX.type = 0;
				break;
				
			case 0x0000000C:
				// ANDI
				if(ID_EX.left){
					printf("# ANDI\n");
					ID_EX.ALUOutput = ID_EX.A & ID_EX.imm;
					ID_EX.type = 1;

				// SYSCALL
				}else{ 
					//if(CURRENT_STATE.REGS[2] = 0xA){ // check register $v0 = $2 for the value 10
						end_p = true;
					//}
				}

				break;
				
			case 0x00000025: 
				// OR
				printf("# OR\n");
				ID_EX.ALUOutput = ID_EX.A | ID_EX.B;
				ID_EX.type = 0;
				break;
				
			case 0x000000D:
				// ORI
				printf("# ORI\n");
				ID_EX.ALUOutput = ID_EX.A & ID_EX.imm;
				ID_EX.type = 1;
				break;
				
			case 0x00000026:
				// XOR
				printf("# XOR\n");
				ID_EX.ALUOutput = ID_EX.A ^ ID_EX.B;
				ID_EX.type = 0;
				break;
			
			case 0x000000E:
				// XORI
				printf("# XORI\n");
				//printf("XORI between %x and %x\n",ID_EX.A,ID_EX.imm & 0x0000FFFF);
				ID_EX.ALUOutput = ID_EX.A ^ (ID_EX.imm & 0x0000FFFF);
				ID_EX.type = 1;
				//printf("XORI result=%x\n",ID_EX.ALUOutput);
				break;
			
			case 0x00000027:
				// NOR
				printf("# NOR\n");
				ID_EX.ALUOutput = ~ (ID_EX.A | ID_EX.B);
				ID_EX.type = 0;
				break;
			
			case 0x0000002A:
				// SLT
				printf("# SLT\n");
				if(ID_EX.A < ID_EX.B){
					ID_EX.ALUOutput = 0x01;
				}
				else{
					ID_EX.ALUOutput = 0x00;
				}
				ID_EX.type = 0;
				break;
			
			case 0x0000000A:
				// SLTI
				printf("# SLTI\n");
				// sign extend (check if most significant bit is a 1)

				if(ID_EX.A < ID_EX.imm){
					ID_EX.ALUOutput = 0x01;
				}
				else{
					ID_EX.ALUOutput = 0x00;
				}
				ID_EX.type = 1;
				break;
			
			case 0x00000000:
				// BLTZ
				if(IF_ID.middle){
					printf("# BLTZ\n");
					IF_ID.imm = IF_ID.imm << 2;
					// sign extend (check if most significant bit is a 1)
					if(((IF_ID.imm & 0x00008000)>>15)){
						IF_ID.imm = IF_ID.imm | 0xFFFF0000;
					}
					if(((IF_ID.A & 0x80000000)>>31)){
						IF_ID.id = 0;
						branch = true;
						jmpBy = IF_ID.imm-8; // changed
					}

				// SLL
				}else{
					printf("# SLL\n");
					ID_EX.ALUOutput = ID_EX.B << ((ID_EX.imm = ID_EX.IR & 0x000007C0) >> 6);
					ID_EX.type = 0;
				}
				break;
			case 0x00000002:
				// SRL
				if(ID_EX.right){
					printf("# SRL\n");
					ID_EX.ALUOutput = ID_EX.B >> ((ID_EX.imm = ID_EX.IR & 0x000007C0) >> 6);
					ID_EX.type = 0;
				// J
				}else{
					IF_ID.id = 0;
					branch = true;
					printf("# J\n");
					target = ID_EX.IR & 0x03FFFFFF;
		    			target = target << 2;
					highBits = 0xF0000000 & (CURRENT_STATE.PC-8);
					jmpBy = (target | highBits);// - CURRENT_STATE.PC;
				
					// try to find the offset, so that we can jump to that address
					IF_ID.imm = jmpBy - (CURRENT_STATE.PC-8);
					jmpBy = IF_ID.imm-8;
					printf("J, at %x branching by %x to %x\n",CURRENT_STATE.PC-8, jmpBy, CURRENT_STATE.PC + jmpBy);
					//printf("target=%d[0x%x]\njmpBy=%d [0x%x]\n", CURRENT_STATE.PC, CURRENT_STATE.PC, jmpBy, jmpBy);
				}
				break;
			
			case 0x00000003:
				// JAL
				if (ID_EX.left){
					IF_ID.id = 0;
					branch = true;
					printf("# JAL\n");
					target = ID_EX.IR & 0x03FFFFFF;
					target = target << 2;
					highBits = 0xF0000000 & (CURRENT_STATE.PC-8);
					jmpBy = (target | highBits);
				
					// try to find the offset, so that we can jump to that address
					IF_ID.imm = jmpBy - (CURRENT_STATE.PC-8);
					jmpBy = IF_ID.imm-8;
					
					CURRENT_STATE.REGS[31] = CURRENT_STATE.PC;
				}				
				// SRA
				else if(ID_EX.right){
					printf("# SRA\n");

					if((ID_EX.B & 0x80000000)>>31){
						ID_EX.ALUOutput = ID_EX.B >> ((ID_EX.imm = ID_EX.IR & 0x000007C0) >> 6);
						ID_EX.ALUOutput |= 0x80000000;
					}else{
						ID_EX.ALUOutput = ID_EX.B >> ((ID_EX.imm = ID_EX.IR & 0x000007C0) >> 6);
					}
					ID_EX.type = 0;
				}
				break;

			case 0x0000000F:
				// LUI
				printf("# LUI\n");
				ID_EX.ALUOutput = (ID_EX.imm << 16) | 0x0000;
				//printf("LUI result=%x\n",ID_EX.ALUOutput);
				ID_EX.type = 1;
				break;

			case 0x0000002B:
				// SW
				printf("# SW\n");
				ID_EX.ALUOutput = ID_EX.A + ID_EX.imm;
				ID_EX.type = 3;
				//printf("SW result=%x\n",ID_EX.ALUOutput);
				//printf("ID_EX.imm=%d\nbase=%d\nvalue=%x\n[rt]=%x\n", ID_EX.imm, base, location, value);
				break;

			case 0x00000028:
				// SB
				printf("# SB\n");
				ID_EX.ALUOutput = ID_EX.A + ID_EX.imm;
				//printf("ID_EX.imm=%d\nbase=%d\nvalue=%d\nrt=%d\n", ID_EX.imm, base, value, rt);
				break;

			case 0x00000029:
				// SH
				printf("# SH\n");
				
				ID_EX.ALUOutput = ID_EX.A + ID_EX.imm;
				//printf("ID_EX.imm=%d\nbase=%d\nvalue=%d\nrt=%d\n", ID_EX.imm, base, value, rt);
				break;

			case 0x00000010:
				// MFHI
				printf("# MFHI\n");
				ID_EX.ALUOutput = ID_EX.HI;
				ID_EX.type = 0;
				break;

			case 0x00000012:
				// MFLO
				printf("# MFLO\n");
				ID_EX.ALUOutput = ID_EX.LO;
				ID_EX.type = 0;
				break;

			case 0x00000011:
				// MTHI
				printf("# MTHI\n");
				ID_EX.HI = ID_EX.A;
				ID_EX.type = 4;
				break;

			case 0x00000013:
				// MTLO
				printf("# MTLO\n");
				ID_EX.type = 4;
				ID_EX.LO = ID_EX.A;
				break;
			case 0x00000004:
				// BEQ 
				printf("# BEQ\n");
				//Shift left by 2
				ID_EX.imm = ID_EX.imm << 2;
				// sign extend (check if most significant bit is a 1)
				if(((ID_EX.imm & 0x00008000)>>15)){
					ID_EX.imm = ID_EX.imm | 0xFFFF0000;
				}
				if(ID_EX.A == ID_EX.B){
					printf("BEQ is equal, at %x branching by %x to %x\n",CURRENT_STATE.PC-8,ID_EX.imm, CURRENT_STATE.PC + ID_EX.imm-8);
					IF_ID.id = 0;
					branch = true;
					jmpBy = ID_EX.imm-8;
				}
				break;

			case 0x00000005:
				// BNE
				printf("# BNE\n");

				ID_EX.imm = ID_EX.imm << 2;
				if(((ID_EX.imm & 0x00008000)>>15)){
					ID_EX.imm = ID_EX.imm | 0xFFFF0000;
				}
				if(ID_EX.A != ID_EX.B){
					printf("BNE is not equal, at %x branching by %x to %x\n",CURRENT_STATE.PC,ID_EX.imm, CURRENT_STATE.PC - 8 + ID_EX.imm);
					IF_ID.id = 0;
					branch = true;
					jmpBy = ID_EX.imm-8;
				}
				break;

			case 0x00000006:
				// BLEZ
				printf("# BLEZ\n");
				ID_EX.imm = ID_EX.imm << 2;
				if(((ID_EX.imm & 0x00008000)>>15)){
					ID_EX.imm = ID_EX.imm | 0xFFFF0000;
				}
				if(((ID_EX.A & 0x80000000)>>31) || (ID_EX.A == 0x00)){
					IF_ID.id = 0;
					branch = true;
					jmpBy = ID_EX.imm-8;
				}
				break;

			case 0x00000001:
				// BGEZ
				printf("# BGEZ\n");
				ID_EX.imm = ID_EX.imm << 2;
				// sign extend (check if most significant bit is a 1)
				if(((ID_EX.imm & 0x00008000)>>15)){
					ID_EX.imm = ID_EX.imm | 0xFFFF0000;
				}
				if(((ID_EX.A & 0x80000000)>>31) == 0x0 ){
					IF_ID.id = 0;
					branch = true;
					jmpBy = ID_EX.imm-8;
				}
				break;

			case 0x00000007:
				// BGTZ
				printf("# BGTZ\n");
				ID_EX.imm = ID_EX.imm << 2;
				// sign extend (check if most significant bit is a 1)
				if(((ID_EX.imm & 0x00008000)>>15)){
					ID_EX.imm = ID_EX.imm | 0xFFFF0000;
				}
				if(((ID_EX.A & 0x80000000)>>31) == 0x0 && (ID_EX.A != 0x00)){
					IF_ID.id = 0;
					branch = true;
					jmpBy = ID_EX.imm-8;
				}
				break;

			default:
				// default
				printf("default\n");
				break;

		}
		if((ID_EX.type == 0) || (ID_EX.type == 1) || (ID_EX.type == 2) || (ID_EX.type == 4)){
			EX_MEM.RegWrite = 1;
		}else{
			EX_MEM.RegWrite = 0;
		}
	
		//printf("ALUOutput=%x\n",ID_EX.ALUOutput);
		EX_MEM.IR = ID_EX.IR;
		EX_MEM.opcode = ID_EX.opcode;
		EX_MEM.type = ID_EX.type;
		EX_MEM.ALUOutput = ID_EX.ALUOutput;
		EX_MEM.HI = ID_EX.HI;
		EX_MEM.LO = ID_EX.LO;
		EX_MEM.left = ID_EX.left;
		EX_MEM.right = ID_EX.right;
		EX_MEM.RS = ID_EX.RS;
		EX_MEM.RT = ID_EX.RT;
		EX_MEM.RD = ID_EX.RD;
		EX_MEM.A = ID_EX.A;
		EX_MEM.B = ID_EX.B;
		EX_MEM.C = ID_EX.C;
		
	}
	EX_MEM.wb = ID_EX.wb;
	EX_MEM.m = ID_EX.m;

}

/************************************************************/
/* instruction decode (ID) pipeline stage:                                                         */ 
/************************************************************/
void ID() // IF_ID > ID_EX
{
	if(IF_ID.id == 1){
		branch = false;
		/*IMPLEMENT THIS*/
		uint32_t opc;
		uint32_t instruction = IF_ID.IR;
		//printf("IR=%x\n",instruction);
		uint32_t opctemp = instruction & 0xFC000000;
		opctemp = opctemp >> 26;
		//printf("Opctemp=%x\n",opctemp);

		//opcode at right
		if(opctemp == 0x0){
			IF_ID.right = true;
			IF_ID.left = false;
			IF_ID.middle = false;
			opc = instruction & 0x0000003F;
		// opcode in middle
		}else if(opctemp == 0x00000001){
			IF_ID.right = false;
			IF_ID.left = false;
			IF_ID.middle = true;
			opc = instruction & 0x001F0000;
			opc = opc >> 16;
		//opcode at left(null)
		}else{
			IF_ID.left = true;
			IF_ID.right = false;
			IF_ID.middle = false;
			opc = opctemp;
		}


		IF_ID.opcode = opc;
		IF_ID.RS = IF_ID.IR & 0x03E00000;
		IF_ID.RT = IF_ID.IR & 0x001F0000;
		IF_ID.RD = IF_ID.IR & 0x0000FC00;
		IF_ID.RS = IF_ID.RS >> 21;
		IF_ID.RT = IF_ID.RT >> 16;
		IF_ID.RD = IF_ID.RD >> 11;
		IF_ID.A = CURRENT_STATE.REGS[IF_ID.RS]; //rs
		IF_ID.B = CURRENT_STATE.REGS[IF_ID.RT]; //rt
		IF_ID.C = CURRENT_STATE.REGS[IF_ID.RD]; //rd
		//printf("RS=%x\nRT=%x\n",IF_ID.A,IF_ID.B);
		//printf("INSTR=%x\n",IF_ID.IR);
		//printf("RS=%x\n",IF_ID.IR & 0x03E00000);
		//printf("OPCODE=%x, RS=%x, RT=%x, RD=%x\n",IF_ID.opcode,IF_ID.RS,IF_ID.RT,IF_ID.RD);

		IF_ID.imm = instruction & 0xFFFF; //immediate
		if(((IF_ID.imm & 0x00008000)>>15)){
			IF_ID.imm = IF_ID.imm | 0xFFFF0000;
		}

		IF_ID.ex=1;
		IF_ID.id = 1;
		IF_ID.i = 1;
		IF_ID.m = 1;
		IF_ID.wb = 1;
		forward = 0;

		// the outer IF ELSE statements checks to see what type of instruction the previous
		// instruction (the one in the EX stage at this point) is. The type determines which
		// register is being written to (RD for R-type and RT for I-type and load). 
		// So 1=I-type, 2=LOAD, and 0=R-type which is the ELSE part.
		printf("EX_MEM:\n\tA=%x\n\tB=%x\n\tC=%x\n\tRS=%x\n\tRT=%x\n\tRD=%x\n",EX_MEM.A,EX_MEM.B,EX_MEM.C, EX_MEM.RS, EX_MEM.RT,EX_MEM.RD);	
		printf("ID_EX:\n\tA=%x\n\tB=%x\n\tC=%x\n\tRS=%x\n\tRT=%x\n\tRD=%x\n",ID_EX.A,ID_EX.B,ID_EX.C, ID_EX.RS, ID_EX.RT,ID_EX.RD);
		printf("IF_ID:\n\tA=%x\n\tB=%x\n\tC=%x\n\tRS=%x\n\tRT=%x\n\tRD=%x\n",IF_ID.A,IF_ID.B,IF_ID.C, IF_ID.RS, IF_ID.RT,IF_ID.RD);
			

		if((EX_MEM.type == 1) || (EX_MEM.type == 2) || (EX_MEM.type == 3)){
			
			// IF EX.RT == ID.RS HAZARD
			if(EX_MEM.RegWrite && (EX_MEM.RT != 0) && (EX_MEM.RT == IF_ID.RS)){
				// if forwarding is enabled
				if(ENABLE_FORWARDING == 1){
					// forward tells the EX stage which register is to be forwarded into
					// 1 = put the result of previous EX into RS
					// 2 = put the result of previous EX into RT
					// 3 = put the result of previous MEM into RS - load use
					// 4 = put the result of previous MEM into RT - load use
					forward = 1;

					// if the hazard is a load-use hazard, a stall must still occur
					// becuase the loaded values is not ready until the mem stage
					if(EX_MEM.type == 2){ // 2 = load instruction
						forward = 3; // forward from MEM
						IF_ID.ex = 0;
						IF_ID.id = 0;
						IF_ID.i = 0;
						IF_ID.m = 0;
						IF_ID.wb = 0;
						printf("! STALL\n");
					}
				// if forwarding is NOT enabled, must stall
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
			
			}
			// IF EX.RT == ID.RT
			else if(EX_MEM.RegWrite && (EX_MEM.RT != 0) && (EX_MEM.RT == IF_ID.RT)){
				// if forwarding is enabled
				if(ENABLE_FORWARDING == 1){
					// 2 = put result of previous EX stage into RT
					forward = 2;
					// if it is a load instruction, must stall
					if(EX_MEM.type == 2){
						forward = 4; // forward from MEM
						IF_ID.ex = 0;
						IF_ID.id = 0;
						IF_ID.i = 0;
						IF_ID.m = 0;
						IF_ID.wb = 0;
						printf("! STALL\n");
					}
				// if no forwarding, must stall
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
			
			}
			// hazard from MEM stage
			else if(MEM_WB.RegWrite && (MEM_WB.RT != 0) && (MEM_WB.RT == IF_ID.RS)){
				if(ENABLE_FORWARDING == 1){
					forward = 1; // put into RS
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
		
			}
			// hazard from mem stage
			else if(MEM_WB.RegWrite && (MEM_WB.RT != 0) && (MEM_WB.RT == IF_ID.RT)){
				
				if(ENABLE_FORWARDING == 1){
					forward = 2; // put into RT
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
			}
		}
		// instruction in EX stage is R-type so output is register RD
		// everything else is the same as above minus the load-use hazard
		else{
			printf("MEM_WB.RegWrite=%x && (MEM_WB.RD=%x != 0) && (MEM_WB.RD=%x == IF_ID.RS=%x\n",MEM_WB.RegWrite, MEM_WB.RD, MEM_WB.RD, IF_ID.RS);
			//printf("RD=%s\nRT=%s\nRS=%s\n",getReg(EX_MEM.RD),getReg(IF_ID.RT),getReg(IF_ID.RS));
			if(EX_MEM.RegWrite && (EX_MEM.RD != 0) && (EX_MEM.RD == IF_ID.RS)){
				
				if(ENABLE_FORWARDING == 1){
					forward = 1;
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
			
			}
			else if(EX_MEM.RegWrite && (EX_MEM.RD != 0) && (EX_MEM.RD == IF_ID.RT)){
			
				if(ENABLE_FORWARDING == 1){
					forward = 2;
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
			
			}
			else if(EX_MEM.RegWrite && (MEM_WB.RD != 0) && (MEM_WB.RD == IF_ID.RS)){
			
				if(ENABLE_FORWARDING == 1){
					printf("Forward from MEM_WB RD to IF_ID RS\n");
					forward = 1;
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
		
			}
			else if(MEM_WB.RegWrite && (MEM_WB.RD != 0) && (MEM_WB.RD == IF_ID.RT)){
			
				if(ENABLE_FORWARDING == 1){
					printf("Forward from MEM_WB RD to IF_ID RT\n");
					forward = 2;
				}else{
					IF_ID.ex = 0;
					IF_ID.id = 0;
					IF_ID.i = 0;
					IF_ID.m = 0;
					IF_ID.wb = 0;
					printf("! STALL\n");
				}
			}
		}
		
		// the ins_hold stores the instruction that the hazard occured on
		// this is then used in the writeback stage to know when to stop the stalling
		ins_hold = ID_EX.IR; 
	//printf("OPCODE=%x\nA=%x\nB=%x\nC=%x\nImm=%x\n",ID_EX.opcode,ID_EX.A, ID_EX.B, ID_EX.C, ID_EX.imm);
		IF_ID.HI = CURRENT_STATE.HI;
		IF_ID.LO = CURRENT_STATE.LO;

		ID_EX.IR = instruction;
		ID_EX.opcode = IF_ID.opcode;
		ID_EX.A = IF_ID.A;
		ID_EX.B = IF_ID.B;
		ID_EX.C = IF_ID.C;
		ID_EX.imm = IF_ID.imm;
		ID_EX.HI = IF_ID.HI;
		ID_EX.LO = IF_ID.LO;
		ID_EX.left = IF_ID.left;
		ID_EX.right = IF_ID.right;
		ID_EX.type = 100; // default case
		ID_EX.RS = IF_ID.RS;
		ID_EX.RT = IF_ID.RT;
		ID_EX.RD = IF_ID.RD;

	}
	
	ID_EX.ex = IF_ID.ex;
	ID_EX.m = IF_ID.m;
	ID_EX.wb = IF_ID.wb;
	
	

}

/************************************************************/
/* instruction fetch (IF) pipeline stage:                                                              */ 
/************************************************************/
void IF() // IF_ID
{

	if(IF_ID.i == 1){ // set to a 1 in main()
		if(IF_ID.id == 0){
			IF_ID.id = 1;
			IF_ID.IR = mem_read_32(CURRENT_STATE.PC + jmpBy);
			CURRENT_STATE.PC = CURRENT_STATE.PC + jmpBy + 4;		
		}else{
			//IF_ID.id = 1;
			IF_ID.IR = mem_read_32(CURRENT_STATE.PC);
			//printf("IR=%x\n",IF_ID.IR);
			CURRENT_STATE.PC = CURRENT_STATE.PC + 4;
		}
		INSTRUCTION_COUNT++;
	}

	// stalling causes program to end a cycle short, so this forces
	// one more cycle at the end of the program for completion
	if(end_p){
		if(c == 1){
			RUN_FLAG = false;
		}else{
			c++;
		}
	}

}


/************************************************************/
/* Initialize Memory                                                                                                    */ 
/************************************************************/
void initialize() { 
	init_memory();
	CURRENT_STATE.PC = MEM_TEXT_BEGIN;
	NEXT_STATE = CURRENT_STATE;
	RUN_FLAG = TRUE;
}

/************************************************************/
/* Print the program loaded into memory (in MIPS assembly format)    */ 
/************************************************************/
void print_program(){
	/*IMPLEMENT THIS*/
	int i;
	uint32_t addr;
	
	for(i=0; i<PROGRAM_SIZE; i++){
		addr = MEM_TEXT_BEGIN + (i*4);
		printf("%d. [0x%x]\t",i, addr);
		print_instruction(mem_read_32(addr));
	}	
}

/************************************************************/
/* Print the instruction at given memory address (in MIPS assembly format)    */
/************************************************************/
void print_instruction(uint32_t addr){
    char buffer[50];
    uint32_t instruction = addr;//mem_read_32(addr);
	
    //-----R-Type Instruction variables-----
	uint32_t func = instruction & 0x0000003F;			//bits 0-5
	uint32_t shamt = (instruction & 0x00000780) >> 6;	//bits 6-10
	uint32_t d_reg = (instruction & 0x0000F800) >> 11;	//bits 11-15
	uint32_t t_reg = (instruction & 0x001F0000) >> 16;	//bits 16-20
	uint32_t s_reg = (instruction & 0x03E00000) >> 21;	//bits 21-25
	uint32_t special = (instruction & 0xFC000000);		//bits 26-31
	
	//------I-Type Instruction variables-----
	uint32_t immediate = instruction & 0x0000FFFF;		//bits 0-15
	
	//-----J-Type Instruction variables-----
	uint32_t branch = instruction & 0x001F0000;			//bits 16-20
	
	buffer[0] = '\0';
	
	
    switch(special) {
        case 0x00000000:                              //non-special
            switch(func) {
                case 0x00000020:                      //ADD
                   sprintf(buffer, "ADD %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000021:                      //ADDU
                    sprintf(buffer, "ADDU %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000024:                      //AND
                    sprintf(buffer, "AND %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x0000001A:                      //DIV
                    sprintf(buffer, "DIV %s, %s\n", getReg(s_reg), getReg(t_reg));
                    break;
                case 0x0000001B:                      //DIVU
                    sprintf(buffer, "DIVU %s, %s\n", getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000008:                      //JR
                    sprintf(buffer, "JR %s\n", getReg(s_reg));
                    break;  
                case 0x00000022:                      //SUB
                    sprintf(buffer, "SUB %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000023:                      //SUBU
                    sprintf(buffer, "SUBU %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000018:                      //MULT
                    sprintf(buffer, "MULT %s, %s\n", getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000019:                      //MULTU
                    sprintf(buffer, "MULT %s, %s\n", getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000011:                      //MTHI
                    sprintf(buffer, "MTHI %s\n", getReg(s_reg));
                    break;
                case 0x00000013:                      //MTLO
                    sprintf(buffer, "MTLO %s\n", getReg(s_reg));
                    break;
                case 0x00000025:                      //OR
                    sprintf(buffer, "OR %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000026:                      //XOR
                    sprintf(buffer, "XOR %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000027:                      //NOR
                    sprintf(buffer, "NOR %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x0000002A:                      //SLT
                    sprintf(buffer, "SLT %s, %s, %s\n", getReg(d_reg), getReg(s_reg), getReg(t_reg));
                    break;
                case 0x00000000:                      //SLL
                    sprintf(buffer, "SLL %s, %s, %u\n", getReg(d_reg), getReg(t_reg), shamt);
                    break;
                case 0x00000002:                      //SRL
                    sprintf(buffer, "SRL %s, %s, %u\n", getReg(d_reg), getReg(t_reg), shamt);
                    break;
                case 0x00000003:                      //SRA
                    sprintf(buffer, "SRA %s, %s, %u\n", getReg(d_reg), getReg(t_reg), shamt);
                    break;
                case 0x00000010:                      //MFHI
                    sprintf(buffer, "MFHI %s\n", getReg(d_reg));
                    break;
                case 0x00000012:                      //MFLO
                    sprintf(buffer, "MFLO %s\n", getReg(d_reg));
                    break;
                
                case 0x00000009:                      //JALR
                    sprintf(buffer, "JALR %s, %s\n", getReg(d_reg), getReg(s_reg));
                    break;
                case 0x0000000C:                      //SYSCALL
                    sprintf(buffer, "SYSCALL\n");
                    break;
            }
            break;
        case 0x04000000:                                //REGIMM
            switch(branch) {
                case 0x00010000:                      //BGEZ
                    sprintf(buffer, "BGEZ %s, %d\n", getReg(s_reg), immediate);
                    break;
                case 0x00000000:                      //BLTZ
                    sprintf(buffer, "BLTZ %s, %d\n", getReg(s_reg), immediate);
                    break;
            }
            break;                                         //special
        case 0x20000000:                                //ADDI
            sprintf(buffer, "ADDI %s, %s, %d\n", getReg(t_reg), getReg(s_reg), immediate);
            break;
        case 0x24000000:                                //ADDIU
            sprintf(buffer, "ADDIU %s, %s, %d\n", getReg(t_reg), getReg(s_reg), immediate);
            break;
        case 0x30000000:                                //ANDI
            sprintf(buffer, "ANDI %s, %s, %d\n", getReg(t_reg), getReg(s_reg), immediate);
            break;
        case 0x10000000:                                //BEQ
            sprintf(buffer, "BEQ %s, %s, %d\n", getReg(s_reg), getReg(t_reg), immediate);
            break;
        case 0x14000000:                                //BNE
            sprintf(buffer, "BNE %s, %s, %x\n", getReg(s_reg), getReg(t_reg), immediate);
            break;
        //case 0x08000000:                                //J
        //     sprintf(buffer, "J %zu\n", (size_t)(instruction && 0x03FFFFFF) /*<< 2*/);
        //    break;
        //case 0x0C000000:                                //JAL
        //    sprintf(buffer, "JAL %zu\n", (size_t)(instruction && 0x03FFFFFF) /*<< 2*/);
        //    break;
        case 0x08000000:
        	sprintf(buffer, "J %d\n", (instruction & 0x03FFFFFF) /*<< 2*/);
        	break;
        case 0x0C000000:
        	sprintf(buffer, "JAL %d\n", (instruction & 0x03FFFFFF) /*<< 2*/);
        	break;
        case 0x3C000000:                                //LUI
            sprintf(buffer, "LUI %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0x8C000000:                                //LW
            sprintf(buffer, "LW %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0x80000000:                                //LB
            sprintf(buffer, "LB %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0x34000000:                                //ORI
            sprintf(buffer, "ORI %s, %s, %d\n", getReg(t_reg), getReg(s_reg), immediate);
            break;
        case 0x38000000:                                //XORI
            sprintf(buffer, "XORI %s, %s, %d\n", getReg(t_reg), getReg(s_reg), immediate);
            break;
        case 0x28000000:                                //SLTI
            sprintf(buffer, "SLTI %s, %s, %d\n", getReg(t_reg), getReg(s_reg), immediate);
            break;
        case 0x84000000:                                //LH
            sprintf(buffer, "LH %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0xAC000000:                                //SW
            sprintf(buffer, "SW %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0xA0000000:                                //SB
            sprintf(buffer, "SB %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0xA4000000:                                //SH
            sprintf(buffer, "SH %s, %d(%s)\n", getReg(t_reg), immediate, getReg(s_reg));
            break;
        case 0x18000000:                                //BLEZ
            sprintf(buffer, "BLEZ %s, %d\n", getReg(s_reg), immediate);
            break;
        case 0x1c000000:                                //BGTZ
           sprintf(buffer, "BGTZ %s, %d\n", getReg(s_reg), immediate);
            break;
    }
	
    printf("%s", buffer);
}
/************************************************************/
/* Print the current pipeline                                                                                    */ 
/************************************************************/
void show_pipeline(){
	/*IMPLEMENT THIS*/
	printf("\nCurrent PC: 0x%08x\n", CURRENT_STATE.PC);
	printf("-----------------------------\n");
	printf("IF/ID.IR:\t\t");
	print_instruction(IF_ID.IR);
	printf("IF/ID.PC:\t\t0x%08x\n", IF_ID.PC);
	printf("IF/ID.id: \t\t%d\n",IF_ID.id);
	printf("-----------------------------\n");
	printf("ID/EX.IR:\t\t");
	print_instruction(ID_EX.IR);
	printf("ID/EX.A:\t\t0x%08x\n", ID_EX.A);
	printf("ID/EX.B:\t\t0x%08x\n", ID_EX.B);
	printf("ID/EX.C:\t\t0x%08x\n", ID_EX.C);
	printf("ID/EX.IMM:\t\t0x%08x\n", ID_EX.imm);
	printf("ID/EX.ex: \t\t%d\n",ID_EX.ex);
	printf("-----------------------------\n");
	printf("EX/MEM.IR:\t\t");
	print_instruction(EX_MEM.IR);
	printf("EX/MEM.A:\t\t0x%08x\n", EX_MEM.A);
	printf("EX/MEM.B:\t\t0x%08x\n", EX_MEM.B);
	printf("EX/MEM.C:\t\t0x%08x\n", EX_MEM.C);
	printf("EX/MEM.ALUOutput:\t0x%08x\n", EX_MEM.ALUOutput);
	printf("EX/MEM.LMD:\t\t0x%08x\n", EX_MEM.LMD);
	printf("EX/MEM.m: \t\t%d\n",EX_MEM.m);
	printf("-----------------------------\n");
	printf("MEM/WB.IR:\t\t");
	print_instruction(MEM_WB.IR);
	printf("MEM/WB.RT:\t\t%d\n",MEM_WB.RT);
	printf("MEM/WB.RD:\t\t%d\n",MEM_WB.RD);
	printf("MEM/WB.ALUOutput:\t0x%08x\n", MEM_WB.ALUOutput);
	printf("MEM/WB.LMD:\t\t0x%08x\n", MEM_WB.LMD);
	printf("MEM/WB.wb: \t\t%d\n",MEM_WB.wb);
}

/***************************************************************/
/* main                                                                                                                                   */
/***************************************************************/
int main(int argc, char *argv[]) {                              
	printf("\n**************************\n");
	printf("Welcome to MU-MIPS SIM...\n");
	printf("**************************\n\n");
	IF_ID.i = 1;
	IF_ID.ex = 0;
	IF_ID.id = 0;
	IF_ID.m = 0;
	IF_ID.wb = 0;
	if (argc < 2) {
		printf("Error: You should provide input file.\nUsage: %s <input program> \n\n",  argv[0]);
		exit(1);
	}

	strcpy(prog_file, argv[1]);
	initialize();
	load_program();
	help();
	while (1){
		handle_command();
	}
	return 0;
}
