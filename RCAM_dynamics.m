function xdot=RCAM_dynamics(x,u)

% INPUT FORMAT:
% x = [u;     1
%      v;     2 
%      w;     3
%      p;     4
%      q;     5
%      r;     6
%      phi;   7
%      theta; 8
%      psi;   9
%      xe;    10
%      ye;    11
%      ze];   12
% u = [dAil;  13
%      dStab; 14
%      dRud;  15
%      Thr1;  16
%      Thr2]; 17

u0     = u;
Vb0    = x(1:3);
pqr0   = x(4:6);
euler0 = x(7:9);
Xe0    = x(10:12);

t_sim  = 0;
% res    = sim("RCAM_sim.slx",'SrcWorkspace','current',...
%                 'SimulationMode','rapid', ...
%                 'RapidAcceleratorUpToDateCheck','off');
res    = sim("RCAM_sim.slx",'SrcWorkspace','current');
xdot   = res.xdot';

end

