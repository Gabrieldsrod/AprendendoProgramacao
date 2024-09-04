#Btw sorry for bad english im Brazilian 🇧🇷
import random

#Chose the players
top1 = str(input("Player 1: "))
top2 = str(input("Player 2: "))
jg1 = str(input("Player 3: "))
jg2 = str(input("Player 4: "))
mid1 = str(input("Player 5: "))
mid2 = str(input("Player 6: "))
adc1 = str(input("Player 7: "))
adc2 = str(input("Player 8: "))
sup1 = str(input("Player 9: "))
sup2 = str(input("Player 10: "))

#The players you has chosen ill be randomized in two teams, Top = Top laner, Jg = Jungler, Mid = Mid Laner, Adc = Ad Carry, Sup = Support.
#The roles in a MOBA game. 
#1-2 is the first and second team. 
#Time = Team
times = [top1, top2, jg1, jg2, mid1, mid2, adc1, adc2, sup1, sup2]
random.shuffle(times)
time1, time2 = times[:5], times[5:]

#Print the two teams.
print("O primeiro time é {}".format(time1))  #The first team is {}
print("O segundo time é {}".format(time2))   #The second team is {}
#👊🏿
