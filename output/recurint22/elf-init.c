// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int local0; 		// m[o6 - 8]
    int o0; 		// r8

    __isoc99_scanf();
    o0 = .umul();
    o0 = add2(local0, o0);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x10624
__size32 .umul() {
    int o0; 		// r8
    int o1; 		// r9

    if (((o0 | o1) & 0xfffff000) == 0) {
    } else {
    }
    return /* machine specific */ (int) Y;
}

// address: 0x105c8
__size32 add2(int param1, __size32 param2) {
    __size32 g1; 		// r1
    int o0; 		// r8

    if (param1 > 0) {
        o0 = add1(param1 - 1);
        g1 = param2 + o0 + 2;
    } else {
        g1 = 1;
    }
    return g1;
}

// address: 0x1056c
__size32 add1(int param1) {
    __size32 g1; 		// r1
    int o0; 		// r8

    if (param1 > 0) {
        o0 = add2(param1 - 1, param1 + 2);
        g1 = o0 + 1;
    } else {
        g1 = 1;
    }
    return g1;
}

