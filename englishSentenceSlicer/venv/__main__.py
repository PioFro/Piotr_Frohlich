import random
import os
def slice(inSentence):
    inSentence = inSentence.replace(".", "")
    outSentence = inSentence.split()
    random.shuffle(outSentence)
    return outSentence

def toFile(inSentence, fileHandle):
    fileHandle.truncate()
    for word in inSentence:
        fileHandle.write(word+" / ")
    fileHandle.write("\n______________________________________________________________________________________________\n")


myPlace = os.path.dirname(os.path.realpath(__file__))+os.sep
prepSentence = []

file = open(myPlace+'output.txt', 'w')

st = input("Enter sentence or provide file (name.txt) with sentences ")
isFile = False

if(st.__contains__(".txt")):
    inFile = open(myPlace+st, 'r')
    isFile = True
    print("FILE SELECTED "+st)

if isFile:
    for line in inFile:
        prepSentence.append(slice(line))

else:
    prepSentence = slice(st)
if isFile:
    for line in prepSentence:
        toFile(line, file)
else:
    toFile(prepSentence, file)




