__size32 proc1(__size32 param1, __size32 param2);

// address: 0x1000044c
int main(int argc, char *argv[], char *envp[]) {
    int g3; 		// r3

    g3 = proc1(11, 4);
    printf("%i\n", g3);
    return g3;
}

// address: 0x10000418
__size32 proc1(__size32 param1, __size32 param2) {
    return param1 - param2;
}

