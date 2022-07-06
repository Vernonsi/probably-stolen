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

Max1 dd ?
szMax1 rb 30
szMax1.sizeof = $-szMax1

Max2 dd ?
szMax2 rb 30
szMax2.sizeof = $-szMax2

Min1 dd ?
szMin1 rb 30
szMin1.sizeof = $-szMin1

Min2 dd ?
szMin2 rb 30
szMin2.sizeof = $-szMin2


Result dd ?
szResult rb 30
szResult.sizeof = $-szResult

Tmp1 dd ?
szTmp1 rb 30
szTmp1.sizeof = $-szTmp1

Tmp2 dd ?
szTmp2 rb 30
szTmp2.sizeof = $-szTmp2




section '.text' code readable executable

max:
    cmp EAX, EBX
    jge exitMax
    mov EAX, EBX
exitMax:
    ret

min:
    cmp EAX, EBX
    jle exitMin
    mov EAX, EBX
exitMin:
    ret


ZeroDivision:
    push NULL
    push stub       
    push sizeof.error
    push error      
    push [hOutput]      
    call [WriteConsole]

    jmp ex

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

    mov EAX, 10
    mov EBX,[Y]
    call min
    mov [Min1], EAX

    mov EAX, [Y]
    mov EBX, [X]
    call max
    mov [Max1], EAX

    mov EAX, [Min1]
    mov EBX, [Max1]
    call min
    mov [Min2], EAX

    mov EAX, [X]
    mov EDX, 0
    mov EBX, 10
    div EBX

    mov [Tmp1], EDX

    mov EAX, [Y]
    mov EDX, 0
    mov EBX, 10
    div EBX

    mov [Tmp2], EDX

    mov EAX, [Tmp1]
    mov EBX, [Tmp2]
    call max
    mov [Max2], EAX

    ; ---
    mov EAX, [Min2]
    mov EDX, 0
    mov EBX, [Max2]

    cmp EBX, 0
    je ZeroDivision

    div EBX

    mov [Result], EAX




    ;OUT

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]



    push 10
    push szMin2
    push [Min2]
    call ptr itoa
    add ESP, 3 * 4 

    push [Min2]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.Min2Mask
    push Min2Mask
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Min2]
    push szMin2
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]

    push 10
    push szMax2
    push [Max2]
    call ptr itoa
    add ESP, 3 * 4 

    push [Max2]
    call ptr lstrlen

    push NULL
    push stub       
    push sizeof.Max2Mask
    push Max2Mask
    push [hOutput]      
    call [WriteConsole]

    push 0
    push stub
    push [Max2]
    push szMax2
    push ptr hOutput
    call ptr WriteConsole

    push NULL
    push stub       
    push sizeof.newLine
    push newLine      
    push [hOutput]      
    call [WriteConsole]




    push NULL
    push stub       
    push sizeof.resultMask
    push resultMask      
    push [hOutput]      
    call [WriteConsole]


    push 10
    push szResult
    push [Result]
    call ptr itoa
    add ESP, 3 * 4 

    push 0
    push stub
    push [Result]
    push szResult
    push ptr hOutput
    call ptr WriteConsole
    ; ---
    push 0
    push stub
    push [Result]
    push szResult
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