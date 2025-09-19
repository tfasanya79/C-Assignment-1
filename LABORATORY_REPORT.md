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

The assignment required developing a C++ program implementing a dice game where a user challenges the computer in a best-of-three rounds competition. Each player rolls two dice per round, and the highest sum wins the round. The program must include a comprehensive betting system with money management capabilities.

### Core Requirements
- User vs Computer dice game with 2 dice per player per round
- Best of 3 rounds with early termination when someone wins 2 rounds
- Betting system with three fixed options: 100 SEK, 300 SEK, or 500 SEK
- Money management with deposits up to 5,000 SEK per transaction
- Clear reporting of dice rolls, round winners, and game outcomes
- Prize calculation and total winnings tracking
- Multiple game sessions support
- Random number generation using `rand() % 6 + 1` with proper seeding

## 2. Hidden Assumptions and Requirements Analysis

During the implementation process, several hidden assumptions and requirements were identified and addressed:

### 2.1 Identified Hidden Requirements
1. **Input Validation**: The assignment didn't specify handling invalid user inputs, so comprehensive validation was implemented for bet choices and deposit amounts.

2. **Tie Handling**: The assignment didn't specify what happens when dice rolls are equal. I implemented a tie system where no points are awarded and the round is replayed conceptually.

3. **Money Return on Ties**: When a complete game ends in a tie (equal round wins), I decided to return the user's bet rather than losing it.

4. **Session Management**: The program needed to track money across multiple games within a single session, requiring persistent balance tracking.

5. **Early Game Termination**: While mentioned, the specific implementation of stopping at 2 wins required careful logic to avoid unnecessary rounds.

### 2.2 Design Decisions
1. **Win Calculation**: User wins double their bet (user's bet + computer's equivalent bet)
2. **Loss Handling**: User loses their bet (already deducted before game starts)
3. **Balance Management**: Money is deducted before the game to simulate real betting
4. **User Experience**: Clear prompts and confirmations for all major actions

## 3. Solution Approach and Implementation Strategy

### 3.1 Program Architecture
The solution was structured using modular functions following the building blocks from Lecture 4:

1. **Main Program Loop**: Controls overall program flow and session management
2. **Game Logic Module**: Handles individual game execution and round management
3. **Dice Rolling Function**: Implements random number generation for dice
4. **Money Management Functions**: Handle deposits, betting, and balance tracking
5. **User Interface Functions**: Provide clear output and input handling

### 3.2 Building Blocks Implementation

#### Sequence Building Block
```cpp
int dice1 = rand() % 6 + 1;
int dice2 = rand() % 6 + 1;
return dice1 + dice2;
```
Sequential execution ensures proper dice generation and sum calculation.

#### Selection Building Block
```cpp
if (userRoll > computerRoll) {
    cout << "User wins Round " << round << "!" << endl;
    return 1;
} else if (computerRoll > userRoll) {
    cout << "Computer wins Round " << round << "!" << endl;
    return 2;
} else {
    cout << "Round " << round << " is a tie!" << endl;
    return 0;
}
```
Clear decision-making structure for determining round winners.

#### Iteration Building Block
```cpp
while ((userWins < 2) && (computerWins < 2) && (round <= 3)) {
    // Round execution logic
}
```
Efficient loop control implementing best-of-3 logic with early termination.

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
2. **Session Loop**: Continuous game sessions until user exits
3. **Money Check**: Balance verification and deposit handling
4. **Betting Phase**: Bet selection and validation
5. **Game Execution**: Best-of-3 rounds with proper termination
6. **Result Processing**: Win/loss calculation and balance updates
7. **Session Control**: Continue/exit decision

### 4.2 Game Logic Implementation
The best-of-3 implementation ensures:
- No unnecessary rounds are played
- Clear winner determination
- Proper score tracking
- Early termination when someone reaches 2 wins

### 4.3 Money Management System
- **Deposit Limit**: Maximum 5,000 SEK per deposit
- **Bet Validation**: Ensures sufficient balance before game starts
- **Balance Tracking**: Persistent across multiple games
- **Winnings Calculation**: Proper prize distribution and total tracking

## 5. Strengths and Weaknesses Analysis

### 5.1 Strengths
1. **Comprehensive Input Validation**: All user inputs are validated with appropriate error messages
2. **Clear User Interface**: Well-structured output with informative messages
3. **Modular Design**: Functions are well-separated and reusable
4. **Robust Money Management**: Handles edge cases like insufficient funds
5. **Proper Random Generation**: Correctly seeded and distributed dice rolls
6. **Early Termination Logic**: Efficiently implements best-of-3 without unnecessary rounds
7. **Session Persistence**: Money and winnings track across multiple games
8. **Comprehensive Comments**: Code is well-documented for maintainability

### 5.2 Weaknesses
1. **Limited Error Recovery**: Some input errors require program restart
2. **No Save/Load Functionality**: Session data is lost when program exits
3. **Fixed Bet Options**: Only three predetermined betting amounts
4. **No Game Statistics**: Doesn't track long-term player performance
5. **Console-Only Interface**: Limited to text-based interaction
6. **No Multiplayer Support**: Only single-player vs computer

### 5.3 Potential Improvements
1. Implement file-based session persistence
2. Add configurable bet amounts
3. Include detailed game statistics and history
4. Implement difficulty levels for computer opponent
5. Add graphical user interface
6. Include sound effects and animations

## 6. Testing and Validation

### 6.1 Test Scenarios Covered
- Valid bet amounts (100, 300, 500 SEK)
- Invalid bet inputs (out of range, non-numeric)
- Insufficient balance scenarios
- Maximum deposit limit testing (5,000 SEK)
- Win/loss/tie game outcomes
- Multiple consecutive games
- Early game termination (2-0, 2-1 scenarios)
- Balance tracking across sessions

### 6.2 Validation Results
All test scenarios passed successfully, confirming:
- Proper money management
- Correct game logic implementation
- Appropriate user feedback
- Robust error handling

## 7. Conclusion

The dice game implementation successfully meets all specified requirements while addressing numerous hidden assumptions through thoughtful design decisions. The program demonstrates effective use of C++ building blocks from Lecture 4, including proper sequence, selection, and iteration constructs.

The modular architecture ensures code maintainability and extensibility, while comprehensive input validation and user feedback create a robust user experience. The money management system properly handles real-world betting scenarios with appropriate safeguards.

Future enhancements could focus on persistence features, enhanced user interface options, and expanded game statistics to create an even more engaging gaming experience.

---

*This report demonstrates the complete solution approach, implementation details, and critical analysis required for Assignment 1.*