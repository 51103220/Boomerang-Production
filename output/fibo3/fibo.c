// address: 0x80483f6
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    int local0; 		// m[esp - 12]

    printf("Input number: ");
    scanf("%d", &local0);
    eax = fib(local0);
    printf("fibonacci(%d) = %d\n", local0, eax);
    return 0;
}

// address: 0x80483b0
int fib(int param1) {
    int eax; 		// r24
    int eax_1; 		// r24{43}
    int local2; 		// m[esp - 12]

    if (param1 <= 1) {
        local2 = param1;
    } else {
        eax = fib(param1 - 1);
        eax_1 = fib(param1 - 2);
        local2 = eax + eax_1;
    }
    return local2;
}

