import requests
from bs4 import	BeautifulSoup

nick = str(input('Qual nick deseja checar? '))
print('''
BR
KR
TR
OCE
LAS
EUNE
EUW
NA
LAN
''')
region = str(input('De qual região quer ver? '))
nickchecker = requests.get('https://lols.gg/pt/name/checker/'+ region +'/'+ nick + '/')
a = nickchecker.content
site = BeautifulSoup(a, 'html.parser')
b = site.find(attrs={'class':'text-center'})
b1 = str(b)
n = b1
e = n.replace('<h4 class="text-center">', '')
c = e.replace('</h4>', '')
d = c.replace('None','https://cdn.discordapp.com/attachments/816686443044143116/897868354822471731/unknown.png')
f = d.replace('<h2 class="text-center">', '')
g = f.replace('</h2>', '')
print(g)
