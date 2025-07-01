import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

datosA = pd.read_csv('C:/Users/ricar/Documents/Escom/6to Sem/Señales/Tercer Parcial/664/hw00.csv')
datosB = pd.read_csv('C:/Users/ricar/Documents/Escom/6to Sem/Señales/Tercer Parcial/664/xn00.csv')

a = np.array(datosA.iloc[:, 0])
b = np.array(datosB.iloc[:, 0])

conv00 = np.convolve(a, b)

plt.plot(conv00)
plt.title("Convolución de A y B (664)")
plt.xlabel("Índice")
plt.ylabel("Valor")
plt.grid(True)
plt.show()