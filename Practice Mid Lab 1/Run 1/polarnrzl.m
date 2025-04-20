function [t,x] = polarnrzl(bits,bitrate)
    T = length(bits)/bitrate; 
    n =30;
    N = length(bits)*n;
    dt = T/N;
    t = 0:dt:T;

    x = [zeros(1,length(t))]
    
    for i=0:length(bits)-1
        if bits(i+1) == 1
        
        end
    end

end