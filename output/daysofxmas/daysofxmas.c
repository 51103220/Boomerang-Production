int global21;

// address: 0x106a8
int main(int argc, char *argv[], union { char *[] * x9; char * x10; } envp) {
    int i0; 		// r24
    union { int x13; void * x14; } i0_1; 		// r24
    union { int x13; void * x14; } i0_2; 		// r24
    union { int x13; void * x14; } i0_3; 		// r24
    union { int x13; void * x14; } i0_4; 		// r24
    union { int x13; void * x14; } local16; 		// i0_4{356}
    int o0; 		// r8
    union { int x13; void * x14; } o0_1; 		// r8
    char * *o0_3; 		// r8
    union { int x13; void * x14; } o0_4; 		// r8
    __size8 *o0_5; 		// r8
    union { int x13; void * x14; } o0_6; 		// r8
    union { char *[] * x11; int x12; } o1_2; 		// r9
    union { int x15; char *[] * x16; } o1_5; 		// r9
    unsigned int o1_7; 		// r9
    union { char *[] * x9; char * x10; } o2_2; 		// r10

    if (argc <= 1) {
        if (argc < 0) {
            if (argc < -72) {
L2:
                o0_4 = main(o0_3, o1_2, o2_2);
                i0_1 = o0_4;
                local16 = i0_1;
            } else {
                o0 = (int) *envp;
                if (argc >= -50) {
                    goto L2;
                } else {
                    if (argv == o0) {
                        global21 = global21 - 1;
                        if (global21 - 1 < 0) {
                            __flsbuf();
                            i0_3 = o0_6;
                            local16 = i0_3;
                        } else {
                            o1_7 = *(unsigned char*)(envp + 31);
                            o0_5 = *0x20cf4;
                            i0 = o1_7;
                            *(__size8*)o0_5 = (char) o1_7;
                            *(void **)0x20cf4 = o0_5 + 1;
                            local16 = i0;
                        }
                    } else {
                        goto L2;
                    }
                }
            }
        } else {
            if (argc <= 0) {
                o1_5 = (int) *envp;
                i0_2 = 0;
                local16 = i0_2;
                if (o1_5 == 47) {
L15:
                    i0 = 1;
                    local16 = i0;
                } else {
                    o0_3 = main(-61, o1_5, 0x10948);
                    o0 = main(0, o0_3, envp + 1);
                    if (o0 != 0) {
                        goto L15;
                    }
                }
            } else {
                goto L2;
            }
        }
    } else {
        if (argc <= 2) {
            o0 = main(-86, 0, envp + 1);
            o0 = main(-87, 1 - argv, envp + o0);
            main(-79, -13, envp + o0);
        }
        if (argc < argv) {
            main(argc + 1, argv, envp);
        }
        o0_1 = main(-94, argc - 27, envp);
        i0 = 16;
        local16 = i0;
        if (argc == 2) {
            if (argv <= 12) {
                goto L2;
            } else {
                i0 = 9;
                local16 = i0;
            }
        }
    }
    i0_4 = local16;
    return i0_4;
}

