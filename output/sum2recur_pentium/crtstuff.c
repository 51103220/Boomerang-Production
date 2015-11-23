// address: 0x804846d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    int local0; 		// m[esp - 12]

    __isoc99_scanf();
    eax = sum2recur(local0, 10);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x80484bd
__size32 sum2recur(int param1, int param2) {
    __size32 eax; 		// r24

    if (param1 >= 0 || param2 >= 0) {
        eax = sum2recur(param1 - 1, param2 - 2);
        eax += 3;
    } else {
        eax = 1;
    }
    return eax;
}

