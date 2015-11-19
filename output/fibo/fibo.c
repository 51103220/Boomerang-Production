int fib();

// address: 0x100004c4
int main(int argc, char *argv[], char *envp[]) {
    int g3; 		// r3
    int local0; 		// m[g1 - 24]

    printf("Input number: ");
    scanf("%d", &local0);
    g3 = fib();
    printf("fibonacci(%d) = %d\n", local0, g3);
    return 0;
}

// address: 0x10000440
int fib() {
    int g3; 		// r3
    int g3_1; 		// r3{24}
    __size32 g9; 		// r9
    int local5; 		// m[g1 - 20]

    if (g3 <= 1) {
        local5 = g3;
    } else {
        g3 = fib();
        g3_1 = fib(); /* Warning: also results in g9 */
        local5 = g3 + g3_1;
    }
    return local5; /* WARNING: Also returning: g9 := g9 */
}

