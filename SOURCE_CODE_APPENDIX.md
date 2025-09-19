# Source Code Appendix
## Assignment 1: Roll the Dice

### Complete C++ Implementation with Detailed Comments

```cpp
/*
 * Programming Fundamentals with C++
 * Assignment 1: Roll the Dice
 * Student: soc_kungen
 * Date: September 19, 2025
 * 
 * This program implements a dice game where the user challenges the computer
 * in a best-of-3 rounds competition with comprehensive money management.
 */

#include <iostream>  // For input/output operations
#include <ctime>     // For time-based random seeding as specified
using namespace std;

/*
 * Function: rollDice
 * Purpose: Roll two dice and return their sum
 * Uses building block from lecture: rand() % 6 + 1
 * Returns: Integer sum of two dice (2-12)
 */
int rollDice() {
    int dice1 = rand() % 6 + 1;  // Generate random number 1-6 for first die
    int dice2 = rand() % 6 + 1;  // Generate random number 1-6 for second die
    return dice1 + dice2;        // Return sum of both dice
}

/*
 * Function: displayDiceRoll
 * Purpose: Display dice roll results in a clear format
 * Parameters: player - name of the player (User/Computer)
 *            roll - the dice roll result to display
 */
void displayDiceRoll(const string& player, int roll) {
    cout << player << " rolled: " << roll << endl;
}

/*
 * Function: determineRoundWinner
 * Purpose: Compare dice rolls and determine round winner
 * Parameters: userRoll - user's dice roll result
 *            computerRoll - computer's dice roll result
 *            round - current round number for display
 * Returns: 1 if user wins, 2 if computer wins, 0 if tie
 * Uses selection building block (if/else) from lecture
 */
int determineRoundWinner(int userRoll, int computerRoll, int round) {
    cout << "\n--- Round " << round << " Results ---" << endl;
    displayDiceRoll("User", userRoll);
    displayDiceRoll("Computer", computerRoll);
    
    // Selection building block - determine winner based on comparison
    if (userRoll > computerRoll) {
        cout << "User wins Round " << round << "!" << endl;
        return 1; // User wins
    } else if (computerRoll > userRoll) {
        cout << "Computer wins Round " << round << "!" << endl;
        return 2; // Computer wins
    } else {
        cout << "Round " << round << " is a tie! No winner." << endl;
        return 0; // Tie - no points awarded
    }
}

/*
 * Function: getBetAmount
 * Purpose: Get valid bet amount from user with input validation
 * Returns: Valid bet amount (100, 300, or 500 SEK)
 * Uses iteration building block (while loop) for input validation
 * Uses selection building block (if/else) for choice processing
 */
int getBetAmount() {
    int bet;
    bool validBet = false;
    
    // Iteration building block - repeat until valid input received
    while (!validBet) {
        cout << "\nChoose your bet amount:" << endl;
        cout << "1. 100 SEK" << endl;
        cout << "2. 300 SEK" << endl;
        cout << "3. 500 SEK" << endl;
        cout << "Enter your choice (1-3): ";
        
        int choice;
        cin >> choice;
        
        // Selection building block - process user choice
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

/*
 * Function: depositMoney
 * Purpose: Handle money deposit with validation (max 5000 SEK as specified)
 * Parameters: currentBalance - user's current balance
 * Returns: Updated balance after deposit
 * Uses logical operators building block (&&) from lecture
 */
int depositMoney(int currentBalance) {
    int deposit;
    bool validDeposit = false;
    
    // Input validation loop
    while (!validDeposit) {
        cout << "\nHow much money do you want to deposit? (Max 5000 SEK): ";
        cin >> deposit;
        
        // Logical operators building block - validate deposit amount
        if ((deposit > 0) && (deposit <= 5000)) {
            validDeposit = true;
        } else {
            cout << "Invalid amount! Please enter between 1-5000 SEK." << endl;
        }
    }
    
    return currentBalance + deposit;
}

/*
 * Function: playDiceGame
 * Purpose: Execute main game logic for best-of-3 rounds
 * Parameters: bet - amount of money bet on this game
 * Returns: Money result (0 for loss, bet for tie, bet*2 for win)
 * Uses iteration building block for game rounds
 * Uses logical operators for complex conditions
 */
int playDiceGame(int bet) {
    int userWins = 0;
    int computerWins = 0;
    int round = 1;
    
    cout << "\n=== Starting New Dice Game ===" << endl;
    cout << "Best of 3 rounds wins the game!" << endl;
    cout << "Your bet: " << bet << " SEK" << endl;
    
    // Main game loop - iteration building block with complex conditions
    // Continue while neither player has 2 wins AND haven't exceeded 3 rounds
    while ((userWins < 2) && (computerWins < 2) && (round <= 3)) {
        cout << "\n--- Round " << round << " ---" << endl;
        cout << "Press Enter to roll the dice...";
        cin.ignore(); // Clear input buffer
        cin.get();    // Wait for user input
        
        // Execute dice rolls for both players
        int userRoll = rollDice();
        int computerRoll = rollDice();
        
        // Determine round winner and update scores
        int winner = determineRoundWinner(userRoll, computerRoll, round);
        
        if (winner == 1) {
            userWins++;
        } else if (winner == 2) {
            computerWins++;
        }
        // If tie (winner == 0), no one gets a point
        
        round++;
        
        // Check if game should end early (best of 3 logic)
        // Using logical operators to check win conditions
        if ((userWins == 2) || (computerWins == 2)) {
            cout << "\nGame ended early - someone won 2 rounds!" << endl;
            break; // Exit the game loop early
        }
    }
    
    // Display final game results
    cout << "\n=== FINAL GAME RESULTS ===" << endl;
    cout << "User wins: " << userWins << " rounds" << endl;
    cout << "Computer wins: " << computerWins << " rounds" << endl;
    
    // Calculate winnings/losses and return result
    int result = 0;
    if (userWins > computerWins) {
        cout << "*** USER WINS THE GAME! ***" << endl;
        result = bet * 2; // User wins double the bet (user + computer bet)
        cout << "You won " << result << " SEK!" << endl;
    } else if (computerWins > userWins) {
        cout << "*** COMPUTER WINS THE GAME! ***" << endl;
        result = 0; // User loses the bet (already deducted)
        cout << "You lost your bet of " << bet << " SEK." << endl;
        cout << "Better luck next time!" << endl;
    } else {
        cout << "*** THE GAME IS A TIE! ***" << endl;
        result = bet; // Return the bet on tie
        cout << "It's a tie! Your bet of " << bet << " SEK is returned." << endl;
    }
    
    return result;
}

/*
 * Function: main
 * Purpose: Main program function controlling overall flow
 * Uses all building blocks from lecture: sequence, selection, iteration
 * Implements comprehensive money management and game session control
 */
int main() {
    // Initialize random seed as specified in assignment
    // Using sequence building block
    srand(time(0));
    
    // Initialize program variables
    int balance = 0;         // User's current money balance
    int totalWinnings = 0;   // Total winnings across all games
    bool continueGame = true; // Control flag for main program loop
    
    cout << "=== WELCOME TO THE DICE GAME ===" << endl;
    cout << "Challenge the computer in a dice rolling game!" << endl;
    
    // Main program loop - iteration building block
    while (continueGame) {
        // Check if user needs to deposit money
        if (balance <= 0) {
            cout << "\nYou need money to play!" << endl;
            balance = depositMoney(balance);
        }
        
        // Display current financial status
        cout << "\nCurrent balance: " << balance << " SEK" << endl;
        cout << "Total winnings so far: " << totalWinnings << " SEK" << endl;
        
        // Get bet amount from user
        int bet = getBetAmount();
        
        // Validate sufficient funds - selection building block
        if (bet > balance) {
            cout << "\nNot enough money! You need " << bet << " SEK but only have " 
                 << balance << " SEK." << endl;
            cout << "Would you like to deposit more money? (1=Yes, 0=No): ";
            int depositChoice;
            cin >> depositChoice;
            
            if (depositChoice == 1) {
                balance = depositMoney(balance);
                continue; // Go back to start of loop
            } else {
                cout << "Thanks for playing!" << endl;
                break; // Exit the program
            }
        }
        
        // Deduct bet from balance (simulate real betting)
        balance -= bet;
        cout << "\nYou bet " << bet << " SEK. Remaining balance: " 
             << balance << " SEK" << endl;
        
        // Play the game and get result
        int gameResult = playDiceGame(bet);
        
        // Update balance and winnings based on game result
        balance += gameResult;
        
        // Process game results and update totals
        if (gameResult > bet) {
            // User won - calculate and display prize information
            int prize = gameResult - bet;
            totalWinnings += prize;
            cout << "\nCurrent prize: " << prize << " SEK" << endl;
            cout << "Total winnings: " << totalWinnings << " SEK" << endl;
        } else if (gameResult == 0) {
            // User lost - display consolation message
            cout << "\nConsolation message: Don't give up! Try again!" << endl;
            cout << "Total winnings remaining: " << totalWinnings << " SEK" << endl;
        } else {
            // Tie - bet returned, display neutral message
            cout << "\nYour balance has been restored." << endl;
        }
        
        cout << "\nNew balance: " << balance << " SEK" << endl;
        
        // Ask if user wants to continue playing
        cout << "\nWould you like to play again? (1=Yes, 0=No): ";
        int playAgain;
        cin >> playAgain;
        
        if (playAgain != 1) {
            continueGame = false; // Exit the main loop
        }
    }
    
    // Display final session summary
    cout << "\n=== GAME SESSION ENDED ===" << endl;
    cout << "Final balance: " << balance << " SEK" << endl;
    cout << "Total winnings: " << totalWinnings << " SEK" << endl;
    cout << "Thanks for playing!" << endl;
    
    return 0; // Successful program termination
}
```

### Building Blocks Implementation Summary

1. **Sequence Building Block**: Used throughout for sequential execution of statements, particularly in dice rolling and money calculations.

2. **Selection Building Block**: Implemented using if/else statements for:
   - Round winner determination
   - Bet amount validation
   - Game result processing
   - User choice handling

3. **Iteration Building Block**: Implemented using while loops for:
   - Main program loop (game sessions)
   - Game rounds loop (best-of-3)
   - Input validation loops

4. **Logical Operators**: Used && and || operators for complex conditions like game termination and input validation.

5. **Random Number Generation**: Properly implemented using the specified assignment requirements with srand(time(0)) and rand() % 6 + 1.

### Code Quality Features

- **Comprehensive Comments**: Every function and major code block includes detailed explanations
- **Modular Design**: Code is organized into logical functions for maintainability
- **Input Validation**: All user inputs are validated with appropriate error handling
- **Clear Output**: User-friendly messages and formatting throughout the program
- **Building Block Integration**: Proper use of all required C++ constructs from Lecture 4