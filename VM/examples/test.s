.name "jemoeder"
.comment "aan het poeder"


load:
    lldi %0, %2, r2
    lldi r2, %1, r3
lfork %:load
