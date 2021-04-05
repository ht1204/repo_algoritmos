import random

multDict={7:0,11:0,17:0,13:0,17:0}

res=[]
for j in range(200):
    res.append(random.randint(100, 1000))

j=1
for i in range(len(res)):
    while(j<res[i]):
        if(res[i]%j==0):
            if j not in multDict.keys():
                multDict.update({j:1})   
            else:
                for key, value in multDict.items():
                    if(key==j):
                        multDict[key]+=1

        j+=1
    j=1


print(multDict)


