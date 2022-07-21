//ヘッダーファイルをインクルード

#include "kimatu_data.h"
#include "judge.cpp"
#include "match.cpp"


//sleep関数を使うための記述
static void sleep(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

//Player_A
void Player_A() {
    int total = 0;      // 全単位数
    int num;

    // 単位が100になるまでループ
    while (total < 100) {

        printf("Aは %d 個取得。\n", total);
        // 家から学校へ
        sleep(A_idou_time);

        // 単位を取得する
        num = A_have;

        // 学校から家に帰る
        sleep(A_idou_time);

        if (B_rank == 0 || C_rank == 0) {
            break;
        }
        //全単位数を加算
        total += num;
    }

    A_rank = 0;
    if (A_rank == 0) {
        B_rank = 0;
        C_rank = 0;
    }

    A_sum = total;
    printf("結果：Player_Aは %d 単位取得しました。\n", total);
}

void Player_B() {
    int total = 0;       // 全単位数
    int num;

    // 単位が100になるまでループ
    while (total < 100) {

        printf("Bは %d 個取得。\n", total);
        // 家から学校へ
        sleep(B_idou_time);

        // 単位を取得する
        num = B_have;

        // 学校から家に帰る
        sleep(B_idou_time);

        if (A_rank == 0 || C_rank == 0) {
            break;
        }
        //全単位数を加算
        total += num;
    }

    B_rank = 0;
    if (B_rank == 0) {
        A_rank = 0;
        C_rank = 0;
    }

    B_sum = total;
    printf("結果：Player_Bは %d 単位取得しました。\n", total);
}

void Player_C() {
    int total = 0;      // 全単位数
    int num;

    // 単位が100になるまでループ
    while (total < 100) {

        printf("Cは %d 個取得。\n", total);
        // 家から学校へ
        sleep(C_idou_time);

        // 単位を取得する
        num = C_have;

        // 学校から家に帰る
        sleep(C_idou_time);

        if (A_rank == 0 || B_rank == 0) {
            break;
        }
        //全単位数を加算
        total += num;

    }

    C_rank = 0;
    if (C_rank == 0) {
        A_rank = 0;
        B_rank = 0;
    }

    C_sum = total;
    printf("結果：Player_Cは %d 単位取得しました。\n", total);
}

//randomを生成する関数
int GetRandom(int min, int max)
{
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

int main()
{
    // カレントディレクトリの取得
    char s_currentDir[_MAX_PATH];
    GetCurrentDirectory(sizeof(s_currentDir), s_currentDir);
    // ファイルパスの作成(iniファイルから読み込み)
    char s_inifile[_MAX_PATH];
    sprintf_s(s_inifile, "%s\\kimatu_player_data.ini", s_currentDir);

   //randomに必要な記述
    srand((unsigned int)time(NULL));

    //構造体にiniファイルのデータを格納
    struct Player A,B,C;
    //Player_A
    A.idou_time = GetPrivateProfileInt("A", "idou_time", -1, s_inifile);

    A_idou_time = A.idou_time;

    //Aのみfor文で回すことで実行ごとに変わるようにした。
    for (int i = 0; i < 3; i++) {
        A_have = GetRandom(4, 7);
    }
    //Player_B
    B.idou_time = GetPrivateProfileInt("B", "idou_time", -1, s_inifile);

    B_idou_time = B.idou_time;

    B_have = GetRandom(8, 13);

    //Player_C
   C.idou_time = GetPrivateProfileInt("C", "idou_time", -1, s_inifile);

    C_idou_time = C.idou_time;

    C_have = GetRandom(15, 25);

    printf("Playerは家から学校に単位を取りにいかなければならない。単位をとると家に戻り単位を換算しなければならない。\nAは片道1秒、Bは片道2秒、Cは片道4秒\nAは4～7単位、Bは8～13単位、Cは15～25単位とし先に単位を100個取得した者が勝とする。\n");
    printf("A,B,CどのPlayerが何位になるか予想せよ\n");
    printf("A:");
    scanf_s("%d", &A_Number);
    printf("B:");
    scanf_s("%d", &B_Number);
    printf("C:");
    scanf_s("%d", &C_Number);
    printf("Let's start!!!\n");
    //スレッドを実行

    std::thread personA(Player_A);
    std::thread personB(Player_B);
    std::thread personC(Player_C);
    personA.join();
    personB.join();
    personC.join();

    //勝負の結果を処理している。
    judge();
    match();

    //ファイル出力
    FILE* fp;
    errno_t error;
    error = fopen_s(&fp, "kimatu_result.txt", "w");
    if (error != 0)
        fprintf_s(stderr, "failed to open");
    else {
        char s_buf[BUFFSIZE];
        fprintf(fp, "Player_A: %d単位, Player_B: %d単位, Player_C: %d単位\n", A_sum, B_sum,C_sum);
        fprintf(fp, "Player_A: %d位, Player_B: %d位, Player_C: %d位", A_result, B_result, C_result);
        fclose(fp);
    }
    return 0;
}