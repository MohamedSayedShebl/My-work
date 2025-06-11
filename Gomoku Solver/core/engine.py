from core.constants import *


def check_win(board, x, y, symbol):
    """Check if placing the symbol at (x, y) wins the game."""
    directions = [(1, 0), (0, 1), (1, 1), (1, -1)]

    for dx, dy in directions:
        count = 1

        for direction in [1, -1]:  # check both directions
            i = 1
            while True:
                nx = x + dx * i * direction
                ny = y + dy * i * direction
                if 0 <= nx < BOARD_SIZE and 0 <= ny < BOARD_SIZE and board[nx][ny] == symbol:
                    count += 1
                    i += 1
                else:
                    break

        if count >= 5:
            return True

    return False


def check_win_anywhere(board, symbol):
    for x in range(BOARD_SIZE):
        for y in range(BOARD_SIZE):
            if board[x][y] == symbol and check_win(board, x, y, symbol):
                return True
    return False

