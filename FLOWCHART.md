# Dice Game Flowchart (Updated)

## Program Flow Diagram - Guaranteed Winner Logic

```
                    START
                      |
                      v
            [Initialize random seed]
              srand(time(0))
                      |
                      v
            [Display welcome message]
                      |
                      v
               [Set balance = 0]
            [Set totalWinnings = 0]
                      |
                      v
                 ┌─────────┐
                 │ MAIN    │
                 │ LOOP    │<──────────┐
                 └─────────┘           │
                      |                │
                      v                │
              [Check balance > 0]      │
                   /     \             │
                  NO     YES           │
                  |       |            │
                  v       v            │
            [Deposit money]  [Display balance]
            (Max 5000 SEK)       |     │
                  |              v     │
                  └──────>[Get bet amount]
                              |        │
                              v        │
                     [Validate bet ≤ balance]
                           /     \     │
                          NO     YES   │
                          |       |    │
                          v       v    │
                  [Ask for more  [Deduct bet]
                   deposit]       |    │
                       |          v    │
                       └─────>[PLAY GAME]
                                  |    │
                                  v    │
                           ┌─────────┐ │
                           │ GAME    │ │
                           │ LOGIC   │ │
                           └─────────┘ │
                                  |    │
                                  v    │
                        [Initialize round = 1]
                        [userWins = 0]   │
                        [computerWins = 0]
                                  |    │
                                  v    │
                            ┌─────────┐│
                            │ ROUND   ││
                            │ LOOP    ││<──┐
                            └─────────┘│   │
                                  |    │   │
                                  v    │   │
                          [Roll user dice]  │
                          [Roll computer dice]
                                  |    │   │
                                  v    │   │
                        [Compare dice rolls]│
                             /  |  \   │   │
                           User Tie Computer
                           wins |  wins │   │
                            |   |   |  │   │
                            v   v   v  │   │
                        [Update wins] │   │
                            |   |   |  │   │
                            v   v   v  │   │
                     [Check: userWins == computerWins?]
                             /         \   │   │
                           YES          NO │   │
                            |            | │   │
                            v            v │   │
                    [Continue round]  [Game has winner!]
                    [round++]           |  │   │
                            |           v  │   │
                            └───────>[End game]
                                       |   │   │
                                       v   │   │
                               [Calculate result]
                               (Win/Lose only)  │
                                       |       │
                                       v       │
                               [Update balance] │
                               [Update winnings]│
                                       |       │
                                       v       │
                               [Display results]│
                                       |       │
                                       v       │
                               [Ask play again?]│
                                    /    \     │
                                  YES    NO    │
                                   |      |    │
                                   └──────┘    │
                                          |    │
                                          v    │
                                 [Display final results]
                                          |
                                          v
                                        END
```

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