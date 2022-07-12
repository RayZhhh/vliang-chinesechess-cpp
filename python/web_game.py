from http.server import BaseHTTPRequestHandler, HTTPServer
import logging
import json
from py_vliang_chinesechess.evaluator import *
from py_vliang_chinesechess.chessboard import Chessboard
from sys import argv


class VliangServer(BaseHTTPRequestHandler):

    # def do_GET(self):
    #     self.send_response(200)
    #     self.send_header('Content-type', 'text/html;charset=UTF-8')
    #     self.end_headers()
    #     f = open('../html/index.html', 'r')
    #     output = f.read()
    #     print(output)
    #     output = bytes(output, 'UTF-8')
    #     self.wfile.write(output)

    def do_POST(self):
        # get the size of data
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length).decode('utf-8')

        json_dict = json.loads(post_data)
        # print(json_dict["chessboard"])
        board_str = json_dict["chessboard"]
        board_arr = board_str.split(";")

        # eval
        eval_board = Chessboard()
        pos = 0
        for i in range(0, 10):
            for j in range(0, 9):
                eval_board.board[i][j] = int(board_arr[pos])
                pos += 1

        eval_board.print_chessboard()
        evaluator = DeepeningMultiThreadEvaluator(interface_path='./bin/vliang_py_interface',
                                                  chessboard=eval_board,
                                                  tree_type=TreeType.MTDF_QUIE,
                                                  depth=6,
                                                  color_sign=Chessboard.MIN_LAYER_SIGN,
                                                  res_path='./.res.txt')
        path = evaluator.get_best_path()
        resp_msg = str(path.from_x) + ";" + str(path.from_y) + ";" + str(path.to_x) + ";" + str(path.to_y)
        # print(resp_msg)
        self.send_response(200)
        self.send_header('Content-type', 'text/html;charset=UTF-8')
        self.send_header("Access-Control-Allow-Origin", "*")
        self.send_header("Access-Control-Allow-Methods", "POST, GET, OPTIONS, DELETE, PUT")
        self.send_header("Access-Control-Max-Age", "3600")
        self.send_header("Access-Control-Allow-Headers", "Content-Type, Access-Token, Authorization, ybg")
        self.end_headers()
        self.wfile.write(resp_msg.encode('utf-8'))


def run(server_class=HTTPServer, handler_class=VliangServer, port=8080):
    logging.basicConfig(level=logging.INFO)
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    logging.info('VLIANG-Chinese-Chess server starts.\n')
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    print("httpd.server_close()")
    logging.info('Stopping httpd...\n')


if __name__ == '__main__':
    run(port=8080)
