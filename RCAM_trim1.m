clc
clear
close all

%% Get simulation constants

% RCAM_constants

%% Set target trim conditions

Va_target = 85;   % airspeed target [m/s]
ze_target = 1000; % altitude [m]

global target
target.Va = Va_target;

%% Initialize z_guess

% Initial states
Vb0    = [Va_target 0 0]';  % u v w         [m/s]
pqr0   = [0 0 0]';          % p q r         [deg/s]
euler0 = [0 0 0]';          % phi theta psi [deg]
Xe0    = [0 0 -ze_target]'; % xe ye ze      [m]

% Initial control inputs
u0 = [0;  % Aileron deflection     [deg]
      0;  % Stabilizer deflection  [deg]
      0;  % Rudder deflection      [deg]
      0.5;  % Throttle - engine 1  [deg]
      0.5]; % Throttle - engine 2  [deg]

euler0 = deg2rad(euler0);
pqr0   = deg2rad(pqr0);
u0     = deg2rad(u0);
x0     = [Vb0;pqr0;euler0;Xe0];

init = 1;  % 0 = start from initial guess
           % 1 = use saved values from last run

if init==0
    z0 = [x0;u0];
else
    load RCAM_trim1_res
    z0 = [xstar;ustar];
end

%% Optimization

fprintf('<strong><< OPTIMIZATION START >></strong>');
fprintf('\n');
fprintf('\n');

% fminsearch --------------------------------------------------------------
% tic
% [zstar,f0] = fminsearch('obj_xdot0',z_guess,...
%     optimset('TolX',1e-10,...
%              'MaxFunEvals',1,...
%              'MaxIter',1, ...
%              'Display','iter-detailed', ...
%              'PlotFcns',@optimplotfval));
% toc

% Set bounds --------------------------------------------------------------

load RCAM_constants umin umax

% upper bounds
ub=[inf,...         % 1) u
    0,...           % 2) v
    inf,...         % 3) w
    inf,...         % 4) p roll rate
    inf,...         % 5) q pitch rate
    inf,...         % 6) r yaw rate
    0,...           % 7) phi bank
    deg2rad(10),... % 8) theta pitch
    0,...           % 9) psi heading
    inf,...         % 10) xe
    inf,...         % 11) ye
    -ze_target,...  % 12) ze
    inf,...         % dAileron
    umax(2),...     % dStabilizer
    0,...           % dRudder
    umax(4),...     % throttle1
    umax(5)];       % throttle2

% lower bounds
lb=[-inf,...         % 1) u
    0,...            % 2) v
    -inf,...         % 3) w
    -inf,...         % 4) p roll rate
    -inf,...         % 5) q pitch rate
    -inf,...         % 6) r yaw rate
    0,...            % 7) phi bank
    -deg2rad(10),... % 8) theta pitch
    0,...            % 9) psi heading
    -inf,...         % 10) xe
    -inf,...         % 11) ye
    -ze_target,...   % 12) ze
    -inf,...         % dAileron
    umin(2),...      % dStabilizer
    0,...            % dRudder
    umin(4),...      % throttle1
    umin(5)];        % throttle2

% Set options -------------------------------------------------------------

options.Display       = 'iter-detailed';
options.Algorithm     = 'sqp';
options.FunValCheck   = 'off';
options.ScaleProblem  = 'false';
options.FinDiffType   = 'forward';
% options.DiffMinChange = 1e-3;
% options.DiffMaxChange = 1e-0;
% options.TolCon        = 1e-3;
% options.TolFun        = 1e-6;
% options.TolX          = 1e-10;
options.MaxIter       = 100;
options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Run optimization --------------------------------------------------------

tic
[zstar,fval,exitflag,output] = fmincon(@(x) RCAM_trim1_obj(x),z0,[],[],[],[],lb,ub,[],options);
t_fmincon=toc;

fprintf('<strong><< OPTIMIZATION COMPLETE >></strong>');
fprintf('\n');
fprintf('\n');
disp('Optimization Processing Time:');
fprintf('Total                = %6s\n',char(duration(0,0,t_fmincon)));
fprintf('Avg. per Iteration   = %6s\n',char(duration(0,0,t_fmincon/(output.iterations+1))));
fprintf('Avg. per Func. Eval. = %6.4f seconds\n',t_fmincon/output.funcCount);

%% Process Results

% Extract states & controls -----------------------------------------------
xstar=zstar(1:12);
ustar=zstar(13:17);

% Evaluate accelerations --------------------------------------------------
xdotstar=RCAM_dynamics(xstar,ustar);

% Table 1 - States --------------------------------------------------------
xstardisp=xstar;
xstardisp(4:9)=rad2deg(xstardisp(4:9));
xtable=array2table(xstardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) u     [m/s]', ...
    '2) v     [m/s]', ...
    '3) w     [m/s]', ...
    '4) p     [deg/s]', ...
    '5) q     [deg/s]', ...
    '6) r     [deg/s]', ...
    '7) phi   [deg]', ...
    '8) theta [deg]', ...
    '9) psi   [deg]', ...
    '10) xe   [m]', ...
    '11) ye   [m]', ...
    '12) ze   [m]'});
xtable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), xtable);
xtable0.Properties.VariableNames = xtable.Properties.VariableNames;
xtable0.Properties.RowNames = xtable.Properties.RowNames;
fprintf('\n');
disp('<strong>> Table 1 - States</strong>')
disp(xtable0)
fprintf('\n');

% Table 2 - Controls ------------------------------------------------------
ustardisp=rad2deg(ustar);
utable=array2table(ustardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) dAileron    [deg]', ...
    '2) dStabilizer [deg]', ...
    '3) dRudder     [deg]', ...
    '4) Throttle1   [deg]', ...
    '5) Throttle2   [deg]'});
utable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), utable);
utable0.Properties.VariableNames = utable.Properties.VariableNames;
utable0.Properties.RowNames = utable.Properties.RowNames;
disp('<strong>> Table 2 - Control Inputs</strong>')
disp(utable0)
fprintf('\n');

% Table 3 - Accelerations -------------------------------------------------
xdotstardisp=xdotstar;
xdotstardisp(4:9)=rad2deg(xdotstardisp(4:9));
xdottable=array2table(xdotstardisp,'VariableNames',{'Value'},'RowNames',{ ...
    '1) udot     [m/s2]', ...
    '2) vdot     [m/s2]', ...
    '3) wdot     [m/s2]', ...
    '4) pdot     [deg/s2]', ...
    '5) qdot     [deg/s2]', ...
    '6) rdot     [deg/s2]', ...
    '7) phidot   [deg/s]', ...
    '8) thetadot [deg/s]', ...
    '9) psidot   [deg/s]', ...
    '10) xedot   [m/s]', ...
    '11) yedot   [m/s]', ...
    '12) zedot   [m/s]'});
xdottable0 = varfun(@(x) num2str(x, ['%' sprintf('.%df', 4)]), xdottable);
xdottable0.Properties.VariableNames = xdottable.Properties.VariableNames;
xdottable0.Properties.RowNames = xdottable.Properties.RowNames;
disp('<strong>> Table 3 - Accelerations</strong>')
disp(xdottable0)

% Save results ------------------------------------------------------------
save RCAM_trim1_res xstar ustar

