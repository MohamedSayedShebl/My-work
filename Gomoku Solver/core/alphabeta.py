from .constants import BOARD_SIZE, EMPTY,WIN_SCORE
from .board import is_board_full,is_valid_move,apply_move,get_moves
from .minimax import   evaluate_score_player

def minimax_alpha_beta(board, depth, is_maximizing, player, alpha, beta):  # Added max_depth
    opponent = 'O' if player == 'X' else 'X'

    if evaluate_score_player(board, player) >= WIN_SCORE:
        return float('inf')
    if evaluate_score_player(board, opponent) >= WIN_SCORE:
        return float('-inf')
    if is_board_full(board):
        return 0
    if depth == 0:
        return evaluate_score_player(board, player) - evaluate_score_player(board, opponent)

    possible_moves = get_moves(board)

    center = BOARD_SIZE // 2
    possible_moves.sort(key=lambda m: (abs(m[0] - center) + abs(m[1] - center)), reverse=False)
    if is_maximizing:
        best_score = -float('inf')
        for move in possible_moves:
            if is_valid_move(board, move[0], move[1]):
                apply_move(board, move[0], move[1], player)
                score = minimax_alpha_beta(board, depth - 1, False, opponent, alpha, beta)
                board[move[0]][move[1]] = EMPTY
                best_score = max(score, best_score)
                alpha = max(alpha, best_score)
                if alpha >= beta:
                    break
        return best_score
    else:

        best_score = float('inf')
        for move in possible_moves:
            if is_valid_move(board, move[0], move[1]):
                apply_move(board, move[0], move[1], opponent)
                score = minimax_alpha_beta(board, depth - 1, True, player, alpha, beta)
                board[move[0]][move[1]] = EMPTY
                best_score = min(score, best_score)
                beta = min(beta, best_score)
                if beta <= alpha:
                    break
        return best_score


def find_best_move_alpha_beta(board, player):

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
                score = minimax_alpha_beta(board, 1, False, opponent,-float('inf'),float('inf'))
                board[move[0]][move[1]] = EMPTY

                if score > best_score:
                    best_score = score
                    best_move = (move[0], move[1])

    return best_move