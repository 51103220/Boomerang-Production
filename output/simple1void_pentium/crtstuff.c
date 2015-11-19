// address: 0x804849d
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24
    __size32 local0; 		// m[esp - 12]

    __isoc99_scanf();
    eax = add1(local0);
    printf("Sum = %ld\n", eax);
    return 0;
}

// address: 0x80484e5
__size32 add1(__size32 param1) {
    printscreen("Helloworld");
    return param1 + 1;
}

// address: 0x80484ff
void printscreen(char *param1) {
    puts(param1);
    return;
}

