function [Xdot] = RCAM_model0(X,U)

% Testing
% clc
% clear
% close all
% X =  [85;    % u
%       0;     % v
%       0;     % w
%       0;     % p (roll rate)
%       0;     % q (pitch rate)
%       0;     % r (yaw rate)
%       0;     % phi (bank)
%       0.1;   % theta (pitch)
%       0;];   % psi (heading)
% U =  [0;     % Aileron deflection
%      -0.1;   % Stabilizer deflection
%       0;     % Rudder deflection
%       0.08;  % Throttle - engine 1
%       0.08]; % Throttle - engine 2

%% Control Limits/Saturation

umin(1) = -25; % Min aileron deflection [deg]
umax(1) = 25;  % Max aileron deflection [deg]
umin(2) = -25; % Min stabilizer deflection [deg]
umax(2) = 10;  % Max stabilizer deflection [deg]
umin(3) = -30; % Min rudder deflection [deg]
umax(3) = 30;  % Max rudder deflection [deg]
umin(4) = 0.5; % Min throttle setting (engine 1) [deg]
umax(4) = 10;  % Max throttle setting (engine 1) [deg]
umin(5) = 0.5; % Min throttle setting (engine 2) [deg]
umax(5) = 10;  % Max throttle setting (engine 2) [deg]

umin = deg2rad(umin);
umax = deg2rad(umax);
for i=1:5
    if U(i) > umax(i)
        U(i) = umax(i);
    elseif U(i) < umin(i)
        U(i) = umin(i);
    end
end

%% Extract State and Control Vectors

x1 = X(1); % u
x2 = X(2); % v
x3 = X(3); % w
x4 = X(4); % p (roll rate)
x5 = X(5); % q (pitch rate)
x6 = X(6); % r (yaw rate)
x7 = X(7); % phi (bank)
x8 = X(8); % theta (pitch)
x9 = X(9); % psi (heading)

u1 = U(1); % dA (aileron deflection)
u2 = U(2); % dT (stabilizer deflection)
u3 = U(3); % dR (rudder deflection)
u4 = U(4); % dth1 (throttle - engine 1)
u5 = U(5); % dth2 (throttle - engine 2)

%% Constants

% Nominal vehicle constants
m    = 120000;    % Aircraft total mass [kg]

cbar = 6.6;       % MAC [m]
lt   = 24.8;      % Tail arm length [m]
S    = 260;       % Wing planform area [m2]
St   = 64;        % Tail planform area [m2]

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

% Other constants
rho          = 1.225;          % Air density [kg/m3]
g            = 9.81;           % Gravitational acceleration [m/s2]
depsda       = 0.25;           % Change in downwash wrt alpha (d_eps/d_a) [rad/rad]
alpha_L0     = deg2rad(-11.5); % Zero lift angle of attack [rad]
n            = 5.5;            % Slope of linear region in lift curve
a3           = -768.5;         % Coefficient of alpha^3
a2           = 609.2;          % Coefficient of alpha^2 
a1           = -155.2;         % Coefficient of alpha^1 
a0           = 15.212;         % Coefficient of alpha^0
alpha_switch = deg2rad(14.5);  % Alpha where lift curve goes from linear to non linear

%% Intermediate Variables

% Calculate airspeed
Va = sqrt(x1^2+x2^2+x3^2);

% Calculate aoa & sideslip angle
alpha = atan2(x3,x1);
beta  = asin(x2/Va);

% Calculate dynamic pressure
Q = 0.5*rho*Va^2;

% Define wbe_b (rotational velocity) and V_b (linear velocity) vectors
wbe_b = [x4;x5;x6];
V_b   = [x1;x2;x3];

%% Aerodynamic Forces

% Calculate CL_wb
if alpha <= alpha_switch
    CL_wb = n*(alpha-alpha_L0);
else
    CL_wb = polyval([a3 a2 a1 a0],alpha);
end

