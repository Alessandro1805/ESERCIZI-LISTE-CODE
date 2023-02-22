import random
class Node():
    def __init__(self,key):
        self.key=key
        self.left=None;
        self.right=None;
    def insert(self,key):
        pass
    def insertnode(self,key):
        if self.key:
            if key > self.key:
                if self.right is None:
                    self.right=Node(key)
                else:
                    self.right.insertnode(key)
            elif key< self.key:
                if self.left is None:
                    self.left=Node(key)
                else:
                    self.left.insertnode(key)
    def printree(self,level=0):
        if self.left is not None:
            self.left.printree (level+1)
        print(f"level{level} ->{self.key}")
        if self.right is not None:
            self.right.printree(level+1)
    def findnode(self,pkey):
        if pkey==self.key:
            return True
        else:
            if pkey>self.key:
                if self.right is not None:
                    self.right.findnode(pkey)
                else:
                    return False
            else:
                if self.left is not None:
                    self.left.findnode(pkey)   
                else:
                    return False   
def main():
    root=Node(45)
    lista_key=list(range(0,40,5))
    random.shuffle(lista_key)
    print(lista_key)
    
    albero = Node(lista_key[0])
    for key in lista_key[1:]:
        albero.insertnode(key)
    albero.printree()
    trovato=albero.findnode(lista_key[1])
    print(trovato)
    if trovato:
        print("trovato")
    else:
        print("non trovato")
if __name__=="__main__":
    main()