function f0=obj_xdot0(z)

global target
Va_target = target.Va;

x = z(1:12);
u = z(13:17);

xdot = RCAM_dynamics(x,u);
xdot(10) = [];

theta = x(8);
Va    = sqrt(x(1)^2+x(2)^2+x(3)^2);
alpha = atan2(x(3),x(1));
gam   = theta-alpha;

Q = [xdot;
    Va-Va_target;
    gam];

% penalty weight matrix
H = diag(ones(1,numel(Q)));
H(5,5)=100; % qdot
H(8,8)=1000; % thetadot

f0 = Q'*H*Q;