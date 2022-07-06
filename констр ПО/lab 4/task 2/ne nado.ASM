format PE console NX
  
entry start

include 'WIN32A.INC'

section '.bss' data readable writeable 

hInput dd ?
hOutput dd ? 

stub dd ?
numberOfChars1 dd ? 
numberOfChars2 dd ? 
numberOfChars3 dd ?

section '.data' data readable writeable 
newLine db 13,10

firstStr db 256 dup (0x15)
secondStr db 256 dup (0x15)
thirdStr db 256 dup (0x15)


frame1 db 0x00,0x00, 0xC9, 10 dup (0xCD), 0xBB, 13, 10, 0x00,0x00, 0xBA

sizeof.frame1 = $ - frame1

frame2 db  0xBA, 13,10, 0x00,0xC9,0xCA, 9 dup (0xCD),0xCB,0xBC, \
 13, 10, 0x00, 0xBA
sizeof.frame2 = $ - frame2

frame3 db  0xBA, 13, 10, 0xC9,0xCA, 9 dup(0xCD), 0xCB,0xBC,13,10, 0xBA
sizeof.frame3 = $ - frame3

frame4 db 0xBA, 13, 10,  0xC8,10 dup(0xCD), 0xBC
sizeof.frame4 = $ - frame4

section '.text' code readable executable 

start:

    push STD_INPUT_HANDLE
    call [GetStdHandle]
    mov [hInput], EAX

    push STD_OUTPUT_HANDLE
    call [GetStdHandle]
    mov [hOutput], EAX

    ; ???? ?????? ??????
    push NULL
    push numberOfChars1       
    push 1000
    push firstStr       
    push [hInput]   
    call [ReadConsole] 

    ; ???? ?????? ??????
    push NULL
    push numberOfChars2   
    push 1000   
    push secondStr       
    push [hInput]   
    call [ReadConsole] 

    ; ???? ??????? ??????
    push NULL
    push numberOfChars3  
    push 1000   
    push thirdStr       
    push [hInput]   
    call [ReadConsole] 

    mov EBX, firstStr
    mov EAX, [numberOfChars1]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    mov EBX, secondStr
    mov EAX, [numberOfChars2]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    mov EBX, thirdStr
    mov EAX, [numberOfChars3]
    mov byte [ EBX + EAX - 1 ], 0x15
    mov byte [ EBX + EAX - 2 ], 0x15

    ; ????? ????? ??????
    push NULL              
    push stub    
    push 2
    push newLine       
    push [hOutput]      
    call [WriteConsole]

    ; -----------
    push NULL
    push stub       
    push sizeof.frame1
    push frame1      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ; ????? ?????? ??????
    push NULL              
    push stub    
    push 10
    push firstStr       
    push [hOutput]      
    call [WriteConsole]

    ; -----------
    push NULL
    push stub       
    push sizeof.frame2
    push frame2      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ;????? ?????? ??????
    push NULL              
    push stub    
    push 10
    push secondStr       
    push [hOutput]      
    call [WriteConsole] 

    ; -----------
    push NULL
    push stub       
    push sizeof.frame3
    push frame3      
    push [hOutput]      
    call [WriteConsole]
    ; -----------

    ; ????? ??????? ??????
    push NULL              
    push stub    
    push 10
    push thirdStr       
    push [hOutput]      
    call [WriteConsole] 

    ; -----------
    push NULL
    push stub       
    push sizeof.frame4
    push frame4
    push [hOutput]      
    call [WriteConsole]
    ; -----------

     push 0
    push stub     
    push 1           
    push frame4          
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