// address: 0x104f4
int main(int argc, char *argv[], char *envp[]) {
    int local0; 		// m[o6 - 4]
    int o0; 		// r8
    int o5; 		// r13

    __isoc99_scanf();
    o0 = plusandminus(local0, o5);
    printf("%d\n", o0);
    return 0;
}

// address: 0x1054c
__size32 plusandminus(int param1, __size32 param2) {
    __size32 g1; 		// r1
    __size32 i5; 		// r29
    int o0; 		// r8
    int o0_1; 		// r8{52}
    __size32 o5; 		// r13

    i5 = param2;
    if (param1 > 0) {
        if (param1 <= 100) {
            o0 = plusandminus(param1 - 1, param2); /* Warning: also results in o5 */
            i5 = o0;
            o0_1 = plusandminus(param1 + 2, o5);
            g1 = o0 + o0_1;
        } else {
            g1 = 100;
        }
    } else {
        g1 = 0;
    }
    return g1; /* WARNING: Also returning: o5 := i5 */
}

