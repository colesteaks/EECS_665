# Lab 8
#### Nicholas Jurden, 2415098

### x86-64
The processor is CISC architecture.  [^1^](https://books.google.com/books?id=zvNvk-1OuBoC&pg=PA93&lpg=PA93&dq=x86-64+cisc&source=bl&ots=uIU5Etysw3&sig=_XGfPephCdkZUfUoOLBy7MiVm-I&hl=en&sa=X&ved=0ahUKEwjIycLR2bDQAhXhg1QKHY7vB1g4ChDoAQg2MAU#v=onepage&q=x86-64%20cisc&f=false) According to AMD64 (the processor I chose) documentation,  the processor contains two levels of cache, referred to therein as L1 and L2.
>"The L1 data cache (L1 D-Cache) contains 64 Kbytes of storage organized as two-way set associative. The L1 data cache is protected with ECC. Two simultaneous 64-bit operations (load, store, or combination) are supported. The L1 instruction cache (L1 I-Cache) contains 64Kbytes of storage organized as two-way associative. The L1 instruction cache is protected with parity. The L2 cache contains both instruction and data stream information. It is organized as 16-way setassociative. The L2 cache data and tag store is protected with ECC. When a given cache line in the L2 cache contains instruction stream information, the ECC bits associated with the given line are used to store predecode and branch prediction information."[^2^](http://support.amd.com/TechDocs/31412.pdf)

Like most processors with CISC architecture, x86-64 has a variable width instruction set, as seen below.

x86-64 has support for the following data types: [^3^](http://www.sandpile.org/x86/datatype.htm)
Type | Bit Width
--- | ---
integer | smallest format is signed byte, 8bits. Largest is (un)signed qword, 64bits
floating point | smallest format is half real or word integer, 16 bits. Largest are extended real and packed BCD, 80 bits.
MMX | either 64 bit or 128 bit.
SSE | 128 bit.
SSE2 | 128 bit.
F16C | 64 bit or 128 bit.
AVX | 248 bit or 256 bit.
MVEX | 512 bit.
EVEX | 504, 512, or 496 bit.

x86-64 data types are stored in little-endian format.[^13^](http://www.yolinux.com/TUTORIALS/Endian-Byte-Order.html)

The processor has 16 64 bit registers, used for instructions (stack, return, operations). It also has the following floating point registers: 8 80 bit FP registers/64bit MMX registers (the two overlap) and 16 128 bit SSE registers for streaming filetypes. [^4^](https://www.cs.cmu.edu/~fp/courses/15213-s07/misc/asm64-handout.pdf)

All of x86-64 instructions are variable width. The add operation is variable-width. It has a default instruction size of 32 bits, but can be promoted to 64 bits if REX.W prefix is used. The load integer instruction (FILD) is variable width, either 16, 32 or 64 bit. CALL instruction is variable width. The LOCK prefix can be added for atomicity. The JCC instruction jumps based on a conditional test. It is variable width. The LOCK prefix can be used for atomicity. [^5^](http://www.felixcloutier.com/x86/) x86 instruction set is two-address. For example, in an add operation, the processor adds the value from a source address to value in destination address and stores result in destination address.

### Mips
 Mips is an RISC processor.[^6^](https://www.cs.tcd.ie/Jeremy.Jones/vivio/dlx/dlxtutorial.htm) The R8000 processor has a split level cache structure that reduces cache misses by directing integer data references to a 16-Kbyte on-chip cache while floating-point data references are directed off chip cache of up to 16-Mbytes.[^7^](ftp://ftp.sgi.com/sgi/doc/TFP/R8000_Micro_Paper.ps.Z) Like most RISC processors, mips features a fixed-width instruction set. [^8^](https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/Mips/format.html)

Mips features the following data types: [^9^](http://www.cs.uwm.edu/classes/cs315/Bacon/Lecture/HTML/ch05s04.html)
Directive | Type
--- | ---
word | 32 bit integer
half | 16 bit integer
byte | 8 bit integer
float | 32 bit IEEE floating point
double | 64 bit IEEE floating point
space | uninitialized memory block
ascii | ascii string
asciiz | null terminated ascii string

Almost all MIPS processors are bi-endian, meaning they can run in either big-endian or little-endian format. [^10^](https://www.linux-mips.org/wiki/Endianess)    

Mips features the following register set (all registers are 32 bit): [^11^](http://homepage.cs.uiowa.edu/~ghosh/1-28-10.pdf)
Register | description
--- | ---
r0 | always 0
r1 | reserved for assembler
r2-r3 | stores results
r4-r7 | stores arguments
r8-r15 | temporaries, not saved
r16-r23 | contents saved for later use
r24-r25 | more temporaries
r26-r27 | reserved by operating system
r28 | global pointer
r29 | stack pointer
r30 | frame pointer
r31 | return address

Add is a fixed with instruction, with a format shown below. Load word is a fixed with instruction that loads a word into a register from a specified address. Format: `lw $t, offset($s)`. System call is a fixed with instruction that generates a software interrupt. Format: `syscall`. Branch on equal is a fixed with instruction that jumps to a specified offset if values in two given registers are equal. Format: `beq $r1, $r2, offset`.  [^12^](http://www.mrc.uidaho.edu/mrc/people/jff/digital/MIPSir.html) MIPS features a three-address code instruction set. An example, as above, is the add instruction. Formatted `add $r1, $r2, $r3`, add stores the result of adding values in `$r2` and `$r3` in `$r1`.
