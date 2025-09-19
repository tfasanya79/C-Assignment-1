# Programming Fundamentals with C++
## Assignment 1: Roll the Dice (Updated)
### Laboratory Report

---

**Course:** Programming Fundamentals with C++  
**Assignment:** Assignment 1 - Roll the Dice (Updated with Guaranteed Winner Logic)  
**Student Username:** soc_kungen  
**Date:** September 19, 2025  
**Pages:** 7

---

## 1. Problem Description

The assignment required developing a C++ program implementing a dice game where a user challenges the computer. Each player rolls two dice per round, and the highest sum wins the round. The program must include a comprehensive betting system with money management capabilities.

**🆕 UPDATE**: The program has been amended to ensure there is always a clear winner by continuing rounds until someone has more wins than the other, eliminating tie games.

### Core Requirements
- User vs Computer dice game with 2 dice per player per round
- **🆕 UPDATED**: Continue rounds until there's a clear winner (no ties)
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

2. **🆕 Tie Elimination**: **UPDATED REQUIREMENT** - The game now continues until there's a definitive winner, ensuring no tie outcomes.

3. **🆕 Extra Rounds Logic**: When the game is tied after 3 rounds, additional rounds are played until someone has more wins.

4. **Money Return on Ties**: **REMOVED** - Since ties are no longer possible, this logic has been eliminated.

5. **Session Management**: The program tracks money across multiple games within a single session, requiring persistent balance tracking.

6. **Round Counting**: **NEW** - The program now tracks and displays the total number of rounds played to reach a winner.

### 2.2 Design Decisions
1. **🆕 Win Condition**: Game continues until `userWins != computerWins`
2. **Win Calculation**: User wins double their bet (user's bet + computer's equivalent bet)
3. **Loss Handling**: User loses their bet (already deducted before game starts)
4. **🆕 No Tie Outcomes**: Simplified logic with only win/lose scenarios
5. **User Experience**: Clear prompts and confirmations for all major actions

## 3. Solution Approach and Implementation Strategy

### 3.1 Program Architecture
The solution was structured using modular functions following the building blocks from Lecture 4:

1. **Main Program Loop**: Controls overall program flow and session management
2. **🆕 Updated Game Logic Module**: Handles individual game execution with guaranteed winner logic
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

#### 🆕 Updated Iteration Building Block
```cpp
// OLD LOGIC:
while ((userWins < 2) && (computerWins < 2) && (round <= 3)) {
    // Round execution logic
}

// NEW LOGIC:
while (userWins == computerWins) {
    // Continue until there's a clear winner
}
```
**MAJOR UPDATE**: Efficient loop control implementing guaranteed winner logic.

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
5. **🆕 Game Execution**: Continue rounds until clear winner emerges
6. **🆕 Result Processing**: Win/loss calculation (no ties)
7. **Session Control**: Continue/exit decision

### 4.2 🆕 Updated Game Logic Implementation
The guaranteed winner implementation ensures:
- Rounds continue until `userWins != computerWins`
- No tie games possible
- Proper score tracking with round counting
- Clear winner determination

### 4.3 Money Management System
- **Deposit Limit**: Maximum 5,000 SEK per deposit
- **Bet Validation**: Ensures sufficient balance before game starts
- **Balance Tracking**: Persistent across multiple games
- **🆕 Simplified Winnings**: Only win/lose outcomes (no tie returns)

## 5. Strengths and Weaknesses Analysis

### 5.1 Strengths
1. **🆕 Guaranteed Winner**: Eliminates frustrating tie outcomes
2. **Comprehensive Input Validation**: All user inputs are validated with appropriate error messages
3. **Clear User Interface**: Well-structured output with informative messages
4. **Modular Design**: Functions are well-separated and reusable
5. **Robust Money Management**: Handles edge cases like insufficient funds
6. **Proper Random Generation**: Correctly seeded and distributed dice rolls
7. **🆕 Flexible Round System**: Adapts to continue until winner emerges
8. **Session Persistence**: Money and winnings track across multiple games
9. **Comprehensive Comments**: Code is well-documented for maintainability

### 5.2 Weaknesses
1. **🆕 Potentially Long Games**: Some games might require many rounds
2. **Limited Error Recovery**: Some input errors require program restart
3. **No Save/Load Functionality**: Session data is lost when program exits
4. **Fixed Bet Options**: Only three predetermined betting amounts
5. **No Game Statistics**: Doesn't track long-term player performance
6. **Console-Only Interface**: Limited to text-based interaction
7. **No Multiplayer Support**: Only single-player vs computer

### 5.3 Potential Improvements
1. **🆕 Maximum Round Limit**: Add optional limit to prevent excessively long games
2. Implement file-based session persistence
3. Add configurable bet amounts
4. Include detailed game statistics and history
5. Implement difficulty levels for computer opponent
6. Add graphical user interface
7. Include sound effects and animations

## 6. Testing and Validation

### 6.1 Test Scenarios Covered
- Valid bet amounts (100, 300, 500 SEK)
- Invalid bet inputs (out of range, non-numeric)
- Insufficient balance scenarios
- Maximum deposit limit testing (5,000 SEK)
- **🆕 Extended round scenarios** (games requiring multiple extra rounds)
- **🆕 Winner determination** (various win patterns)
- Multiple consecutive games
- Balance tracking across sessions

### 6.2 🆕 Updated Validation Results
All test scenarios passed successfully, confirming:
- Proper money management
- **🆕 Guaranteed winner logic** works correctly
- Appropriate user feedback
- Robust error handling
- **🆕 No tie games occur**

## 7. Conclusion

The dice game implementation successfully meets all specified requirements while addressing the important enhancement of guaranteed winner logic. The **major update eliminates tie games** by continuing rounds until there's a clear winner, providing a more satisfying gaming experience.

The program demonstrates effective use of C++ building blocks from Lecture 4, with the **key modification being the updated iteration logic** that ensures definitive outcomes. The modular architecture ensures code maintainability and extensibility, while comprehensive input validation and user feedback create a robust user experience.

The **guaranteed winner feature** addresses a potential frustration point in the original design while maintaining all the core functionality and money management capabilities. Future enhancements could focus on balancing game length with the certainty of outcomes.

---

*This updated report demonstrates the enhanced solution approach, implementation details, and critical analysis for the amended Assignment 1 with guaranteed winner logic.*