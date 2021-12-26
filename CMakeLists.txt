project (asmake CXX ASM)
enable_language(ASM_NASM)
set_source_files_properties(asm.asm PROPERTIES COMPILE_FLAGS "-f elf64")
add_executable(asmake main.cpp asm.asm)
