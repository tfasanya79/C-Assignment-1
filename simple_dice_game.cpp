#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Initialize game variables
    int player1_wins = 0;
    int player2_wins = 0;
    int round_number = 1;
    
    cout << "=== Simple Dice Game: Best of 3 ===" << endl;
    cout << "First player to win 2 rounds wins the game!" << endl;
    cout << "Each player rolls one dice (1-6)." << endl << endl;
    
    // Game loop - continue until someone wins 2 rounds
    while (player1_wins < 2 && player2_wins < 2) {
        cout << "=== Round " << round_number << " ===" << endl;
        
        // Player 1's turn
        cout << "Player 1, press Enter to roll the dice...";
        cin.get();
        int dice1 = rand() % 6 + 1;
        cout << "Player 1 rolled: " << dice1 << endl;
        
        // Player 2's turn
        cout << "Player 2, press Enter to roll the dice...";
        cin.get();
        int dice2 = rand() % 6 + 1;
        cout << "Player 2 rolled: " << dice2 << endl;
        
        // Determine round winner
        if (dice1 > dice2) {
            cout << "Player 1 wins this round!" << endl;
            player1_wins++;
        } else if (dice2 > dice1) {
            cout << "Player 2 wins this round!" << endl;
            player2_wins++;
        } else {
            cout << "It's a tie this round!" << endl;
        }
        
        // Display current score
        cout << "Score: Player 1: " << player1_wins << ", Player 2: " << player2_wins << endl;
        cout << endl;
        
        round_number++;
    }
    
    // Declare overall winner
    if (player1_wins >= 2) {
        cout << "🎉 Player 1 wins the game! 🎉" << endl;
    } else {
        cout << "🎉 Player 2 wins the game! 🎉" << endl;
    }
    
    cout << "Thanks for playing!" << endl;
    
    return 0;
}