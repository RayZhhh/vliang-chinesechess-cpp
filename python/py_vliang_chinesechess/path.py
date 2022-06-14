class ChessPath:
    def __init__(self, from_x=0, from_y=0, to_x=0, to_y=0, eat=0):
        self.from_x = from_x
        self.from_y = from_y
        self.to_x = to_x
        self.to_y = to_y
        self.eat = eat
        self.value = 0

    def __str__(self):
        return "ChessPath { <" + str(self.from_x) + ", " + str(self.from_y) + "> to <" + str(self.to_x) + ", " + str(
            self.to_y) + "> eat " + str(self.eat) + "}"
