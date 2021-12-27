// ECE 4270 Group 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include "mu-mips.h"

// takes the register ($v0) and returns its converted register as an int
int getReg(char *temp){
	if(strcmp(temp, "$zero") == 0){
		return 0;
	}else if(strcmp(temp, "$at") == 0){
		return 1;
	}
	else if(strcmp(temp, "$v0") == 0){
		return 2;
	}
	else if(strcmp(temp, "$v1") == 0){
		return 3;
	}
	else if(strcmp(temp, "$a0") == 0){
		return 4;
	}
	else if(strcmp(temp, "$a1") == 0){
		return 5;
	}
	else if(strcmp(temp, "$a2") == 0){
		return 6;
	}
	else if(strcmp(temp, "$a3") == 0){
		return 7;
	}
	else if(strcmp(temp, "$t0") == 0){
		return 8;
	}
	else if(strcmp(temp, "$t1") == 0){
		return 9;
	}
	else if(strcmp(temp, "$t2") == 0){
		return 10;
	}
	else if(strcmp(temp, "$t3") == 0){
		return 11;
	}
	else if(strcmp(temp, "$t4") == 0){
		return 12;
	}
	else if(strcmp(temp, "$t5") == 0){
		return 13;
	}
	else if(strcmp(temp, "$t6") == 0){
		return 14;
	}
	else if(strcmp(temp, "$t7") == 0){
		return 15;
	}
	else if(strcmp(temp, "$s0") == 0){
		return 16;
	}
	else if(strcmp(temp, "$s1") == 0){
		return 17;
	}
	else if(strcmp(temp, "$s2") == 0){
		return 18;
	}
	else if(strcmp(temp, "$s3") == 0){
		return 19;
	}
	else if(strcmp(temp, "$s4") == 0){
		return 20;
	}
	else if(strcmp(temp, "$s5") == 0){
		return 21;
	}
	else if(strcmp(temp, "$s6") == 0){
		return 22;
	}
	else if(strcmp(temp, "$s7") == 0){
		return 23;
	}
	else if(strcmp(temp, "$t8") == 0){
		return 24;
	}
	else if(strcmp(temp, "$t9") == 0){
		return 25;
	}
	else if(strcmp(temp, "$k0") == 0){
		return 26;
	}
	else if(strcmp(temp, "$k1") == 0){
		return 27;
	}
	else{
		return -100;
	}
}

