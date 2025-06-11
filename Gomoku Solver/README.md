****Task Division for Gomoku Game Solver Project (5 Members)****

**Task 1: Game Setup and User Input Handling**

Design the Gomoku board (e.g., 15×15 or 19×19 grid).

Implement functions to accept and validate user input for the board state (e.g., coordinate system or matrix input).

Handle initial game setup (e.g., Human vs. AI or AI vs. AI mode selection).

**Task 2: Game Engine and Rules Implementation**

Enforce Gomoku rules (win condition: 5 in a row horizontally/vertically/diagonally).

Implement move validation (e.g., prevent overwriting occupied cells).

Manage game state updates after each move.

**Task 3: Minimax Algorithm Implementation**

Implement the Minimax algorithm for AI decision-making.

Design a heuristic function to evaluate board states (e.g., prioritize blocking opponent’s 4-in-a-row).

Integrate depth limits to control computational complexity.

**Task 4: Alpha-Beta Pruning Algorithm Implementation**

Optimize the Minimax algorithm using Alpha-Beta pruning.

Compare performance (e.g., number of nodes evaluated) with plain Minimax.

Ensure compatibility with the game engine for AI vs. AI mode.

**Task 5: Output, Testing, and Bonus GUI**

Display the AI’s chosen move (coordinates) and updated board state.

Test all game modes (Human vs. AI, AI vs. AI) and edge cases (e.g., full board).

(Bonus) Implement a simple GUI (e.g., using Pygame or Tkinter) for interactive play.


**Collaboration & Integration**

**Shared Components:**

All members must agree on board representation (e.g., 2D list) and coordinate system.

Task 3 and Task 4 members collaborate to ensure Minimax and Alpha-Beta use the same heuristic.


**Integration:**

Task 1 and Task 2 members work together to link input handling with the game engine.

Task 5 member integrates outputs from all modules for final testing.
