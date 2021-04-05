file = open('palabraLista.txt', 'r', encoding="utf8")
wordList = []

for line in file:
  stripped_line = line.strip()
  line_list = stripped_line.split()
  wordList.append(line_list)


wordFlatList = []
for sublist in wordList:
    for item in sublist:
        wordFlatList.append(item)

wordFinalList=sorted(wordFlatList, key=str.lower)

for wordItem in wordFinalList:
    print(wordItem+":")
