% Line coding main function
clear all;
close all;

bits =[1 0 1 0 0 1 1 1 0 0 1 ];

bitrate = 1;

figure; % show the figure
[t,s] = manchester(bits,bitrate,"JE_THOMAS");
plot(t,s,"lineWidth",3);
xlabel("Time in Sec","fontsize",14,'fontWeight','bold');
ylabel("Amplitude in Volts",'fontsize',14,'fontWeight','bold');
title(['Manchester JE Thomas: ' num2str(bits)]);

figure; % show the figure
[t,s] = manchester(bits,bitrate,"IEEE");
plot(t,s,"lineWidth",3);
xlabel("Time in Sec","fontsize",14,'fontWeight','bold');
ylabel("Amplitude in Volts",'fontsize',14,'fontWeight','bold');
title(['Manchester IEEE: ' num2str(bits)]);





figure; % show the figure
[t,s] = ami(bits,bitrate);
plot(t,s,"lineWidth",3);
xlabel("Time in Sec","fontsize",14,'fontWeight','bold');
ylabel("Amplitude in Volts",'fontsize',14,'fontWeight','bold');
title(['AMI: ' num2str(bits)]);