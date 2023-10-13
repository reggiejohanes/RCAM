function f0=RCAM_trim2_obj(z)

global target
Va_target    = target.Va;
ze_target    = target.ze;
% gamma_target = target.gamma;

x=[z(1);...     % u
   0;...        % v
   z(2);...     % w
   0;...        % p
   0;...        % q
   0;...        % r
   0;...        % phi
   z(3);...     % theta
   0;...        % psi
   0;...        % xe
   0;...        % ye
   -ze_target]; % ze
u=[0;...        % dAil
   z(4);...     % dStab
   0;...        % dRud
   z(5);...     % throttle1
   z(5)];       % throttle2

xdot = RCAM_dynamics(x,u);
xdot(10) = [];

theta = x(8);
Va    = sqrt(x(1)^2+x(2)^2+x(3)^2);
alpha = atan2(x(3),x(1));
gam   = theta-alpha;

Q = [xdot;
    Va-Va_target;
    gam];

H = diag(ones(1,numel(Q))); % penalty weight matrix
H(5,5)=100; % penalty weight for qdot pitch acceleration

f0 = Q'*H*Q;