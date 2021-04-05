def upDownCountWhile():
  oneToEnd = 1
  endToOne=100

  while(oneToEnd <= 100 and endToOne >=1):
    print("\n\t Count Up : ",oneToEnd," | ",
    " Count Down : ",endToOne)

    oneToEnd += 1
    endToOne -= 1


def upDownCount():

  for oneToEnd, endToOne in zip(range(1, 101), range(100, 0, -1)):
    print("\n\t Count Up : ",oneToEnd," | ",
    " Count Down : ",endToOne)


### Function Main #####
def main():
  upDownCount()
  print("\n\n\t")
  upDownCountWhile()
  print("\n\n\t")

############# End of function ##################

###Execute Function main ######
if __name__ == '__main__':
  main()