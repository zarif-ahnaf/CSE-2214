clc;
close all;
clear all;

% Input bit Stream
bit_seq = [1 0 1 1 0 1];
fs = 1000; % Sampling frequency
f = 10; % Carrier Frequency

% TIme vector for One bit
t = 0:1/fs:1-(1/fs);

% Take carrier Signal
carrier = cos(2*pi*f*t);

% ASK Modulation Scheme
ask_sig = [];

for bit = bit_seq
    if bit == 1
        ask_sig = [ask_sig carrier];
    else
        ask_sig = [ask_sig zeros(1,length(t))];
    end
end

% Time Vector for Total Signal
t_total =  0:1/fs:(length(ask_sig)-1)/fs;

figure;
% Draw input bit stream;
subplot(3,1,1);

% plot(repelem(bit_seq,length(t)),'linewidth', 3);
plot(t_total, kron(bit_seq, ones(1, length(t))), 'LineWidth', 3);
title("Input Bit");
ylabel("Bit Value");


subplot(3,1,2);
plot(t,carrier);
title("Carrier Signal");
ylabel("Amplitude");


subplot(3,1,3);
plot(t_total,ask_sig);
title("Modulated signal");
ylabel("Amplitude");