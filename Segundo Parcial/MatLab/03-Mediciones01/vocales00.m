% archivo 02 de Abril 2025: audioA.wav
clc
clear all
close all
%*****************************************
Fs = 16384;
register = audiorecorder(Fs, 16, 1);
disp('Comenzar');
recordblocking(register, 1);
disp('Finalizar');
%*****************************************
play(register);
s = getaudiodata(register);
plot(s);
audiowrite('audioA.wav',s,Fs);
[s, Fs] = audioread('audioA.wav');