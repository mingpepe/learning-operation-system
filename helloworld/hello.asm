	org  07c00h
	mov	ax, cs
	mov	ds, ax
	mov	es, ax
	call	hello
	jmp	$
hello:
	mov	ax, msg
	mov	bp, ax
	mov	cx, 11
	mov	ax, 01301h
	mov	bx, 000ch
	mov	dl, 0
	int	10h
	ret
msg:		db	"Hello world"
times 	510-($-$$)	db	0
dw 	0xaa55