.MODEL SMALL
.STACK 1000H
.DATA
		number DB "00000$"
.CODE
f PROC
		PUSH BP
		MOV BP, SP
		SUB SP, 2
L1:
		MOV AX, 5
		MOV [BP-2], AX
L2:
L4:
		MOV AX, [BP-2]
		PUSH DX
		MOV DX, AX
		MOV AX, 0
		CMP DX, AX
		JG L6
		MOV AX, 0
		JMP L7
L6:
		MOV AX, 1
L7:
		POP DX
		CMP AX, 0
		JE L3
L5:
		MOV AX, [BP+4]
		PUSH AX
		INC AX
		MOV [BP+4], AX
		POP AX
L8:
		MOV AX, [BP-2]
		PUSH AX
		DEC AX
		MOV [BP-2], AX
		POP AX
L9:
		JMP L4
L3:
		MOV AX, 3
		PUSH CX
		MOV CX, AX
		MOV AX, [BP+4]
		PUSH DX
		CWD
		MUL CX
		POP DX
		POP CX
		PUSH DX
		MOV DX, AX
		MOV AX, 7
		SUB DX, AX
		MOV AX, DX
		POP DX
		MOV BX,AX
L10:
		MOV AX, 9
		MOV [BP+4], AX
L11:
		ADD SP, 2
		POP BP
		RET 2
f ENDP
g PROC
		PUSH BP
		MOV BP, SP
		SUB SP, 2
		SUB SP, 2
L12:
		MOV AX, [BP+6]
		PUSH AX
		CALL f
		MOV AX, BX
		PUSH DX
		MOV DX, AX
		MOV AX, [BP+6]
		ADD AX, DX
		POP DX
		PUSH DX
		MOV DX, AX
		MOV AX, [BP+4]
		ADD AX, DX
		POP DX
		MOV [BP-2], AX
L13:
		MOV AX, 0
		MOV [BP-4], AX
L15:
		MOV AX, [BP-4]
		PUSH DX
		MOV DX, AX
		MOV AX, 7
		CMP DX, AX
		JL L17
		MOV AX, 0
		JMP L18
L17:
		MOV AX, 1
L18:
		POP DX
		CMP AX, 0
		JE L14
L16:
		MOV AX, [BP-4]
		PUSH CX
		MOV CX, AX
		MOV AX, 3
		PUSH DX
		PUSH AX
		PUSH CX
		POP AX
		POP CX
		CWD
		DIV CX
		MOV AX, DX
		POP DX
		POP CX
		PUSH DX
		MOV DX, AX
		MOV AX, 0
		CMP DX, AX
		JE L22
		MOV AX, 0
		JMP L23
L22:
		MOV AX, 1
L23:
		POP DX
		CMP AX, 0
		JE L21
L20:
		MOV AX, [BP-2]
		PUSH DX
		MOV DX, AX
		MOV AX, 5
		ADD AX, DX
		POP DX
		MOV [BP-2], AX
L24:
		JMP L19
L21:
		MOV AX, [BP-2]
		PUSH DX
		MOV DX, AX
		MOV AX, 1
		SUB DX, AX
		MOV AX, DX
		POP DX
		MOV [BP-2], AX
L25:
L19:
L26:
		MOV AX, [BP-4]
		PUSH AX
		INC AX
		MOV [BP-4], AX
		POP AX
		JMP L15
L14:
		MOV AX, [BP-2]
		MOV BX,AX
L27:
		ADD SP, 4
		POP BP
		RET 4
g ENDP
main PROC
		MOV AX, @DATA
		MOV DS, AX
		PUSH BP
		MOV BP, SP
		SUB SP, 2
		SUB SP, 2
		SUB SP, 2
L28:
		MOV AX, 1
		MOV [BP-2], AX
L29:
		MOV AX, 2
		MOV [BP-4], AX
L30:
		MOV AX, [BP-2]
		PUSH AX
		MOV AX, [BP-4]
		PUSH AX
		CALL g
		MOV AX, BX
		MOV [BP-2], AX
L31:
		MOV AX, [BP-2]
		CALL print_output
		CALL new_line
L32:
		MOV AX, 0
		MOV [BP-6], AX
L34:
		MOV AX, [BP-6]
		PUSH DX
		MOV DX, AX
		MOV AX, 4
		CMP DX, AX
		JL L36
		MOV AX, 0
		JMP L37
L36:
		MOV AX, 1
L37:
		POP DX
		CMP AX, 0
		JE L33
L35:
		MOV AX, 3
		MOV [BP-2], AX
L38:
L40:
		MOV AX, [BP-2]
		PUSH DX
		MOV DX, AX
		MOV AX, 0
		CMP DX, AX
		JG L42
		MOV AX, 0
		JMP L43
L42:
		MOV AX, 1
L43:
		POP DX
		CMP AX, 0
		JE L39
L41:
		MOV AX, [BP-4]
		PUSH AX
		INC AX
		MOV [BP-4], AX
		POP AX
L44:
		MOV AX, [BP-2]
		PUSH AX
		DEC AX
		MOV [BP-2], AX
		POP AX
L45:
		JMP L40
L39:
L46:
		MOV AX, [BP-6]
		PUSH AX
		INC AX
		MOV [BP-6], AX
		POP AX
		JMP L34
L33:
		MOV AX, [BP-2]
		CALL print_output
		CALL new_line
L47:
		MOV AX, [BP-4]
		CALL print_output
		CALL new_line
L48:
		MOV AX, [BP-6]
		CALL print_output
		CALL new_line
L49:
		MOV AX, 0
		MOV BX,AX
L50:
L51:
		POP BP
		MOV AX,4CH
		INT 21H
main ENDP
print_output proc  ;print what is in ax
		PUSH AX
		PUSH BX
		PUSH CX
		PUSH DX
		PUSH SI
		LEA SI,number
		MOV BX,10
		ADD SI,4
		CMP AX,0
		JNGE negate
		print:
		XOR DX,DX
		DIV BX
		MOV [SI],DL
		ADD [SI],'0'
		DEC SI
		CMP AX,0
		JNE print
		INC SI
		LEA DX,SI
		MOV AH,9
		INT 21H
		POP SI
		POP DX
		POP CX
		POP BX
		POP AX
		RET
		negate:
		PUSH AX
		MOV AH,2
		MOV DL,'-'
		INT 21H
		POP AX
		NEG AX
		JMP print
print_output ENDP

new_line proc
		push ax
		push dx
		mov ah,2
		mov dl,0Dh
		int 21h
		mov ah,2
		mov dl,0Ah
		int 21h
		pop dx
		pop ax
		ret
new_line endp
END main
