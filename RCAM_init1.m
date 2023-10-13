
t_sim  = 480;

% Initial states
Xe0    = [0 0 -1000]'; % xe ye ze      [m]
Vb0    = [85 0 0]';    % u v w         [m/s]
euler0 = [0 6 0]';     % phi theta psi [deg]
pqr0   = [0 0 0]';     % p q r         [deg/s]

% Initial control inputs
u0 = [0;     % Aileron deflection    [deg]
     -11.75; % Stabilizer deflection [deg]
      0;     % Rudder deflection     [deg]
      4.5;   % Throttle - engine 1   [deg]
      4.5];  % Throttle - engine 2   [deg]

euler0 = deg2rad(euler0);
pqr0   = deg2rad(pqr0);
u0     = deg2rad(u0);

