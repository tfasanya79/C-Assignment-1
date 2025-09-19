# Corrected Dice Game Flowchart

## Best-of-3 Dice Game (First to win 2 rounds)

```
START
  |
  ▼
Initialize Game State
- Set player1_wins = 0
- Set player2_wins = 0  
- Set round_number = 1
- Seed random number generator
  |
  ▼
MAIN GAME LOOP
  |
  ▼
Display Round Number
"=== Round X ==="
  |
  ▼
Player 1 Turn
"Player 1, press Enter to roll the dice"
  |
  ▼
Wait for Player 1 Input
(cin.get())
  |
  ▼
Generate Random Number
dice1 = rand() % 6 + 1
  |
  ▼
Display Player 1 Result
"Player 1 rolled: X"
  |
  ▼
Player 2 Turn
"Player 2, press Enter to roll the dice"
  |
  ▼
Wait for Player 2 Input
(cin.get())
  |
  ▼
Generate Random Number
dice2 = rand() % 6 + 1
  |
  ▼
Display Player 2 Result
"Player 2 rolled: Y"
  |
  ▼
Compare Dice Values
  |
  ▼
┌─────────────────┐
│ dice1 > dice2?  │
└─────────────────┘
         │
    YES  │  NO
         │
         ▼
    ┌────────────┐
    │ dice1 <    │
    │ dice2?     │
    └────────────┘
         │
    YES  │  NO
         │
┌────────▼─────────┐   ┌──────────────┐   ┌──────────────┐
│ Player 1 Wins    │   │ Player 2     │   │ It's a Tie!  │
│ Round            │   │ Wins Round   │   │ No winner    │
│ "Player 1 wins   │   │ "Player 2    │   │ "It's a tie  │
│  this round!"    │   │  wins this   │   │  this round!"│
│ player1_wins++   │   │  round!"     │   │              │
└──────────────────┘   │ player2_wins++│   └──────────────┘
         │              └──────────────┘            │
         │                     │                   │
         └─────────────────────┼───────────────────┘
                               │
                               ▼
                    Display Current Score
                    "Score: Player 1: X, Player 2: Y"
                               │
                               ▼
                         Increment Round
                         round_number++
                               │
                               ▼
                    ┌─────────────────────┐
                    │ Check Win Condition │
                    │ player1_wins >= 2?  │
                    └─────────────────────┘
                               │
                          YES  │  NO
                               │
                      ┌────────▼─────────┐
                      │ Declare Player 1 │
                      │ as Overall Winner│
                      │ "Player 1 wins   │
                      │  the game!"      │
                      │ EXIT PROGRAM     │
                      └──────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │ player2_wins >= 2?  │
                    └─────────────────────┘
                               │
                          YES  │  NO
                               │
                      ┌────────▼─────────┐
                      │ Declare Player 2 │
                      │ as Overall Winner│
                      │ "Player 2 wins   │
                      │  the game!"      │
                      │ EXIT PROGRAM     │
                      └──────────────────┘
                               │
                               ▼
                       Continue Game Loop
                       (Go back to MAIN GAME LOOP)
```

## Key Features:
- **Best-of-3 Format**: First player to win 2 rounds wins the game
- **Automatic Continuation**: Game continues until someone reaches 2 wins
- **Fair Play**: Both players have equal chances with random dice rolls (1-6)
- **Clear Round Tracking**: Each round is numbered and results are displayed
- **Tie Handling**: Tie rounds don't count toward the win condition
- **Interactive**: Players press Enter to roll, creating engagement
- **No Early Termination**: Game doesn't stop at round 3, continues until winner determined
- **Score Display**: Current win count shown after each round

## Algorithm Logic:
1. **Initialization**: Set up game variables and random seed
2. **Round Loop**: Continue while neither player has 2 wins
3. **Player Turns**: Sequential dice rolling with user interaction
4. **Round Evaluation**: Compare dice values and award wins
5. **Progress Display**: Show running score
6. **Win Check**: Check if someone reached 2 wins after each round
7. **Game End**: Declare winner and exit when condition met

## Building Blocks Used:
- **Sequence**: Linear execution of dice rolling and score display
- **Selection**: If/else structures for winner determination
- **Iteration**: While loop continues until someone wins 2 rounds
- **Input/Output**: Interactive player input and result display