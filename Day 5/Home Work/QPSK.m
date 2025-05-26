$
clc;
close all;
clear all;

bit_seq = [0 0 1 0 1 0 1 1 0 0 1 1 1 0 0 1 0 1 1 1 0 1 1 1];
fs = 1000; % Sampling frequency
f = 2;    % Carrier Frequency

% Ensure even number of bits by padding with zero if necessary
if mod(length(bit_seq), 2) ~= 0
    bit_seq = [bit_seq 0];
end

t_symbol = 0:1/fs:1-(1/fs); 

% QPSK Modulation Scheme
symbols = reshape(bit_seq, 2, [])'; 
qpsk_sig = [];

for i = 1:size(symbols,1)
    b1 = symbols(i,1);
    b2 = symbols(i,2);
    % Convert to Gray code
    g1 = b1;
    g2 = xor(b1, b2);
    % Calculate phase
    phase = (2*g1 + g2) * (pi/2) + pi/4;
    % Generate modulated segment
    modulated_segment = cos(2*pi*f*t_symbol + phase);
    qpsk_sig = [qpsk_sig modulated_segment];
end

t_total = 0:1/fs:(length(qpsk_sig)-1)/fs;

full_carrier = cos(2*pi*f*t_total);  

bit_duration = length(t_symbol)/2; 
input_bit_signal = kron(bit_seq, ones(1, bit_duration));
t_input = 0:1/fs:(length(input_bit_signal)-1)/fs;

figure;

subplot(3,1,1);
plot(t_input, input_bit_signal, 'LineWidth', 3);
title("Input Bit Stream");
ylabel("Bit Value");
xlim([0 t_total(end)]);

subplot(3,1,2);
plot(t_total, full_carrier);
title("Full-Length Carrier Signal");
ylabel("Amplitude");
xlim([0 t_total(end)]);

subplot(3,1,3);
plot(t_total, qpsk_sig);
title("Modulated Signal (QPSK)");
ylabel("Amplitude");
xlim([0 t_total(end)]);