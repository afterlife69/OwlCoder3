class Trie:
    def __init__(self):
        self.links = {}
        self.end = 0
        
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        root = Trie()
        for path in folder:
            t = root
            for i in path.split('/'):
                if not i:
                    continue
                if i not in t.links:
                    t.links[i] = Trie()
                t = t.links[i]
            t.end = 1
        res = []
        def dfs(root, cur):
            if root.end:
                res.append(cur)
                return
            for k,v in root.links.items():
                dfs(v, cur + '/' + k)
                
        for k,v in root.links.items():
            dfs(v, '/' + k)
        return res
        
                    
            
            