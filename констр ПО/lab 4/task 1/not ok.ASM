format PE console NX

entry start

include 'WIN32A.INC'

section '.bss' data readable writeable 

hInput dd ?
hOutput dd ? 

stub dd ?
dwNumber dd ? 
buf db ?
numberOfChars1 dd ?

section '.data' data readable writeable 
message db 'Hello, world!'
sizeof.message = $ - message

f1 db '{'
sizeof.f1= $ - f1

f2 db '}'
sizeof.f2= $ - f2

firstStr dd ?
szfirstStr rb 30
sizeof.firstStr = $-szfirstStr



section '.text' code readable executable 

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX


  

;        push NULL
;    push numberOfChars1
;    push 1000
;    push firstStr
;    push [hInput]
;    call [ReadConsole]

     push 0
    push stub     
    push sizeof.f1
    push f1
    push [hOutput]      
    call [WriteConsole]

;    push NULL
;    push stub
;    push sizeof.firstStr
;    push firstStr
;    push [hOutput]
;    call [WriteConsole]

    push 0
    push stub     
    push sizeof.message
    push message       
    push [hOutput]      
    call [WriteConsole]

     push 0
    push stub     
    push sizeof.f2
    push f2
    push [hOutput]      
    call [WriteConsole]



        push NULL
    push numberOfChars1       
    push 1000
    push firstStr       
    push [hInput]   
    call [ReadConsole]


    push 0              
    call [ExitProcess]  

section '.idata' import data readable writeable

library kernel32, 'KERNEL32.DLL'

import kernel32,\
    ExitProcess, 'ExitProcess',\    
    GetStdHandle, 'GetStdHandle',\
    WriteConsole, 'WriteConsoleA',\
    ReadConsole, 'ReadConsoleA' 

section '.reloc' fixups data readable discardable