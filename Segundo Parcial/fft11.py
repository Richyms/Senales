# fft11
# Ejercicio para FFT
#
import numpy as np
import scipy.fftpack as fourier
import pandas as pd
from openpyxl import Workbook
wb = Workbook()
import matplotlib.pyplot as plt


Ts = 0.0078125
Fs=1/Ts


#x1 = pd.read_excel('C:\\Users\\ricar\\Documents\\Escom\\6to Sem\\Señales\\Segundo Parcial\\dato00.xlsx',)
#x2 = np.genfromtxt('C:\\Users\\ricar\\Documents\\Escom\\6to Sem\\Señales\\Segundo Parcial\\dato01.csv',)
x1 = pd.read_excel('C:\\Users\\ricar\\Documents\\Escom\\6to Sem\\Señales\\Segundo Parcial\\Tarea_Correlación\\dato00.xlsx',)
x2 = np.genfromtxt('C:\\Users\\ricar\\Documents\\Escom\\6to Sem\\Señales\\Segundo Parcial\\Tarea_Correlación\\dato00.csv',)
n = Ts*np.arange(0, len(x1))
plt.subplot(2,1,1)
plt.plot(n,x1,'.-')
plt.xlabel('Tiempo (s)', fontsize='14')
plt.ylabel('Amplitud', fontsize='14')
Ns = len(x2)

print(Fs)
print(len(x2))

gk = fourier.fft(x2)
M_gk = abs(gk)

F = Fs*np.arange(0, len(x2))/len(x2)
print(F)

plt.subplot(2,1,2)
plt.plot(F, M_gk)

plt.show()
