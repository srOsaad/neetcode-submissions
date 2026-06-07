class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map = {}
        ret = []
        for x in nums:
            if x not in map:
                map[x]=1
            else:
                map[x]+=1

        map = sorted(map.items(), key = lambda x:x[1],reverse=True)
        for key,_ in map:
            ret.append(key)
            k-=1
            if k==0: break
        return ret
