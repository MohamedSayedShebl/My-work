from core.constants import *


def create_board():
    return [[EMPTY for _ in range(BOARD_SIZE)] for _ in range(BOARD_SIZE)]


def is_valid_move(board, x, y):
    """Check if the move is inside the board and the cell is empty."""
    return 0 <= x < BOARD_SIZE and 0 <= y < BOARD_SIZE and board[x][y] == EMPTY


def apply_move(board, x, y, symbol):
    """Place the symbol at the given position."""
    board[x][y] = symbol


def is_board_full(board):
    return len(get_moves(board)) ==0

# def get_moves(board):
#     moves=set()
#     for row in range(BOARD_SIZE):
#         for col in range(BOARD_SIZE):
#             if board[row][col] == EMPTY:
#                 moves.add((row, col))
#     return list(moves)

def get_moves(board, radius=1):
    moves = set()
    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE):
            if board[row][col] != EMPTY:
                for i in range(-radius, radius + 1):
                    for j in range(-radius, radius + 1):
                        r, c = row + i, col + j
                        if 0 <= r < BOARD_SIZE and 0 <= c < BOARD_SIZE and board[r][c] == EMPTY:
                            moves.add((r, c))
    return list(moves)