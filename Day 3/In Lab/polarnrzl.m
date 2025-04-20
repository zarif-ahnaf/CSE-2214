function [t,x] = polarnrzl(bits,bitrate)
    T = length(bits)/bitrate;
    display(T);
    n =30;
    N=n*length(bits);
    display(N);

    dt = T/N;
    display(dt);

    t = 0:dt:T;
    display(t)
    x = [zeros(1,length(t))];
    display(x);

    for i=0:length(bits)-1
        if bits(i+1) == 1
            x(i*n+1:(i+1)*n)=-1;
        else
            x(i*n+1:(i+1)*n)=+1;
        end
    end
    display(x);

end