section .data
    hello_message db "Hello, Holberton", 0xA, 0 ; Define the string with a newline and null terminator

section .text
    extern printf ; Declare the external printf function

    global main
    main:
        ; Prepare arguments for printf
        mov rdi, hello_message ; The format string / message to print
        ; Call printf
        call printf

        ; Exit
        mov rax, 60 ; syscall: exit
        xor rdi, rdi ; status
        syscall
