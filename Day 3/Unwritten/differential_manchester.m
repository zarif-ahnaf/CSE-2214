function [t, x] = differential_manchester(bits, bitrate)
    % DIFFERENTIAL_MANCHESTER Generates a Differential Manchester encoded signal
    %   bits - Input binary sequence
    %   bitrate - Transmission bitrate
    %   t - Time vector
    %   x - Encoded signal

    T = length(bits) / bitrate; % Total duration
    n = 30; % Number of samples per half bit
    N = n * length(bits) * 2; % Total number of samples

    dt = T / N;
    t = 0:dt:T;
    x = zeros(1, length(t));

    % Initial level: assume starting with high (1)
    current_level = 1;

    for i = 0:length(bits)-1
        start_idx = i * 2 * n + 1;
        mid_idx = start_idx + n;
        end_idx = (i + 1) * 2 * n;

        if bits(i+1) == 0
            % Transition at the beginning
            current_level = -current_level;
        end

        % Mid-bit transition (always)
        x(start_idx:mid_idx) = current_level;
        current_level = -current_level;
        x(mid_idx+1:end_idx) = current_level;
    end
end
