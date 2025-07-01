% Cargar los datos
datosA = readtable('C:/Users/ricar/Documents/Escom/6to Sem/Señales/Tercer Parcial/hw00.xlsx');
datosB = readtable('C:/Users/ricar/Documents/Escom/6to Sem/Señales/Tercer Parcial/xn00.xlsx');

% Convertir a arrays
a = table2array(datosA);
b = table2array(datosB);

% Aplanar los arrays si es necesario
a = a(:)';
b = b(:)';

% Calcular la convolución
convo = conv(a, b, 'full');

% Crear la gráfica
figure('Position', [100, 100, 1000, 500]);
plot(convo);
title('Convolución de las señales');
xlabel('Índice');
ylabel('Valor de la convolución');
grid_on;