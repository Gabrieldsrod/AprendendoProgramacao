import discord
from discord.ext import commands
import requests
from bs4 import BeautifulSoup
from riotwatcher import LolWatcher
from discord_components import DiscordComponents, Button, ButtonStyle

client = commands.Bot(command_prefix="$", if_insensitive=True)

@client.event
async def on_ready():
    print('Começando...')

@client.command()
async def wa(ctx):
    await ctx.send('Pare de rodar.')

@client.command()
async def ma(ctx):
    await ctx.send('Pare de rodar.')

@client.command()
async def ha(ctx):
    await ctx.send('Pare de rodar.')

@client.command(if_insensitive=True)
async def nick(ctx, nick, region='br'):
    headers = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36"}
    nickchecker = requests.get('https://lols.gg/pt/name/checker/'+ region +'/'+ nick + '/', headers=headers)
    a = nickchecker.content
    site = BeautifulSoup(a, 'html.parser')
    dias = site.find_all("h4", attrs={"class":"text-center"})
    erro = site.find_all("div", attrs={"class":"card-footer"})
    d1 = str(dias)
    f = d1.replace('<h2 class="text-center">', '')
    g = f.replace('</h2>', '')
    j = g.replace('<h4 class="text-center">', '')
    l = j.replace('</h4>','')
    ç = l.replace('[]', 'https://cdn.discordapp.com/attachments/816686443044143116/897868354822471731/unknown.png')
    p = ç.replace(']','')
    h = p.replace('[','')
    message = h
    await ctx.send(message)

@client.command(if_insensitive=True)
async def message(ctx, *, user:discord.Member):
    message = 'pf me salva sou um anão indiano escravizado👳🏾‍♂️🙏🏾'
    embed = discord.Embed(title=message)
    await user.send(embed=embed)

@client.command(if_insensitive=True)
async def dm(ctx, user:discord.Member, nick, region):
    api_key = 'RGAPI-8c7dfd71-50ca-454c-87c8-5bc15b86f067'
    watcher = LolWatcher(api_key)
    me = watcher.summoner.by_name(region, nick)
    status = watcher.league.by_summoner(region, me['id'])
    status1 = str(status)
    a = status1.replace("leagueId", "League Id")
    b = a.replace("queueType", "Fila")
    c = b.replace("tier", "Liga")
    d = c.replace("RANKED_FLEX_SR", "Ranqueada Flexível")
    e = d.replace("rank", "Divisão")
    f = e.replace("summonerId", "Id de invocador")
    g = f.replace("summonerName", "Nick")
    h = g.replace("leaguePoints", "PDLS")
    i = h.replace("wins", "Vitórias")
    j = i.replace("losses", "Derrotas")
    k = j.replace('[{', '')
    l = k.replace('}]', '')
    m = l.replace("veteran", "veterano")
    n = m.replace("inactive", "inativo")
    o = n.replace("summonerId", "Id de Invocador")
    p = o.replace("hotStreak", "Sequência de Vitórias")
    q = p.replace("RANKED_SOLO_5x5", "Ranqueada Solo/Duo")
    r = q.replace("'", '')
    s = r.replace("{", '')
    t = s.replace("}", '')
    print(status)

    d2 = status[0]['tier']
    d1 = d2.replace('GRANDMASTER', 'Grão Mestre')
    d3 = d1.replace('MASTER', 'Mestre')
    d4 = d3.replace('CHALLENGER', 'Desafiante')
    d5 = d4.replace('GOLD', 'Ouro')
    d6 = d5.replace('SILVER','Prata')
    d7 = d6.replace('BRONZE', 'Bronze')
    d8 = d7.replace('IRON', 'Ferro')
    d9 = d8.replace('PLATINUM', 'Platina')
    d10 = d9.replace('DIAMOND', 'Diamante')

    Wsolo = int(status[0]['wins'])
    Lsolo = int(status[0]['losses'])

    wrsolo = int((Wsolo / (Wsolo + Lsolo))*100)
    
    embed = discord.Embed(title="Conta buscada com êxito!", color=discord.Color.from_rgb(254, 131, 33))
    embed.set_image(url="https://lol-skin.weblog.vc/img/wallpaper/tiles/Kassadin_5.jpg?1642588647")
    embed.set_author(name="@Rifuzada", icon_url="https://cdn.discordapp.com/attachments/778980015756935199/937495913377710160/unknown.png")
    embed.add_field(name="Nick",value=status[0]['summonerName'],inline=False)
    embed.add_field(name="Elo", value=d10,inline=False) 
    embed.add_field(name="Vitórias",value=status[0]['wins'])
    embed.add_field(name="Winrate",value=(f'{wrsolo}%'))
    embed.add_field(name="Derrotas", value=status[0]['losses'])
    if status[0]['tier'] == 'MASTER' or 'GRANDMASTER' or 'CHALLENGER':
        embed.add_field(name="Pdl",value=status[0]['leaguePoints'],inline=False)
    else:
        embed.add_field(name="Divisão", value=status[0]['rank'],inline=False)
        embed.add_field(name="Pdl",value=status[0]['leaguePoints'],inline=False)
    Twitter =  Button(style=ButtonStyle.URL, label="Twitter🐦", url="https://twitter.com/rifuzada")

    await user.send(embed=embed, 
        components=[[Twitter]], 
        )

    buttons={"embed":embed}

        
    

client.run('ODg0MjU4NjgxMTU4NTMzMTYw.YTV4Eg.-S1f0BPd1ycnTdTHu6yrlHqpU_I')
