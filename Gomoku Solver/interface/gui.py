import tkinter as tk
from tkinter import messagebox
from core.board import create_board, is_valid_move, apply_move, is_board_full,get_moves
from core.engine import check_win
from core.minimax import  find_best_move
from core.alphabeta import find_best_move_alpha_beta
from core.constants import *

class GomokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Gomoku Game - Task 1")

        self.board = [['.' for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]
        self.buttons = []
        self.game_mode = tk.IntVar()

        self.setup_mode_selection()

    def setup_mode_selection(self):
        frame = tk.Frame(self.root)
        frame.pack(pady=10)

        tk.Label(frame, text="Select Game Mode:").pack()
        tk.Radiobutton(frame, text="1. Human vs AI", variable=self.game_mode, value=1).pack()
        tk.Radiobutton(frame, text="2. AI vs AI", variable=self.game_mode, value=2).pack()

        tk.Button(frame, text="Start Game", command=self.start_game).pack(pady=5)

    def start_game(self):
        if self.game_mode.get() not in [1, 2]:
            messagebox.showerror("Error", "Please select a game mode.")
            return

        for widget in self.root.winfo_children():
            widget.destroy()  # clear previous widgets

        self.draw_board()

        if self.game_mode.get() == 2:
            self.root.after(500, lambda: self.handle_click(0, 0))

    def draw_board(self):
        frame = tk.Frame(self.root)
        frame.pack()

        for i in range(BOARD_SIZE):
            row = []
            for j in range(BOARD_SIZE):
                btn = tk.Button(frame, text='.', width=3, height=1,command=lambda x=i, y=j: self.handle_click(x, y))
                btn.grid(row=i, column=j)
                row.append(btn)
            self.buttons.append(row)

    def disable_board(self):
        for row in self.buttons:
            for btn in row:
                btn.config(state='disabled')

    def handle_click(self, x, y):
        if self.game_mode.get() == 2:
            ai_1 = find_best_move(self.board, 'X')
            if ai_1:
                ai1_x, ai1_y = ai_1
                apply_move(self.board, ai1_x, ai1_y, 'X')
                self.buttons[ai1_x][ai1_y].config(text='X', state='disabled')
                if check_win(self.board, ai1_x, ai1_y, 'X'):
                    messagebox.showinfo("Game Over", "AI 1 (Minimax) wins!")
                    self.disable_board()
                    return

            if is_board_full(self.board):
                messagebox.showinfo("Game Over", "Draw!")
                self.disable_board()
                return

            ai_2 = find_best_move_alpha_beta(self.board, 'O')
            if ai_2:
                ai2_x, ai2_y = ai_2
                apply_move(self.board, ai2_x, ai2_y, 'O')
                self.buttons[ai2_x][ai2_y].config(text='O', state='disabled')
                if check_win(self.board, ai2_x, ai2_y, 'O'):
                    messagebox.showinfo("Game Over", "AI 2 (Alpha-Beta) wins!")
                    self.disable_board()
                    return

            if is_board_full(self.board):
                messagebox.showinfo("Game Over", "Draw!")
                self.disable_board()
                return

            self.root.after(500, lambda: self.handle_click(0, 0))
            return



        # Check if move is valid
        if not is_valid_move(self.board, x, y):
            messagebox.showwarning("Invalid Move", "Cell already occupied.")
            return

        # Human move
        apply_move(self.board, x, y, 'X')
        self.buttons[x][y].config(text='X', state='disabled')

        # Check if human wins
        if check_win(self.board, x, y, 'X'):
            messagebox.showinfo("Game Over", "You win!")
            self.disable_board()
            return

        ai=find_best_move(self.board,'O')

        ai_x ,ai_y = ai
        apply_move(self.board, ai_x, ai_y, 'O')
        self.buttons[ai_x][ai_y].config(text='O', state='disabled')

        if check_win(self.board, x, y, 'O'):
            messagebox.showinfo("Game Over", "Computer win!")
            self.disable_board()
            return

        # print(get_moves(self.board))


        # Here, we will later add AI move (Task 3)
        # For now, only Human move is handled.
        # print(evaluate_score_player(self.board,'X'))

