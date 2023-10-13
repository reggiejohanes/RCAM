function stop = outputFcn_global(x,optimValues,state)
% outputFcn_global()
%
% OutputFun for optimizers (fminunc, fmincon etc),  saving intermediate results 
% in global variable "outputFcn_global_data" for later access. 
%
% It is not supposed for live updates during optimization but for 
% later inspection, which is much more efficient. 
%
% Usage 
%   options = optimoptions( ... , 'OutputFcn',@outputFcn_global ); 
%   [XOpt,fval,exitflag,output] = fminunc(@fun, X0, options); 
%   outputFcn_global_data(k).x 
%
% See also the supplied example file. 
%
% Last Changes
%   Daniel Frisch, ISAS, 10.2020: created example
%   Daniel Frisch, ISAS, 11.2019: improved documentation 
% Created
%   Daniel Frisch, ISAS, 10.2019 
%
stop = false;
global outputFcn_global_data
switch state
  case 'init'
    outputFcn_global_data = struct();
    outputFcn_global_data.x = x;
    outputFcn_global_data.optimValues = optimValues;
    outputFcn_global_data.timerVal = tic;
  case 'iter'
    ind = length(outputFcn_global_data)+1;
    outputFcn_global_data(ind).x = x;
    outputFcn_global_data(ind).optimValues = optimValues;
    outputFcn_global_data(ind).timerVal = toc(outputFcn_global_data(1).timerVal);
  case 'done'
    %
  otherwise
    error('wrong switch')
end
end



