void twofib();

// address: 0x80483f5
int main(int argc, char *argv[], char *envp[]) {
    int local0; 		// m[esp - 8]
    int local1; 		// m[esp - 20]

    printf("Enter number: ");
    scanf("%d", &local0);
    twofib();
    printf("Fibonacci of %d is %d\n", local0, local1);
    return 0;
}

// address: 0x804839c
void twofib() {
    __size32 local11; 		// m[esp - 12]{64}
    __size32 local12; 		// local11{64}
    int local2; 		// m[esp - 12]
    int local3; 		// m[esp - 8]
    __size32 local9; 		// m[esp + 8]

    if (local9 != 0) {
        twofib();
        local11 = local3;
        local3 += local2;
        local12 = local11;
    } else {
        local2 = 0;
        local3 = 1;
        local12 = local2;
    }
    local11 = local12;
    *(__size32*)local10 = local11;
    *(__size32*)(local10 + 4) = local3;
    return;
}

