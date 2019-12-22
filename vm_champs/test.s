.name "test"
.comment "this is a test file"

loop:
        sti r1, %:live, %1
live:
        live %0
        ld %0, r2
        zjmp %:loop2

loop2:
        sti r1, %1, %1
