.name		"zork"
.comment	"I'M ALIIIIVE"

	sti r1, %15, %1
	and r1, %0, r1
	live %1
	zjmp %-5
