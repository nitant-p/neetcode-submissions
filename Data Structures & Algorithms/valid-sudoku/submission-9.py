class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(len(board)):
            row = set()
            for j in range(len(board[0])):
                n = board[i][j]
                if n != "." and n in row:
                    return False
                row.add(n)
            
        for i in range(len(board[0])):
            row = set()
            for j in range(len(board)):
                n = board[j][i]
                if n != "." and n in row:
                    return False
                row.add(n)

        for i in range(3):
            for j in range(3):
                row = set()
                for x in range((3*i), (3 * i) + 3):
                    for y in range((3*j), (3 * j) + 3):
                        print(f"x: {x}, y: {y}")
                        if board[x][y] != "." and board[x][y] in row:
                            return False
                        row.add(board[x][y])

        return True