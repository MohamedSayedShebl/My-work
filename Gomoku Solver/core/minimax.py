from .constants import BOARD_SIZE, EMPTY,WIN_SCORE
from .board import is_board_full,is_valid_move,apply_move,get_moves



# def ai_first_move(board):
#     ai=None
#     for x in range(BOARD_SIZE):
#         for y in range(BOARD_SIZE):
#             if board[x][y] != EMPTY:
#                 random_play = random.random()
#                 if 0 <= random_play < 0.125:
#                     ai = (x-1,y)
#
#                 elif 0.125 <= random_play < 0.25:
#                     ai = (x + 1, y)
#
#                 elif 0.25 <= random_play < 0.375:
#                     ai = (x , y+1)
#
#                 elif 0.375 <= random_play < 0.5:
#                     ai = (x , y-1)
#
#                 elif 0.5 <= random_play < 0.625:
#                     ai = (x-1, y-1)
#
#                 elif 0.625 <= random_play < 0.75:
#                     ai = (x-1 , y+1)
#
#                 elif 0.75 <= random_play < 0.875:
#                     ai = (x +1, y-1)
#
#                 else:
#                     ai = (x+1 , y+1)
#
#                 if 0 <= ai[0] <BOARD_SIZE and 0 <= ai[1] < BOARD_SIZE and board[ai[0]][ai[1]] == EMPTY:
#                     return ai
#     center=BOARD_SIZE//2
#     if board[center][center] == EMPTY:
#         return center,center
#
#     return None






def minimax(board, depth, is_maximizing, player):  # Added max_depth
    opponent = 'O' if player == 'X' else 'X'



    if evaluate_score_player(board,player) >= WIN_SCORE:
        return float('inf')
    if evaluate_score_player(board,opponent) >= WIN_SCORE:
        return float('-inf')
    if is_board_full(board):
        return 0
    if depth == 0:
        return evaluate_score_player(board, player) - evaluate_score_player(board, opponent)

    possible_moves=get_moves(board)

    center = BOARD_SIZE // 2
    possible_moves.sort(key=lambda m: (abs(m[0] - center) + abs(m[1] - center)), reverse=False)
    if is_maximizing:
        best_score = -float('inf')
        for move in possible_moves:
            if is_valid_move(board, move[0],move[1]):
                apply_move(board, move[0], move[1], player)
                score = minimax(board, depth - 1, False, opponent)
                board[move[0]][move[1]] = EMPTY
                best_score = max(score, best_score)
        return best_score
    else:

        best_score = float('inf')
        for move in possible_moves:
                if is_valid_move(board, move[0], move[1]):
                    apply_move(board, move[0], move[1], opponent)
                    score = minimax(board, depth - 1, True, player)
                    board[move[0]][move[1]] = EMPTY
                    best_score = min(score, best_score)
        return best_score


#
#
#
def find_best_move(board, player):

    center = BOARD_SIZE // 2
    if is_valid_move(board, center, center):
        return (center, center)

    best_score = -float('inf')
    best_move = (-1, -1)
    opponent = 'O' if player == 'X' else 'X'
    possible_moves = get_moves(board)
    possible_moves.sort(key=lambda m: (abs(m[0] - center) + abs(m[1] - center)), reverse=False)
    for move in possible_moves:
            if is_valid_move(board, move[0], move[1]):
                apply_move(board, move[0], move[1], player)
                score = minimax(board, 1, False, opponent)
                board[move[0]][move[1]] = EMPTY

                if score > best_score:
                    best_score = score
                    best_move = (move[0], move[1])

    return best_move



def evaluate_score_player(board, symbol):
    # score= max(eval_horizontal(board, symbol), eval_vertical(board, symbol),eval_diagonal(board, symbol))
    # return score
    score = 0
    score += 1000 * count_consecutive(board, symbol, 5)
    score += 100 * count_consecutive(board, symbol, 4)
    score += 10 * count_consecutive(board, symbol, 3)
    score += 1 * count_consecutive(board, symbol, 2)
    return score


