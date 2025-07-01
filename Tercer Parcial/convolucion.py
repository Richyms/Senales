import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

datosA = pd.read_csv('hw00.csv')
datosB = pd.read_csv('xn00.csv')

a = np.array(datosA.iloc[:, 0])
b = np.array(datosB.iloc[:, 0])

conv00 = np.convolve(a, b)

plt.plot(conv00)
plt.title("Convolución de A y B")
plt.xlabel("Índice")
plt.ylabel("Valor")
plt.grid(True)
plt.show()