// address: 0x104b4
int main(int argc, char *argv[], char *envp[]) {
    __size32 o0; 		// r8

    o0 = add15(25);
    o0 = add10(o0);
    o0 = add5(o0);
    printarg(o0);
    return 0;
}

// address: 0x10514
__size32 add15(__size32 param1) {
    return param1 + 15;
}

// address: 0x10534
__size32 add10(__size32 param1) {
    return param1 + 10;
}

// address: 0x10554
__size32 add5(__size32 param1) {
    return param1 + 5;
}

// address: 0x10574
void printarg(int param1) {
    printf("Fifty five is %d\n", param1);
    return;
}

