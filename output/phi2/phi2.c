void proc1(int param1, char param2[], int param3);

// address: 0x100004f4
int main(int argc, char *argv[], char *envp[]) {
    __size32 g4; 		// r4
    int local0; 		// m[g1 - 64]

    g4 = *(argv + 4);
    proc1(argc, g4, local0);
    printf("%d\n", argc);
    return 0;
}

// address: 0x10000440
void proc1(int param1, char param2[], int param3) {
    int g3_1; 		// r3
    int g3_2; 		// r3{21}
    int local0; 		// m[g1 - 40]
    int local1; 		// m[g1 - 32]
    int local2; 		// param3{69}

    local2 = param3;
    if (param1 <= 2) {
        strlen(param2);
        local0 = g3_1;
    } else {
        strlen(param2);
        local0 = g3_1;
        strlen(param2);
        local1 = g3_2;
        printf("%d", g3_1 + g3_2);
        local2 = local1;
    }
    param3 = local2;
    printf("%d, %d", local0, param3);
    return;
}