// takes the op as a character array and returns its integer representation 
int opToInt(char *temp){
	if(strcmp(temp,"add") == 0){
		return 32;
	}else if(strcmp(temp,"addu") == 0){
		return 33;
	}
	else if(strcmp(temp,"addi") == 0){
		return 8;
	}
	else if(strcmp(temp,"addiu") == 0){
		return 9;
	}
	else if(strcmp(temp,"sub") == 0){
		return 34;
	}
	else if(strcmp(temp,"subu") == 0){
		return 35;
	}
	else if(strcmp(temp,"mult") == 0){
		return 24;
	}
	else if(strcmp(temp,"multu") == 0){
		return 25;
	}
	else if(strcmp(temp,"div") == 0){
		return 26;
	}
	else if(strcmp(temp,"divu") == 0){
		return 27;
	}
	else if(strcmp(temp,"and") == 0){
		return 36;
	}
	else if(strcmp(temp,"andi") == 0){
		return 12;
	}
	else if(strcmp(temp,"or") == 0){
		return 37;
	}
	else if(strcmp(temp,"ori") == 0){
		return 13;
	}
	else if(strcmp(temp,"xor") == 0){
		return 38;
	}
	else if(strcmp(temp,"xori") == 0){
		return 14;
	}
	else if(strcmp(temp,"nor") == 0){
		return 39;
	}
	else if(strcmp(temp,"slt") == 0){
		return 42;
	}
	else if(strcmp(temp,"slti") == 0){
		return 10;
	}
	else if(strcmp(temp,"sll") == 0){
		return 0;
	}
	else if(strcmp(temp,"srl") == 0){
		return 2;
	}
	else if(strcmp(temp,"sra") == 0){
		return 3;
	}
	else if(strcmp(temp, "bne") == 0){
		return 5;
	}
	else if(strcmp(temp, "lw") == 0){
		return 35;
	}
	else if(strcmp(temp, "lb") == 0){
		return 32;
	}
	else if(strcmp(temp, "lh") == 0){
		return 33;
	}
	else if(strcmp(temp, "lui") == 0){
		return 15;
	}
	else if(strcmp(temp, "sw") == 0){
		return 43;
	}
	else if(strcmp(temp, "sb") == 0){
		return 40;
	}
	else if(strcmp(temp, "sh") == 0){
		return 41;
	}
	else if(strcmp(temp, "mfhi") == 0){
		return 16;
	}
	else if(strcmp(temp, "mflo") == 0){
		return 18;
	}
	else if(strcmp(temp, "mthi") == 0){
		return 17;
	}
	else if(strcmp(temp, "mtlo") == 0){
		return 19;
	}
	else if(strcmp(temp, "beq") == 0){
		return 4;
	}
	else if(strcmp(temp, "blez") == 0){
		return 6;
	}
	else if(strcmp(temp, "bltz") == 0){
		return 0;
	}
	else if(strcmp(temp, "bgez") == 0){
		return 1;
	}
	else if(strcmp(temp, "bgtz") == 0){
		return 7;
	}
	else if(strcmp(temp, "j") == 0){
		return 2;
	}
	else if(strcmp(temp, "jr") == 0){
		return 8;
	}
	else if(strcmp(temp, "jal") == 0){
		return 3;
	}
	else if(strcmp(temp, "jalr") == 0){
		return 9;
	}
	else{
		return -100;
	}
}

