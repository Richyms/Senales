clc
clear all
close all
%***************
Fs = 16384;
register = audiorecorder(Fs, 16, 1);
disp('Comenzar');
recordblocking(register, 1);
disp('Finalizar');
%***************
play(register);
s = getaudiodata(register);
plot(s);
audiowrite('martes.wav',s,Fs);
[s, Fs] = audioread('martes.wav');

% Calcular la Transformada de Fourier
N = length(s); % Longitud de la señal
Y = fft(s);    % Transformada de Fourier

% Calcular el vector de frecuencias correspondiente
f = (0:N-1)*(Fs/N); % Vector de frecuencias

figure;
plot(f, abs(Y));
title('Transformada de Fourier');
xlabel('Frecuencia (Hz)');
ylabel('Magnitud');

figure;
spectrogram(s, 256, 250, [], Fs, 'y-axis');
title('Señal');