	MOV r1,#0
	MOV rip,rsp	;jumping back to caller

	JMP _while1
	MOV sp,pos	;place arguments on stack
	MOV rsp,rip;assign return address
	INC rsp;
	MOV ip,__putc	;jumping to instruction ::putc
	MOV rsp, 0
	MOV r1,#pos
	MOV r1,#arg
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	while1:
	JNZ _endwhile	;exit whileloop1
__main:
	MOV r0,#0
	MOV rip,rsp	;jumping back to caller

	MOV r1,#cursor
	MOV r1,#cursor
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#buffer
	MOV r0,#letter
	MOV %r1,r0	;place contents of RO(return value) in address in r1
__putc:
	MOV r1,#stress
	MOV r0,#12
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#0
	MOV rip,rsp	;jumping back to caller

	JMP _while1
	MOV sp,pos	;place arguments on stack
	MOV rsp,rip;assign return address
	INC rsp;
	MOV ip,__putc	;jumping to instruction ::putc
	MOV rsp, 0
	MOV r1,#pos
	MOV r1,#arg
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	while1:
	JNZ _endwhile	;exit whileloop1
__main:
	MOV r0,#0
	MOV rip,rsp	;jumping back to caller

	MOV r1,#cursor
	MOV r1,#cursor
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#buffer
	MOV r0,#letter
	MOV %r1,r0	;place contents of RO(return value) in address in r1
__putc:
	MOV r1,#stress
	MOV r0,#12
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#0
	MOV rip,rsp	;jumping back to caller

	JMP _while1
	MOV sp,pos	;place arguments on stack
	MOV rsp,rip;assign return address
	INC rsp;
	MOV ip,__putc	;jumping to instruction ::putc
	MOV rsp, 0
	MOV r1,#pos
	MOV r1,#arg
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	while1:
	JNZ _endwhile	;exit whileloop1
__main:
	MOV r0,#0
	MOV rip,rsp	;jumping back to caller

	MOV r1,#cursor
	MOV r1,#cursor
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#buffer
	MOV r0,#letter
	MOV %r1,r0	;place contents of RO(return value) in address in r1
__putc:
	MOV r1,#stress
	MOV r0,#12
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#0
	MOV rip,rsp	;jumping back to caller

	JMP _while1
	MOV sp,pos	;place arguments on stack
	MOV rsp,rip;assign return address
	INC rsp;
	MOV ip,__putc	;jumping to instruction ::putc
	MOV rsp, 0
	MOV r1,#pos
	MOV r1,#arg
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	while1:
	JNZ _endwhile	;exit whileloop1
__main:
	MOV r0,#0
	MOV rip,rsp	;jumping back to caller

	MOV r1,#cursor
	MOV r1,#cursor
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#buffer
	MOV r0,#letter
	MOV %r1,r0	;place contents of RO(return value) in address in r1
__putc:
	MOV r1,#stress
	MOV r0,#12
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#0
	MOV rip,rsp	;jumping back to caller

	JMP _while1
	MOV sp,pos	;place arguments on stack
	MOV rsp,rip;assign return address
	INC rsp;
	MOV ip,__putc	;jumping to instruction ::putc
	MOV rsp, 0
	MOV r1,#pos
	MOV r1,#arg
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	while1:
	JNZ _endwhile	;exit whileloop1
__main:
	MOV r0,#0
	MOV rip,rsp	;jumping back to caller

	MOV r1,#cursor
	MOV r1,#cursor
	MOV r0,#1
	ADD
	MOV %r1,r0	;place contents of RO(return value) in address in r1
	MOV r1,#buffer
	MOV r0,#letter
	MOV %r1,r0	;place contents of RO(return value) in address in r1
__putc:
	MOV r1,#stress
	MOV r0,#12
	MOV %r1,r0	;place contents of RO(return value) in address in r1
