
%% Control Limits/Saturation

% Max/min deflections
umin(1) = -25; % Min aileron deflection          [deg]
umax(1) = 25;  % Max aileron deflection          [deg]
umin(2) = -25; % Min stabilizer deflection       [deg]
umax(2) = 10;  % Max stabilizer deflection       [deg]
umin(3) = -30; % Min rudder deflection           [deg]
umax(3) = 30;  % Max rudder deflection           [deg]
umin(4) = 0.5; % Min throttle setting (engine 1) [deg]
umax(4) = 10;  % Max throttle setting (engine 1) [deg]
umin(5) = 0.5; % Min throttle setting (engine 2) [deg]
umax(5) = 10;  % Max throttle setting (engine 2) [deg]

% Rate limits
dumax(1)   = 60; % Aileron    [deg/s]
dumax(2)   = 60; % Stabilizer [deg/s]
dumax(3)   = 60; % Rudder     [deg/s]
dumax(4:5) = 2;  % Throttle   [deg/s]

% Convert to rad
umin  = deg2rad(umin);
umax  = deg2rad(umax);
dumax = deg2rad(dumax);

%% Constants

% Nominal vehicle constants
m    = 120000;    % Aircraft total mass [kg]
cbar = 6.6;       % MAC [m]
lt   = 24.8;      % Tail arm length [m]
S    = 260;       % Wing planform area [m2]
St   = 64;        % Tail planform area [m2]
Ib   = m*[40.07    0     -2.0923; % intertia matrix
          0        64     0;
         -2.0923   0      99.92];

Xcg  = 0.23*cbar; % x position of CoG [m]
Ycg  = 0;         % y position of CoG [m]
Zcg  = 0.1*cbar;  % z position of CoG [m]

Xac  = 0.12*cbar; % x position of AC [m]
Yac  = 0;         % x position of AC [m]
Zac  = 0;         % x position of AC [m]

% Engine constants
Xapt1 = 0;        % x position of engine 1 force [m]
Yapt1 = -7.94;    % y position of engine 1 force [m]
Zapt1 = -1.9;     % z position of engine 1 force [m]

Xapt2 = 0;        % x position of engine 2 force [m]
Yapt2 = 7.94;     % y position of engine 2 force [m]
Zapt2 = -1.9;     % z position of engine 2 force [m]

% Aerodynamic data
depsda       = 0.25;           % Change in downwash wrt alpha (d_eps/d_a) [rad/rad]
alpha_L0     = deg2rad(-11.5); % Zero lift angle of attack [rad]
n            = 5.5;            % Slope of linear region in lift curve
a3           = -768.5;         % Coefficient of alpha^3
a2           = 609.2;          % Coefficient of alpha^2 
a1           = -155.2;         % Coefficient of alpha^1 
a0           = 15.212;         % Coefficient of alpha^0
alpha_switch = deg2rad(14.5);  % Alpha where lift curve goes from linear to non linear
cd_m1        = 5.5;            % Drag curve:
cd_c1        = 0.654;          % CD=(cd_c2+cd_m2*(cd_c1+cd_m1*alpha)^2)
cd_m2        = 0.07;
cd_c2        = 0.13;
dCYdbeta     = -1.6;           % Sideforce slope wrt sideslip
dCYdRud      = 0.24;           % Sideforce slope wrt rudder deflection

% Environment
rho          = 1.225;          % Air density [kg/m3]
g            = 9.81;           % Gravitational acceleration [m/s2]

save RCAM_constants
