// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    __size32 local0; 		// m[esp - 12]

    __isoc99_scanf();
    eax = factor(local0);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x80484b5
int factor(__size32 param1) {
    int eax; 		// r24

    if (param1 != 1) {
        eax = factor(param1 - 1);
        eax = param1 * eax;
    } else {
        eax = 1;
    }
    return eax;
}

