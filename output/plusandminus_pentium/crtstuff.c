// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    int local0; 		// m[esp - 8]

    __isoc99_scanf();
    eax = plusandminus(local0);
    printf("%d\n", eax);
    return 0;
}

// address: 0x80484ad
__size32 plusandminus(int param1) {
    __size32 eax; 		// r24
    int eax_1; 		// r24{37}

    if (param1 > 0) {
        if (param1 <= 100) {
            eax = plusandminus(param1 - 1);
            eax_1 = plusandminus(param1 + 2);
            eax = eax_1 + eax;
        } else {
            eax = 100;
        }
    } else {
        eax = 0;
    }
    return eax;
}

