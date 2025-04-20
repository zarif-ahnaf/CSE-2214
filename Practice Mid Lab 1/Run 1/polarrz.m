function [t,x] = polarrz(bits,bitrate)
    T = length(bits)/bitrate
    n = 30
    N = n*length(bits);
    
    dt = T/N;
    t = 0:dt:T;
    x = [zeros(1,length(t))]
    
    for i=0:length(bits)-1
        if bits(i+1) == 1
            x(i*n+1:i*n+floor(0.5*n))=1;
        else
            x(i*n+1:i*n+floor(0.5*n))=-1;
        end
    end
end