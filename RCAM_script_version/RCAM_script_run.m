clc
clear
% close all

%% Initial Conditions

% Initial states
x0 = [85;    % u
      0;     % v
      0;     % w
      0;     % p (roll rate)
      0;     % q (pitch rate)
      0;     % r (yaw rate)
      0;     % phi (bank)
      0.1;   % theta (pitch)
      0;];   % psi (heading)

% Initial control inputs
u0 = [0;     % Aileron deflection
     -0.1;   % Stabilizer deflection
      0;     % Rudder deflection
      0.08;  % Throttle - engine 1
      0.08]; % Throttle - engine 2

%% Simulation Duration

TF = 300;

%% Run Model

res=sim('RCAM_script_sim.slx');

%% Plot Results
t=res.tout;

u_res=res.simU.Data;
x_res=res.simX.Data;

figure('Name','Control History')
for i=1:5
    subplot(5,1,i)
    plot(t,u_res(:,i))
    legend('u'+string(i))
    grid on
end

figure('Name','State History')
for i=1:9
    subplot(3,3,i)
    plot(t,x_res(:,i))
    legend('x'+string(i))
    grid on
end

