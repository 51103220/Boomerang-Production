int fib(int param1);

// address: 0x80483cf
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24

    eax = fib(10);
    printf("%i\n", eax);
    return 0;
}

// address: 0x8048390
int fib(int param1) {
    int eax; 		// r24
    int eax_1; 		// r24{30}
    int local4; 		// m[esp - 12]

    if (param1 <= 1) {
        local4 = param1;
    } else {
        eax = fib(param1 - 1);
        eax_1 = fib(param1 - 2);
        local4 = eax + eax_1;
    }
    return local4;
}

