
t_sim = 480;

% load RCAM_trim1_res.mat xstar ustar
load RCAM_trim2_res.mat xstar ustar

u0     = ustar;
Vb0    = xstar(1:3);
pqr0   = xstar(4:6);
euler0 = xstar(7:9);
Xe0    = xstar(10:12);