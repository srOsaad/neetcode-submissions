class Solution:
    def isValidRow(self,i,lis):
        check = [False]*9
        for x in range(9):
            p = lis[i][x]
            if p.isdigit():
                p = int(p)-1
                if check[p]:
                    return False
                check[p]=True
        return True
    
    def isValidCol(self,i,lis):
        check = [False]*9
        for x in range(9):
            p = lis[x][i]
            if p.isdigit():
                p = int(p)-1
                if check[p]:
                    return False
                check[p]=True
        return True

    def isValidBox(self,i,l,lis):
        check = [False]*9
        for x in range(i,i+3):
            for y in range(l,l+3):
                p = lis[x][y]
                if p.isdigit():
                    p = int(p)-1
                    if check[p]:
                        return False
                    check[p]=True
        return True

             
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        for i in range(9):
            if self.isValidRow(i,board) == False:
                return False

        for i in range(9):
            if self.isValidCol(i,board) == False:
                return False

        for i in range(0,9,3):
            for l in range(0,9,3):
                if self.isValidBox(i,l,board) == False:
                    return False
        return True
        