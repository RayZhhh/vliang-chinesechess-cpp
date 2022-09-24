import json
import sys
sys.path.append('..')
from yoll.dicts import _path_id_dict
from yoll.chess import Chessboard, ChessPath


# ========================================= 读取棋谱文件 =========================================
# cm_file = open('../data/raw_chess_manual.json', 'r')
# # 读取文件所有内容
# json_str = cm_file.read()
#
# # 转化成 json_dict
# cm_json = json.loads(json_str)
#
# half_game = 0
# full_game = 0
#
# for i in range(0, len(cm_json)):
#     if cm_json[i]['init'] == '':
#         full_game += 1
#     else:
#         half_game += 1
#
# print('half game nums: ', half_game)
# print('full game nums: ', full_game)
#
# fout = open('../data/full_game.txt', 'w')
# row_num = 0
#
# for i in range(0, len(cm_json)):
#     if cm_json[i]['init'] == '':
#         move_list = cm_json[i]['move_list']
#         move_list_f = ''
#         for j in range(0, len(move_list), 2):
#             move_list_f += move_list[j + 1]
#             move_list_f += move_list[j]
#         fout.write(move_list_f)
#         fout.write('\n')
#         row_num += 1
#
# print(row_num)
# ========================================= 读取棋谱文件 =========================================



# ========================================= 过滤得到所有正确无误的棋谱 =========================================
# def is_move_list_legal(move_list) -> bool:
#     """检查 move list 路径中的各种东西是否合法，因为发现有些路径有严重错误"""
#     board = Chessboard()
#     for i in range(0, len(move_list), 8):
#         fx, fy, tx, ty = int(move_list[i]), int(move_list[i + 1]), int(move_list[i + 2]), int(move_list[i + 3])
#         path = ChessPath(fx, fy, tx, ty)
#         board.move_chess(path)
#
#         if i + 4 < len(move_list):
#             fx, fy, tx, ty = int(move_list[i + 4]), int(move_list[i + 5]), int(move_list[i + 6]), int(move_list[i + 7])
#             path = ChessPath(fx, fy, tx, ty)
#             if str(path) not in _path_num_dict.keys():
#                 return False
#
#             board.move_chess(path)
#     return True
#
#
# fin = open('../data/full_game.txt', 'r')
# fout = open('../data/correct_lists.txt', 'w')
# lines = fin.readlines()
# for line in lines:
#     line = line.strip('\n')
#     if is_move_list_legal(line):
#         fout.write(line + '\n')
# ========================================= 过滤得到所有正确无误的棋谱 =========================================


# ========================================= 生成数据集 =========================================
# out_self = open('../data/self_move.txt', 'w')
# out_rival_temp = open('../data/rival_move_temp.txt', 'w')
#
#
# def gen_dataset(move_list: str):
#     board = Chessboard()
#
#     for i in range(0, len(move_list), 8):
#
#         out_self.write(board.to_board_sequence() + '#')  # 写棋盘
#         fx, fy, tx, ty = int(move_list[i]), int(move_list[i + 1]), int(move_list[i + 2]), int(move_list[i + 3])
#         path = ChessPath(fx, fy, tx, ty)
#         out_self.write(str(path) + '\n')  # 写路径
#         board.move_chess(path)
#
#         if i + 4 < len(move_list):
#             out_rival_temp.write(board.to_board_sequence() + '#')
#             fx, fy, tx, ty = int(move_list[i + 4]), int(move_list[i + 5]), int(move_list[i + 6]), int(move_list[i + 7])
#             path = ChessPath(fx, fy, tx, ty)
#             out_rival_temp.write(str(path) + '\n')
#             board.move_chess(path)
#
#
# in_full_game = open('../data/correct_lists.txt', 'r')
# all_lines = in_full_game.readlines()
# for i in all_lines:
#     path = i.strip('\n')
#     gen_dataset(path)
# ========================================= 生成数据集 =========================================


# ========================================= 生成 self_move_sym =========================================
# fout = open('../data/self_move_sym.txt', 'w')
# fin = open('../data/self_move.txt', 'r')
#
# all_lines = fin.readlines()
#
# for line in all_lines:
#     board = Chessboard(board_seq=line.split('#')[0])
#     path = ChessPath(path_str=line.split('#')[1])
#     # board.print_chessboard()
#     # print('path: ', line.split('#')[1])
#     board.symmetry()
#     path.symmetry()
#     print('one hot index: ', _path_num_dict[str(path)])
#     fout.write(board.to_board_sequence() + '#')
#     fout.write(str(path) + '\n')
# ========================================= 生成 self_move_sym =========================================


# ========================================= 生成 rival_move =========================================
# fin = open('../data/rival_move_temp.txt', 'r')
# fout = open('../data/rival_move.txt', 'w')
#
# all_lines = fin.readlines()
#
# for line in all_lines:
#     board = Chessboard(board_seq=line.split('#')[0])
#     path = ChessPath(path_str=line.split('#')[1])
#     board.side_exchange()
#     path.side_exchange()
#     print('one hot index: ', _path_num_dict[str(path)])  ###########################################################
#     fout.write(board.to_board_sequence() + '#')
#     fout.write(str(path) + '\n')
# ========================================= 生成 rival_move =========================================


# ========================================= 生成 rival_move_sym =========================================
# fout = open('../data/rival_move_sym.txt', 'w')
# fin = open('../data/rival_move.txt', 'r')
#
# all_lines = fin.readlines()
#
# for line in all_lines:
#     board = Chessboard(board_seq=line.split('#')[0])
#     path = ChessPath(path_str=line.split('#')[1])
#     # board.print_chessboard()
#     # print('path: ', line.split('#')[1])
#     board.symmetry()
#     path.symmetry()
#     print('one hot index: ', _path_num_dict[str(path)])  ###########################################################
#     fout.write(board.to_board_sequence() + '#')
#     fout.write(str(path) + '\n')
# ========================================= 生成 rival_move_sym =========================================


# ========================================= 将四个棋谱合成为一个 =========================================
fout = open('../data/cchess_data.txt', 'w')
fin1 = open('../data/self_move.txt', 'r')
fin2 = open('../data/self_move_sym.txt', 'r')
fin3 = open('../data/rival_move.txt', 'r')
fin4 = open('../data/rival_move_sym.txt', 'r')

fins = [fin1, fin2, fin3, fin4]

for fin in fins:
    all_lines = fin.readlines()
    for line in all_lines:
        fout.write(line)
# ========================================= 将四个棋谱合成为一个 =========================================
