% BPSK Modulation
clc; close all; clear all;

% Input bit stream
bit_seq = [1 0 1 1 0 1];

fs = 1000;      % Sampling frequency (Hz)
fc = 10;        % Carrier frequency (Hz)

% Time vector for one bit
Tb = 1;                         % Bit duration in seconds
t = 0 : 1/fs : Tb - 1/fs;       % One-bit time axis

% Preallocate BPSK signal
bpsk_sig = zeros(1, length(bit_seq)*length(t));

% Generate BPSK
idx = 1;
for bit = bit_seq
    if bit == 1
        carrier = cos(2*pi*fc*t);
    else
        carrier = -cos(2*pi*fc*t);
    end
    bpsk_sig(idx:idx+length(t)-1) = carrier;
    idx = idx + length(t);
end

% Total time vector
t_total = 0 : 1/fs : (length(bpsk_sig)-1)/fs;

% Plotting
figure;

% 1) Input bit stream
subplot(3,1,1);
plot(t_total, kron(bit_seq, ones(1,length(t))), 'LineWidth',2);
ylim([-0.2 1.2]);
title('Input Bit Stream');
ylabel('Bit Value');
xlabel('Time (s)');

% 2) Example carriers
subplot(3,1,2);
plot(t, cos(2*pi*fc*t), 'b', 'LineWidth',1.5); hold on;
plot(t, -cos(2*pi*fc*t), 'r--', 'LineWidth',1.5); hold off;
legend('Bit=1: 10 Hz', 'Bit=0: -10 Hz', 'Location', 'best');
title('BPSK Carriers for “1” (solid) and “0” (dashed)');
ylabel('Amplitude');
xlabel('Time (s)');

% 3) BPSK modulated signal
subplot(3,1,3);
plot(t_total, bpsk_sig, 'LineWidth',1.5);
title('BPSK Modulated Signal');
ylabel('Amplitude');
xlabel('Time (s)');