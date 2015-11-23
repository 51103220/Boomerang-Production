// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int local0; 		// m[o6 - 8]
    int o0; 		// r8

    __isoc99_scanf();
    o0 = add1(local0);
    printf("Sum = %ld\n", o0);
    return 0;
}

// address: 0x1054c
__size32 add1(int param1) {
    __size32 g1; 		// r1
    int o0; 		// r8

    if (param1 > 0) {
        o0 = add2(param1 - 1);
        g1 = o0 + 1;
    } else {
        g1 = 1;
    }
    return g1;
}

// address: 0x1059c
__size32 add2(int param1) {
    __size32 g1; 		// r1
    int i5; 		// r29
    int o0; 		// r8

    if (param1 > 0) {
        o0 = add1(param1 - 1);
        g1 = i5 + o0;
    } else {
        g1 = 1;
    }
    return g1;
}

