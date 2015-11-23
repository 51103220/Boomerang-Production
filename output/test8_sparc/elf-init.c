// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    __size32 g3; 		// r3
    int o0; 		// r8
    int o2; 		// r10

    __isoc99_scanf();
    o0 = add1(o2, 10, g3 + 10, 10);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x10568
__size32 add1(__size32 param2, __size32 param3, __size32 param4, __size32 param4) {
    __size32 o0; 		// r8

    o0 = add2(param2, param3, param4, param4);
    return o0;
}

// address: 0x10594
__size32 add2(__size32 param1, __size32 param2, __size32 param3, __size32 param4) {
    __size32 g2; 		// r2

    g2 = param3 + param2 + param1 + 2;
    return g2 + param4;
}