// can be used for an immediate value (immediate or offset)
// takes the value (either 0xA or -8 or whatever) as a character array and converts it to an integer
int getImm(char *temp){
	if(temp[1] == 'x'){ 					// for the form 0xA
		return (int)strtol(temp, NULL, 0);	// this takes a char array of the form 0x**** and converts it
	}else if(temp[1] != 'x'){				// for an actual value like 9 or -8
		return atoi(temp);
	}else{									// for 0
		return 0;
	}
}
void assemble(char *name){
		FILE * fp;
		FILE * fout;
		char instr[1000], hold[1000], fileOutName[32];
		char *op, *rs, *rt, *rd, *imm, *off, *base, *sa, *target;
		uint32_t ins;
		fp = fopen(name, "r");
		sprintf(fileOutName,"assembled_%s",name);
		if (fp == NULL) {
			//printf("Error: Can't open program file\n");
			exit(-1);
		}
		sprintf(fileOutName,"assembled_%s",name);
		fout = fopen(fileOutName,"w");

		// for every instruction in the file
		while(fgets(instr, sizeof(instr), fp) != NULL){
			strncpy(hold, instr, 1000);
			ins = ins & 0x0;
			op = strtok(instr, " ");

			if(strcmp(op,"add") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}else if(strcmp(op,"addu") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"addi") == 0){
				// split up instruction
				rt = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate character array to an integer and shift into place
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op,"addiu") == 0){
				// split up instruction
				rt = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate character array to an integer and shift into place
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op,"sub") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"subu") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"mult") == 0){
				// split up instruction
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rs=%s\nrt=%s\n",rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
			}
			else if(strcmp(op,"multu") == 0){
				// split up instruction
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rs=%s\nrt=%s\n",rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
			}
			else if(strcmp(op,"div") == 0){
				// split up instruction
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rs=%s\nrt=%s\n",rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
			}
			else if(strcmp(op,"divu") == 0){
				// split up instruction
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rs=%s\nrt=%s\n",rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
			}
			else if(strcmp(op,"and") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"andi") == 0){
				// split up instruction
				rt = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate character array to an integer and shift into place
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op,"or") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"ori") == 0){
				// split up instruction
				rt = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate character array to an integer and shift into place
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op,"xor") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"xori") == 0){
				// split up instruction
				rt = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate character array to an integer and shift into place
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op,"nor") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				// printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"slt") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				rt = strtok(NULL, " \n");
				//printf("rd=%s\nrs=%s\nrt=%s\n",rd,rs,rt);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op,"slti") == 0){
				// split up instruction
				rt = strtok(NULL, ", ");
				rs = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate character array to an integer and shift into place
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op,"sll") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rt = strtok(NULL, ", ");
				sa = strtok(NULL, " \n");
				//printf("rd=%s\nrt=%s\nsa=%s\n",rd,rt,sa);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
				ins = ins | (getImm(sa) << 6);
			}
			else if(strcmp(op,"srl") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rt = strtok(NULL, ", ");
				sa = strtok(NULL, " \n");
				//printf("rd=%s\nrt=%s\nsa=%s\n",rd,rt,sa);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
				ins = ins | (getImm(sa) << 6);
			}
			else if(strcmp(op,"sra") == 0){
				// split up instruction
				rd = strtok(NULL, ", ");
				rt = strtok(NULL, ", ");
				sa = strtok(NULL, " \n");
				//printf("rd=%s\nrt=%s\nsa=%s\n",rd,rt,sa);
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getReg(rd) << 11);
				ins = ins | (getImm(sa) << 6);
			}
			else if(strcmp(op, "bne") == 0){
				// split up instruction
				rs = strtok(NULL, ", "); 
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate (offset) character array to an integer and shift into place
				ins = ins | ((getImm(off) >> 2) & 0xffff);
			}
			else if(strcmp(op, "lw") == 0){
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " (");
				base = strtok(NULL, ")");
				//printf("rt=%s\noff=%s\nbase=%s\n",rt,off,base);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(base) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(off) & 0xffff);
				
			}
			else if(strcmp(op, "lb") == 0){
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " (");
				base = strtok(NULL, ")");
				//printf("rt=%s\noff=%s\nbase=%s\n",rt,off,base);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(base) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(off) & 0xffff);
			}
			else if(strcmp(op, "lh") == 0){
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " (");
				base = strtok(NULL, ")");
				//printf("rt=%s\noff=%s\nbase=%s\n",rt,off,base);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(base) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(off) & 0xffff);
			}
			else if(strcmp(op, "lui") == 0){
				rt = strtok(NULL, ", ");
				imm = strtok(NULL, " \n");
				//printf("rt=%s\nimm=%s\n",rt,imm);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(imm) & 0xffff);
			}
			else if(strcmp(op, "sw") == 0){
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " (");
				base = strtok(NULL, ")");
				//printf("rt=%s\noff=%s\nbase=%s\n",rt,off,base);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(base) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(off) & 0xffff);
			}
			else if(strcmp(op, "sb") == 0){
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " (");
				base = strtok(NULL, ")");
				//printf("rt=%s\noff=%s\nbase=%s\n",rt,off,base);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(base) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(off) & 0xffff);
			}
			else if(strcmp(op, "sh") == 0){
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " (");
				base = strtok(NULL, ")");
				//printf("rt=%s\noff=%s\nbase=%s\n",rt,off,base);
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(base) << 21);
				ins = ins | (getReg(rt) << 16);
				ins = ins | (getImm(off) & 0xffff);
			}
			else if(strcmp(op, "mfhi") == 0){
				rd = strtok(NULL, " \n");
				//printf("rd=%s\n",rd);
				ins = ins | (opToInt(op) & 0xffff);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op, "mflo") == 0){
				rd = strtok(NULL, " \n");
				//printf("rd=%s\n",rd);
				ins = ins | (opToInt(op) & 0xffff);
				ins = ins | (getReg(rd) << 11);
			}
			else if(strcmp(op, "mthi") == 0){
				rs = strtok(NULL, " \n");
				//printf("rs=%s\n",rd);
				ins = ins | (opToInt(op) & 0xffff);
				ins = ins | (getReg(rd) << 21);
			}
			else if(strcmp(op, "mtlo") == 0){
				rs = strtok(NULL, " \n");
				//printf("rs=%s\n",rd);
				ins = ins | (opToInt(op) & 0xffff);
				ins = ins | (getReg(rd) << 21);
			}
			else if(strcmp(op, "beq") == 0){
				// split up instruction
				rs = strtok(NULL, ", "); 
				rt = strtok(NULL, ", ");
				off = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | (getReg(rt) << 16);
				// convert the immediate (offset) character array to an integer and shift into place
				ins = ins | ((getImm(off) >> 2) & 0xffff);
			}
			else if(strcmp(op, "blez") == 0){
				// split up instruction
				rs = strtok(NULL, ", "); 
				off = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);

				// convert the immediate (offset) character array to an integer and shift into place
				ins = ins | ((getImm(off) >> 2) & 0xffff);
			}
			// DOUBLE CHECK
			else if(strcmp(op, "bltz") == 0){
				// split up instruction
				rs = strtok(NULL, ", "); 
				off = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (0x1 << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | ((opToInt(op) & 0x1f) << 16);
				// convert the immediate (offset) character array to an integer and shift into place
				ins = ins | ((getImm(off) & 0xffff) >> 2);
			}
			// DOUBLE CHECK
			else if(strcmp(op, "bgez") == 0){
				// split up instruction
				rs = strtok(NULL, ", "); 
				off = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (0x1 << 26);
				ins = ins | (getReg(rs) << 21);
				ins = ins | ((opToInt(op) & 0x1f) << 16);
				// convert the immediate (offset) character array to an integer and shift into place
				ins = ins | ((getImm(off) & 0xffff) >> 2);
			}
			else if(strcmp(op, "bgtz") == 0){
				// split up instruction
				rs = strtok(NULL, ", "); 
				off = strtok(NULL, " \n");
				// convert each charcter arrray to an integer and then shift into place
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getReg(rs) << 21);

				// convert the immediate (offset) character array to an integer and shift into place
				ins = ins | ((getImm(off) & 0xffff) >> 2);
			}
			else if(strcmp(op, "j") == 0){
				target = strtok(NULL, " \n");
				ins = ins | (opToInt(op) << 26);
				ins = ins | ((getImm(target) & 0x3ffffff) >> 2);
			}
			else if(strcmp(op, "jr") == 0){
				rs = strtok(NULL, " \n");
				ins = ins | (opToInt(op) & 0x3f);
				ins = ins | (getReg(rs) << 21);
			}
			else if(strcmp(op, "jal") == 0){
				target = strtok(NULL, " \n");
				ins = ins | (opToInt(op) << 26);
				ins = ins | (getImm(target) & 0x3ffffff);
			}
			else if(strcmp(op, "jalr") == 0){
				rd = strtok(NULL, ", ");
				rs = strtok(NULL, " \n");
				ins = ins | (getReg(rs) << 21);
				
				if(rs == NULL){ // JALR rs
					ins = ins | (getReg(rd) << 21); //rd = rs
				}else{			// JALR rd, rs
					ins = ins | ((getReg(rs)&0x3f) << 21);
					ins = ins | ((getReg(rd)&0x3f) << 11);
				}
				ins = ins | (opToInt(op) & 0x3f);
			}
			else{
				ins = ins | 12;
			}
			//printf("%x\n",ins);
			fprintf(fout,"%x\n",ins);
		}
		fclose(fp);
		fclose(fout);
}


int main(int argc, char *argv[]) { 
		if (argc < 2) {
			printf("Error: You should provide input file.\nUsage: %s <input program> \n\n",  argv[0]);
			exit(1);
		}
		printf("[#] Assembling -> assembled_%s\n",argv[1]);
		assemble(argv[1]);
		printf("[#] Done.\n[#] To simulate, run: ./mu-mips assembled_%s\n",argv[1]);

}
	