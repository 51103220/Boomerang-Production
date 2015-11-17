int fib(int param1);

// address: 0x100004fc
int main(int argc, char *argv[], char *envp[]) {
    int g3; 		// r3
    int local0; 		// m[g1 - 24]

    printf("Input number: ");
    scanf("%d", &local0);
    g3 = fib(local0);
    printf("fibonacci(%d) = %d\n", local0, g3);
    return 0;
}

// address: 0x10000440
int fib(int param1) {
    int g3; 		// r3
    int g3_2; 		// r3{24}
    int local5; 		// m[g1 - 32]

    if (param1 <= 1) {
        if (param1 != 1) {
            local5 = param1;
        } else {
            local5 = 1;
        }
    } else {
        g3 = fib(param1 - 1);
        g3_2 = fib(g3 - 1);
        printf("%d", g3 + g3_2);
        local5 = g3;
    }
    return local5;
}

