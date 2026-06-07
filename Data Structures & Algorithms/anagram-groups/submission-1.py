class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        aux = []
        ret = []
        added = [False]*len(strs)
        haveToAdd = len(strs)
        for w in strs:
            aux.append(sorted(w))
        for i in range(len(aux)):
            temp = []
            if added[i]:
                continue
            temp.append(strs[i])
            haveToAdd -= 1
            added[i]=True

            for l in range(i+1,len(aux)):
                if added[l]:
                    continue

                if aux[i]==aux[l]:
                    temp.append(strs[l])
                    haveToAdd -= 1
                    added[l]=True
            ret.append(temp)
            if haveToAdd == 0:
                break
                   
        return ret