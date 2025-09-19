#include <iostream>
#include <ctime>
using namespace std;

/* Function to roll two dice and return the sum
   Uses building block from lecture: rand() % 6 + 1 */
int rollDice() {
    int dice1 = rand() % 6 + 1;  // Random number 1-6
    int dice2 = rand() % 6 + 1;  // Random number 1-6
    return dice1 + dice2;        // Return sum of both dice
}

/* Function to display dice roll results clearly */
void displayDiceRoll(const string& player, int roll) {
    cout << player << " rolled: " << roll << endl;
}

/* Function to determine round winner and display result */
int determineRoundWinner(int userRoll, int computerRoll, int round) {
    cout << "\n--- Round " << round << " Results ---" << endl;
    displayDiceRoll("User", userRoll);
    displayDiceRoll("Computer", computerRoll);
    
    if (userRoll > computerRoll) {
        cout << "User wins Round " << round << "!" << endl;
        return 1; // User wins
    } else if (computerRoll > userRoll) {
        cout << "Computer wins Round " << round << "!" << endl;
        return 2; // Computer wins
    } else {
        cout << "Round " << round << " is a tie! No winner." << endl;
        return 0; // Tie
    }
}

/* Function to get valid bet amount using selection building block */
int getBetAmount() {
    int bet;
    bool validBet = false;
    
    while (!validBet) {  // Iteration building block - repeat until valid
        cout << "\nChoose your bet amount:" << endl;
        cout << "1. 100 SEK" << endl;
        cout << "2. 300 SEK" << endl;
        cout << "3. 500 SEK" << endl;
        cout << "Enter your choice (1-3): ";
        
        int choice;
        cin >> choice;
        
        // Selection building block - if/else structure from lecture
        if (choice == 1) {
            bet = 100;
            validBet = true;
        } else if (choice == 2) {
            bet = 300;
            validBet = true;
        } else if (choice == 3) {
            bet = 500;
            validBet = true;
        } else {
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
        }
    }
    
    return bet;
}

/* Function to handle money deposit with validation */
int depositMoney(int currentBalance) {
    int deposit;
    bool validDeposit = false;
    
    while (!validDeposit) {
        cout << "\nHow much money do you want to deposit? (Max 5000 SEK): ";
        cin >> deposit;
        
        // Logical operators building block from lecture
        if ((deposit > 0) && (deposit <= 5000)) {
            validDeposit = true;
        } else {
            cout << "Invalid amount! Please enter between 1-5000 SEK." << endl;
        }
    }
    
    return currentBalance + deposit;
}

/* Main game function implementing the dice game logic */
int playDiceGame(int bet) {
    int userWins = 0;
    int computerWins = 0;
    int round = 1;
    
    cout << "\n=== Starting New Dice Game ===" << endl;
    cout << "Game continues until there's a clear winner!" << endl;
    cout << "Your bet: " << bet << " SEK" << endl;
    
    // Main game loop - iteration building block with guaranteed winner logic
    // Continue until someone has more wins than the other (no ties allowed)
    while (userWins == computerWins) {
        cout << "\n--- Round " << round << " ---" << endl;
        cout << "Press Enter to roll the dice...";
        cin.ignore();
        cin.get();
        
        // Roll dice for both players
        int userRoll = rollDice();
        int computerRoll = rollDice();
        
        // Determine round winner using selection
        int winner = determineRoundWinner(userRoll, computerRoll, round);
        
        if (winner == 1) {
            userWins++;
        } else if (winner == 2) {
            computerWins++;
        }
        // If tie (winner == 0), no one gets a point - continue playing
        
        round++;
        
        // Display current score after each round
        cout << "Current Score - User: " << userWins << ", Computer: " << computerWins << endl;
        
        // Check if we have a winner (someone has more wins than the other)
        if (userWins != computerWins) {
            cout << "\nGame has a winner after " << (round-1) << " rounds!" << endl;
            break;
        } else if (round > 3) {
            cout << "\nGame is tied after 3 rounds. Playing extra rounds until there's a winner!" << endl;
        }
    }
    
    // Display final game results
    cout << "\n=== FINAL GAME RESULTS ===" << endl;
    cout << "User wins: " << userWins << " rounds" << endl;
    cout << "Computer wins: " << computerWins << " rounds" << endl;
    cout << "Total rounds played: " << (round-1) << endl;
    
    // Calculate winnings/losses - no ties possible now
    int result = 0;
    if (userWins > computerWins) {
        cout << "*** USER WINS THE GAME! ***" << endl;
        result = bet * 2; // User wins double the bet (user's bet + computer's bet)
        cout << "You won " << result << " SEK!" << endl;
    } else {
        cout << "*** COMPUTER WINS THE GAME! ***" << endl;
        result = 0; // User loses the bet (already deducted)
        cout << "You lost your bet of " << bet << " SEK." << endl;
        cout << "Better luck next time!" << endl;
    }
    
    return result;
}

/* Main function using building blocks from lecture */
int main() {
    // Initialize random seed as specified in assignment
    srand(time(0));
    
    int balance = 0;
    int totalWinnings = 0;
    bool continueGame = true;
    
    cout << "=== WELCOME TO THE DICE GAME ===" << endl;
    cout << "Challenge the computer in a dice rolling game!" << endl;
    
    // Main program loop
    while (continueGame) {
        // Check if user needs to deposit money
        if (balance <= 0) {
            cout << "\nYou need money to play!" << endl;
            balance = depositMoney(balance);
        }
        
        cout << "\nCurrent balance: " << balance << " SEK" << endl;
        cout << "Total winnings so far: " << totalWinnings << " SEK" << endl;
        
        // Get bet amount
        int bet = getBetAmount();
        
        // Check if user has enough money
        if (bet > balance) {
            cout << "\nNot enough money! You need " << bet << " SEK but only have " << balance << " SEK." << endl;
            cout << "Would you like to deposit more money? (1=Yes, 0=No): ";
            int depositChoice;
            cin >> depositChoice;
            
            if (depositChoice == 1) {
                balance = depositMoney(balance);
                continue; // Go back to start of loop
            } else {
                cout << "Thanks for playing!" << endl;
                break;
            }
        }
        
        // Deduct bet from balance
        balance -= bet;
        cout << "\nYou bet " << bet << " SEK. Remaining balance: " << balance << " SEK" << endl;
        
        // Play the game and get result
        int gameResult = playDiceGame(bet);
        
        // Update balance and winnings based on game result
        balance += gameResult;
        
        if (gameResult > bet) {
            // User won
            int prize = gameResult - bet;
            totalWinnings += prize;
            cout << "\nCurrent prize: " << prize << " SEK" << endl;
            cout << "Total winnings: " << totalWinnings << " SEK" << endl;
        } else {
            // User lost (no ties possible with new logic)
            cout << "\nConsolation message: Don't give up! Try again!" << endl;
            cout << "Total winnings remaining: " << totalWinnings << " SEK" << endl;
        }
        
        cout << "\nNew balance: " << balance << " SEK" << endl;
        // For now, let's ask if user wants to continue
        cout << "\nWould you like to play again? (1=Yes, 0=No): ";
        int playAgain;
        cin >> playAgain;
        
        if (playAgain != 1) {
            continueGame = false;
        }
    }
    
    cout << "\n=== GAME SESSION ENDED ===" << endl;
    cout << "Final balance: " << balance << " SEK" << endl;
    cout << "Total winnings: " << totalWinnings << " SEK" << endl;
    cout << "Thanks for playing!" << endl;
    
    return 0;
}