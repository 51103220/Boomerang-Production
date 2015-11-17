for f in *.c ; do sparc-unknown-linux-gnu-gcc "$f" -o  "${f%.c}" ; done
for f in *.c ; do sparc-unknown-linux-gnu-gcc -S "$f" -o  "${f%.c}.s" ; done
