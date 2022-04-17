.include "m328Pdef.inc"
Start:
        ldi r17, 0b11000011 ; identifying input pins 10,11,12,13
        out DDRD,r17            ; declaring pins as input
        ldi r17, 0b11111111 ;
        out PORTD,r17           ; activating internal pullup for pins 10,11,12,13  
        in r17,PINB
        
        ldi r20,0b00000010
        rcall loopr
        
        ldi r21,0b00000001
        and r21,r17 ;s
        lsr r17
        ldi r22,0b00000001
        and r22,r17 ;r
        lsr r17
        ldi r23,0b00000001
        and r23,r17 ;q
        lsr r17
        ldi r24,0b00000001
        and r24,r17 ;p
            
        ldi r25,0b00000001
        ldi r26,0b00000001
        eor r26,r24     ;p'
        eor r25,r23     ;q'
        
            mov r27,r21
        com r27    ;s'
            mov r28,r22 
            com r28    ;r’
   
            
            mov r19,r26
            mov r20,r27
            and r19,r20         ;p's'
            mov r31,r19
            com r31          ;(p’s’)’
      
            
           mov r19,r24
           mov r20,r25 
           and r19,r20          ;pq’
           mov r30,r19    
           com r30          ;(pq’)’
     
            
            mov r19,r23
            mov r20,r22
            and r19,r20         ;qr
            mov r29,r19
            com r29          ;(qr)’
 
            mov r19,r29
            mov r20,r25
            mov r17,r28
            and r19,r20         ;p'q'
            and r17,r19     ;p’q’r’ 
            mov r23,r17
            com r23          ;(p’q’r’)’ 
            
           
            mov r19,r26
            mov r20,r28
            mov r17,r21
            and r19,r20         ;p'r'
            and r19,r17    ;p’r’s
            mov r27,r19 
            com r27          ;(p’r’s)’ 
                 
   
        and r31,r30
            and r31,r29
            and r31,r23
            and r31,r27
        rcall loopl
        ldi r16, 0b00100000 ;identifying output pins 2,3,4,5
        out DDRB,r16            ;declaring pins as output
        out PORTB,r31           ;writing output to pins 2,3,4,5
        
        rjmp Start
loopr:  lsr r17
        dec r20
        brne loopr
        ret
loopl:  lsl r31
        dec r20
        brne loopl
        ret

