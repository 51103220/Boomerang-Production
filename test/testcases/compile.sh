for f in *.c ; do sparc-unknown-linux-gnu-gcc "$f" -o  "${f%.c}_sparc" ; done
for f in *.c ; do sparc-unknown-linux-gnu-gcc -S "$f" -o  "${f%.c}_sparc.s" ; done
for f in *.c ; do gcc "$f" -o "${f%.c}_pentium" ; done
for f in *.c ; do gcc -S "$f" -o  "${f%.c}_pentium.s" ; done

