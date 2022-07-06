format PE console NX
entry start

include 'WIN32A.INC'

section '.data' data readable writeable 

error db 'Division by zero!!!'
sizeof.error = $ - error

xMask db 'Enter X: '
sizeof.xMask = $ - xMask

yMask db 'Enter Y: '
sizeof.yMask = $ - yMask

Min2Mask db 'min(min(10,y),max(x,y)): '
sizeof.Min2Mask = $ - Min2Mask

Max2Mask db 'max(x%10,y%10)): '
sizeof.Max2Mask = $ - Max2Mask


resultMask db 'min(min(10,y),max(x,y))/max(x%10,y%10): '
sizeof.resultMask = $ - resultMask

newLine db 13,10
sizeof.newLine = $ - newLine

section '.bss' data readable writeable

stub dd ?
hInput dd ?
hOutput dd ?
dwNumber1 dd ?
dwNumber2 dd ?


X dd ?
szX rb 30
szX.sizeof = $-szX

Y dd ?
szY rb 30
szY.sizeof = $-szY

Des dd ?
szDes rb 30
szDes.sizeof = $-szDes

Tmp1 dd ?
szTmp1 rb 30
szTmp1.sizeof = $-szTmp1

Tmp2 dd ?
szTmp2 rb 30
szTmp2.sizeof = $-szTmp2

Tmp3 dd ?
szTmp3 rb 30
szTmp3.sizeof = $-szTmp3


section '.text' code readable executable

Desytki:
mov [Des],0
mov [Tmp3], EAX
mov EAX, [Tmp2]
chtoto:
mov EDX,0
mov EBX, 10
div EBX



add [Des], EDX
cmp EAX, 10
ja chtoto
konchik:
mov EAX, [Tmp3]
ret

start:
    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    push NULL
    push stub       
    push sizeof.xMask
    push xMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push dwNumber1
    push szX.sizeof
    push szX
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber1
    mov byte ptr szX + EBX - 2, 0

        push szX
    call ptr atoi
    add ESP, 4

    mov [X], EAX

    push NULL
    push stub       
    push sizeof.yMask
    push yMask      
    push [hOutput]      
    call [WriteConsole]

    push 0
    push dwNumber2
    push szY.sizeof
    push szY
    push ptr hInput
    call ptr ReadConsole

    mov EBX, ptr dwNumber2
    mov byte ptr szY + EBX - 2, 0

        push szY
    call ptr atoi
    add ESP, 4

    mov [Y], EAX
    ;vichislyaem
    mov [Tmp1], 1
    mov EAX, [X]
    mov [Tmp2], EAX
    add [Tmp2], 1

    mov ECX, [Y]

shtuka:
    mov EAX, [Y]
    cmp [Tmp2],EAX
    je nelup
    mov EAX,[Tmp1]
    mov EDX, 0
    mov EBX, 2
    div EBX

    cmp EDX, 0
    jne shkip

call Desytki

      push 10
    push szDes
    push [Des]
    call ptr itoa
    add ESP, 3 * 4 

    push [Des]
    call ptr lstrlen



    push 0
    push stub
    push [Des]
    push szDes
    push ptr hOutput
    call ptr WriteConsole

    shkip:
    add [Tmp1], 1
    add [Tmp2], 1
    loop shtuka

nelup:

;out


    ; ---
    push 0
    push stub
    push [X]
    push szX
    push [hInput]   
    call [ReadConsole]

ex:
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