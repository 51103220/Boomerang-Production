// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    __size32 local0; 		// m[esp - 12]
    __size32 local1; 		// m[esp - 16]

    __isoc99_scanf();
    __isoc99_scanf();
    eax = add2(local1, local0);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x80484d1
__size32 add2(__size32 param1, __size32 param2) {
    return param2 + param1;
}

