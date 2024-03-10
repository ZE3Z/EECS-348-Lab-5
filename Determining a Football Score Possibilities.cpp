#include <iostream>
#include <vector>

using namespace std;

// Function to print the combinations
void printCombinations(int score) {
    cout << "Possible combinations of scoring plays for " << score << " points:" << endl;

    // Iterate through all possible combinations of scores
    for (int TD = 0; TD * 6 <= score; ++TD) { // Touchdowns worth 6 points
        for (int FG = 0; FG * 3 <= score; ++FG) { // Field Goals worth 3 points
            for (int Safety = 0; Safety * 2 <= score; ++Safety) { // Safeties worth 2 points
                for (int TD1pt = 0; TD1pt <= TD; ++TD1pt) { // TDs with 1-pt conversions (can't exceed number of TDs)
                    for (int TD2pt = 0; TD2pt <= TD - TD1pt; ++TD2pt) { // TDs with 2-pt conversions (can't exceed remaining TDs)

                        int totalScore = TD * 6 + FG * 3 + Safety * 2 + TD1pt + TD2pt * 2;

                        // If the total score matches the input score, print this combination
                        if (totalScore == score) {
                            cout << TD << " TDs, " << FG << " FGs, " << Safety << " Safeties, "
                                 << TD1pt << " TDs + 1-pt, " << TD2pt << " TDs + 2-pt" << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    while (true) {
        int score;
        cout << "Enter the NFL score (Enter 0 or 1 to STOP): ";
        cin >> score;

        // Break if score is less than 2
        if (score < 2) {
            break;
        }

        // Call function to print all combinations for the given score
        printCombinations(score);
    }

    return 0;
}