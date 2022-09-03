import copy


# 开始生成数据集
# 对于每个走法，我们记录当前的盘面（以board_str形式），然后将盘面进行左右对称，同时路径也进行相应的对称，并记录对称后的走法。


def gen_one_game(move_list: str, path: str):
    move_list = [move_list[i] for i in range(len(move_list) - 1)]
    # print(move_list)

    if int(move_list[0]) < 6:
        raise RuntimeError('move_list[0] < 6')

    if len(move_list) % 4 != 0:
        print(move_list)
        raise RuntimeError('Length of the path list can not divided by 4.')

    out = open(path, 'w')

    board = Chessboard()

    for i in range(0, len(move_list), 8):

        # 写棋盘
        out.write(board.to_board_sequence() + '#')
        out.flush()
        # 写路径
        fx1, fy1, tx1, ty1 = int(move_list[i]), int(move_list[i + 1]), int(move_list[i + 2]), int(move_list[i + 3])
        path1 = ChessPath(fx1, fy1, tx1, ty1)
        out.write(str(path1) + '\n')

        # 棋盘左右对称，路径反转，写棋盘写路径
        board_, path1_ = copy.deepcopy(board), copy.deepcopy(path1)
        board_.symmetry()
        path1_.symmetry()

        # print(board_.to_board_sequence())
        out.write(board_.to_board_sequence() + '#')
        out.flush()
        out.write(str(path1_) + '\n')

        # 走棋
        board.move_chess(path1)

        # 轮到对手下棋，但是AI学习的时候依然学习对手的决策，将对手当成自己方
        if i + 4 < len(move_list):
            fx2, fy2, tx2, ty2 = \
                int(move_list[i + 4]), int(move_list[i + 5]), int(move_list[i + 6]), int(move_list[i + 7])
            path2 = ChessPath(fx2, fy2, tx2, ty2)

            board.side_exchange()
            path2.side_exchange()

            # print(board.to_board_sequence())
            out.write(board.to_board_sequence() + '#')
            out.write(str(path2) + '\n')

            # 棋盘左右对称，路径反转，写棋盘写路径
            board_, path2_ =  copy.deepcopy(board), copy.deepcopy(path2)
            board_.symmetry()
            path2_.symmetry()
            out.write(board_.to_board_sequence() + '#')
            out.write(str(path2_) + '\n')

            # 再次反转棋盘
            board.side_exchange()

        out.flush()

    out.close()


OUT_PATH = '../rl/data/full_game_dataset.txt'
f_full_game = open('../data/full_game.txt', 'r')

for _ in range(6598):
    line = f_full_game.readline()
    if line != '':
        gen_one_game(line, path=OUT_PATH)
