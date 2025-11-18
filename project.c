/*MySPIM mini processor simulator - draft 
Name: Gabriela P; Vanessa S
Date: 11/10/2025*/

#include "spimcore.h" 
#include "spimcore.c"
#include <stdio.h>
#include <stdlib.h>

/* ALU
Inputs:  A, B, ALUControl
Outputs: ALUresult, Zero
Ignore overflows and flags
*/
void ALU(unsigned A, unsigned B, char ALUControl,
         unsigned *ALUresult, char *Zero)
{
    unsigned Z = 0;

    switch (ALUControl) // Make sure we can use this standard suggestion from VS Code
    {
        case 0: // 1 [000]  - ADD
            Z = A + B;
            break;

        case 1: // 2 [001] - SUB
            Z = A - B;
            break;

        case 2: // 3 [010] - SLT (signed)
            Z = ((int)A < (int)B) ? 1u : 0u;
            break;

        case 3: // 4 [011] - SLTU (unsigned)
            Z = (A < B) ? 1u : 0u;
            break;

        case 4: // 5 [100] - AND
            Z = A & B;
            break;

        case 5: // 6 [101] - OR
            Z = A | B;
            break;

        case 6: // 7 [110] - Shift left 16 bits
            Z = B << 16;
            break;

        case 7: // 8 [111] - NOT A
            Z = ~A;
            break;

        default: // if something weird happens it will break out
            Z = 0;
            break;
    }

    *ALUresult = Z;
    *Zero = (Z == 0) ? 1 : 0;
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC,unsigned *Mem,unsigned *instruction)
{
          if (PC % 4 != 0 || PC / 4 >= MEMSIZE) { // divide by 4 and check for remainder bc in mips everything is in 4 
        return 1; // return error and stop: unaligned or out of bounds
    }
    *instruction = Mem[PC / 4];
    return 0; // works if its a multiple of 4

    
    if (*instruction == 0x00000000) // this is for "illegal" instructions (not sure we need it)
        return 1; // Halt

    return 0; // No error occurs
}


/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1,unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{

}



/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op,struct_controls *controls)
{

}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1,unsigned r2,unsigned *Reg,unsigned *data1,unsigned *data2)
{
*data1 = Reg[r1]; // finds the value at the register index r1 and assigns to data1
*data2 = Reg[r2]; // finds the value at the register index r2 and assigns to data2
}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{
    if (offset & 0x8000) // check if the sign bit is 1
        *extended_value = offset | 0xFFFF0000; // fill with 1s 
    else
        *extended_value = offset & 0x0000FFFF; // fill with 0s}
}
/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{
    unsigned B = (ALUSrc) ? extended_value : data2;
    char control;

    if (ALUOp == 0) // LW or SW
        control = 0; // ADD
    else if (ALUOp == 1) // BEQ
        control = 1; // SUB
    else // R-type
    {
        switch (funct)
        {
            case 32: // ADD
                control = 0;
                break;
            case 34: // SUB
                control = 1;
                break;
            case 36: // AND
                control = 4;
                break;
            case 37: // OR
                control = 5;
                break;
            case 42: // SLT
                control = 2;
                break;
            default:
                control = 0;
                break;
        }
    }

    ALU(data1, B, control, ALUresult, Zero);
    return 0;
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult,unsigned data2,char MemWrite,char MemRead,unsigned *memdata,unsigned *Mem)
{

}


/* Write Register */
/* 10 Points */
void write_register(unsigned r2,unsigned r3,unsigned memdata,unsigned ALUresult,char RegWrite,char RegDst,char MemtoReg,unsigned *Reg)
{

}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec,unsigned extended_value,char Branch,char Jump,char Zero,unsigned *PC)
{

}



