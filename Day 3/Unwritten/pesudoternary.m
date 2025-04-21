function [t, x] = pseudoternary(bits, bitrate)
    % PSEUDOTERNARY Generates a pseudoternary encoded signal
    %   bits - Input binary sequence
    %   bitrate - Transmission bitrate
    %   t - Time vector
    %   x - Encoded signal
    
    T = length(bits) / bitrate; % Total duration
    n = 30; % Number of samples per bit
    N = n * length(bits); % Total number of samples
    
    dt = T / N;
    t = 0:dt:T;
    x = zeros(1, length(t));
    
    last_zero_polarity = 1; % Start with positive for the first '0'
    
    for i = 0:length(bits)-1
        start_idx = i * n + 1;
        end_idx = (i + 1) * n;
        
        if bits(i+1) == 0
            x(start_idx:end_idx) = last_zero_polarity;
            last_zero_polarity = -last_zero_polarity; % Toggle polarity
        else
            x(start_idx:end_idx) = 0; % One is represented by zero voltage
        end
    end
end
