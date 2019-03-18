file = open("file.txt", "r")
verse = 0
while verse != -1:
    verse = input("Żeby zakończyć zatwierdź -1. Wiersz: ")
    if(int(verse) == -1):
        break
    letter = input("Litera: ")
    file = open("file.txt", "r")
    for i in range(int(verse)):
        verseString = file.readline()
    file.close()
    print(verseString)
    letterString = verseString[int(letter)-1]
    print(letterString)