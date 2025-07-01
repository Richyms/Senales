% archivo 23 de Noviembre 2023: audioA.wav
clc
clear all
close all
%*****************************************
Fs = 16384;
register = audiorecorder(Fs, 16, 1);
disp('Comenzar');
recordblocking(register, 3);
disp('Finalizar');
%*****************************************
play(register);
s = getaudiodata(register);
plot(s);
audiowrite('audioA.wav',s,Fs);
[s, Fs] = audioread('audioA.wav');