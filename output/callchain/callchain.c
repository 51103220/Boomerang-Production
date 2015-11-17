int add15(int param1);
int add10(int param1);
int add5(int param1);
void printarg(int param1);

// address: 0x10b64
int main(int argc, char *argv[], char *envp[]) {
    int o0; 		// r8

    o0 = add15(25);
    o0 = add10(o0);
    o0 = add5(o0);
    printarg(o0);
    return 0;
}

// address: 0x10b40
int add15(int param1) {
    return param1 + 15;
}

// address: 0x10b38
int add10(int param1) {
    return param1 + 10;
}

// address: 0x10b30
int add5(int param1) {
    return param1 + 5;
}

// address: 0x10b48
void printarg(int param1) {
    printf("Fifty five is %d\n", param1);
    return;
}

