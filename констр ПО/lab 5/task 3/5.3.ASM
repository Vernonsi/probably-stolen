format PE console NX
entry start

include 'WIN32A.INC'

section '.data' data readable writeable 

frame1 db 'Input N: '
sizeof.frame1 = $ - frame1




section '.bss' data readable writeable

hInput dd ?
hOutput dd ?
dwNumber dd ?
stub dd ?

szNum rb 30
szNum.sizeof = $-szNum

N dd ?
szN rb 30
szN.sizeof = $-szN

Exp dd ?
szExp rb 30
szExp.sizeof = $-szExp

Tmp dd ?
szTmp rb 30
szTmp.sizeof = $-szTmp

Res dd ?
szRes rb 30
szRes.sizeof = $-szRes

section '.text' code readable executable




start:
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    push NULL
    push stub       
    push sizeof.frame1
    push frame1      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push dwNumber
    push szN.sizeof
    push szN
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber
    mov byte ptr szN + EBX - 2, 0
    
        push szN
    call ptr atoi
    add ESP, 4

    mov [N], EAX


    push 0             ;STR V INT
    push dwNumber
    push szExp.sizeof
    push szExp
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber
    mov byte ptr szN + EBX - 2, 0
    
        push szExp
    call ptr atoi
    add ESP, 4

    mov [Exp], EAX      ; KONCHILI







    mov [Res], 1

    mov EAX, [Res]
    mov ECX, [Exp]
    mov EAX, [N]
    mov [Tmp], EAX
   ; dec [Tmp]


   KONEC:

    jz  INACHE   ; jz eto n & 1 vrode scas bi pisat cod iz java v asm kogda ne znaesh ni to ni to no da ladno tot kto pridumal komenti ochen krutoi


    mov EAX, [Res]
    mov EBX, [N]
    mul EBX ; a kak zapisat chislo posle mul pravilno
    mov [Res], EAX    ; eto dolzhno bit Res*=N

    mov EAX, [N]
    mov EBX, [Tmp]
    mul EBX
    mov [N], EAX ; N*=N

    mov EAX, [Exp]
    mov EDX, 0
    mov EBX, 2
    div EBX
    mov [Exp], EAX; Exp>>=1

;    mov ECX, [Exp]

    INACHE:


   LOOP  KONEC


    mov EAX, [N]
    mov EDX, 0
    mov EBX, [Tmp]
    div EBX
    mov [N], EAX

    push 10
    push szN
    push [N]
    call ptr itoa
    add ESP, 3 * 4 ; 

    push [N]
    call ptr lstrlen

    push 0
    push dwNumber
    push [N]
    push szN
    push ptr hOutput
    call ptr WriteConsole



    push 0
    push dwNumber
    push szN.sizeof
    push szN
    push ptr hInput
    call ptr ReadConsole

    push 0
    call [ExitProcess]

section '.idata' import data readable writeable

library kernel32, 'KERNEL32.DLL', \
    msvcrt, 'MSVCRT.DLL'

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA'

import msvcrt, \
    atoi, 'atoi',\
    itoa, '_itoa'

section '.reloc' fixups data readable discardable