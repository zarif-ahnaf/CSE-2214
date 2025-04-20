function [t,x] = polarnrzi(bits,bitrate)
    T = length(bits)/bitrate
    n =30;
    N =length(bits)*n;

    dt = T/N;

    t  = 0:dt:T; 
    x = [zeros(1,length(t))]
    last_level = 1;
    for i=0:length(bits)-1
        if bits(i+1) == 1
            x(i*n+1:(i+1)*n) = -last_level;
            last_level = -last_level;
        else
            x(i*n+1:(i+1)*n) = last_level;
    end
end