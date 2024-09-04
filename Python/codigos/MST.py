import requests
from tkinter import *

nick = 'Rifu'#Put the nickname you wanna check
region = 'br1'#The region of the summoner, br1,na1,kr1,tr1,euw1, etc.
apikey = 'RGAPI-82b5a0f8-c40b-48c2-9067-bfa55893ad0b'#your apikey
ids = requests.get(f'https://'+region+'.api.riotgames.com/lol/summoner/v4/summoners/by-name/'+ nick +'?api_key='+apikey)
pf2 = ids.json()
summonerid = pf2['id']#Summonerid u want saw the masteries
mastery = requests.get(f'https://{region}.api.riotgames.com/lol/champion-mastery/v4/champion-masteries/by-summoner/{summonerid}?api_key={apikey}')
top_5 = mastery.json()
ids = requests.get(f'https://{region}.api.riotgames.com/lol/summoner/v4/summoners/{summonerid}?api_key={apikey}')
pf = ids.json()
pf1 = str(pf)


def get_champions_name(_id):
    all_champion_id = {
    1: 'Annie',
    2: 'Olaf',
    3: 'Galio',
    4: 'Twisted Fate',
    5: 'Xin Zhao',
    6: 'Urgot',
    7: 'Le Blanc',
    8: 'Vladimir',
    9: 'Fiddlesticks',
    10: 'Kayle',
    11: 'Master Yi',
    12: 'Alistar',
    13: 'Ryze',
    14: 'Sion',
    15: 'Sivir',
    16: 'Soraka',
    17: 'Teemo',
    18: 'Tristana',
    19: 'Warwick',
    20: 'Nunu & Willump',
    21: 'Miss Fortune',
    22: 'Ashe',
    23: 'Tryndamere',
    24: 'Jax',
    25: 'Morgana',
    26: 'Zilean',
    27: 'Singed',
    28: 'Evelynn',
    29: 'Twitch',
    30: 'Karthus',
    31: "Cho' Gath",
    32: 'Amumu',
    33: 'Rammus',
    34: 'Anivia',
    35: 'Shaco',
    36: 'Dr.Mundo',
    37: 'Sona',
    38: 'Kassadin',
    39: 'Irelia',
    40: 'Janna',
    41: 'Gangplank',
    42: 'Corki',
    43: 'Karma',
    44: 'Taric',
    45: 'Veigar',
    48: 'Trundle',
    50: 'Swain',
    51: 'Caitlyn',
    53: 'Blitzcrank',
    54: 'Malphite',
    55: 'Katarina',
    56: 'Nocturne',
    57: 'Maokai',
    58: 'Renekton',
    59: 'Jarvan IV',
    60: 'Elise',
    61: 'Orianna',
    62: 'Wukong',
    63: 'Brand',
    64: 'Lee Sin',
    67: 'Vayne',
    68: 'Rumble',
    69: 'Cassiopeia',
    72: 'Skarner',
    74: 'Heimerdinger',
    75: 'Nasus',
    76: 'Nidalee',
    77: 'Udyr',
    78: 'Poppy',
    79: 'Gragas',
    80: 'Pantheon',
    81: 'Ezreal',
    82: 'Mordekaiser',
    83: 'Yorick',
    84: 'Akali',
    85: 'Kennen',
    86: 'Garen',
    89: 'Leona',
    90: 'Malzahar',
    91: 'Talon',
    92: 'Riven',
    96: "Kog' Maw",
    98: 'Shen',
    99: 'Lux',
    101: 'Xerath',
    102: 'Shyvana',
    103: 'Ahri',
    104: 'Graves',
    105: 'Fizz',
    106: 'Volibear',
    107: 'Rengar',
    110: 'Varus',
    111: 'Nautilus',
    112: 'Viktor',
    113: 'Sejuani',
    114: 'Fiora',
    115: 'Ziggs',
    117: 'Lulu',
    119: 'Draven',
    120: 'Hecarim',
    121: "Kha' Zix",
    122: 'Darius',
    126: 'Jayce',
    127: 'Lissandra',
    131: 'Diana',
    133: 'Quinn',
    134: 'Syndra',
    136: 'Aurelion Sol',
    141: 'Kayn',
    142: 'Zoe',
    143: 'Zyra',
    145: "Kai' sa",
    147: "Seraphine",
    150: 'Gnar',
    154: 'Zac',
    157: 'Yasuo',
    161: "Vel' Koz",
    163: 'Taliyah',
    166: "Akshan",
    164: 'Camille',
    201: 'Braum',
    202: 'Jhin',
    203: 'Kindred',
    222: 'Jinx',
    223: 'TahmKench',
    234: 'Viego',
    235: 'Senna',
    236: 'Lucian',
    238: 'Zed',
    240: 'Kled',
    245: 'Ekko',
    246: 'Qiyana',
    254: 'Vi',
    266: 'Aatrox',
    267: 'Nami',
    268: 'Azir',
    350: 'Yuumi',
    360: 'Samira',
    412: 'Thresh',
    420: 'Illaoi',
    421: "Rek'Sai",
    427: 'Ivern',
    429: 'Kalista',
    432: 'Bard',
    497: 'Rakan',
    498: 'Xayah',
    516: 'Ornn',
    517: 'Sylas',
    526: 'Rell',
    518: 'Neeko',
    523: 'Aphelios',
    555: 'Pyke',
    875: "Sett",
    777: "Yone",
    887: "Gwen",
    876: "Lillia",


    }
    return all_champion_id.get(_id)


