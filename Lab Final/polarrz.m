function [t,x] = polarrz(bits,bitrate)
  T = length(bits)/bitrate; % Total Duration
  display(T);
  n = 30; % No of samples
  N = n*length(bits); % Total Samples
  display(N);
  dt = T/N; % Smallest time interval
  display(dt);
  t = 0:dt:T; % time vector
  display(t);
  x = [zeros(1,length(t))]; % Encoded value
  display(x);
  for i=0:length(bits)-1
        if bits(i+1)==1
            x(i*n+1:i*n+floor(0.5*n)) =1; % For positive value
        else
            x(i*n+1:i*n+floor(0.5*n)) =-1; % For 0 value
        end
  end
  display(x);

end