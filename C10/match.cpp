

int match() {
    if (A_Number == A_result && B_Number == B_result && C_Number == C_result) {
        printf("you are a genius!!!");
    }
    else if ((A_Number == A_result && B_Number == B_result) || (B_Number == B_result && C_Number == C_result) || (A_Number == A_result && C_Number == C_result)) {
        printf("you win!!");
    }
    else if (A_Number != A_result && B_Number != B_result && C_Number != C_result) {
        printf("you lose...");
    }
    else {
        printf("The game was drawn!");
    }
    return 0;
}
