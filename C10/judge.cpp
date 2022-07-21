
int judge() {
    if (A_sum > B_sum && A_sum > C_sum) {
        A_result = 1;
    }
    else if (A_sum < B_sum && A_sum < C_sum) {
        A_result = 3;
    }
    else {
        A_result = 2;
    }

    if (B_sum > A_sum && B_sum > C_sum) {
        B_result = 1;
    }
    else if (B_sum < A_sum && B_sum < C_sum) {
        B_result = 3;
    }
    else {
        B_result = 2;
    }

    if (C_sum > A_sum && C_sum > B_sum) {
        C_result = 1;
    }
    else if (C_sum < A_sum && C_sum < B_sum) {
        C_result = 3;
    }
    else {
        C_result = 2;
    }
    return 0;
}