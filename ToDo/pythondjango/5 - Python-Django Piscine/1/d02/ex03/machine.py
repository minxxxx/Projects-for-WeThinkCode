
# coding: utf-8

# In[1]:


from beverages import *
import random        


# In[46]:


class CoffeeMachine:
    number_of_serves = 0
    def __init__(self):
        self.number_of_serves = 0
    
    class EmptyCup(HotBeverage):
        descr = "An empty cup?! Gimme my money back!"
#         self.name = "empty cup"
        def __init__(self, a = 0.9, b = "empty cup"):
            HotBeverage.__init__(self, a, b)
        
    class BrokenMachineException(Exception):
        def __init__(self, message = "This coffee machine has to be repaired."):
            Exception.__init__(self, "This coffee machine has to be repaired.")
        
    def repair(self):
        self.number_of_serves = 0
        print('You can order again.')
        
    def serve(self, instance):
        self.number_of_serves += 1
        print('\nOrder ' + str(self.number_of_serves))
        if self.number_of_serves >= 9:
#             raise self.BrokenMachineException()
            if bool(random.randint(0, 1)):
#                 print("It works")
                return instance()
            else: 
#                 print("It doesn't work")
                print(self.EmptyCup())
                raise self.BrokenMachineException()
        else:
            return instance()
        
    
if __name__ == "__main__":
    for i in range(2):
        try:
            machine = CoffeeMachine()

            print(machine.serve(Coffee))
            print(machine.serve(HotBeverage))
            print(machine.serve(Coffee))
            print(machine.serve(Tea))
            print(machine.serve(Tea))
            print(machine.serve(Tea))
            print(machine.serve(Cappuccino))
            print(machine.serve(Coffee))
            print(machine.serve(Tea))
            print(machine.serve(Tea))
            print(machine.serve(Coffee))
        except Exception as e:
            print(e)
            machine.repair()

        

