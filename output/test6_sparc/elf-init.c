// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int o0; 		// r8

    __isoc99_scanf();
    o0 = add1();
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x10548
__size32 add1() {
    __size32 o0; 		// r8

    o0 = add2();
    return o0;
}

// address: 0x10568
__size32 add2() {
    __size32 g1; 		// r1

    return g1 + 2;
}