% Calculate CL_t
epsilon = depsda*(alpha-alpha_L0);
alpha_t = alpha-epsilon+u2+1.3*x5*lt/Va;
CL_t    = 3.1*(St/S)*alpha_t;

% Total lift coefficient
CL = CL_wb + CL_t;

% Total drag coefficient (neglecting tail)
CD = 0.13 + 0.07*(5.5*alpha+0.654)^2;

% Total sideforce coefficient
CY = -1.6*beta+0.24*u3;

% Dimensional forces in stability axis
FA_s = Q*S*[-CD;
             CY;
            -CL];

% Rotation from stability to body axis
C_bs = [cos(alpha)    0    -sin(alpha);
        0             1     0;
        sin(alpha)    0     cos(alpha)];

FA_b = C_bs*FA_s;

%% Aerodynamic Moments

% Define eta, dCMcd, dCMdu
eta = [-1.4*beta;
       -0.59-(3.1*(St*lt)/(S*cbar))*(alpha-epsilon);
        (1-alpha*(180/(15*pi)))*beta];

dCMdx = (cbar/Va)*[-11   0                             5;
                    0    (-4.03*(St*lt^2)/(S*cbar^2))  0;
                    1.7  0                            -11.5];

dCMdu = [-0.6  0                        0.22; % control effectiveness
          0    (-3.1*(St*lt)/(S*cbar))  0;
          0    0                       -0.63];

% Aerodynamic moment coefficients
CMac_b = eta + dCMdx*wbe_b + dCMdu*[u1;u2;u3];

% Dimensionalize aerodynamic moments about AC
MAac_b = CMac_b*Q*S*cbar;

% Transfer moment to CG
rcg_b  = [Xcg;Ycg;Zcg];
rac_b  = [Xac;Yac;Zac];
MAcg_b = MAac_b + cross(FA_b,rcg_b-rac_b);

%% Engine Forces & Moments

% Thrust for each engine
F1 = u4*m*g;
F2 = u5*m*g;

% Vectorize engine thrust (assuming installation angle = 0 deg)
FE1_b = [F1;0;0];
FE2_b = [F2;0;0];

FE_b = FE1_b + FE2_b;

% Moment due to engine thrust
mew1 = [Xcg - Xapt1;
        Yapt1 - Ycg;
        Zcg - Zapt1];

mew2 = [Xcg - Xapt2;
        Yapt2 - Ycg;
        Zcg - Zapt2];

MEcg1_b = cross(mew1,FE1_b);
MEcg2_b = cross(mew2,FE2_b);

MEcg_b = MEcg1_b + MEcg2_b;

%% Gravity Effects

% Gravitational forces in the body frame
g_b  = g*[-sin(x8);
          cos(x8)*sin(x7);
          cos(x8)*cos(x7)];
Fg_b = m*g_b;

%% Equations of Motion

% Inertia matrix
Ib = m*[40.07    0     -2.0923;
        0        64     0;
       -2.0923   0      99.92];

% invIb = inv(Ib);
invIb = (1/m)*[0.0249836    0         0.000523151;
               0            0.015625  0;
               0.000523151  0         0.010019];

% All forces in body axis -> calculate linear accelerations
% (udot, vdot, wdot)
F_b = Fg_b + FE_b + FA_b;
x1x3dot = (1/m)*F_b - cross(wbe_b,V_b);

% All moments in body axis -> calculate angular accelerations
% (pdot,qdot,rdot)
Mcg_b = MAcg_b + MEcg_b;
x4x6dot = invIb*(Mcg_b - cross(wbe_b,Ib*wbe_b));

% Calculate phidot, thetadot, psidot
H_phi = [1  sin(x7)*tan(x8)  cos(x7)*tan(x8);
         0  cos(x7)         -sin(x7);
         0  sin(x7)/cos(x8)  cos(x7)/cos(x8)];
x7x9dot = H_phi*wbe_b;

% Complie Xdot vector
Xdot = [x1x3dot;
        x4x6dot;
        x7x9dot];

end