__size32 fib1();
__size32 fib2(int param1);

// address: 0x10000504
int main(int argc, char *argv[], char *envp[]) {
    int g3; 		// r3
    int local0; 		// m[g1 - 24]

    printf("Input number: ");
    scanf("%d", &local0);
    g3 = fib1();
    printf("fibonacci(%d) = %d\n", local0, g3);
    return 0;
}

// address: 0x10000440
__size32 fib1() {
    __size32 g3; 		// r3

    g3 = fib2(g3);
    return g3;
}

// address: 0x10000480
__size32 fib2(int param1) {
    void *g1; 		// r1
    int g29; 		// r29
    int g3; 		// r3
    int g31; 		// r31

    if (param1 <= 1) {
    } else {
        fib1();
        g3 = fib1();
        *(__size32*)(g31 + 12) = g29 + g3;
    }
    g31 = g1 - 32;
    g3 = *(g31 + 12);
    return g3;
}

