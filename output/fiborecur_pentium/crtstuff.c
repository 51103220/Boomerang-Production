// address: 0x804849d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    int local0; 		// m[esp - 16]
    __size32 local1; 		// m[esp - 12]
    int local3; 		// m[esp - 8]

    local1 = 0;
    __isoc99_scanf();
    puts("Fibonacci series");
    local3 = 1;
    while (local3 <= local0) {
        eax = Fibonacci(local1);
        printf("%d\n", eax);
        local1++;
        local3++;
    }
    return 0;
}

// address: 0x804850f
__size32 Fibonacci(__size32 param1) {
    __size32 eax; 		// r24
    __size32 eax_1; 		// r24{37}

    if (param1 != 0) {
        if (param1 != 1) {
            eax = Fibonacci(param1 - 1);
            eax_1 = Fibonacci(param1 - 2);
            eax = eax_1 + eax;
        } else {
            eax = 1;
        }
    } else {
        eax = 0;
    }
    return eax;
}

