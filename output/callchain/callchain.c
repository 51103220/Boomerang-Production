__size32 add15(__size32 param1);
__size32 add10(__size32 param1);
__size32 add5(__size32 param1);
void printarg(int param1);

// address: 0x10b64
int main(int argc, char *argv[], char *envp[]) {
    __size32 o0; 		// r8

    o0 = add15(25); /* Warning: also results in o0 */
    o0 = add10(o0); /* Warning: also results in o0 */
    o0 = add5(o0); /* Warning: also results in o0 */
    printarg(o0);
    return 0;
}

// address: 0x10b40
__size32 add15(__size32 param1) {
    return param1 + 15;
}

// address: 0x10b38
__size32 add10(__size32 param1) {
    return param1 + 10;
}

// address: 0x10b30
__size32 add5(__size32 param1) {
    return param1 + 5;
}

// address: 0x10b48
void printarg(int param1) {
    printf("Fifty five is %d\n", param1);
    return;
}

