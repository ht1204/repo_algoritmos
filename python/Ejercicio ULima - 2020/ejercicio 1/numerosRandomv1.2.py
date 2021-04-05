import random

multDict={7:0,11:0,13:0,17:0}

res=[]
for j in range(200):
    res.append(random.randint(100, 1000))

for i in range(len(res)):
    for j in range(1,res[i]+1):
        if(res[i]%j==0):
            multDict[j]=multDict.get(j,0)+1


tupleMultiples=multDict.items()

print('Lista de números')
print(res)

print('___________________')
print('Lista de múltiplos')

for tupleItem in sorted(tupleMultiples):
    print(tupleItem[0],': ',tupleItem[1])


