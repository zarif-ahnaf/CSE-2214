function [t, x] = manchester(bits, bitrate, convention)
    % MANCHESTER Generates a Manchester encoded signal
    %   bits - Input binary sequence
    %   bitrate - Transmission bitrate
    %   convention - Encoding convention ('IEEE' or 'JE_THOMAS')
    %   t - Time vector
    %   x - Encoded signal
    
    T = length(bits) / bitrate; % Total duration
    n = 30; % Number of samples per half bit
    N = n * length(bits) * 2; % Total number of samples
    
    dt = T / N;
    t = 0:dt:T;
    x = zeros(1, length(t));
    
    for i = 0:length(bits)-1
        start_idx = i * 2 * n + 1;
        mid_idx = start_idx + n;
        end_idx = (i + 1) * 2 * n;
        
        if strcmp(convention, 'IEEE')
            if bits(i+1) == 0
                x(start_idx:mid_idx) = -1; % First half low
                x(mid_idx+1:end_idx) = 1;  % Second half high
            else
                x(start_idx:mid_idx) = 1;  % First half high
                x(mid_idx+1:end_idx) = -1; % Second half low
            end
        elseif strcmp(convention, 'JE_THOMAS')
            if bits(i+1) == 0
                x(start_idx:mid_idx) = 1;  % First half high
                x(mid_idx+1:end_idx) = -1; % Second half low
            else
                x(start_idx:mid_idx) = -1; % First half low
                x(mid_idx+1:end_idx) = 1;  % Second half high
            end
        else
            error('Invalid convention. Choose either "IEEE" or "JE_THOMAS".');
        end
    end
end
