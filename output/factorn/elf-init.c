// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    __size32 local0; 		// m[o6 - 8]
    int o0; 		// r8

    __isoc99_scanf();
    o0 = factor(local0);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x1054c
__size32 factor(__size32 param1) {
    __size32 g1; 		// r1
    __size32 o0; 		// r8

    if (param1 != 1) {
        factor(param1 - 1);
        o0 = .umul();
        g1 = o0;
    } else {
        g1 = 1;
    }
    return g1;
}

// address: 0x105ac
__size32 .umul() {
    int o0; 		// r8
    int o1; 		// r9

    if (((o0 | o1) & 0xfffff000) == 0) {
    } else {
    }
    return /* machine specific */ (int) Y;
}

