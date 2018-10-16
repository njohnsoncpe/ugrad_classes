
%constants
alpha = 26.66;
beta = 133.33;
alpha_p = 32.7345;
f = 2;
K = f*(alpha_p.^2)/(4*beta);
Kf = alpha_p/2;

sim('Lab_2_sim');

subplot(211)
plot(Y(:,1), Y(:,2)); grid
title('Plant Output')
xlabel('Time (sec.)')
ylabel('Motor Output (Volts)')

subplot(212)
plot(U(:,1), U(:,2)); grid
title('Plant Input')
xlabel('Time (sec.)')
ylabel('Motor Input (Volts)')

ind = find(Y(:,2)<=2.97);
max_input = max(U(:,2))
Ts=Y(max(ind),1)