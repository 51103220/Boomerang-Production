// address: 0x10474
int main(int argc, char *argv[], char *envp[]) {
    __size8 r2; 		// r2
    __size8 r2_1; 		// r2{9}

    r2 = 10;
    do {
        r2_1 = r2;
        r2 = r2_1 - 1;
    } while (r2_1 - 1 != 0);
    return r2_1 - 1;
}

