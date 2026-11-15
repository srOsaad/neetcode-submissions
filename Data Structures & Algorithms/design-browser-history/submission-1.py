class Tab:
    url = None
    back = None
    forward = None

class BrowserHistory:

    def __init__(self, homepage: str):
        self.homepage = Tab()
        self.homepage.url = homepage 

    def visit(self, url: str) -> None:
        t = Tab()
        t.url = url
        t.back = self.homepage
        self.homepage.forward = t
        self.homepage = self.homepage.forward

    def back(self, steps: int) -> str:
        while self.homepage.back != None and steps>0:
            self.homepage = self.homepage.back
            steps-=1
        return self.homepage.url

    def forward(self, steps: int) -> str:
        while self.homepage.forward != None and steps>0:
            self.homepage = self.homepage.forward
            steps-=1
        return self.homepage.url


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)