	org 07c00h	;将程序加载到7c00h处，内存7c00h，是计算机完成自检后执行的位置
	mov ax,cs
	mov ds,ax
	mov es,ax
	call DispStr
	jmp $
DispStr:
	mov ax,BootMessage
	mov bp,ax
	mov cx,16
	mov ax,01301h
	mov bx,000ch
	mov dl,0
	int 10h
	ret
BootMessage:
times 510-($-$$)
dw 	  0xaa55

