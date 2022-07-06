format PE console NX
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable

        hInput dd ?
        hOutput dd ?
        dwNumber dd ?
        buf db ?
stub dd ?


N dd ?
szN rb 30
szN.sizeof = $-szN

Tmp dd ?
szTmp rb 30
sizeof.Tmp = $-szTmp
Tmp1 dd ?
szTmp1 rb 30
sizeof.Tmp1 = $-szTmp1


        tempStr db "asd"

        numberFirst rb 30
        numberFirst.sizeof = $-numberFirst

        point db '.'
        point.sizeof = $ - point

        endl db 13,10
        endl.sizeof = $ - endl

        strResult dd ?

        strTrue db "TRUE"

        buffer db ?

        array  dd 15 dup ("")
        size   dd 15

        arrayPtr dd ?


        resultSumArray dd 0
        template db "%d ", 0

        DigitsSum dd 0, 0
        szDigitsSum rb 30
        szDigitsSum.sizeof = $-DigitsSum


section '.text' code readable executable

printArray:
        push EBP
        mov EBP, ESP
        cycle_printArray:
                cmp dword ptr EBP + 12, 0
                je endFunction_printArray
                mov EAX, [ EBP + 8 ]
                mov EAX, dword ptr EAX
                cinvoke printf, template, EAX
                add dword ptr EBP + 8, 4
                dec dword ptr EBP + 12
        jmp cycle_printArray
        endFunction_printArray:
        pop EBP
ret 8

sumArray:
        push EBP
        mov EBP, ESP

        mov EDX,  dword ptr EBP + 8
        mov dword ptr EDX, 0

        cycle_sumArray:
                cmp dword ptr EBP + 16, 0
                je endFunctionsumArray

                mov EAX, dword ptr EBP + 12
                mov EAX, dword ptr EAX

                mov EDX,  dword ptr EBP + 8
                add [EDX], EAX

                add dword ptr EBP + 12, 4

                dec dword ptr EBP + 16

        jmp cycle_sumArray
        endFunctionsumArray:
        pop EBP
ret 12


incArray:
        push EBP
        mov EBP, ESP

        cycle_incArray:
                cmp dword ptr EBP + 12, 0
                je endFunctionIncArray

                mov EAX, dword ptr EBP + 8

                inc dword ptr EAX

                add dword ptr EBP + 8, 4

                dec dword ptr EBP + 12

        jmp cycle_incArray
        endFunctionIncArray:
        pop EBP
ret 8

rule_1:
    push EBP
    mov EBP, ESP

    mov EAX, [EBP + 8]

    push EDX
    mov EDX, 0

    push ESI
    mov ESI,[EBP + 12]

    add EAX, ESI

    pop ESI
    pop EDX
    pop EBP
ret 8

makeArrayByRule_1:
        push EBP
        mov EBP, ESP

        push ESI
        push EAX
        push EDX

        mov ESI, 0

        cycle_makeArrayByRule_1:

                cmp dword ptr EBP + 12, 0
                je endFunction_makeArrayByRule_1

                push ESI
                push [N]
                call rule_1

                mov EDX, dword ptr EBP + 8
                mov dword ptr EDX, EAX



                mov EBX, -3
               mul EBX
                mov [N], EAX





               ; add ESI, 7

                add dword ptr EBP + 8, 4

                dec dword ptr EBP + 12
        jmp cycle_makeArrayByRule_1
        endFunction_makeArrayByRule_1:

        pop ESI
        pop EAX
        pop EDX
        pop EBP
ret 8

makeArrayByRule_2:
        push EBP
        mov EBP, ESP

        push ESI
        push EAX
        push EDX
        push EDI

        mov EDI, 7

        cycle_makeArrayByRule_2:

                cmp dword ptr EBP + 12, 0
                je endFunction_makeArrayByRule_2

                mov ESI, dword ptr EBP + 8
                mov EAX,dword ptr  ESI



 call Razryad
                mov dword ptr ESI, EAX


                
                add dword ptr EBP + 8, 4

                dec dword ptr EBP + 12

        jmp cycle_makeArrayByRule_2
        endFunction_makeArrayByRule_2:
        pop EDI
        pop ESI
        pop EAX
        pop EDX
        pop EBP
ret 8

abs:
getabs:
neg EAX
js getabs
ret

Razryad:
mov [Tmp], EAX
call abs

cmp EAX, 10
jb konec

mov EDX,0
mov EBX,10
div EBX

mov EDX,0
mov EBX,10
div EBX

mov EAX, EDX
cmp EAX, 0
je konec

mov EDX,0
mov EBX,2
div EBX

mov EAX,EDX

cmp EAX,0
jne konec
mov EAX, [Tmp]
mov [Tmp], EAX
 neg EAX
  mov [Tmp], EAX
konec:
mov EAX, [Tmp]
ret

start:
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX
    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    mov [N],3
    push [size]
    push array
    call makeArrayByRule_1

    push [size]
    push array
    call printArray
    invoke WriteConsole, [hOutput], endl, 2, 0, 0

    push [size]
    push array
    push resultSumArray
    call sumArray

    push 10
    push strResult
    push [resultSumArray]
    call [itoa]
    add ESP, 3 * 4

    push strResult
    call [lstrlen]
    invoke WriteConsole, [hOutput], strResult, EAX, 0, 0
    invoke WriteConsole, [hOutput], endl, 2, 0, 0

 mov [N],3
    push [size]
    push array
    call makeArrayByRule_2

    push [size]
    push array
    push resultSumArray
    call sumArray

    push [size]
    push array
    call printArray
    invoke WriteConsole, [hOutput], endl, 2, 0, 0

    push 10
    push strResult
    push [resultSumArray]
    call [itoa]
    add ESP, 3 * 4

    push strResult
    call [lstrlen]
    invoke WriteConsole, [hOutput], strResult, EAX, 0, 0
    invoke WriteConsole, [hOutput], endl, 2, 0, 0

    push 0
    push dwNumber
    push szN.sizeof
    push szN
    push ptr hInput
    call ptr ReadConsole



    push 0
    call [ExitProcess]

section '.idata' import data readable writeable
library user32,'user32.dll', \
    kernel32, 'KERNEL32.DLL', \
    msvcrt, 'MSVCRT.DLL'

import kernel32,\
    lstrlen, 'lstrlenA',\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA'

import user32,\
    MsgBox,'MessageBoxA',\ 
    wsprintf,'wsprintfA'

import msvcrt, \
    atoi, 'atoi',\
    itoa, '_itoa', \
    printf, 'printf'

section '.reloc' fixups data readable discardable