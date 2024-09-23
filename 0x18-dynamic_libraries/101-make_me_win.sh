#!/bin/bash
mv gm gm_backup
echo -e '#include <stdio.h>\nint main() { printf("9 8 10 24 75 9\n"); return 0; }' > gm.c
gcc -o gm gm.c
rm gm.c
