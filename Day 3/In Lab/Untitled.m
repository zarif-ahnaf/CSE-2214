% Line coding main function
clear all;
close all;

bits =[1 0 1 0 ];

bitrate = 1;

figure; % show the figure
[t,s] = polarrz(bits,bitrate);
plot(t,s,"lineWidth",3);
xlabel("Time in Sec","fontsize",14,'fontWeight','bold');
ylabel("Amplitude in Volts",'fontsize',14,'fontWeight','bold');
title(['Polar RZ: ' num2str(bits)]);

figure;
[t, s] = unipolarnrz(bits, bitrate);
plot(t, s, 'linewidth', 3);
xlabel('Time in sec', 'fontsize', 14, 'fontweight', 'bold');
ylabel('Amplitude in Volts', 'fontsize', 14, 'fontweight', 'bold');
title(['unipolar NRZ: ' num2str(bits)]); 

figure;
[t, s] = polarnrzi(bits, bitrate);
plot(t, s, 'linewidth', 3);
xlabel('Time in sec', 'fontsize', 14, 'fontweight', 'bold');
ylabel('Amplitude in Volts', 'fontsize', 14, 'fontweight', 'bold');
title(['polar NRZ-I: ' num2str(bits)]); 

figure;
[t, s] = polarnrzl(bits, bitrate);
plot(t, s, 'linewidth', 3);
xlabel('Time in sec', 'fontsize', 14, 'fontweight', 'bold');
ylabel('Amplitude in Volts', 'fontsize', 14, 'fontweight', 'bold');
title(['polar RZI: ' num2str(bits)]);
