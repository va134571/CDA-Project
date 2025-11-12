#include "spimcore.h"


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

}


/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset,unsigned *extended_value)
{

}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1,unsigned data2,unsigned extended_value,unsigned funct,char ALUOp,char ALUSrc,unsigned *ALUresult,char *Zero)
{

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

