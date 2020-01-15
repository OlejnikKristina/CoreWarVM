#by zaz, still not as good as rainbowdash though
#2013

.name		"helltrain"
.comment	"choo-choo, motherf*****s !"

entry:
	sti		r1, %:beegees_gen, %1
	sti		r1, %:beegees, %1
	sti		r1, %:cc_spawn, %1
	sti		r1, %:wall, %1
	sti		r1, %:cc4, %1
	sti		r1, %:cc4, %9
	sti		r1, %:cc4, %17
	sti		r1, %:cc4l, %1
	sti		r1, %:cc4ld, %2
	sti		r1, %:cc3, %1
	sti		r1, %:cc3, %9
	sti		r1, %:cc2, %1
	ld		%0, r16
	fork	%:cc_spawn