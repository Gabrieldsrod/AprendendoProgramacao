import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Dados fornecidos
tempo = np.array([0.175842, 0.310802, 0.426998, 0.528348])
distancia = np.array([150.9, 301.2, 451.0, 603.0])

# Função para ajuste linear
def func_linear(t, a, b):
    return a * t + b

# Ajuste dos dados para obter os coeficientes da função
popt, pcov = curve_fit(func_linear, tempo, distancia)

# Coeficientes do ajuste
a, b = popt

# Plotagem dos dados e da função ajustada
plt.scatter(tempo, distancia, label='Dados')
plt.plot(tempo, func_linear(tempo, a, b), color='red', label='Ajuste Linear')

# Configurações do gráfico
plt.xlabel('Tempo')
plt.ylabel('Distância')
plt.title('Gráfico da Distância em Função do Tempo')
plt.legend()

# Mostrar o gráfico
plt.show()

# A velocidade do objeto é o coeficiente 'a' da função ajustada
velocidade = a
print("A velocidade do objeto é:", velocidade)