studentDictionary={
                    '1': [2.8,2.5,3,4],
                    '2': [2.7,5,3.5]
                }

for key in studentDictionary:
    for items in studentDictionary[key]:
        for i in range(len(studentDictionary[key])-1):
            for j in range(0,len(studentDictionary[key])-i-1):
                if studentDictionary[key][j] < studentDictionary[key][j+1] :
                    studentDictionary[key][j], studentDictionary[key][j+1] = studentDictionary[key][j+1], studentDictionary[key][j]
                


for key, value in studentDictionary.items() :
    print (key, value)
    
        


