# Dice Game Program Flowchart

## Program Flow Diagram

```
                    [START]
                       |
                   Initialize
                  (Seed random,
                   balance = 0,
                totalWinnings = 0)
                       |
                       v
                ┌─── Balance > 0? ───┐
                │                    │
             NO │                    │ YES
                │                    │
                v                    v
         [Deposit Money]          [Choose Bet]
         (Max 5000 SEK)          (100/300/500 SEK)
                │                    │
                └──────┬─────────────┘
                       v
                 Sufficient Funds?
                       │
                   NO  │  YES
                ┌──────┴──────┐
                │             │
                v             v
          [Error Message]  [Deduct Bet]
          (Try again)     (From balance)
                │             │
                └─────────────┘
                       │
                       v
                 [Initialize Game]
                (userWins = 0,
                computerWins = 0,
                 round = 1)
                       │
                       v
            ┌─── GAME LOOP ────┐
            │                  │
            │  (userWins < 2)  │
            │       AND        │ 
            │ (computerWins<2) │
            │       AND        │
            │   (round <= 3)   │
            │                  │
            └──── YES ─────────┘
                       │
                       v
                 [Roll Dice]
               (User & Computer
                each roll 2 dice)
                       │
                       v
               [Compare Dice Sums]
                       │
            ┌──────────┼──────────┐
            │          │          │
     User > Computer   │   Computer > User
            │          │          │
            v          v          v
      [User Wins]  [Tie Round]  [Computer Wins]
      (userWins++) (No points)  (computerWins++)
            │          │          │
            └──────────┼──────────┘
                       │
                       v
                [Round = Round + 1]
                       │
                       v
              [Display Current Score]
                       │
                       v
            ┌─── Check Early Win ───┐
            │                       │
            │  userWins == 2  OR    │
            │  computerWins == 2    │
            │                       │
            └──── YES ──────────────┘
                       │
                       v
                [End Game Loop]
                       │
                       v
              ┌─ Determine Winner ─┐
              │                    │
       userWins > computerWins?    │
              │                    │
        YES   │                    │ NO
              │                    │
              v                    v
        [USER WINS!]         [Check Tie]
        (Win bet × 2)             │
              │            userWins ==
              │           computerWins?
              │                    │
              │              YES   │   NO
              │                    │    │
              │                    v    v
              │              [GAME TIE] [COMPUTER WINS!]
              │             (Return bet) (User loses bet)
              │                    │    │
              └────────────────────┼────┘
                                   │
                                   v
                          [Display Results]
                         (Show final score,
                          rounds played,
                           money won/lost)
                                   │
                                   v
                            Play Again?
                                   │
                             YES   │   NO
                        ┌──────────┼──────────┐
                        │                     │
                        v                     v
                [Back to Balance Check] [Display Final Stats]
                                             │
                                             v
                                          [END]
```

## Key Flowchart Features

### Game Logic Flow
- **Best-of-3 Implementation**: Loop continues while `(userWins < 2) AND (computerWins < 2) AND (round <= 3)`
- **Early Termination**: Game ends immediately when someone reaches 2 wins
- **Round Tie Handling**: Tied rounds award no points, game continues to next round
- **Complete Game Tie**: Rare scenario (1-1 with round 3 tie) returns user's bet

### Decision Points
1. **Balance Check**: Ensures user has money to play
2. **Bet Validation**: Confirms sufficient funds for chosen bet
3. **Game Loop**: Controls best-of-3 rounds with early termination
4. **Round Winner**: Determines who wins each individual round
5. **Early Win Check**: Stops game when someone reaches 2 wins
6. **Final Winner**: Determines overall game outcome and money flow

### Money Flow
- **Deposit**: Up to 5,000 SEK per transaction
- **Bet Deduction**: Money removed before game starts
- **Win Calculation**: User wins 2× bet amount
- **Loss Handling**: User loses their bet (already deducted)
- **Tie Handling**: User's bet is returned

### Building Blocks Used
- **Sequence**: Linear execution of dice rolling and calculations
- **Selection**: If/else structures for winner determination
- **Iteration**: While loops for game sessions and round management
- **Logical Operators**: Combined conditions for game loop control`

## Key Changes in Updated Logic

### **Major Change: Guaranteed Winner**
- **Old Logic**: Best of 3 rounds, ties possible
- **New Logic**: Continue rounds until userWins ≠ computerWins

### **Updated Decision Points**

1. **Money Check**: Does user have sufficient balance?
2. **Bet Validation**: Is bet amount valid and ≤ balance?
3. **Round Winner**: Who won the current round?
4. **🆕 Winner Check**: Are wins equal? (If yes, continue; if no, game ends)
5. **Continue Playing**: Does user want another game?

### **Eliminated Logic**
- ❌ Best of 3 limit removed
- ❌ Tie game outcomes removed
- ❌ Bet return on ties removed

## Building Blocks Used

- **Sequence**: Linear execution of statements
- **Selection**: if/else decisions at each diamond
- **🆕 Modified Iteration**: `while (userWins == computerWins)` - continues until winner
- **Functions**: Separate modules for dice rolling, game logic

## Flow Explanation

1. **Initialization**: Set up random seed and variables
2. **Money Management**: Check balance, deposit if needed
3. **Betting**: Get valid bet amount from user
4. **🆕 Game Execution**: Play rounds until there's a clear winner
5. **🆕 Result Processing**: Calculate winnings/losses (no ties)
6. **Session Control**: Continue or exit program

## Updated Game Logic Details

### **Round Loop Logic**
```cpp
while (userWins == computerWins) {
    // Play round
    // Update wins
    // Check if winner exists
}
```

### **Possible Outcomes**
- **User Wins**: userWins > computerWins → User gets 2× bet
- **Computer Wins**: computerWins > userWins → User loses bet
- **🚫 No Ties**: Game continues until someone has more wins