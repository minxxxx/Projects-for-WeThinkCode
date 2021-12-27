
# coding: utf-8

# In[39]:


class HotBeverage:
    
    descr = "Just some hot water in a cup."
    def __init__(self, a = 0.30, b = "hot beverage"):
        self.price = a
        self.name = b
    
    
    def description(self):
        return self.descr 
    
    def __str__(self):
        return 'name :' + self.name + '\n' + 'price : ' + str(self.price) + '\n' + 'description : ' + self.description()
    
class Coffee:
    
    descr = "A coffee, to stay awake."
    def __init__(self, a = 0.40, b = "coffee"):
        self.price = a
        self.name = b
    
    
    def description(self):
        return self.descr 
    
    def __str__(self):
        return 'name :' + self.name + '\n' + 'price : ' + str(self.price) + '\n' + 'description : ' + self.description()
    
class Tea:
    
    descr = "Aromatic beverage commonly prepared by pouring hot or boiling water over cured leaves of the Camellia sinensis."
    def __init__(self, a = 0.30, b = "tea"):
        self.price = a
        self.name = b
    
    
    def description(self):
        return self.descr 
    
    def __str__(self):
        return 'name :' + self.name + '\n' + 'price : ' + str(self.price) + '\n' + 'description : ' + self.description()
    
class Chocolate:
    
    descr = "Chocolate, sweet chocolate..."
    def __init__(self, a = 0.50, b = "chocolate"):
        self.price = a
        self.name = b
    
    
    def description(self):
        return self.descr 
    
    def __str__(self):
        return 'name :' + self.name + '\n' + 'price : ' + str(self.price) + '\n' + 'description : ' + self.description()
    

class Cappuccino:
    
    descr = "Un po’ di Italia nella sua tazza!"
    def __init__(self, a = 0.45, b = "cappuccino"):
        self.price = a
        self.name = b
    
    
    def description(self):
        return self.descr 
    
    def __str__(self):
        return 'name :' + self.name + '\n' + 'price : ' + str(self.price) + '\n' + 'description : ' + self.description()
    
    
if __name__ == "__main__":
    hotwater = HotBeverage()
    print(hotwater)
    coffe = Coffee()
    print(coffe)
    tea = Tea()
    print(tea)
    choco = Chocolate()
    print(choco)
    cap_coffe = Cappuccino()
    print(cap_coffe)


# In[38]:


cup = HotBeverage()
cup.__str__()

