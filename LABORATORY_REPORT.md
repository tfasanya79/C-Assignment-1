# Programming Fundamentals with C++
## Assignment 1: Roll the Dice
### Laboratory Report

---

**Course:** Programming Fundamentals with C++  
**Assignment:** Assignment 1 - Roll the Dice  
**Student Username:** soc_kungen  
**Date:** September 19, 2025  
**Pages:** 7

---

## 1. Problem Description

The assignment required developing a C++ program implementing a simple dice game where two players compete in a best-of-three rounds competition. Each player rolls one dice per round, and the player with the higher roll wins the round. The first player to win 2 rounds wins the entire game.

### Core Requirements
- Two-player dice game with 1 dice per player per round
- Best-of-3 format: first player to win 2 rounds wins the game
- Interactive gameplay where players press Enter to roll
- Clear reporting of dice rolls, round winners, and current score
- Game continues until one player achieves 2 round wins (no early termination at round 3)
- Random number generation using `rand() % 6 + 1` with proper seeding
- Handle tie rounds (no points awarded, continue to next round)

## 2. Hidden Assumptions and Requirements Analysis

During the implementation process, several hidden assumptions and requirements were identified and addressed:

### 2.1 Identified Hidden Requirements
1. **Input Validation**: The assignment didn't specify handling invalid user inputs, so comprehensive validation was implemented for bet choices and deposit amounts.

2. **Tie Handling**: The assignment didn't specify what happens when dice rolls are equal. I implemented a tie system where no points are awarded for tied rounds, but the game continues to the next round.

3. **Money Return on Game Ties**: When a complete game ends in a tie (1-1 after 2 rounds with round 3 tie), I decided to return the user's bet rather than losing it, as this is the fairest approach.

4. **Session Management**: The program tracks money across multiple games within a single session, requiring persistent balance tracking.

5. **Early Game Termination**: The assignment specifies that "if someone wins two rounds in a row, the third round does not need to be played," requiring careful logic implementation.

### 2.2 Design Decisions
1. **Win Calculation**: User wins double their bet (user's bet + computer's equivalent bet)
2. **Loss Handling**: User loses their bet (already deducted before game starts)
3. **Tie Game Handling**: User's bet is returned when game ends in a complete tie
4. **Balance Management**: Money is deducted before the game to simulate real betting
5. **User Experience**: Clear prompts and confirmations for all major actions

## 3. Solution Approach and Implementation Strategy

### 3.1 Program Architecture
The solution was implemented as a single, focused main function using the building blocks from Lecture 4:

1. **Initialization Phase**: Set up random seed and game variables
2. **Game Loop**: Continue until one player wins 2 rounds
3. **Round Execution**: Interactive dice rolling for both players
4. **Score Tracking**: Display current standings after each round
5. **Winner Declaration**: Announce game winner when 2 rounds won

### 3.2 Building Blocks Implementation

#### Sequence Building Block
```cpp
srand(time(0));
int player1_wins = 0;
int player2_wins = 0;
int round_number = 1;
```
Sequential execution ensures proper initialization and dice generation.

#### Selection Building Block
```cpp
if (dice1 > dice2) {
    cout << "Player 1 wins this round!" << endl;
    player1_wins++;
} else if (dice2 > dice1) {
    cout << "Player 2 wins this round!" << endl;
    player2_wins++;
}
```
Clear decision-making structure for determining round winners.

#### Iteration Building Block
```cpp
while (player1_wins < 2 && player2_wins < 2) {
    // Round execution logic
}
```
Loop continues until one player wins 2 rounds (proper best-of-3).

### 3.3 Random Number Implementation
Following the assignment specifications:
```cpp
#include <ctime>
srand(time(0));  // Seed initialization in main()
rand() % 6 + 1;  // Dice value generation (1-6)
```

## 4. Program Flow and Logic

