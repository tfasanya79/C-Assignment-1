# Dice Game Flowchart

## Program Flow Diagram

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
                        [Check if 2 wins]  │
                             /    \     │   │
                           YES    NO    │   │
                            |      |    │   │
                            v      v    │   │
                        [End game] [Continue]
                            |      |    │   │
                            v      └────┘   │
                     [Calculate result]     │
                        (Win/Lose/Tie)      │
                            |               │
                            v               │
                     [Update balance]       │
                     [Update winnings]      │
                            |               │
                            v               │
                     [Display results]      │
                            |               │
                            v               │
                     [Ask play again?]      │
                           /    \           │
                         YES    NO          │
                          |      |          │
                          └──────┘          │
                                 |          │
                                 v          │
                        [Display final results]
                                 |
                                 v
                               END
```

## Key Decision Points

1. **Money Check**: Does user have sufficient balance?
2. **Bet Validation**: Is bet amount valid and ≤ balance?
3. **Round Winner**: Who won the current round?
4. **Game End**: Has someone won 2 rounds (best of 3)?
5. **Continue Playing**: Does user want another game?

## Building Blocks Used

- **Sequence**: Linear execution of statements
- **Selection**: if/else decisions at each diamond
- **Iteration**: Loops for main game and rounds
- **Functions**: Separate modules for dice rolling, game logic

## Flow Explanation

1. **Initialization**: Set up random seed and variables
2. **Money Management**: Check balance, deposit if needed
3. **Betting**: Get valid bet amount from user
4. **Game Execution**: Play best-of-3 rounds
5. **Result Processing**: Calculate winnings/losses
6. **Session Control**: Continue or exit program