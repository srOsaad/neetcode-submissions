class Solution:

    def encode(self, strs: List[str]) -> str:
        ret = ''
        for w in strs:
            for c in w:
                if c==';' or c=='_':
                    ret+=';'
                ret+=c
            ret+='_'
        return ret

    def decode(self, s: str) -> List[str]:
        w = ''
        ret = []
        jstadd = False
        for c in s:
            if jstadd:
                w+=c
                jstadd=False
            elif c=='_':
                ret.append(w)
                w=''
            elif c==';':
                jstadd = True
            else:
                w+=c
        if w!='':
            ret.append(w)
        return ret