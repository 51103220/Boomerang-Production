__size32 fib(int param1);

// address: 0x100004a8
int main(int argc, char *argv[], char *envp[]) {
    int g3; 		// r3
    __size32 g3_2; 		// r3{45}
    int local0; 		// m[g1 - 24]

    printf("Input number: ");
    scanf("%d", &local0);
    if (local0 > 1) {
        g3 = fib(local0 - 1);
        g3_2 = fib(local0 - 2);
        printf("fibonacci(%d) = %d\n", local0, g3 + g3_2);
    } else {
        printf("fibonacci(%d) = %d\n", local0, local0);
    }
    return 0;
}

// address: 0x10000434
__size32 fib(int param1) {
    __size32 g0; 		// r0
    int g3; 		// r3
    __size32 g3_1; 		// r3{26}

    g0 = /* machine specific */ (int) LR;
    if (param1 > 1) {
        g3 = fib(param1 - 1);
        g0 = fib(param1 - 2); /* Warning: also results in g3_1 */
        g3 += g3_1;
    } else {
        g3 = param1;
    }
    return g0; /* WARNING: Also returning: g3 := g3 */
}

