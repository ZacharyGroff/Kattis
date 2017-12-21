n = int(input())
wins = 0
for _ in range(n):
    #avoid going out of range in a lazy way
    abilities = input().upper() + 'E'
    won = True
    for i in range(len(abilities)):
        if(abilities[i] == 'C' and abilities[i+1] == 'D'):
            won = False
    if (won == True):
        wins += 1

print(wins)
        
