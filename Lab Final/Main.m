clc;
clear all;
close all;

bits =[1 0 1 0 ];

bitrate = 1;

figure;
[t,s] = polarrz(bits,bitrate);
plot(t,s,"lineWidth",3);
xlabel("Time in Sec","fontsize",16,'fontWeight','bold');
ylabel("Amplitude in Volts",'fontsize',16,'fontWeight','bold');
title(['Polar RZ: ' num2str(bits)]);

