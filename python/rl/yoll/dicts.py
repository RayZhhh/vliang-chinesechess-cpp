
#
#
#

# 所有路径的数量
_num_paths: int = ...

# 存放路径对应编号的字典
# key: str   => 路径
# value: int => 该路径的编号
_path_num_dict = dict()

# 存放编号对应路径的字典
# key: int   => 路径编号
# value: str => 该编号对应的路径
_num_path_dict = dict()


def _init_dicts():
    """初始化 _num_path_dict 和 _path_num_dict"""

    def convert(fx, fy, tx, ty):
        """将 tuple 路径转换为 str 的 key"""
        return str(fx) + str(fy) + str(tx) + str(ty)

    def is_legal_pos(x, y):
        """判断这个当前坐标在棋盘上是否合法"""
        if 0 <= x < 10 and 0 <= y < 9:
            return True
        else:
            return False

    paths = []

    # 找到车、马、将、炮、卒的所有路径
    # 遍历棋盘上的每个点作为路径的起始点
    for i in range(10):
        for j in range(9):
            # 纵向的所有路径
            for rows in range(10):
                if rows == i:
                    continue
                paths.append(convert(i, j, j, rows))

            # 横向所有路径
            for cols in range(9):
                if cols == j:
                    continue
                paths.append(convert(i, j, i, cols))

            # 马的所有位置
            for nx, ny in [(-2, -1), (-1, -2), (-2, 1), (1, -2), (2, -1), (-1, 2), (2, 1), (1, 2)]:
                if is_legal_pos(i + nx, j + ny):
                    paths.append(convert(i, j, i + nx, j + ny))

    # 枚举象的所有路径
    paths_of_3 = ['0220', '0224', '0624', '0628',
                  '2002', '2042', '2402', '2406',
                  '2442', '2446', '2806', '2846',
                  '4220', '4224', '4624', '4628',
                  '5270', '5274', '5674', '5678',
                  '7052', '7092', '7452', '7456',
                  '7492', '7496', '7856', '7896',
                  '9270', '9274', '9674', '9678']

    # 枚举士的所有路径
    paths_of_4 = ['0314', '0514', '1403', '1405',
                  '1423', '1425', '2314', '2514',
                  '7384', '7584', '8473', '8475',
                  '8493', '8495', '9384', '9584']

    paths = paths + paths_of_3 + paths_of_4
    global _num_paths
    _num_paths = len(paths)

    # 将路径加入字典
    for num, path in enumerate(paths):
        _num_path_dict[num] = path
        _path_num_dict[path] = num


_init_dicts()
