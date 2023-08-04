#include <iostream>
#include <cstdlib> 
#include <ctime>    
#include <vector>
#include <algorithm> 

int Rule1(int player1Number, int player2Number) {
    if ((player1Number == 41 && player2Number == 43) || (player1Number == 43 && player2Number == 42) || (player1Number == 42 && player2Number == 41)) {
        return 4;
    }
    return 0;
}
int Rule2(int player1Number, int player2Number) {
    if ((player1Number == 43 && player2Number == 41) || (player1Number == 41 && player2Number == 42) || (player1Number == 42 && player2Number == 43)) {
        return 4;
    }
    return 0;
}
int Rule3(int player1Number, int player2Number) {
    if ((player1Number == 32 && player2Number == 31) || (player2Number == 32 && player1Number == 31)) {
        return 1;
    }
    return 0;
}
int Rule4(int player1Number, int player2Number) {
    if ((player1Number == 22 && player2Number == 21) || (player2Number == 22 && player1Number == 21)) {
        return 1;
    }
    return 0;
}
int Rule5(int player1Number, int player2Number) {
    if ((player1Number == 12 && player2Number == 11) || (player1Number == 11 && player2Number == 12) || (player1Number == 12 && player2Number == 13) || (player1Number == 13 && player2Number == 12) || (player1Number == 11 && player2Number == 13) || (player1Number == 13 && player2Number == 11)) {
        return 1;
    }
    return 0;
}
int Rule6(int player1Number, int player2Number) {
    if (((player1Number == 43) || (player1Number == 42) || (player1Number == 41)) && ((12 < player2Number) && (player2Number < 40))) {
        return 40;
    }
    return 0;
}
int Rule7(int player1Number, int player2Number) {
    if (((player2Number == 43) || (player2Number == 42) || (player2Number == 41)) && ((12 < player1Number) && (player1Number < 40))) {
        return 40;
    }
    return 0;
}
int Rule8(int player1Number, int player2Number) {
    if (((player1Number == 32) || (player1Number == 31)) && (((20 < player2Number) && (player2Number < 30)) || (player2Number != 11))) {
        return 30;
    }
    return 0;
}
int Rule9(int player1Number, int player2Number) {
    if (((player2Number == 32) || (player2Number == 31)) && (((20 < player1Number) && (player1Number < 30)) || (player1Number != 11))) {
        return 30;
    }
    return 0;
}
int Rule10(int player1Number, int player2Number) {
    if (((player1Number == 32) || (player1Number == 31)) && (player2Number == 12)) {
        return 1;
    }
    return 0;
}
int Rule11(int player1Number, int player2Number) {
    if (((player2Number == 32) || (player2Number == 31)) && (player1Number == 12)) {
        return 1;
    }
    return 0;
}
int Rule12(int player1Number, int player2Number) {
    if (((player1Number == 22) || (player1Number == 21)) && (player2Number == 11)) {
        return 1;
    }
    return 0;
}
int Rule13(int player1Number, int player2Number) {
    if (((player2Number == 22) || (player2Number == 21)) && (player1Number == 11)) {
        return 1;
    }
    return 0;
}
int Rule14(int player1Number, int player2Number) {
    if ((player1Number == 11) && ((player2Number == 43) || (player2Number == 42) || (player2Number == 41))) {
        return 1;
    }
    return 0;
}
int Rule15(int player1Number, int player2Number) {
    if ((player2Number == 11) && ((player1Number == 43) || (player1Number == 42) || (player1Number == 41))) {
        return 1;
    }
    return 0;
}
int Rule16(int player1Number, int player2Number) {
    if ((player1Number == 12) && ((player2Number == 43) || (player2Number == 42) || (player2Number == 41))) {
        return 1;
    }
    return 0;
}
int Rule17(int player1Number, int player2Number) {
    if ((player1Number == 12) && ((player2Number == 22) || (player2Number == 21))) {
        return 1;
    }
    return 0;
}
int Rule18(int player1Number, int player2Number) {
    if ((player2Number == 12) && ((player1Number == 43) || (player1Number == 42) || (player1Number == 41))) {
        return 1;
    }
    return 0;
}
int Rule19(int player1Number, int player2Number) {
    if ((player2Number == 12) && ((player1Number == 22) || (player1Number == 21))) {
        return 1;
    }
    return 0;
}
int Rule20(int player1Number, int player2Number) {
    if ((player1Number == 13) && ((player2Number == 32) || (player2Number == 31))) {
        return 1;
    }
    return 0;
}
int Rule21(int player1Number, int player2Number) {
    if ((player1Number == 13) && ((player2Number == 22) || (player2Number == 21))) {
        return 1;
    }
    return 0;
}
int Rule22(int player1Number, int player2Number) {
    if ((player2Number == 13) && ((player1Number == 32) || (player1Number == 31))) {
        return 1;
    }
    return 0;
}
int Rule23(int player1Number, int player2Number) {
    if ((player2Number == 13) && ((player1Number == 22) || (player1Number == 21))) {
        return 1;
    }
    return 0;
}

