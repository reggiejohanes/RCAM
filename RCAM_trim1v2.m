clc
clear
close all

%% Set target trim conditions

Va_target = 85;            % airspeed target [m/s]
ze_target = 1000;          % altitude [m]
% gamma_target = deg2rad(0); % flight path angle [deg]

global target
target.Va    = Va_target;
target.ze    = ze_target;
% target.gamma = gamma_target;

%% Initialize z_guess

% Initial states
x0 = [Va_target;   % u [m/s]
      0;           % w [m/s]
      deg2rad(0)]; % theta [deg]

% Initial control inputs
u0 = [deg2rad(0);    % Stabilizer deflection [deg]
      deg2rad(0.5)]; % Throttle - engine 1&2 [deg]

init = 0;  % 0 = start from initial guess
           % 1 = use saved values from last run

if init==0
    z0 = [x0;u0];
else
    load RCAM_trim1v2_res zstar
    z0 = zstar;
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
    inf,...         % 3) w
    deg2rad(10),... % 8) theta pitch
    umax(2),...     % dStabilizer
    umax(4)];       % throttle1

% lower bounds
lb=[-inf,...        % 1) u
    -inf,...        % 3) w
    -deg2rad(10),...% 8) theta pitch
    umin(2),...     % dStabilizer
    umin(4)];%,...  % throttle1

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
% options.MaxIter       = 100;
options.PlotFcns      = {@optimplotx, @optimplotfval, @optimplotfunccount, @optimplotconstrviolation, @optimplotstepsize, @optimplotfirstorderopt};
options.OutputFcn     = @outputFcn_global;

% Run optimization --------------------------------------------------------

tic
[zstar,fval,exitflag,output] = fmincon(@(x) obj_xdot0v2(x),z0,[],[],[],[],lb,ub,[],options);
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
xstar=[zstar(1);... % u
       0;...        % v
       zstar(2);... % w
       0;...        % p
       0;...        % q
       0;...        % r
       0;...        % phi
       zstar(3);... % theta
       0;...        % psi
       0;...        % xe
       0;...        % ye
       -ze_target]; % ze
ustar=[0;...        % dAil
       zstar(4);... % dStab
       0;...        % dRud
       zstar(5);... % throttle1
       zstar(5)];   % throttle2

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
save RCAM_trim1v2_res zstar xstar ustar

