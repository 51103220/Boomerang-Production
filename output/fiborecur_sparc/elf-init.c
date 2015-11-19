// address: 0x10514
int main(int argc, char *argv[], char *envp[]) {
    int local0; 		// m[o6 - 12]
    __size32 local1; 		// m[o6 - 4]
    int local2; 		// m[o6 - 8]
    __size32 o0; 		// r8

    local1 = 0;
    __isoc99_scanf();
    puts("Fibonacci series");
    local2 = 1;
    while (local2 <= local0) {
        o0 = Fibonacci(local1);
        printf("%d\n", o0);
        local1++;
        local2++;
    }
    return 0;
}

// address: 0x105b8
__size32 Fibonacci(__size32 param1) {
    __size32 g1; 		// r1
    __size32 o0; 		// r8
    __size32 o0_1; 		// r8{52}

    if (param1 != 0) {
        if (param1 != 1) {
            o0 = Fibonacci(param1 - 1);
            o0_1 = Fibonacci(param1 - 2);
            g1 = o0 + o0_1;
        } else {
            g1 = 1;
        }
    } else {
        g1 = 0;
    }
    return g1;
}

