#Crea string a lista donde cada letra es un item.
def convertToList(word):
    letterList=[]
    letterList[:0]=word
    return letterList
##end of function##

def factorial(number):
    if(number == 0 or number == 1):
        return 1
    
    if(number > 1):
        return number * factorial(number - 1)
##end of function##

def main():
    word="parangaricutirimicuaro"
    lettersList=convertToList(word)
    print("Letras de palabra: ", lettersList)
    print()
    letterSet=set(sorted(lettersList)) #se crea el conjunto.
    print("Conjunto de letras: ",letterSet)
    print()
    print("Longitud de conjunto: ", len(letterSet))
    setLength=len(letterSet)
    subsetSize=5 
    totalSubsets=factorial(setLength)//(factorial(setLength-subsetSize)*factorial(subsetSize)) #División entera
    print("Total subconjuntos posibles con tamaño ",subsetSize, ": ", totalSubsets)
    


main()