def pegar_maestrias():
        champion_id = top_5[0]['championId']
        Maestria1 = top_5[0]['championLevel']
        Pontos1 = top_5[0]['championPoints']
        Bau1 = top_5[0]['chestGranted']
        Maestria2 = top_5[1]['championLevel']
        Champion2 = top_5[1]['championId']
        Bau2 = top_5[1]['chestGranted']
        Pontos2 = top_5[1]['championPoints']
        Champion3 = top_5[2]['championId']
        Bau3 = top_5[2]['chestGranted']
        Pontos3 = top_5[2]['championPoints']
        Maestria3 = top_5[2]['championLevel']
        if 1 <= int(champion_id) <= 887:
            Bauz = str(Bau1)
            a = Bauz.replace("True", "Sim")
            c = a.replace("False", "Não")
            Baus = str(Bau2)
            b = Baus.replace("False", "Não")
            d = b.replace("True", "Sim")
            Bau = str(Bau3)
            e = Bau.replace("False", "Não")
            f = e.replace("True", "Sim")
        for name in pf.get('name'):
            text1 = 'O perfil pesquisado foi: ' + pf['name'] +'\n'
            text2 ="A Sua maior maestria é com o champion: {}\n".format(get_champions_name(int(champion_id)))
            text3 = "Sua maestria é de nível {}.\nCom {} pontos de maestria.\nJá ganhou baú com este champion? {}\n".format(Maestria1, Pontos1, c)
            text4 = "Sua Segunda maior maestria é com o champion: {}\n".format(get_champions_name(int(Champion2)))
            text5 = "Sua maestria é de nível {}.\nCom {} pontos de maestria.\nJá ganhou baú com este champion? {}\n".format(Maestria2, Pontos2, d)
            text6 = "Sua Segunda maior maestria é com o champion: {}\n".format(get_champions_name(int(Champion3)))
            text7 = "Sua maestira é de nível {}\nCom {} pontos de maestria.\nJá ganhou baú com este champion? {}\n".format(Maestria3, Pontos3, f)
            texto_maestrias['text'] = text1, text2, text3, text4, text5, text6, text7
            texto_orientacao['text'] = text1




region1 = str(region)
a = region1.replace('br1', 'BR')
b = a.replace('kr', 'KR')
c = b.replace('tr1','TR')
d = c.replace('OC1','OCE')
e = d.replace('LA2','LAS')
f = e.replace('EUN1','EUNE')
g = f.replace('EUW1','EUW')
h = g.replace('NA1','NA')
i = h.replace('LA1','LAN')
l = i.replace('Br1', 'BR')


janela = Tk()
janela.title("Mastery Search Tool - MST, @Rifuzada")#Masteries
janela.geometry("350x380")
janela.configure(background="black")


texto_orientacao = Label(janela, text="Clique no botão abaixo para exibir as maestrias de "+ pf['name'], font=('Arial', 10), background='black', fg='#00FF00') #Click down in the button to view the masters of
texto_orientacao.grid(column=1, row=4)

regiao = Label(janela, text="A Região selecionada é {0}".format(l), background='black', fg='#00FF00')#The selected Region is 
regiao.grid(column=1,row=5)

botao = Button(janela, text="Buscar Maestrias", command=pegar_maestrias,background='#002', foreground='#f0f8ff', relief=RAISED, bd=5,padx=10,pady=10)#Search Masteries
botao.grid(column=1, row=6)
info = Label(janela, text="by @Rifuzada",background='black', fg='yellow')#Maded by @Rifuzada
info.grid(column=1, row=25)

texto_maestrias = Label(janela, text='', background='black', fg='#00FF00')
texto_maestrias.grid(column=1, row=7)


janela.mainloop()
