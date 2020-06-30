class ProductOfNumbers:
    products = []
    after = -1
    
    def __init__(self):
        self.products.append(1)

    def add(self, num: int) -> None:
        if num == 0:
            self.after = len(self.products)
            num = 1
        self.products.append(num * self.products[-1])

    def getProduct(self, k: int) -> int:
        if len(self.products)-1-k < self.after:
            return 0
        return int(self.products[-1] / self.products[len(self.products)-1-k])
            


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)
