extern from_cpp

section .text

; global from_asm
global from_asm
from_asm:
    call from_cpp
    ret


; uint32_t fl_str_len(const char* src@rdi);
global fl_str_len
fl_str_len:
    mov rax, rdi        ; Copy the start address
.start_loop:
    cmp BYTE [rax], 0    ; Check if current char is NULL
    je .exit_loop       ; If it is NULL, jump to exit
    inc rax             ; Increment current char
    jmp .start_loop
.exit_loop:
    sub rax, rdi
    ret

; int32_t fl_str_toupper(char* src@rdi, uint32_t n@rsi, char* dst@rdx);
global fl_str_toupper
fl_str_toupper:
    ; Check for null pointers
    cmp rdx, 0
    je .exit_error
    cmp rdi, 0
    je .exit_error

    mov r8, 0; Initialize counter
.loop_condition:
    cmp r8d, esi    ; Loop while counter is less than n
    jb .loop_body
    mov eax, r8d
    ret
.loop_body:
    mov rax, rdi        ; Leads character from src[counter]
    add rax, r8
    mov al, BYTE [rax]
    cmp al, 97          ; Checks if the character is a lower case one
    jb .loop_body_end
    cmp al, 122
    ja .loop_body_end

    sub al, 32

.loop_body_end:
    mov rbx, rdx        ; Copies the character to dst[counter]
    add rbx, r8
    mov BYTE [rbx], al
    inc r8d
    jmp .loop_condition

.exit_error:
    mov eax, -1
    ret

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

; 

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
