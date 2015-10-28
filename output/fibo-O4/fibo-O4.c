int fib(int param1);

// address: 0x10ad0
int main(int argc, char *argv[], char *envp[]) {
    int local0; 		// m[o6 - 20]

    printf("Input number: ");
    scanf("%d", &local0);
    if (local0 <= 1) {
        fib(local0 - 1);
        fib(local0 - 2);
    }
}

// address: 0x10a9c
int fib(int param1) {
    int i0; 		// r24
    int o0; 		// r8
    int o0_1; 		// r8{38}

    i0 = param1;
    if (param1 > 1) {
        o0 = fib(param1 - 1);
        o0_1 = fib(param1 - 2);
        i0 = o0 + o0_1;
    }
    return i0;
}

