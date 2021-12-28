section .text
global add32
add32:
    add rsi, rdi
    mov rax, rsi
    ret

global settrue
settrue:
    ; rdi
    mov BYTE [rdi], 1
    ret

global adc32
adc32:
    add edi, esi
    jc .has_carry
    mov BYTE [rdx], 0
    mov eax, edi
    ret
.has_carry:
    mov BYTE [rdx], 1
    mov eax, edi
    ret


; bool add64_check_carry(uint64_t,uint64_t,uint64_t*);
global add64_check_carry
add64_check_carry:
    add rdi, rsi
    mov QWORD [rdx], rdi
    jc .has_carry
    mov eax, 0
    ret
.has_carry:
    mov eax, 1
    ret
