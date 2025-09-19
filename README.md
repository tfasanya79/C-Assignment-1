# Dice Game Assignment - Implementation Summary

## Overview
Successfully implemented a C++ dice game program that meets all the assignment requirements using building blocks from Lecture 4.

## Assignment Requirements Met
✅ User vs Computer dice game with 3 rounds  
✅ Best of 3 rounds logic (early termination when someone wins 2 rounds)  
✅ Betting system with three options: 100 SEK, 300 SEK, 500 SEK  
✅ Money management with maximum deposit of 5000 SEK  
✅ Clear reporting of dice rolls for each round  
✅ Round-by-round winner determination  
✅ Game winner announcement  
✅ Prize calculation and total winnings tracking  
✅ Consolation messages for losses  
✅ Multiple game sessions support  
✅ Proper random number generation using rand() % 6 + 1 with srand(time(0))  

## Building Blocks from Lecture 4 Used

### 1. **Sequence** - Sequential execution
```cpp
int dice1 = rand() % 6 + 1;
int dice2 = rand() % 6 + 1;
return dice1 + dice2;
```

### 2. **Selection** - if/else statements
```cpp
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
```

### 3. **Iteration** - while loops
```cpp
while ((userWins < 2) && (computerWins < 2) && (round <= 3)) {
    // Game round logic
}
```

### 4. **Logical operators** - &&, ||, !
```cpp
if ((deposit > 0) && (deposit <= 5000)) {
    validDeposit = true;
}
```

### 5. **Proper includes and random seeding**
```cpp
#include <iostream>
#include <ctime>
using namespace std;

// In main():
srand(time(0));
```

### 6. **Clear commenting and documentation**
```cpp
/* Function to roll two dice and return the sum
   Uses building block from lecture: rand() % 6 + 1 */
```

## Key Features Implemented

1. **Dice Rolling System**: Each player rolls two dice, sum is compared
2. **Round Management**: Best of 3 with early termination
3. **Money System**: Deposit, betting, balance tracking, winnings calculation
4. **User Interface**: Clear prompts, results display, game status
5. **Input Validation**: Valid bet amounts, deposit limits
6. **Game Flow Control**: Multiple sessions, continue/exit options

## Files Created
- `dice_game.cpp` - Complete C++ source code
- `dice_game` - Compiled executable (ready to run)

## Test Results
✅ Program compiles successfully with g++  
✅ Handles user input validation  
✅ Correctly implements best-of-3 logic  
✅ Properly calculates winnings and losses  
✅ Manages money deposits and betting  
✅ Provides clear game output and user feedback  

## Usage
```bash
./dice_game
```

The program provides an interactive experience where users can:
1. Deposit money (max 5000 SEK per deposit)
2. Choose bet amounts (100, 300, or 500 SEK)
3. Play dice games against the computer
4. Track winnings and balance
5. Play multiple games in one session