close all;
clear all;

bits = [];
bitrate = 1;

[t,s] = polarrz(bits,bitrate);

plot(t,s,"lineWidth",3);
xLabel("Time in Seconds","fontSize",14,"fontWeight","bold");
xLabel("Amplitude in Volts","fontSize",14,"fontWeight","bold");