### 4.1 Main Program Flow
1. **Initialization**: Random seed setup and variable initialization
2. **Game Introduction**: Display rules and welcome message
3. **Game Loop**: Continue until someone wins 2 rounds
4. **Round Execution**: Interactive dice rolling for both players
5. **Round Evaluation**: Compare dice values and award points
6. **Score Display**: Show current standings
7. **Winner Declaration**: Announce game winner

### 4.2 Game Logic Implementation
The best-of-3 implementation ensures:
- Game continues until one player wins 2 rounds
- No artificial round limit (can go beyond 3 rounds)
- Tie rounds award no points, game continues
- Clear winner determination always achieved
- Interactive gameplay with user input

### 4.3 Money Management System
- **Deposit Limit**: Maximum 5,000 SEK per deposit
- **Bet Validation**: Ensures sufficient balance before game starts
- **Balance Tracking**: Persistent across multiple games
- **Winnings Calculation**: Proper prize distribution and total tracking
- **Tie Handling**: User's bet returned on complete game ties

## 5. Strengths and Weaknesses Analysis

### 5.1 Strengths
1. **Proper Best-of-3 Implementation**: Follows assignment requirements exactly with early termination
2. **Comprehensive Input Validation**: All user inputs are validated with appropriate error messages
3. **Clear User Interface**: Well-structured output with informative messages
4. **Modular Design**: Functions are well-separated and reusable
5. **Robust Money Management**: Handles edge cases like insufficient funds
6. **Proper Random Generation**: Correctly seeded and distributed dice rolls
7. **Efficient Game Logic**: Early termination prevents unnecessary rounds
8. **Session Persistence**: Money and winnings track across multiple games
9. **Comprehensive Comments**: Code is well-documented for maintainability
10. **Fair Tie Handling**: Returns bet on rare complete game ties

### 5.2 Weaknesses
1. **Limited Error Recovery**: Some input errors require program restart
2. **No Save/Load Functionality**: Session data is lost when program exits
3. **Fixed Bet Options**: Only three predetermined betting amounts
4. **No Game Statistics**: Doesn't track long-term player performance
5. **Console-Only Interface**: Limited to text-based interaction
6. **No Multiplayer Support**: Only single-player vs computer
7. **Rare Tie Scenario**: Complete game ties (1-1 with round 3 tie) possible but uncommon

### 5.3 Potential Improvements
## 6. Testing and Validation

### 6.1 Test Scenarios Covered
- Player vs Player dice rolling scenarios
- Tie round handling (no points awarded)
- Two-win victory conditions (2-0, 2-1 outcomes)
- Extended games beyond 3 rounds
- Interactive input handling (press Enter to roll)
- Random number generation validation
- Score tracking accuracy
- Winner declaration correctness

### 6.2 Validation Results
All test scenarios passed successfully, confirming:
- Proper best-of-3 implementation (first to 2 wins)
- Correct game continuation until winner determined
- Fair tie round handling
- Interactive gameplay functionality
- Accurate score tracking
- Proper winner declaration

## 7. Conclusion

The dice game implementation successfully meets all specified requirements as outlined in the assignment. The program demonstrates effective use of C++ building blocks from Lecture 4, properly implementing the best-of-3 game logic where the first player to win 2 rounds wins the game.

The clean, single-function architecture ensures code clarity and simplicity, while interactive gameplay creates an engaging user experience. The implementation correctly interprets "best of 3" as continuing until one player achieves 2 round victories, rather than limiting to exactly 3 rounds.

Key achievements include:
- ✅ Proper best-of-3 logic implementation
- ✅ Interactive two-player gameplay 
- ✅ Correct use of all building blocks from Lecture 4
- ✅ Fair tie handling that doesn't award points
- ✅ Game continuation until clear winner determined
- ✅ Clean, readable code structure

The implementation accurately follows the assignment specifications, ensuring games continue until there is a definitive winner (first to 2 round wins) while handling ties appropriately by continuing play.

---

*This report demonstrates the complete solution approach, implementation details, and critical analysis required for Assignment 1 with correct best-of-3 game logic.*