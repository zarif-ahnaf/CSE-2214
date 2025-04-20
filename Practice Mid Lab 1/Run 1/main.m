% Line coding main function
clear all;
close all;

bits =[1 0 1 0 ];

bitrate = 1;

figure; % show the figure
[t,s] = unipolarrz(bits,bitrate);
plot(t,s,"lineWidth",3);
xlabel("Time in Sec","fontsize",14,'fontWeight','bold');
ylabel("Amplitude in Volts",'fontsize',14,'fontWeight','bold');
title(['Unipolar NRZ: ' num2str(bits)]);
