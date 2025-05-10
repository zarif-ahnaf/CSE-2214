% FSK Modulation
clc; close all; clear all;

% Input bit stream
bit_seq = [1 0 1 1 0 1];

fs = 1000;      % Sampling frequency (Hz)
f1 = 10;        % Carrier frequency for bit 1 (Hz)
f0 = 20;        % Carrier frequency for bit 0 (Hz)

% Time vector for one bit
Tb = 1;                         % Bit duration in seconds
t = 0 : 1/fs : Tb - 1/fs;       % One-bit time axis

% Preallocate FSK signal
fsk_sig = zeros(1, length(bit_seq)*length(t));

% Generate FSK
idx = 1;
for bit = bit_seq
    if bit == 1
        fsk_sig(idx:idx+length(t)-1) = cos(2*pi*f1*t);
    else
        fsk_sig(idx:idx+length(t)-1) = cos(2*pi*f0*t);
    end
    idx = idx + length(t);
end

% Total time vector
t_total = 0 : 1/fs : (length(fsk_sig)-1)/fs;

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
plot(t, cos(2*pi*f1*t), 'b', 'LineWidth',1.5); hold on;
    plot(t, cos(2*pi*f0*t), 'r--', 'LineWidth',1.5); hold off;
    legend(['f_1 = ', num2str(f1), ' Hz'], ['f_0 = ', num2str(f0), ' Hz']);
    title('FSK Carriers for “1” (solid) and “0” (dashed)');
ylabel('Amplitude');
xlabel('Time (s)');

% 3) FSK modulated signal
subplot(3,1,3);
plot(t_total, fsk_sig, 'LineWidth',1.5);
title('FSK Modulated Signal');
ylabel('Amplitude');
xlabel('Time (s)');