int main() {
    std::vector<int> availableNumbers1 = { 11,12,13,21,22,31,32,41,42,43 };
    std::vector<int> availableNumbers2 = { 11,12,13,21,22,31,32,41,42,43 };
    int player1Score = 0, player2Score = 0;
    const int NUM_ROUNDS = 10;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int round = 1; round <= NUM_ROUNDS; ++round) {
        int player1Number;
        std::cout << "ラウンド " << round << ": あなたの番です。利用可能な数字を入力してください: ";
        std::cin >> player1Number;

        while (std::find(availableNumbers1.begin(), availableNumbers1.end(), player1Number) == availableNumbers1.end()) {
            std::cout << "無効な数字です。利用可能な数字を入力してください: ";
            std::cin >> player1Number;
        }

        availableNumbers1.erase(std::find(availableNumbers1.begin(), availableNumbers1.end(), player1Number));

        int player2Number;
        do {
            player2Number = availableNumbers2[rand() % availableNumbers2.size()];
        } while (std::find(availableNumbers2.begin(), availableNumbers2.end(), player2Number) == availableNumbers2.end());

        availableNumbers2.erase(std::find(availableNumbers2.begin(), availableNumbers2.end(), player2Number));

        int specialScore1 = Rule1(player1Number, player2Number);
        int specialScore2 = Rule2(player1Number, player2Number);
        int specialScore3 = Rule3(player1Number, player2Number);
        int specialScore4 = Rule4(player1Number, player2Number);
        int specialScore5 = Rule5(player1Number, player2Number);
        int specialScore6 = Rule6(player1Number, player2Number);
        int specialScore7 = Rule7(player1Number, player2Number);
        int specialScore8 = Rule8(player1Number, player2Number);
        int specialScore9 = Rule9(player1Number, player2Number);
        int specialScore10 = Rule10(player1Number, player2Number);
        int specialScore11 = Rule11(player1Number, player2Number);
        int specialScore12 = Rule12(player1Number, player2Number);
        int specialScore13 = Rule13(player1Number, player2Number);
        int specialScore14 = Rule14(player1Number, player2Number);
        int specialScore15 = Rule15(player1Number, player2Number);
        int specialScore16 = Rule16(player1Number, player2Number);
        int specialScore17 = Rule17(player1Number, player2Number);
        int specialScore18 = Rule18(player1Number, player2Number);
        int specialScore19 = Rule19(player1Number, player2Number);
        int specialScore20 = Rule20(player1Number, player2Number);
        int specialScore21 = Rule21(player1Number, player2Number);
        int specialScore22 = Rule22(player1Number, player2Number);
        int specialScore23 = Rule23(player1Number, player2Number);

        if (specialScore1 > 0) {
            std::cout << player1Number << "対" << player2Number << "であなたの勝利です。" << specialScore1 << "点獲得します。\n";
            player1Score += specialScore1;
        }
        else if (specialScore2 > 0) {
            std::cout << player1Number << "対" << player2Number << "で相手の勝利です。" << specialScore2 << "点獲得します。\n";
            player2Score += specialScore2;
        }
        else if (specialScore3 > 0) {
            std::cout << player1Number << "対" << player2Number << "で引き分けです\n";
        }
        else if (specialScore4 > 0) {
            std::cout << player1Number << "対" << player2Number << "で引き分けです\n";
        }
        else if (specialScore5 > 0) {
            std::cout << player1Number << "対" << player2Number << "で引き分けです\n";
        }
        else if (specialScore6 > player2Number) {
            std::cout << player1Number << "対" << player2Number << "であなたの勝利で4点獲得します。\n";
            player1Score += 4;
        }
        else if (specialScore7 > player1Number) {
            std::cout << player1Number << "対" << player2Number << "で相手の勝利で4点獲得します。\n";
            player2Score += 4;
        }
        else if (specialScore8 > player2Number) {
            std::cout << player1Number << "対" << player2Number << "であなたの勝利で3点獲得します。\n";
            player1Score += 3;
        }
        else if (specialScore9 > player1Number) {
            std::cout << player1Number << "対" << player2Number << "で相手の勝利で3点獲得します。\n";
            player2Score += 3;
        }
        else if (specialScore10 > 0) {
            std::cout << "搾取！" << player1Number << "対" << player2Number << "であなたの勝利で7点獲得します。\n";
            player1Score += 7;
        }
        else if (specialScore11 > 0) {
            std::cout << "増税！" << player1Number << "対" << player2Number << "で相手の勝利で7点獲得します。\n";
            player2Score += 7;
        }
        else if (specialScore12 > 0) {
            std::cout << "リセット！" << player1Number << "対" << player2Number << "で相手の総得点が0点になります。\n";
            player2Score = 0;
        }
        else if (specialScore13 > 0) {
            std::cout << "絶体絶命！" << player1Number << "対" << player2Number << "であなたの総得点が0点になります。\n";
            player1Score = 0;
        }
        else if (specialScore14 > 0) {
            std::cout << "下剋上！" << player1Number << "対" << player2Number << "であなたの勝利で5点獲得します。\n";
            player1Score += 5;
        }
        else if (specialScore15 > 0) {
            std::cout << "都落ち！" << player1Number << "対" << player2Number << "で相手の勝利で5点獲得します。\n";
            player2Score += 5;
        }
        else if (specialScore16 > 0) {
            std::cout << "反乱！" << player1Number << "対" << player2Number << "であなたの勝利で4点獲得します。\n";
            player1Score += 4;
        }
        else if (specialScore17 > 0) {
            std::cout << "反乱！" << player1Number << "対" << player2Number << "であなたの勝利で2点獲得します。\n";
            player1Score += 2;
        }
        else if (specialScore18 > 0) {
            std::cout << "反乱！" << player1Number << "対" << player2Number << "で相手の勝利で4点獲得します。\n";
            player2Score += 4;
        }
        else if (specialScore19 > 0) {
            std::cout << "反乱！" << player1Number << "対" << player2Number << "で相手の勝利で2点獲得します。\n";
            player2Score += 2;
        }
        else if (specialScore20 > 0) {
            std::cout << "一攫千金！" << player1Number << "対" << player2Number << "であなたの勝利で7点獲得します。\n";
            player1Score += 7;
        }
        else if (specialScore21 > 0) {
            std::cout << "絶望！" << player1Number << "対" << player2Number << "であなたの負けで7点失います。\n";
            player1Score -= 7;
        }
        else if (specialScore22 > 0) {
            std::cout << "絶望！" << player1Number << "対" << player2Number << "で相手の勝利で7点獲得します。\n";
            player2Score += 7;
        }
        else if (specialScore23 > 0) {
            std::cout << "一攫千金！" << player1Number << "対" << player2Number << "で相手の負けで7点失います。\n";
            player2Score -= 7;
        }
        else {
            std::cout << player1Number << "対" << player2Number << "で引き分けです！\n";
        }
    }
            std::cout << "ゲーム終了！\n";
            std::cout << "あなたの得点: " << player1Score << " 点\n";
            std::cout << "相手の得点: " << player2Score << " 点\n";

            if (player1Score > player2Score) {
                std::cout << "あなたの勝利です！\n";
            }
            else if (player1Score < player2Score) {
                std::cout << "あなたの負けです！\n";
            }
            else {
                std::cout << "引き分けです！\n";
            }

            return 0;
        }