# def eval_horizontal(board,player):
#     max_consecutive = 0
#
#     for row in range(BOARD_SIZE):
#         current_count = 0
#         for col in range(BOARD_SIZE):
#             if board[row][col] == player:
#                 current_count += 1
#                 max_consecutive = max(max_consecutive, current_count)
#             else:
#                 current_count = 0
#
#     return max_consecutive
#
# def eval_vertical(board,player):
#     max_consecutive = 0
#
#     for col in range(BOARD_SIZE):
#         current_count = 0
#         for row in range(BOARD_SIZE):
#             if board[row][col] == player:
#                 current_count += 1
#                 max_consecutive = max(max_consecutive, current_count)
#             else:
#                 current_count = 0
#
#     return max_consecutive
#
# def eval_diagonal(board, player):
#     max_consecutive = 0
#
#     for row in range(BOARD_SIZE):
#         for col in range(BOARD_SIZE):
#             if board[row][col] == player:
#                 count = 1
#                 i = 1
#                 while (row + i < BOARD_SIZE and col + i < BOARD_SIZE and
#                        board[row + i][col + i] == player):
#                     count += 1
#                     i += 1
#                 max_consecutive = max(max_consecutive, count)
#
#     for row in range(BOARD_SIZE):
#         for col in range(BOARD_SIZE):
#             if board[row][col] == player:
#                 count = 1
#                 i = 1
#                 while (row + i < BOARD_SIZE and col - i >= 0 and
#                        board[row + i][col - i] == player):
#                     count += 1
#                     i += 1
#                 max_consecutive = max(max_consecutive, count)
#
#     return max_consecutive

def count_consecutive(board, player, length):
    count = 0
    # horizontal
    for row in range(BOARD_SIZE):
        for col in range(BOARD_SIZE - length + 1):
            if all(board[row][col + i] == player for i in range(length)):
                count += 1
    #vertical
    for col in range(BOARD_SIZE):
        for row in range(BOARD_SIZE - length + 1):
            if all(board[row + i][col] == player for i in range(length)):
                count += 1
    #diagonal
    for row in range(BOARD_SIZE - length + 1):
        for col in range(length - 1, BOARD_SIZE):
            if all(board[row + i][col - i] == player for i in range(length)):
                count += 1

    for row in range(BOARD_SIZE - length + 1):
        for col in range(BOARD_SIZE - length + 1):
            if all(board[row + i][col + i] == player for i in range(length)):
                count += 1
    return count

# def evaluate_position(board, player):
#     """Simple evaluation function - counts potential lines"""
#     opponent = 'O' if player == 'X' else 'X'
#     score = 0
#
#     # Check all possible 5-in-a-row segments
#     for i in range(BOARD_SIZE):
#         for j in range(BOARD_SIZE):
#             if board[i][j] == player:
#                 score += 10
#             elif board[i][j] == opponent:
#                 score -= 10
#
#     return score
#
#
# def minimax(board, depth, is_maximizing, player, max_depth=2):
#     opponent = 'O' if player == 'X' else 'X'
#
#     # Base cases
#     if check_win_anywhere(board,player):
#         return 1000 - depth  # Prefer faster wins
#     elif check_win_anywhere(board, opponent):
#         return -1000 + depth  # Prefer slower losses
#     elif is_board_full(board) or depth >= max_depth:
#         return evaluate_position(board, player)
#
#     if is_maximizing:
#         best_score = -float('inf')
#         for i in range(BOARD_SIZE):
#             for j in range(BOARD_SIZE):
#                 if is_valid_move(board, i, j):
#                     apply_move(board, i, j, player)
#                     score = minimax(board, depth + 1, False, player, max_depth)
#                     board[i][j] = EMPTY
#                     best_score = max(score, best_score)
#         return best_score
#     else:
#         best_score = float('inf')
#         for i in range(BOARD_SIZE):
#             for j in range(BOARD_SIZE):
#                 if is_valid_move(board, i, j):
#                     apply_move(board, i, j, opponent)
#                     score = minimax(board, depth + 1, True, player, max_depth)
#                     board[i][j] = EMPTY
#                     best_score = min(score, best_score)
#         return best_score
#
#
# def find_best_move(board, player):
#     best_score = -float('inf')
#     best_move = None
#
#     # Check center first for better opening moves
#     center = BOARD_SIZE // 2
#     if is_valid_move(board, center, center):
#         return (center, center)
#
#     for i in range(BOARD_SIZE):
#         for j in range(BOARD_SIZE):
#             if is_valid_move(board, i, j):
#                 apply_move(board, i, j, player)
#                 score = minimax(board, 0, False, player)
#                 board[i][j] = EMPTY
#
#                 if score > best_score or best_move is None:
#                     best_score = score
#                     best_move = (i, j)
#
#     return best_move if best_move else (center, center)