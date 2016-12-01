    .text
    .globl tstconst
tstconst:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       $10, %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstcall
tstcall:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       $10, %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .data
    .globl strval0
strval0:
    .asciz    "Test: %d %d\n"

    .text
    .globl tstadd
tstadd:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       264(%esp), %eax
    addl       268(%esp), %eax
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstsub
tstsub:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       264(%esp), %eax
    subl       268(%esp), %eax
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstmul
tstmul:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       264(%esp), %eax
    imull       268(%esp), %eax
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstdiv
tstdiv:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       264(%esp), %eax
    movl        $0, %edx
    idivl       268(%esp)
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstmod
tstmod:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstshl
tstshl:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       264(%esp), %eax
    movb       268(%esp), %cl
    shll       %cl, %eax
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

    .text
    .globl tstshr
tstshr:
    push       %ebp
    movl       %esp, %ebp
    subl       $256, %esp
    movl       264(%esp), %eax
    movb       268(%esp), %cl
    shrl       %cl, %eax
    movl       %eax, 252(%esp)
    movl       252(%esp), %eax
    addl       $256, %esp
    pop        %ebp
    ret

